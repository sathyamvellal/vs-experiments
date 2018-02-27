#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>

const int WIDTH = 1280;
const int HEIGHT = 960;
const char* title = "Hello World";

void logInfo();
void onInit();
void onShutdown();
void onResize(int newWidth, int newHeight);
void onRender();

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	// Depth Buffer | Double Buffering | RGBA for FrameBuffer
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	// OpenGL v3.3
	glutInitContextVersion(3, 3);
	// OpenGL Core Profile with Debugging
	glutInitContextFlags(GLUT_CORE_PROFILE | GLUT_DEBUG);
	// Remove fixed function OpenGL compatibility
	glutInitContextProfile(GLUT_FORWARD_COMPATIBLE);
	// Window size
	glutInitWindowSize(WIDTH, HEIGHT);
	// Create Window
	glutCreateWindow(title);

	glewExperimental = GL_TRUE;
	GLenum err = glewInit();

	if (err != GLEW_OK) {
		std::cerr << "ERROR: " << glewGetErrorString(err) << std::endl;
		std::cin.get();
		exit(1);
	} else {
		if (GLEW_VERSION_3_3) {
			std::cout << "Driver supports OpenGL 3.3" << std::endl;
			std::cout << "Details" << std::endl;
		}
	}

	logInfo();

	onInit();
	glutCloseFunc(onShutdown);
	glutDisplayFunc(onRender);
	glutReshapeFunc(onResize);
	glutMainLoop();

	return 0;
}

void logInfo()
{
	std::cout << "\tUsing glew: " << glewGetString(GLEW_VERSION) << std::endl;
	std::cout << "\tVendor: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "\tRenderer: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "\tVersion: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "\tGLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
}

void onInit()
{
	glClearColor(1, 0, 0, 0);
	std::cout << "Initialisation successful!" << std::endl;
}

void onShutdown()
{
	std::cout << "Shutdown successful!" << std::endl;
}

void onResize(int newWidth, int newHeight)
{
	// We aren't doing any resize for now.
}

void onRender()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutSwapBuffers();
}