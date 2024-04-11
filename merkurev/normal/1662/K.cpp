#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) {fprintf(stderr, __VA_ARGS__);fflush(stderr);}
#else
	#define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

const double PI = 4 * atan(1.);

const double INF = 1e5;
const int IT = 60;

const double eps = 1e-7;
bool eq(double x, double y) {
	return abs(x - y) < eps;
}
bool ls(double x, double y) {
	return x < y && !eq(x, y);
}
bool lseq(double x, double y) {
	return x < y || eq(x, y);
}

double sqr(double x) {
	return x * x;
}

struct Point {
	double x, y;

	Point() : x(), y() {}
	Point (double _x, double _y) : x(_x), y(_y) {}

	void scan() {
		scanf("%lf%lf", &x, &y);
	}
	void print() {
		printf("%.12lf %.12lf\n", x, y);
	}

	Point operator + (const Point &a) const {
		return Point(x + a.x, y + a.y);
	}
	Point operator - (const Point &a) const {
		return Point(x - a.x, y - a.y);
	}
	Point operator * (const double &k) const {
		return Point(x * k, y * k);
	}
	Point operator / (const double &k) const {
		return Point(x / k, y / k);
	}
	double operator % (const Point &a) const {
		return x * a.x + y * a.y;
	}
	double operator * (const Point &a) const {
		return x * a.y - y * a.x;
	}
	double sqrLen() const {
		return *this % *this;
	}
	double len() const {
		return sqrt(sqrLen());
	}
	Point norm() const {
		return *this / len();
	}
	Point ort() const {
		return Point(-y, x);
	}
	Point rot(const double &ca, const double &sa) const {
		return *this * ca + ort() * sa;
	}
	Point rot(const double &ang) const {
		return rot(cos(ang), sin(ang));
	}
};

bool intersectLines(Point A, Point a, Point B, Point b, Point &I) {
	if (eq(a * b, 0)) return false;
	double y = ((A - B) * a) / (b * a);
	I = B + b * y;
	return true;
}

Point getH(Point P, Point A, Point a) {
	return A + a * (((P - A) % a) / a.sqrLen());
}
bool intersectLineCircle(Point A, Point a, Point O, double R, Point &I1, Point &I2) {
	Point H = getH(O, A, a);
	double x = (O - H).len();
	if (ls(R, x)) return false;
	if (eq(R, x)) {
		I1 = I2 = H;
		return true;
	}
	a = a.norm();
	x = sqrt(sqr(R) - sqr(x));
	I1 = H + a * x;
	I2 = H - a * x;
	return true;
}

bool intersectCircles(Point O1, double R1, Point O2, double R2, Point &I1, Point &I2) {
	if (R1 < R2) {
		swap(O1, O2);
		swap(R1, R2);
	}
	double L = (O1 - O2).len();
	if (ls(R1 + R2, L) || ls(L, R1 - R2) || eq(L, 0)) return false;
	if (eq(R1 + R2, L) || eq(L, R1 - R2)) {
		I1 = I2 = O1 + (O2 - O1).norm() * R1;
		return true;
	}
	double x = (sqr(R1) - sqr(R2) + sqr(L)) / (2 * L);
	Point a = (O2 - O1).norm();
	Point H = O1 + a * x;
	a = a.ort();
	x = sqrt(sqr(R1) - sqr(x));
	I1 = H + a * x;
	I2 = H - a * x;
	return true;
}

bool isInside(Point P, Point O, double R) {
	return lseq((P - O).sqrLen(), sqr(R));
}

double getAngle(Point v, Point u) {
	return abs(atan2(v * u, v % u));
}

int sgn(double x) {
	if (eq(x, 0)) return 0;
	if (x > 0) return 1;
	return -1;
}
bool onDiffSides(Point A, Point B, Point P, Point Q) {
	return sgn((P - A) * (B - A)) * sgn((Q - A) * (B - A)) == -1;
}

Point findFermat(Point A, Point B, Point C) {
	if (getAngle(B - A, C - A) >= 2 * PI / 3) return A;
	if (getAngle(A - B, C - B) >= 2 * PI / 3) return B;
	if (getAngle(A - C, B - C) >= 2 * PI / 3) return C;
	Point BB = A + (C - A).rot(PI / 3);
	if (!onDiffSides(A, C, B, BB)) BB = A + (C - A).rot(-PI / 3);
	Point AA = B + (C - B).rot(PI / 3);
	if (!onDiffSides(B, C, A, AA)) AA = B + (C - B).rot(-PI / 3);
	Point I;
	assert(intersectLines(A, AA - A, B, BB - B, I));
	return I;
}

double F(Point A, Point B, Point C) {
	Point D = findFermat(A, B, C);
	return (A - D).len() + (B - D).len() + (C - D).len();
}

Point A, B, C;

double f(double x, double y) {
	Point P = Point(x, y);
	double res = 0;
	res = max(res, F(A, B, P));
	res = max(res, F(A, C, P));
	res = max(res, F(B, C, P));
	return res;
}
double g(double x) {
	double l = -INF, r = INF;
	for (int it = 0; it < IT; it++) {
		double lm = l + (r - l) / 3;
		double rm = r - (r - l) / 3;
		if (f(x, lm) < f(x, rm))
			r = rm;
		else
			l = lm;
	}
	return f(x, (l + r) / 2);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	A.scan();
	B.scan();
	C.scan();

	double l = -INF, r = INF;
	for (int it = 0; it < IT; it++) {
		double lm = l + (r - l) / 3;
		double rm = r - (r - l) / 3;
		if (g(lm) < g(rm))
			r = rm;
		else
			l = lm;
	}
	printf("%.13lf\n", g((l + r) / 2));

	return 0;
}