#pragma comment (linker, "/STACK:128000000")
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

/*int pr[] = { 97, 2011 };
int mods[] = { 1000000007, 1000000009 };

const int C = 100500;

int powers[2][C];*/

int MOD = 1000000007;

int c[5010][5010];

//int catalan[200500];

int binpow(int q, int w, int mod) {
	if (!w)
		return 1;
	if (w & 1)
		return q * binpow(q, w - 1, mod) % mod;
	return binpow(q * q % mod, w / 2, mod);
}

void precalc() {

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

	for (int i = 0; i < 5010; ++i) {
		c[i][i] = c[i][0] = 1;
		for (int j = 1; j < i; ++j) {
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
		}
	}
}



int gcd(int q, int w) {
	while (w) {
		q %= w;
		swap(q, w);
	}
	return q;
}

#define int li

//int mod = 1000000007;

vector<int> dsu;

int findSet(int v) {
	if (dsu[v] == v)
		return v;
	return dsu[v] = findSet(dsu[v]);
}

void merge(int q, int w) {
	q = findSet(q);
	w = findSet(w);
	if (rand() & 1)
		dsu[q] = w;
	else
		dsu[w] = q;
}

vector<vector<int>> G;

vector<int> used;

bool dfs(int v, int ch) {
	if (used[v] != -1) {
		return used[v] == ch;
	}
	used[v] = ch;
	bool res = true;
	for (int to : G[v]) {
		res &= dfs(to, ch ^ 1);
	}
	return res;
}

void solve() {
	int n, m;
	cin >> n >> m;
	dsu.resize(n);
	G.resize(n);
	for (int i = 0; i < n; ++i) {
		dsu[i] = i;
	}

	vector<vector<pair<int, int>>> g(n);
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		--a; --b;
		g[a].push_back(mp(b, c));
		g[b].push_back(mp(a, c));
	}

	for (int i = 0; i < n; ++i) {
		for (auto item : g[i]) {
			int to = item.first;
			if (item.second == 1) {
				merge(i, to);
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (auto item : g[i]) {
			int to = item.first;
			if (item.second == 0) {
				if (findSet(i) == findSet(to)) {
					cout << "0\n";
					return;
				}
				G[findSet(i)].push_back(findSet(to));
				G[findSet(to)].push_back(findSet(i));
			}
		}
	}

	used.assign(n, -1);

	int cnt = 0;

	for (int i = 0; i < n; ++i) {
		if (i != findSet(i)) {
			continue;
		}
		if (used[i] != -1) {
			continue;
		}
		if (!dfs(i, 0)) {
			cout << "0\n";
			return;
		}
		++cnt;
	}

	int res = 1;
	for (int i = 0; i < cnt - 1; ++i) {
		res = res * 2 % MOD;
	}

	cout << res << "\n";


}