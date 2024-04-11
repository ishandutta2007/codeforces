#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<vector<pair<int, int>>> g;
vector<int> col, comp;

void dfs(int v, bool &valid) {
	comp.push_back(v);
	for (auto [u, t] : g[v]) {
		if (col[u] == -1) {
			col[u] = col[v] ^ t;
			dfs(u, valid);
		} else {
			valid &= (col[u] == col[v] ^ t);
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<vector<array<int, 2>>> where(n);
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			where[x - 1].push_back({i, 0});
		}
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			where[x - 1].push_back({i, 1});
		}
		bool valid = true;
		for (int i = 0; i < n; i++) {
			valid &= (where[i].size() == 2);
		}
		if (!valid) {
			cout << "-1\n";
			continue;
		}
		g.clear();
		g.resize(n);
		for (int i = 0; i < n; i++) {
			int n1 = where[i][0][0], n2 = where[i][1][0];
			if (n1 != n2) {
				g[n1].emplace_back(n2, (where[i][0][1] == where[i][1][1]));
				g[n2].emplace_back(n1, (where[i][0][1] == where[i][1][1]));
			}
		}
		col.clear();
		col.resize(n, -1);
		for (int i = 0; i < n && valid; i++) {
			if (col[i] == -1) {
				comp.clear();
				col[i] = 0;
				dfs(i, valid);
				int sm = 0;
				for (auto v : comp) {
					sm += col[v];
				}
				if (sm * 2 > comp.size()) {
					for (auto v : comp) {
						col[v] ^= 1;
					}
				}
			}
		}
		if (!valid) {
			cout << "-1\n";
		} else {
			cout << accumulate(col.begin(), col.end(), 0) << '\n';
			for (int i = 0; i < n; i++) {
				if (col[i]) {
					cout << i + 1 << ' ';
				}
			}
			cout << '\n';
		}
	}
}