#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<vector<int>> g, jump;
vector<int> sz, par, dep;
vector<char> used;

void dfs(int v, int pr) {
	jump[0][v] = pr;
	for (auto u : g[v]) {
		if (u == pr) continue;
		dep[u] = dep[v] + 1;
		dfs(u, v);
	}
}

void calc_sz(int v, int pr) {
	sz[v] = 1;
	for (auto u : g[v]) {
		if (u == pr || used[u]) continue;
		calc_sz(u, v);
		sz[v] += sz[u];
	}
}

int get_centroid(int v, int pr, int sz_all) {
	for (auto u : g[v]) {
		if (u == pr || used[u]) continue;
		if (sz[u] * 2 > sz_all) return get_centroid(u, v, sz_all);
	}
	return v;
}

void go(int v, int pr) {
	calc_sz(v, v);
	v = get_centroid(v, v, sz[v]);
	par[v] = pr;
	used[v] = 1;
	for (auto u : g[v]) {
		if (!used[u]) go(u, v);
	}
}

inline int la(int v, int del) {
	for (int level = 0; level < jump.size(); level++) {
		if ((del >> level) % 2) v = jump[level][v];
	}
	return v;
}

inline int lca(int v, int u) {
	if (dep[v] < dep[u]) swap(u, v);
	v = la(v, dep[v] - dep[u]);
	if (u == v) return v;
	for (int level = jump.size() - 1; level >= 0; level--) {
		if (jump[level][v] != jump[level][u]) {
			v = jump[level][v];
			u = jump[level][u];
		}
	}
	return jump[0][v];
}

inline int len(int v, int u) {
	return dep[v] + dep[u] - 2 * dep[lca(u, v)];
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;
	g.resize(n);
	for (int i = 1; i < n; i++) {
		int v, u;
		cin >> v >> u;
		v--, u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}

	dep.resize(n);
	jump.resize(32 - __builtin_clz(n), vector<int>(n));
	dfs(0, 0);
	for (int level = 1; level < jump.size(); level++) {
		for (int i = 0; i < n; i++) jump[level][i] = jump[level - 1][jump[level - 1][i]];
	}

	sz.resize(n);
	used.resize(n);
	par.resize(n, -1);
	go(0, -1);
	vector<int> nearest = dep;

	while (m--) {
		int t, v;
		cin >> t >> v;
		v--;
		if (t == 1) {
			for (int i = v; i != -1; i = par[i]) nearest[i] = min(nearest[i], len(v, i));
		} else {
			int ans = dep[v];
			for (int i = v; i != -1; i = par[i]) ans = min(ans, nearest[i] + len(v, i));
			cout << ans << '\n';
		}
	}
}