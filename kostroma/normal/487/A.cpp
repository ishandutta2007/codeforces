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

#define int li

void precalc() {

}

int h[2], a[2], d[2];

int H, A, D;

bool good(int mya, int myd, int myhp) {
	if (mya <= d[1])
		return false;

	int death = h[1] / (mya - d[1]);
	if (death * (mya - d[1]) < h[1])
		++death;

	return death * (a[1] - myd) < myhp;

}

void solve() {
	for (int i = 0; i < 2; ++i)
		cin >> h[i] >> a[i] >> d[i];

	cin >> H >> A >> D;

	int ans = 2e9;

	for (int mya = a[0]; mya <= max(a[0], d[1] + h[1]); mya++) {
		for (int myd = d[0]; myd <= max(a[1], d[0]); ++myd) {
			int l = h[0] - 1, r = 100000;
			while (l + 1 < r) {
				int m = (l + r) / 2;
				if (good(mya, myd, m))
					r = m;
				else
					l = m;
			}

			if (good(mya, myd, r)) {
				ans = min(ans, (mya - a[0]) * A + (myd - d[0]) * D + (r - h[0]) * H);
			}

		}
	}

	cout << ans << "\n";
			

}