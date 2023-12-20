#include <iostream>
#include <string>

using namespace std;

// студенты

class Student {
protected:
    string name;
    int age;

public:
    void SetName(const string& n) { name = n; }
    const string& GetName() const { return name; }

    void SetAge(int a) { age = a; }
    int GetAge() const { return age; }

    void Print() const {
        cout << "Студент: " << GetName() << ", Возраст: " << GetAge() << " лет\n";
    }
};

class Aspirant : public Student {
private:
    string thesisTopic;

public:
    void SetThesisTopic(const string& topic) { thesisTopic = topic; }

    const string& GetThesisTopic() const { return thesisTopic; }

    void Print() const {
        Student::Print();
        cout << "Тема кандидатской работы: " << GetThesisTopic() << "\n";
    }
};

// транспорт

class Transport {
protected:
    int distance;
    int cost;
public:
    virtual void CalculateTripDetails() const = 0;

    void SetDistance(int d) { distance = d; }
    const int GetDistance() const { return distance; }

    void SetCost(int c) { cost = c; }
    const int GetCost() const { return cost; }
};

class Car : public Transport {
public:
    void CalculateTripDetails() const override {
        cout << "Расчет поездки на автомобиле: " << GetCost() * GetDistance() << "\n";
    }
};

class Taxi : public Transport {
public:
    void CalculateTripDetails() const override {
        cout << "Расчет поездки на такси: " << GetCost() * GetDistance() << "\n";
    }
};

class Tram : public Transport {
public:
    void CalculateTripDetails() const override {
        cout << "Расчет поездки на трамвае: " << GetCost() * GetDistance() << "\n";
    }
};

class Trol : public Transport {
public:
    void CalculateTripDetails() const override {
        cout << "Расчет поездки на троллейбусе: " << GetCost() * GetDistance() << "\n";
    }
};

class Mars : public Transport {
public:
    void CalculateTripDetails() const override {
        cout << "Расчет поездки на маршрутке: " << GetCost() * GetDistance() << "\n";
    }
};

class Electro : public Transport {
public:
    void CalculateTripDetails() const override {
        cout << "Расчет поездки на электросамокате: " << GetCost() * GetDistance() << "\n";
    }
};

class Train : public Transport {
public:
    void CalculateTripDetails() const override {
        cout << "Расчет поездки на поезде: " << GetCost() * GetDistance() << "\n";
    }
};

class Plane : public Transport {
public:
    void CalculateTripDetails() const override {
        cout << "Расчет поездки на самолете: " << GetCost() * GetDistance() << "\n";
    }
};

class Bysicle : public Transport {
public:
    void CalculateTripDetails() const override {
        cout << "Расчет поездки на велосипеде: " << GetCost() * GetDistance() << "\n";
    }
};

// кисти

class Pen {
protected:
    string color;
    float thick;
    int type;
public:
    void SetColor(const string& c) { color = c; }
    const string& GetColor() const { return color; }

    void SetThick(float t) { thick = t; }
    const int GetThick() const { return thick; }

    void SetType(int t) { type = t; }
    const int GetType() const { return type; }

    void Draw() const {
        cout << "Рисование: " << GetColor() << " " << GetThick() << " " << GetType() << "\n";
    }
};

class Brush {
protected:
    string color = "0";
public:
    void SetColor(const string& c) { color = c; }
    const string& GetColor() const { return color; }

    void Fill() const {
        cout << "Заливка: " << GetColor() << "\n";
    }
};

class SolidBrush : public Brush {
public:
    void Fill() {
        cout << "Заливка Solid: " << GetColor() << "\n";
    }
};
class GradientBrush : public Brush {
private:
    string* colors;
    int count;
public:
    void SetColors(string* c, int _count) {
        colors = new string[_count];
        for (int i = 0; i < _count; i++) colors[i] = c[i];
        count = _count;
    }
    string GetColors() const {
        string ret;
        for (int i = 0; i < count; i++) {
            ret += colors[i] + " ";
        }
        return ret;
    }

    void Fill() {
        cout << "Заливка GradientBrush: " << GetColors() + GetColor() << "\n";
    }
};
class HatchBrush : public Brush {
private:
    string sec_col;
    int type;
public:
    void SetSecond(const string& c) { sec_col = c; }
    const string& GetSecond() const { return sec_col; }
    void SetType(int t) { type = t; }
    const int GetType() const { return type; }

    void Fill() {
        cout << "Заливка HatchBrush: " << GetColor() + GetSecond() + " тип " << GetType() << "\n";
    }
};
class TextureBrush : public Brush {
private:
    string path;
public:
    void SetPath(const string& p) { path = p; }
    const string& Getpath() const { return path; }

    void Fill() {
        cout << "Заливка TextureBrush: " << GetColor() + " путь " + Getpath() << "\n";
    }
};
class VisualBrush : public Brush {
private:
    int id;
public:
    void SetID(const int i) { id = i; }
    const int GetID() const { return id; }

    void Fill() {
        cout << "Заливка VisualBrush: " << GetColor() + " ID " + to_string(GetID()) << "\n";
    }
};

class LinearGradientBrush : public GradientBrush {
public:
    void Fill() {
        cout << "Заливка LinearGradientBrush: " << GetColors() + GetColor() << "\n";
    }
};
class RadialGradientBrush : public GradientBrush {
public:
    void Fill() {
        cout << "Заливка RadialGradientBrush: " << GetColors() + GetColor() << "\n";
    }
};

