#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<vector<int>> g, each;
vector<char> used;
vector<int> dep, par;

void dfs(int v, int pr) {
	used[v] = 1;
	par[v] = pr;
	each[dep[v]].push_back(v);
	for (auto u : g[v]) {
		if (used[u]) continue;
		dep[u] = dep[v] + 1;
		dfs(u, v);
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		g.clear();
		each.clear();
		used.clear();
		dep.clear();
		par.clear();

		int n, m;
		cin >> n >> m;
		g.resize(n);
		for (int i = 0; i < m; i++) {
			int v, u;
			cin >> v >> u;
			v--, u--;
			g[v].push_back(u);
			g[u].push_back(v);
		}
		par.resize(n);
		used.resize(n);
		dep.resize(n);
		each.resize(n);
		dfs(0, -1);

		int need = (n + 1) / 2;
		vector<int> way;
		for (int i = 0; i < n; i++) {
			if (dep[i] < need - 1) continue;
			for (int j = i; j != -1; j = par[j]) way.push_back(j);
			break;
		}
		if (way.size() >= need) {
			cout << "PATH\n" << way.size() << '\n';
			for (auto x : way) cout << x + 1 << ' ';
			cout << '\n';
			continue;
		}
		vector<pair<int, int>> res;
		for (auto &els : each) {
			for (int i = 1; i < els.size(); i += 2) res.emplace_back(els[i - 1], els[i]);
		}
		cout << "PAIRING\n" << res.size() << '\n';
		for (auto [x, y] : res) cout << x + 1 << ' ' << y + 1 << '\n';
	}
}