#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cassert>

using namespace std;

const double PI = 2 * acos(0);
const double EPS = 1E-5;

struct Point {
	double x, y;
	Point() {
	}
	Point(double _x, double _y) {
		x = _x;
		y = _y;
	}
	void read() {
		scanf("%lf %lf", &x, &y);
	}
	void print() {
		printf("%lf %lf\n", x, y);
	}
};

struct Line {
	double a, b, c;
	Line() {
	}
	Line(Point p1, Point p2) {
		a = p2.y - p1.y;
		b = p1.x - p2.x;
		c = -a * p1.x - b * p1.y;
	}
};

Point operator + (Point a, Point b) {
	return Point(a.x + b.x, a.y + b.y);
}

Point operator - (Point a, Point b) {
	return Point(a.x - b.x, a.y - b.y);
}

Point operator / (Point a, double x) {
	return Point(a.x / x, a.y / x);
}

Point intersect(Line l1, Line l2) {
	double del = l1.a * l2.b - l2.a * l1.b;
	return Point((l1.b * l2.c - l2.b * l1.c) / del,
				 (l2.a * l1.c - l1.a * l2.c) / del);
}

Line perpendicular(Line l, Point p) {
	swap(l.a, l.b);
	l.a = -l.a;
	l.c = -l.a * p.x - l.b * p.y;
	return l;
}

Point circumcenter(Point a, Point b, Point c) {
	return intersect(perpendicular(Line(a, b), (a + b) / 2.0), 
					 perpendicular(Line(b, c), (b + c) / 2.0));
}

bool eq(double a, double b){
	return fabs(a - b) < EPS;
}

double angle[3];
Point p[3];

int main() {
	for(int i = 0; i < 3; ++i) p[i].read();
	Point mid = circumcenter(p[0], p[1], p[2]);
	for(int i = 0; i < 3; ++i) {
		p[i] = p[i] - mid;
		angle[i] = atan2(p[i].y, p[i].x);
	}
	double rSq = p[0].x * p[0].x + p[0].y * p[0].y;
	sort(angle, angle + 3);
	double d1 = (angle[1] - angle[0]) / (2 * PI),
		   d2 = (angle[2] - angle[1]) / (2 * PI);
	for(int i = 3; i <= 100; ++i) {
		if(eq(d1 * i, round(d1 * i)) && eq(d2 * i, round(d2 * i))) {
			printf("%.7lf\n", i * cos(PI / i) * sin(PI / i) * rSq);
			return 0;
		}
	}
	assert(false);
}