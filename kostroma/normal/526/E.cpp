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

#define int li

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for (int w = 0; w < q; ++w) {
		int b;
		cin >> b;

		vector<int> nex(n);
		int curSum = 0;
		int j = 0;
		for (int i = 0; i < n; ++i) {
			if (i > 0) {
				curSum -= a[i - 1];
			}
			for (; j < n; ++j) {
				if (curSum + a[j] > b) {
					break;
				}
				curSum += a[j];
			}
			nex[i] = j;
		}

		vector<pair<int, int>> ans(n);

		int sum = 0;
		for (int i = n - 1; i >= 0; --i) {
			sum += a[i];
			if (nex[i] == n) {
				ans[i] = mp(1, sum);
				continue;
			}
			pair<int, int> next = ans[nex[i]];
			ans[i] = mp(next.first + 1, next.second);
		}

		int res = ans[0].first;
		sum = 0;
		for (int i = 0; i < n; ++i) {

			if (sum + ans[i].second <= b) {
				res = min(res, ans[i].first);
			}

			sum += a[i];
			if (sum > b) {
				break;
			}
		}

		cout << res << "\n";

	}

}