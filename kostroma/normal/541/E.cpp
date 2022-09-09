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
vector<int> color;

bool bip = true;

vector<vector<int>> comps;

void dfs(int v, int col) {
	//cout << v + 1 << ' ' << col << "\n";
	if (color[v] != -1) {
		if (color[v] != col) {
			bip = false;
		}
		return;
	}
	color[v] = col;
	comps.back().push_back(v);
	for (int to : g[v]) {
		dfs(to, col ^ 1);
	}
}

void solve() {
	int n, m;
	cin >> n >> m;
	g.resize(n);
	color.assign(n, -1);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	for (int i = 0; i < n; ++i) {
		if (color[i] == -1) {
			comps.push_back(vector<int>());
			dfs(i, 0);
		}
	}

	if (!bip) {
		cout << "-1\n";
		return;
	}

	int sum = 0;

	for (auto& vs : comps) {

		sort(all(vs));

		vector<vector<int>> curG(vs.size());
		for (int i = 0; i < vs.size(); ++i) {
			int start = vs[i];
			for (int to : g[start]) {
				int pos = lower_bound(all(vs), to) - vs.begin();
				curG[i].push_back(pos);
			}
		}

		int maxDepth = 0;
		vector<int> d(vs.size());
		vector<int> q;
		for (int start = 0; start < vs.size(); ++start) {
			d.assign(vs.size(), -1);
			q.clear();
			d[start] = 0;
			q.push_back(start);
			for (int i = 0; i < q.size(); ++i) {
				int v = q[i];
				for (int to : curG[v]) {
					if (d[to] == -1) {
						d[to] = d[v] + 1;
						q.push_back(to);
					}
				}
			}

			for (int i = 0; i < vs.size(); ++i) {
				maxDepth = max(maxDepth, d[i]);
			}

		}

		sum += maxDepth;
	}


	cout << sum << "\n";
}