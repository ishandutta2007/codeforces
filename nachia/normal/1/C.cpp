#include<bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

template<class Ty>
using passive_queue = priority_queue<Ty, vector<Ty>, greater<Ty>>;


struct Point {
	double x, y;
	Point() {}
	Point(double X, double Y) { x = X; y = Y; }
	Point operator+(const Point& r) const { return Point{ x + r.x, y + r.y }; };
	Point operator-(const Point& r) const { return Point{ x - r.x, y - r.y }; };
	Point operator*(const double& r) const { return Point{ x * r, y * r }; }
	double operator*(const Point& r) const { return x * r.x + y * r.y; }
	Point N() const { return { y, -x }; }
	bool Par(const Point& r) const {
		if (x == 0.0 && y == 0.0) return true;
		if (r.x == 0.0 && r.y == 0.0) return true;
		if (x == 0.0 && r.x == 0.0) return true;
		if (x == 0.0 || r.x == 0.0) return false;
		return abs(y / x - r.y / r.x) < 1e-10;
	}
};
double sqDist(const Point & a, const Point & b) {
	Point d = b - a;
	return d * d;
}
pair<Point, double> OutCenter(const Point & a, const Point & b, const Point & c) {
	Point ab = b - a, ac = c - a;
	if (ab.Par(ac)) return{ {0.0,0.0}, 1e8 };
	Point Nab = ab.N(), Nac = ac.N();
	Point bc = c - b;
	double S = (Nac.y * bc.x - Nac.x * bc.y) / (Nac.y * Nab.x - Nac.x * Nab.y);

	Point ans = (Nab * S + ab) * 0.5;
	double d = ans * ans;
	return { ans + a, d };
}

UL gcd(UL a, UL b) { return b ? gcd(b, a % b) : a; }

struct Problem {

	void Solve() {
		double pi = 3.141592653589793;
		Point a, b, c;
		cin >> a.x >> a.y;
		cin >> b.x >> b.y;
		cin >> c.x >> c.y;
		auto C = OutCenter(a, b, c);
		a = a - C.first;
		b = b - C.first;
		c = c - C.first;
		for (UL j = 3; j <= 100; j++) {
			bool oka = false, okb = false;
			for(UL k = 1; k < j; k++) {
				double angle = 2 * pi / j * k;
				double x = sin(angle) * a.y + cos(angle) * a.x;
				double y = cos(angle) * a.y - sin(angle) * a.x;
				if (abs(b.x - x) < 1e-4)if (abs(b.y - y) < 1e-4) oka = true;
				if (abs(c.x - x) < 1e-4)if (abs(c.y - y) < 1e-4) okb = true;
			}

			if (oka && okb) {
				double ans = C.second * j * sin(2.0 * pi / j) * 0.5;
				cout << ans << endl; return;
			}
		}
	}

	Problem();
};
int main() {
	unique_ptr<Problem> p(new Problem());
	p->Solve();
	return 0;
}
Problem::Problem() {
	cout << fixed << setprecision(10);
}