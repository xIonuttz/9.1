#include <iostream>

// Base Shape class
class Shape {
public:
    virtual void draw() const = 0;
    virtual ~Shape() {}
};

// Derived Circle class
class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a Circle\n";
    }
};

// Derived Square class
class Square : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a Square\n";
    }
};

// Drawing class with injected dependency (Shape)
class Drawing {
private:
    const Shape& shape;

public:
    // Constructor with dependency injection
    Drawing(const Shape& shape) : shape(shape) {}

    // Method to draw the injected shape
    void drawShape() const {
        shape.draw();
    }
};

int main() {
    // Create instances of shapes
    Circle circle;
    Square square;

    // Create instances of Drawing with different shapes injected
    Drawing drawingWithCircle(circle);
    Drawing drawingWithSquare(square);

    // Draw the shapes using the Drawing class
    std::cout << "Drawing with Circle:\n";
    drawingWithCircle.drawShape();

    std::cout << "\nDrawing with Square:\n";
    drawingWithSquare.drawShape();

    return 0;
}
