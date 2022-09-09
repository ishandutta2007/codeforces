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

const int C = 100500;
int powers[2][C];*/

//int MOD = 1000000007;

//int c[5010][5010];

//int catalan[200500];

//ld doubleC[100][100];

int binpow(int q, int w, int mod) {
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


//#define int li

//const int mod = 1000000007;


void solve() {
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> points_x(n), points_y(n);
	for (int i = 0; i < n; ++i) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int x = (x1 + x2), y = (y1 + y2);
		points_x[i].first = x;
		points_y[i].first = y;
		points_x[i].second = points_y[i].second = i;
	}

	sort(all(points_x));
	sort(all(points_y));

	if (points_x.size() > 2 * (k + 1)) {
		points_x.erase(points_x.begin() + k + 1, points_x.end() - k - 1);
	}
	if (points_y.size() > 2 * (k + 1)) {
		points_y.erase(points_y.begin() + k + 1, points_y.end() - k - 1);
	}

	n = points_x.size();

	li ans = 2e18;

	set<int> used;

	for (int lef_x = 0; lef_x < n; ++lef_x) {
		for (int rig_x = lef_x; rig_x < n; ++rig_x) {
			for (int lef_y = 0; lef_y < n; ++lef_y) {
				for (int rig_y = lef_y; rig_y < n; ++rig_y) {

					used.clear();

					for (int i = 0; i < lef_x; ++i) {
						used.insert(points_x[i].second);
					}
					for (int i = 0; i < lef_y; ++i) {
						used.insert(points_y[i].second);
					}
					for (int i = rig_x + 1; i < n; ++i) {
						used.insert(points_x[i].second);
					}
					for (int i = rig_y + 1; i < n; ++i) {
						used.insert(points_y[i].second);
					}

					if (used.size() > k) {
						continue;
					}

					int diffX = points_x[rig_x].first - points_x[lef_x].first;
					int diffY = points_y[rig_y].first - points_y[lef_y].first;
					if (diffX == 0) {
						++diffX;
					}
					if (diffY == 0) {
						++diffY;
					}
					if (diffX & 1) {
						++diffX;
					}
					if (diffY & 1) {
						++diffY;
					}

					ans = min(ans, (diffX / 2) * 1LL * (diffY / 2));

				}
			}

		}
	}

	cout << ans << "\n";

}