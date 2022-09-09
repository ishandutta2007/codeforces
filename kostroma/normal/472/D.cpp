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

int gcd (int q, int w) {
	while(w) {
		q %= w;
		swap(q, w);
	}
	return q;
}

int binpow (int q, int w, int mod) {
	if (!w)
		return 1 % mod;
	if (w & 1) {
		return (q * binpow(q, w - 1, mod)) % mod;
	}
	return binpow((q * q) % mod, w / 2, mod);
}

int n;

int matrix[2010][2010];

int dsu[2010];

vector<pair<int, pair<int, int>> > edges;

int findSet (int v) {
	if (dsu[v] == v)
		return v;
	return dsu[v] = findSet(dsu[v]);
}

void merge (int q, int w) {
	q = findSet(q);
	w = findSet(w);
	if (rand() & 1)
		dsu[q] = w;
	else
		dsu[w] = q;
}

int dist[2010];

vector<vector<int>> g;

void dfs(int v, int p = -1) {
	for (int to : g[v]) {
		if (to == p)
			continue;
		dist[to] = dist[v] + matrix[v][to];
		dfs(to, v);
	}
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		dsu[i] = i;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			int cur;
			cin >> cur;
			matrix[i][j] = cur;
			if (cur == 0 && i != j) {
				cout << "NO\n";
				return;
			}
			if (i == j && cur != 0) {
				cout << "NO\n";
				return;
			}
			if (i < j)
				edges.push_back(mp(cur, mp(i, j)));
		}

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (matrix[i][j] != matrix[j][i]) {
				cout << "NO\n";
				return;
			}

	g.resize(n);

	sort(all(edges));
	for (int i = 0; i < edges.size(); ++i) {
		int a = edges[i].second.first, b = edges[i].second.second;
		if (findSet(a) != findSet(b)) {
			merge(a, b);
			g[a].push_back(b);
			g[b].push_back(a);
		}
	}

	for (int v = 0; v < n; ++v) {
		dist[v] = 0;
		dfs(v);
		for (int u = 0; u < n; ++u)
			if (dist[u] != matrix[v][u]) {
				cout << "NO\n";
				return;
			}
	}
	cout << "YES\n";
}