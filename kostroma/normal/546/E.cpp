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

struct Edge {
	int from, to, cap, flow;
};

vector<Edge> edges;

vector<int> g[1000];

void addEdge(int from, int to, int cap) {
	g[from].push_back(edges.size());
	edges.push_back({ from, to, cap, 0 });
	g[to].push_back(edges.size());
	edges.push_back({ to, from, 0, 0 });
}

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

const int INF = 1000000000;

int getFlow(int s, int t, int n) {
	int flow = 0;

	while (true) {
		vector<int> pred(n, -1);
		queue<int> q;
		q.push(s);

		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (int edgeId : g[cur]) {
				if (edges[edgeId].flow == edges[edgeId].cap) {
					continue;
				}
				int to = edges[edgeId].to;
				if (pred[to] == -1) {
					pred[to] = edgeId;
					q.push(to);
				}
			}
		}

		if (pred[t] == -1) {
			break;
		}

		int addFlow = INF;
		int last = t;
		while (last != s) {
			int curEdge = pred[last];
			addFlow = min(addFlow, edges[curEdge].cap - edges[curEdge].flow);
			last = edges[curEdge].from;
		}

		last = t;
		while (last != s) {
			int curEdge = pred[last];
			edges[curEdge].flow += addFlow;
			edges[curEdge ^ 1].flow -= addFlow;
			last = edges[curEdge].from;
		}

		flow += addFlow;
	}
	return flow;
}

void solve() {
	int n, m;
	cin >> n >> m;
	int s = 2 * n, t = 2 * n + 1;
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < n; ++i) {
		int cur;
		cin >> cur;
		addEdge(s, i, cur);
		sum1 += cur;
	}
	for (int i = 0; i < n; ++i) {
		int cur;
		cin >> cur;
		addEdge(i + n, t, cur);
		sum2 += cur;
	}

	for (int i = 0; i < n; ++i) {
		addEdge(i, i + n, 1e9);
	}

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		addEdge(a, b + n, 1e9);
		addEdge(b, a + n, 1e9);
	}

	int res = getFlow(s, t, 2 * n + 2);
	if (sum1 == res && sum2 == res) {
		cout << "YES\n";

		vector<vector<int>> ans(n, vector<int>(n));
		for (int i = 0; i < edges.size(); i += 2) {
			auto item = edges[i];
			if (item.from < n && item.to >= n) {
				ans[item.from][item.to - n] = item.flow;
			}
		}

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cout << ans[i][j] << ' ';
			}
			cout << "\n";
		}

	}
	else {
		cout << "NO\n";
	}

}