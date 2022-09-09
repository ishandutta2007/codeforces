//#pragma comment (linker, "/STACK:128000000")
//#include "testlib.h"
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
//#include <unordered_map>
//#include <unordered_set>
#include <ctime>
#include <stack>
#include <queue>
using namespace std;
//#define FILENAME ""
#define mp make_pair
#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve();
void precalc();
clock_t start;
//int timer = 1;

bool doing = true;

int main() {
#ifdef room111
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen(FILENAME".in", "r", stdin);
	//freopen(FILENAME ".out", "w", stdout);
#endif
	int t = 1;
	cout.sync_with_stdio(0);
	cin.tie(0);
	precalc();
	cout.precision(10);
	cout << fixed;
	//cin >> t;
	start = clock();
	int testNum = 1;
	while (t--) {
		//cout << "Case #" << testNum++ << ": ";
		solve();
		//++timer;
	}

#ifdef room111
	cerr << "\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

	return 0;
}

//BE CAREFUL: IS INT REALLY INT?

//#define int li

void precalc() {

}

int binpow(int q, int w, int mod) {
	if (!w)
		return 1;
	if (w & 1)
		return q * binpow(q, w - 1, mod) % mod;
	return binpow(q * q % mod, w / 2, mod);
}

int mod = 1000000007;

int gcd(int q, int w) {
	while (w) {
		q %= w;
		swap(q, w);
	}
	return q;
}

//ld eps = 1e-9;

struct Point {
	li x, y;
	Point() {}
	Point(li x, li y) :x(x), y(y) {}
	void scan() {
		cin >> x >> y;
	}

	Point operator + (const Point& ot) const {
		return Point(x + ot.x, y + ot.y);
	}

	Point operator - (const Point& ot) const {
		return Point(x - ot.x, y - ot.y);
	}

	li sqrDist() const {
		return x * x + y * y;
	}

	li operator * (const Point& ot) const {
		return x * ot.y - y * ot.x;
	}

	li operator % (const Point& ot) const {
		return x * ot.x + y * ot.y;
	}

	bool operator == (const Point& ot) const {
		return x == ot.x && y == ot.y;
	}

	void print() const {
		cout << x << ' ' << y << "\n";
	}

};

vector<Point> points, segments;

Point a, b;

bool inside(Point q, Point center, li sqrR) {
	return (q - center).sqrDist() < sqrR;
}

bool outside(Point q, Point center, li sqrR) {
	return (q - center).sqrDist() > sqrR;
}

void solve() {

	a.scan();
	int n, m;
	cin >> n;
	points.resize(n);
	for (int i = 0; i < n; ++i) {
		points[i].scan();
	}

	b.scan();
	cin >> m;
	segments.resize(m);
	for (int i = 0; i < m; ++i) {
		segments[i].scan();
	}


	if (a == b) {
		cout << "NO\n";
		return;
	}

	for (int it = 0; it < 2; ++it) {

		for (int i = 0; i < n; ++i) {
			Point center = points[i] + b - a;
			li sqrR = (b - a).sqrDist();

			for (int j = 0; j < m; ++j) {
				Point fs = segments[j], sc = segments[(j + 1) % m];

				if (inside(fs, center, sqrR) && inside(sc, center, sqrR)) {
					continue;
				}

				if (!outside(fs, center, sqrR) || !outside(sc, center, sqrR)) {
					cout << "YES\n";
					return;
				}

				assert(outside(fs, center, sqrR) && outside(sc, center, sqrR));

				if (((fs - center) % (fs - sc)) < 0 || ((sc - center) % (sc - fs)) < 0) {
					continue;
				}

				li area = abs((fs - center) * (sc - center));

				if (area * area <= sqrR * (fs - sc).sqrDist()) {


					cout << "YES\n";
					return;
				}

			}

		}

		swap(n, m);
		segments.swap(points);
		swap(a, b);

	}

	cout << "NO\n";

}