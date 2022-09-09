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

//ld eps = 1e-9;

int n;

struct edge {
	int a, b;
	int c;
	edge(int a, int b, int c) :a(a), b(b), c(c) {}
};

vector<edge> edges;

vector<vector<int>> g;

int another(int v, int id) {
	if (edges[id].a == v)
		return edges[id].b;
	return edges[id].a;
}

vector<int> cnt;

vector<int> level;

void dfs1(int v, int p = -1, int lev = 0) {
	cnt[v] = 1;
	level[v] = lev;
	for (int id : g[v]) {
		int to = another(v, id);
		if (to == p)
			continue;
		dfs1(to, v, lev + edges[id].c);
		cnt[v] += cnt[to];
	}
}

vector<int> sums;

void dfs2(int v, int p = -1) {
	for (int id : g[v]) {
		int to = another(v, id);
		if (to == p)
			continue;
		sums[to] = sums[v] + (n - 2 * cnt[to]) * edges[id].c;
		//cout << v << ' ' << to << ' ' << cnt[to] << ' ' << sums[v] << ' ' << sums[to] << "\n";
		dfs2(to, v);
	}
}

void solve() {
	cin >> n;
	g.resize(n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		--a;
		--b;
		g[a].push_back(edges.size());
		g[b].push_back(edges.size());
		edges.push_back(edge(a, b, c));
	}

	level.resize(n);
	cnt.resize(n);
	dfs1(0);

	sums.resize(n);
	for (int i = 0; i < n; ++i) {
		sums[0] += level[i];
	}

	dfs2(0);

	int bigsum = 0;
	for (int i = 0; i < n; ++i) {
		bigsum += sums[i];
		//cout << i + 1 << ' ' << sums[i] << endl;
	}

	int Q;
	cin >> Q;


	for (int it = 0; it < Q; ++it) {
		int id, c;
		cin >> id >> c;
		--id;
		int diff = edges[id].c - c;
		edges[id].c = c;
		int lowest = edges[id].a;
		if (level[lowest] < level[edges[id].b]) {
			lowest = edges[id].b;
		}

		bigsum -= 2 * cnt[lowest] * (n - cnt[lowest]) * diff;

		ld res = 3 * bigsum / 1.0 / n / (n - 1);

		//cerr << bigsum << endl;

		cout << res << "\n";
	}
}