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

int mod;
int n, m, b;

void solve() {
	cin >> n >> m >> b >> mod;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vector<vector<vector<int>>> dp(2, vector<vector<int>>(b + 1, vector<int>(n + 1, 0)));
	dp[0][0][0] = 1;
	int w = 0;
	for (int pos = 0; pos < m; ++pos) {
		dp[w ^ 1].assign(b + 1, vector<int>(n + 1, 0));
		for (int errors = 0; errors <= b; ++errors) {
			for (int nex = 1; nex < n; ++nex) {
				dp[w][errors][nex] += dp[w][errors][nex - 1];
				if (dp[w][errors][nex] >= mod)
					dp[w][errors][nex] -= mod;
			}

			for (int nex = 0; nex < n; ++nex) {
				int nexErrors = errors + a[nex];
				if (nexErrors <= b) {
					dp[w ^ 1][nexErrors][nex] += dp[w][errors][nex];
					if (dp[w ^ 1][nexErrors][nex] >= mod)
						dp[w ^ 1][nexErrors][nex] -= mod;
				}
			}

		}

		w ^= 1;
	}

	int ans = 0;
	for (int errs = 0; errs <= b; ++errs) {
		for (int nex = 0; nex < n; ++nex) {
			ans = (ans + dp[w][errs][nex]) % mod;
		}
	}

	cout << ans << "\n";

}