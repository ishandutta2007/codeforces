#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <cmath>
#include <ctime>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using vi = vector<int>;
void solve();


int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	auto start = clock();
#endif
	cout.sync_with_stdio(0);
	cin.tie(0);
	cout.precision(10);
	cout << fixed;
	int t;
	//cin >> t;
	t = 1;
	while (t--) {
		solve();
	}
#ifdef LOCAL
	cerr << endl << endl << (clock() - start) / double(CLOCKS_PER_SEC) << endl;
#endif
	return 0;
}

//#define int li

struct Edge {
	int from, to;
	int w;
	int get(int v) {
		if (v == from) {
			return to;
		}
		else {
			return from;
		}
	}
};

vector<Edge> edges;
vector<vector<int>> g;

int TIMER = 1;
vector<int> tin, fup;
vector<char> used;
vector<int> bridge;
int erased_edge = -1;
vector<int> parent;

int BRIDGE = 1;

void dfs(int v, int par_edge) {
	used[v] = true;
	tin[v] = TIMER++;
	fup[v] = tin[v];
	parent[v] = par_edge;
	for (int e : g[v]) {
		if (e == par_edge) {
			continue;
		}
		if (e == erased_edge) {
			continue;
		}
		int to = edges[e].get(v);
		if (used[to]) {
			fup[v] = min(fup[v], tin[to]);
		}
		else {
			dfs(to, e);
			fup[v] = min(fup[v], fup[to]);
			if (fup[to] > tin[v]) {
				bridge[e] = BRIDGE;
			}
		}
	}
}

void my_clear(int n, int m) {
	tin.resize(n);
	fup.resize(n);
	used.assign(n, false);
}

void solve() {
	int n, m;
	cin >> n >> m;
	int s, t;
	cin >> s >> t;
	--s; --t;
	edges.resize(m);
	g.resize(n);
	for (int i = 0; i < m; ++i) {
		cin >> edges[i].from >> edges[i].to >> edges[i].w;
		--edges[i].from;
		--edges[i].to;
		g[edges[i].from].push_back(i);
		g[edges[i].to].push_back(i);
	}

	bridge.assign(m, 0);
	my_clear(n, m);
	parent.resize(n);
	dfs(s, -1);
	if (!used[t]) {
		cout << "0\n0\n";
		return;
	}
	int ans = 2e9 + 10;
	vector<int> best_res;
	vector<int> to_er;
	for (int r = 0; r < n; ++r) {
		to_er.push_back(parent[r]);
	}
	
	for (int x : to_er) {
		erased_edge = x;
		if (erased_edge == -1) {
			continue;
		}
		++BRIDGE;
		my_clear(n, m);
		dfs(s, -1);
		if (!used[t]) {
			if (ans > edges[erased_edge].w) {
				ans = edges[erased_edge].w;
				best_res = { erased_edge };
			}
			continue;
		}

		int last = t;
		while (last != s) {
			int e = parent[last];
			if (bridge[e] == BRIDGE) {
				if (ans > edges[erased_edge].w + edges[e].w) {
					ans = edges[erased_edge].w + edges[e].w;
					best_res = { erased_edge, e };
				}
			}
			last = edges[e].get(last);
		}
	}

	if (ans > 2e9 + 5) {
		cout << "-1\n";
		return;
	}
	cout << ans << "\n" << best_res.size() << "\n";
	for (int v : best_res) {
		cout << v + 1 << ' ';
	}
	cout << "\n";


}