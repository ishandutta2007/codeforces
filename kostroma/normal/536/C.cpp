#pragma comment (linker, "/STACK:128000000")
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
#include <bitset>
//#include <unordered_map>
//#include <unordered_set>
#include <ctime>
#include <stack>
#include <queue>
#include <fstream>
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
		//cout << "Case #" << testNum++ << ":\n";
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

int gcd(int q, int w) {
	while (w) {
		q %= w;
		swap(q, w);
	}
	return q;
}

//#define int li

//int mod = 1000000007;

ld eps = 1e-18;

ld PI = acos((ld)-1.0);

struct Point {
	ld x, y;
	vector<int> id;
	Point() { x = y = 0; }
	Point(ld x, ld y) :x(x), y(y) {}
	void scan() { cin >> x >> y; }
	bool operator < (const Point& other) const { return x + eps < other.x || fabs(x - other.x) < eps && y + eps < other.y; }
	Point operator - (const Point& other) const { return Point(x - other.x, y - other.y); }
	Point operator + (const Point& other) const { return Point(x + other.x, y + other.y); }
	Point operator * (ld c) const { return Point(x * c, y * c); }
	void print() const { cout << x << ' ' << y << ' ' << "\n"; }
	ld operator * (const Point& other) const { return x * other.y - y * other.x; }
	ld operator % (const Point& other) const { return x * other.x + y * other.y; }
	ld dist() const { return sqrt(x * x + y * y); }
	ld sqrDist() const { return x * x + y * y; }
	Point operator / (ld c) const { return Point(x / c, y / c); }
	bool operator == (const Point& other) const { return fabs(x - other.x) < eps && fabs(y - other.y) < eps; }
	Point rotate(ld alpha) const { return Point(x * cos(alpha) - y * sin(alpha), x * sin(alpha) + y * cos(alpha)); }
	Point normalized() const { return *this / dist(); }
};

void solve() {
	int n;
	cin >> n;
	vector<Point> points;
	map<pair<int, int>, int> ids;
	for (int i = 0; i < n; ++i) {
		int r, c;
		cin >> r >> c;
		int id = points.size();
		if (ids.count(mp(r, c))) {
			id = ids[mp(r, c)];
		}
		if (id == points.size()) {
			points.push_back(Point((ld)1.0 / r, (ld)1.0 / c));
			ids[mp(r, c)] = id;
		}
		points[id].id.push_back(i);
	}

	sort(all(points));

	vector<Point> up, down;

	for (int i = 0; i < points.size(); ++i) {
		while (up.size() > 1 && (up[up.size() - 2] - up.back()) * (points[i] - up.back()) < -eps) {
			up.pop_back();
		}
		up.push_back(points[i]);

		while (down.size() > 1 && (down[down.size() - 2] - down.back()) * (points[i] - down.back()) > eps) {
			down.pop_back();
		}
		down.push_back(points[i]);
	}

	vector<int> res(n, 0);

	for (int i = 0; i < down.size(); ++i) {
		int prev = i - 1;
		if (i > 0 && down[i].y + eps > down[i - 1].y) {
			break;
		}
		for (int to : down[i].id) {
			res[to] = 1;
		}
	}

	for (int i = 0; i < n; ++i) {
		if (res[i]) {
			cout << i + 1 << ' ';
		}
	}
	cout << "\n";

}