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

//#define int li

vector<vector<int>> g;

vector<vector<int>> dp;
vector<int> cnt;

void dfs(int v, int turn) {
	if (g[v].empty()) {
		cnt[v] = 1;
		dp[v][0] = dp[v][1] = 0;
		return;
	}

	for (int to : g[v]) {
		dfs(to, turn ^ 1);
		cnt[v] += cnt[to];
	}

	if (!turn) {
		int best = 0;
		for (int to : g[v]) {
			best = max(best, cnt[v] - cnt[to] + dp[to][0]);
		}
		dp[v][0] = best;

		for (int to : g[v]) {
			dp[v][1] += dp[to][1] + 1;
		}
		--dp[v][1];
	}
	else {
		int best = cnt[v] - 1;
		for (int to : g[v]) {
			best = min(best, dp[to][1]);
		}
		dp[v][1] = best;

		for (int to : g[v]) {
			dp[v][0] += dp[to][0];
		}
	}
}

void solve() {
	
	int n;
	cin >> n;
	g.resize(n);
	dp.assign(n, vector<int>(2));
	cnt.assign(n, 0);

	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		g[u].push_back(v);
	}

	dfs(0, 0);

	cout << dp[0][0] + 1 << ' ' << dp[0][1] + 1 << "\n";

}