// фигуры

class Geometry {
protected:
    Pen pen;
    Brush* brush;
public:
    void SetPen(const Pen p) { pen = p; }
    void SetBrush(Brush* b) { brush = b; }
    const Pen GetPen() const { return pen; }
    const Brush GetBrush() { return *brush; }
};

class Rectangle : public Geometry {
public:
    void Draw() {
        cout << "Нарисован треугольник: " << '\n';
        GetPen().Draw();
        GetBrush().Fill();
    }
};
class Ellipse : public Geometry {
public:
    void Draw() {
        cout << "Нарисован круг: " << '\n';
        GetPen().Draw();
        GetBrush().Fill();
    }
};
class Polyline : public Geometry {
public:
    void Draw() {
        cout << "Нарисован многоугольник: " << '\n';
        GetPen().Draw();
        GetBrush().Fill();
    }
};

// шрифт 

class Font {
protected:
    int size;
    string family;
    bool bold;
    bool italic;
    bool underline;
    string color;
public:
    int GetSize() const { return size; }
    string GetFamily() const { return family; }
    bool GetBold() const { return bold; }
    bool GetItalic() const { return italic; }
    bool GetUnderline() const { return underline; }
    string GetColor() const { return color; }

    void SetSize(int s) { size = s; }
    void SetFamily(string f) { family = f; }
    void SetBold(bool b) { bold = b; }
    void SetItalic(bool i) { italic = i; }
    void SetUnderline(bool u) { underline = u; }
    void SetColor(string c) { color = c; }
};

class Text {
protected:
    string text;
public:
    string GetText() const { return text; }
    void SetText(string t) { text = t; }
};

class Button : public Font, public Text {
public:
    void Draw() {
        cout << "Текст: " << GetText() << '\n' <<
            "Размер: " << GetSize() << '\n' <<
            "Семья: " << GetFamily() << '\n' <<
            "Жирный: " << GetBold() << '\n' <<
            "Наклоненный: " << GetItalic() << '\n' <<
            "Нижнее подчеркивание: " << GetUnderline() << '\n' <<
            "Цвет: " << GetColor() << 'n';
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    Student student;
    student.SetName("Иван");
    student.SetAge(20);
    cout << "Имя студента: " << student.GetName() << ", Возраст: " << student.GetAge() << " лет\n";

    Aspirant aspirant;
    aspirant.SetName("Петр");
    aspirant.SetAge(25);
    aspirant.SetThesisTopic("Исследование алгоритмов");
    cout << "Имя аспиранта: " << aspirant.GetName() << ", Возраст: " << aspirant.GetAge() << " лет\n";
    cout << "Тема кандидатской работы: " << aspirant.GetThesisTopic() << "\n\n";

    int distance = 450;
    Car car;
    car.SetCost(30); car.SetDistance(distance);
    Taxi taxi;
    taxi.SetCost(50); taxi.SetDistance(distance);
    Tram tram;
    tram.SetCost(7); tram.SetDistance(distance);
    Trol trol;
    trol.SetCost(10); trol.SetDistance(distance);
    Mars mars;
    mars.SetCost(7); mars.SetDistance(distance);
    Electro electro;
    electro.SetCost(3); electro.SetDistance(distance);
    Train train;
    train.SetCost(5); train.SetDistance(distance);

    car.CalculateTripDetails();
    taxi.CalculateTripDetails();
    tram.CalculateTripDetails();
    trol.CalculateTripDetails();
    mars.CalculateTripDetails();
    electro.CalculateTripDetails();
    train.CalculateTripDetails();
    cout << "\n";

    string colors[] = { "123AFF", "89BBC5", "DE9A41" };
    Pen pen;
    pen.SetColor("FF9977"); pen.SetThick(12.5); pen.SetType(3);
    Brush brush;
    brush.SetColor("AA3312");
    SolidBrush solid;
    solid.SetColor("349109");
    GradientBrush gradient;
    gradient.SetColors(colors, 3); gradient.SetColor("384018");
    HatchBrush hatch;
    hatch.SetColor("458273"); hatch.SetSecond("384761"); hatch.SetType(5);
    TextureBrush texture;
    texture.SetPath("/home/etc/logo");
    VisualBrush visual;
    visual.SetColor("473820"); visual.SetID(19);
    LinearGradientBrush linear;
    linear.SetColors(colors, 3); linear.SetColor("371927");
    RadialGradientBrush radial;
    radial.SetColors(colors, 3); radial.SetColor("283847");

    pen.Draw();
    brush.Fill();
    solid.Fill();
    gradient.Fill();
    hatch.Fill();
    texture.Fill();
    visual.Fill();
    linear.Fill();
    radial.Fill();
    cout << '\n';

    Rectangle rect;
    rect.SetPen(pen); rect.SetBrush(&linear);
    Ellipse ell;
    ell.SetPen(pen); ell.SetBrush(&radial);
    Polyline poly;
    poly.SetPen(pen); poly.SetBrush(&gradient);

    rect.Draw();
    ell.Draw();
    poly.Draw();
    cout << '\n';

    Button button;
    button.SetSize(14);
    button.SetFamily("Times New Roman");
    button.SetBold(false);
    button.SetItalic(true);
    button.SetUnderline(true);
    button.SetColor("blue");
    button.SetText("Сюда кликать");
    button.Draw();

    return 0;
}