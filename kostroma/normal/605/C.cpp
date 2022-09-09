#pragma comment (linker, "/STACK:1280000000")
#define _CRT_SECURE_NO_WARNINGS
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
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <stack>
#include <queue>
#include <fstream>
#include <sstream>
#include <complex>
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

int testNumber = 1;

bool todo = true;

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
	start = clock();
	int t = 1;
	cout.sync_with_stdio(0);
	cin.tie(0);
	precalc();
	cout.precision(10);
	cout << fixed;
	//cin >> t;
	int testNum = 1;
	while (t--) {
		//cout << "Case #" << testNum++ << ": ";
		solve();
		++testNumber;
		//++timer;
	}

#ifdef room111
	cerr << "\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

	return 0;
}

//BE CAREFUL: IS INT REALLY INT?

//#define int li

/*int pr[] = { 97, 2011 };
int mods[] = { 1000000007, 1000000009 };

const int C = 300500;
int powers[2][C];*/

//int MOD = 1000000007;

//int c[5010][5010];

//int catalan[200500];

//ld doubleC[100][100];

template<typename T>
T binpow(T q, T w, T mod) {
	if (!w)
		return 1 % mod;
	if (w & 1)
		return q * 1LL * binpow(q, w - 1, mod) % mod;
	return binpow(q * 1LL * q % mod, w / 2, mod);
}

/*int curMod = 1000000009;

int fact[100500], revfact[100500];

int getC(int n, int k) {
int res = fact[n] * revfact[n - k] % curMod * revfact[k] % curMod;
return res;
}*/

//const int C = 500500;

//int least_prime[C];

void precalc() {

	/*for (int i = 2; i < C; ++i) {
		if (!least_prime[i]) {
			least_prime[i] = i;
			for (li j = i * 1LL * i; j < C; j += i) {
				least_prime[j] = i;
			}
		}
	}*/

	/*fact[0] = revfact[0] = 1;
	for (int i = 1; i < 100500; ++i) {
	fact[i] = fact[i - 1] * i % curMod;
	revfact[i] = binpow(fact[i], curMod - 2, curMod);
	}*/

	/*for (int w = 0; w < 2; ++w) {
	powers[w][0] = 1;
	for (int j = 1; j < C; ++j) {
	powers[w][j] = (powers[w][j - 1] * 1LL * pr[w]) % mods[w];
	}
	}*/

	/*catalan[0] = 1;
	for (int n = 0; n < 200500 - 1; ++n) {
	catalan[n + 1] = catalan[n] * 2 * (2 * n + 1) % MOD * binpow(n + 2, MOD - 2, MOD) % MOD;
	}*/

	/*for (int i = 0; i < 5010; ++i) {
	c[i][i] = c[i][0] = 1;
	for (int j = 1; j < i; ++j) {
	c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
	}
	}*/

	/*for (int i = 0; i < 100; ++i) {
	doubleC[i][i] = doubleC[i][0] = 1.0;
	for (int j = 1; j < i; ++j) {
	doubleC[i][j] = doubleC[i - 1][j - 1] + doubleC[i - 1][j];
	}
	}*/

}

template<typename T>
T gcd(T q, T w) {
	while (w) {
		q %= w;
		swap(q, w);
	}
	return q;
}
template<typename T>
T lcm(T q, T w) {
	return q / gcd(q, w) * w;
}


#define int li

//const int mod = 1000000007;

struct Point {
	int x, y;
	Point() {}
	Point(int x, int y) :x(x), y(y) {}
	void scan() {
		cin >> x >> y;
	}
	Point operator - (const Point& ot) const {
		return Point(x - ot.x, y - ot.y);
	}
	int operator * (const Point& ot) const {
		return x * ot.y - y * ot.x;
	}
	bool operator < (const Point& ot) const {
		return mp(x, y) < mp(ot.x, ot.y);
	}
};

int signum(int cur) {
	if (cur > 0) {
		return 1;
	}
	if (cur < 0) {
		return -1;
	}
	return 0;
}

void solve() {
	int n, p, q;
	cin >> n >> p >> q;
	vector<Point> points(n);
	for (int i = 0; i < n; ++i) {
		points[i].scan();
	}
	sort(all(points));

	vector<Point> up, down;
	for (int i = 0; i < n; ++i) {
		while (up.size() > 1 && (up[up.size() - 2] - up.back()) * (points[i] - up.back()) <= 0) {
			up.pop_back();
		}
		up.push_back(points[i]);

		while (down.size() > 1 && (down[down.size() - 2] - down.back()) * (points[i] - down.back()) >= 0) {
			down.pop_back();
		}
		down.push_back(points[i]);
	}

	points = up;
	for (int i = (int)down.size() - 2; i > 0; --i) {
		points.push_back(down[i]);
	}

	n = points.size();

	double res = 1e9;
	for (Point cur : points) {
		double cur_res = max(p / 1. / cur.x, q / 1. / cur.y);
		res = min(res, cur_res);
	}

	for (int i = 0; i < n; ++i) {
		int nex = (i + 1) % n;
		Point diff = points[nex] - points[i];

		if (signum(points[i] * Point(p, q)) * signum(points[nex] * Point(p, q)) >= 0) {
			continue;
		}

		int znam = Point(p, q) * diff;
		if (znam != 0) {
			double t = (points[i] * points[nex]) / 1.0 / znam;
			res = min(res, 1. / t);
		}
	}

	cout << res << "\n";

}