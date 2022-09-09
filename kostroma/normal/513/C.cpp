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

int gcd(int q, int w) {
	while (w) {
		q %= w;
		swap(q, w);
	}
	return q;
}

//int mod = 1000000007;

//#define int li

int n;
int l[10], r[10];

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> l[i] >> r[i];
	}
	
	ld ans = 0;

	for (int win = 0; win < n; ++win) {
		for (int sec = 0; sec < n; ++sec) {
			if (sec == win) {
				continue;
			}
			vector<int> losers;
			for (int i = 0; i < n; ++i) {
				if (i != win && i != sec) {
					losers.push_back(i);
				}
			}

			for (int val = l[sec]; val <= r[sec]; ++val) {

				ld pr = 1.0 / (r[sec] - l[sec] + 1);

				for (int i : losers) {
					int cur = min(r[i], val) - l[i] + 1;

					if (cur <= 0) {
						pr = 0;
						break;
					}

					ld prob = cur / 1.0 / (r[i] - l[i] + 1);

					if (i > sec && val <= r[i]) {
						prob -= 1.0 / (r[i] - l[i] + 1);
					}

					pr *= prob;
				}

				int cur = r[win] - max(l[win], val) + 1;

				if (cur <= 0) {
					pr = 0;
				}
				else {
					ld prob = cur / 1.0 / (r[win] - l[win] + 1);
					//cout << cur <<  ' ' << val << ' ' << prob << "\n";
					if (win < sec && val >= l[win]) {
						prob -= 1.0 / (r[win] - l[win] + 1);
					}

					//cout << val << ' ' << prob << "\n";

					pr *= prob;
				}

				ans += pr * val;
			}


		}
	}

	cout << ans << "\n";

}