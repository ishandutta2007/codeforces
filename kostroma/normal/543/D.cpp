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

#define int li

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

int n;

vector<vector<int>> g;

int mod = 1000000007;

vector<int> dpOne;

void dfs(int v) {
	dpOne[v] = 1;
	for (int to : g[v]) {
		dfs(to);
		dpOne[v] = dpOne[v] * 1LL * (1 + dpOne[to]) % mod;
	}
	if (dpOne[v] < 0)
		dpOne[v] += mod;
}

vector<int> ans;

void dfs1(int v, int ways, int sumOne) {
	ans[v] = ways;

	vector<int> prefix(g[v].size() + 1), suffix(g[v].size() + 1);
	prefix[0] = 1;
	suffix.back() = 1;
	for (int i = 0; i < g[v].size(); ++i) {
		int to = g[v][i];
		prefix[i + 1] = prefix[i] * (dpOne[to] + 1) % mod;
	}
	for (int i = (int)g[v].size() - 1; i >= 0; --i) {
		int to = g[v][i];
		suffix[i] = suffix[i + 1] * (dpOne[to] + 1) % mod;
	}

	for (int i = 0; i < g[v].size(); ++i) {
		int to = g[v][i];
		int curWays = prefix[i] * suffix[i + 1] % mod;
		int newSumOne = (sumOne * curWays + (curWays)* (v != 0)) % mod;
		dfs1(to, ((ways - newSumOne + dpOne[to]) % mod + mod) % mod, newSumOne);
	}
}

void solve() {

	cin >> n;
	g.resize(n);
	for (int i = 1; i < n; ++i) {
		int p;
		cin >> p;
		--p;
		g[p].push_back(i);
	}

	dpOne.assign(n, 0);
	dfs(0);

	ans.assign(n, 0);
	dfs1(0, dpOne[0], 1);

	for (int i = 0; i < n; ++i) {
		cout << ((ans[i] % mod) + mod) % mod << ' ';
	}

}