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

int n, m;

vector<vector<int>> g;

vector<vector<int>> dist;

void solve() {
	cin >> n >> m;
	g.resize(n);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dist.assign(n, vector<int>(n, -1));
	for (int v = 0; v < n; ++v) {
		queue<int> q;
		q.push(v);
		dist[v][v] = 0;
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (int to : g[cur]) {
				if (dist[v][to] == -1) {
					dist[v][to] = dist[v][cur] + 1;
					q.push(to);
				}
			}
		}
	}

	int s[2], t[2], l[2];
	for (int i = 0; i < 2; ++i) {
		cin >> s[i] >> t[i] >> l[i];
		--s[i];
		--t[i];
	}

	if (dist[s[0]][t[0]] > l[0] || dist[s[1]][t[1]] > l[1]) {
		cout << "-1\n";
		return;
	}

	int res = dist[s[0]][t[0]] + dist[s[1]][t[1]];

	for (int a = 0; a < n; ++a) {
		for (int b = 0; b < n; ++b) {
			int fs = dist[s[0]][a] + dist[b][t[0]];
			int sc = min(dist[s[1]][a] + dist[b][t[1]], dist[s[1]][b] + dist[a][t[1]]);
			if (fs <= l[0] - dist[a][b] && sc <= l[1] - dist[a][b])
				res = min(res, fs + sc + dist[a][b]);
		}
	}

	cout << m - res << "\n";

}