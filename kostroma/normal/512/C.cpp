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

//ld eps = 1e-9;

int n;

int a[210];

bool isPrime(int k) {
	for (int p = 2; p * p <= k; ++p) {
		if (k % p == 0)
			return false;
	}
	return true;
}

const int INF = 2e9;

struct edge {
	int from, to, cap, flow;
};

vector<edge> edges;
vector<int> g[300];
int q[300];
int d[300];
int ptr[300];

bool bfs (int s, int t) {
	memset(d, -1, sizeof d);
	int qh = 0, qt = 0;
	q[qt++] = s;
	d[s] = 0;
	while (qh != qt) {
		int cur = q[qh++];
		for (int i = 0; i < g[cur].size(); ++i) {
			edge& e = edges[g[cur][i]];
			if (e.flow != e.cap && d[e.to] == -1) {
				q[qt++] = e.to;
				d[e.to] = d[cur] + 1;
			}
		}
	}
	return d[t] != -1;
}

int dfs(int v, int t, int mx) {
	if (!mx)
		return mx;
	if (v == t)
		return mx;
	for (int& i = ptr[v]; i < g[v].size(); ++i) {
		int id = g[v][i];
		edge& e = edges[id];
		if (d[e.to] == d[v] + 1) {
			if (int pushed = dfs(e.to, t, min(mx, (e.cap - e.flow)))) {
				e.flow += pushed;
				edges[id ^ 1].flow -= pushed;
				return pushed;
			}
		}
	}
	return 0;
}

int dinic(int s, int t) {
	int res = 0;
	while (bfs(s, t)) {
		memset(ptr, 0, sizeof ptr);
		while (int pushed = dfs(s, t, INF)) {
			res += pushed;
		}
	}
	return res;
}

void add_edge(int from, int to, int cap) {
	edge e1 = { from, to, cap, 0 };
	edge e2 = { to, from, 0, 0 };
	g[from].push_back(edges.size());
	edges.push_back(e1);
	g[to].push_back(edges.size());
	edges.push_back(e2);
}


void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (isPrime(a[i] + a[j])) {
				if (a[i] % 2 == 0) {
					add_edge(i, j, 1);
				}
				else {
					add_edge(j, i, 1);
				}
			}
		}
	}

	int s = n, t = n + 1;
	for (int i = 0; i < n; ++i) {
		if (a[i] % 2 == 0) {
			add_edge(s, i, 2);
		}
		else {
			add_edge(i, t, 2);
		}
	}

	int flow = dinic(s, t);

	if (flow != n) {
		cout << "Impossible\n";
		return;
	}

	vector<vector<int>> e(n);

	for (int i = 0; i < edges.size(); i += 2) {
		if (edges[i].flow == 1 && edges[i].cap == 1) {
			e[edges[i].from].push_back(edges[i].to);
			e[edges[i].to].push_back(edges[i].from);
		}
	}

	vector<vector<int>> ans;
	vector<int> have(n, false);
	for (int i = 0; i < n; ++i) {
		if (have[i])
			continue;
		int cur = i;
		vector<int> curAns;
		while (!have[cur]) {
			have[cur] = true;
			curAns.push_back(cur);
			int nex = e[cur][0];
			if (have[nex]) {
				nex = e[cur][1];
			}
			cur = nex;
		}
		ans.push_back(curAns);
	}

	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i].size() << ' ';
		for (int j = 0; j < ans[i].size(); ++j) {
			cout << ans[i][j] + 1 << ' ';
		}
		cout << "\n";
	}

}