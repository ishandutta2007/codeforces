#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<vector<int>> g;
vector<int> used, top_sort;

void dfs(int v, bool &cycle) {
	used[v] = 1;
	for (auto &u : g[v]) {
		if (!used[u]) {
			dfs(u, cycle);
		} else {
			cycle |= (used[u] == 1);
		}
	}
	used[v] = 2;
	top_sort.push_back(v);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		used.clear();
		g.clear();
		top_sort.clear();
		int n, m;
		cin >> n >> m;
		g.resize(n);
		vector<pair<int, int>> edges;
		for (int i = 0; i < m; i++) {
			int t, v, u;
			cin >> t >> v >> u;
			v--, u--;
			if (t) {
				g[v].push_back(u);
			} else {
				edges.emplace_back(v, u);
			}
		}
		used.resize(n);
		bool cycle = false;
		for (int i = 0; i < n; i++) {
			if (!used[i]) {
				dfs(i, cycle);
			}
		}
		if (cycle) {
			cout << "NO\n";
		} else {
			reverse(top_sort.begin(), top_sort.end());
			cout << "YES\n";
			for (int i = 0; i < n; i++) {
				for (auto j : g[i]) {
					cout << i + 1 << ' ' << j + 1 << '\n';
				}
			}
			vector<int> ind(n);
			for (int i = 0; i < n; i++) {
				ind[top_sort[i]] = i;
			}
			for (auto &[v, u] : edges) {
				if (ind[v] > ind[u]) {
					swap(u, v);
				}
				cout << v + 1 << ' ' << u + 1 << '\n';
			}
		}
	}
}