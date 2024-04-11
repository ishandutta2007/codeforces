#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<pair<int, int>>> g(n);
	for (int i = 0; i < m; i++) {
		int v, u, w;
		cin >> v >> u >> w;
		v--, u--;
		g[v].emplace_back(u, w);
	}
	vector<vector<pair<int, int>>> into(n);
	for (int i = 0; i < n; i++) {
		if (!g[i].size()) return cout << "0\n", 0;
		sort(g[i].begin(), g[i].end(), [](pair<int, int> &a, pair<int, int> &b) {
			return a.second < b.second;
		});
		for (int j = 0; j < g[i].size(); j++) into[g[i][j].first].emplace_back(g[i].size() - 1, j);
	}
	vector<vector<char>> valid(k * k, vector<char>(k * k, 1));
	vector<vector<char>> can(k, vector<char>(k, 1));
	for (int v = 0; v < n; v++) {
		if (!into[v].size()) return cout << "0\n", 0;
		sort(into[v].begin(), into[v].end());
		vector<pair<int, int>> ninto;
		for (int i = 0; i < into[v].size();) {
			int j = i + 1;
			while (j < into[v].size() && into[v][i] == into[v][j]) j++;
			if (j - i > 1) can[into[v][i].first][into[v][i].second] = 0;
			else ninto.push_back(into[v][i]);
			i = j;
		}
		into[v] = ninto;
		if (!into[v].size()) return cout << "0\n", 0;
		for (int i = 0; i < into[v].size(); i++) {
			for (int j = i + 1; j < into[v].size(); j++) {
				pair<int, int> a = into[v][i], b = into[v][j];
				int ida = a.first * k + a.second;
				int idb = b.first * k + b.second;
				valid[ida][idb] = valid[idb][ida] = 0;
			}
		}
	}
	int ans = 0;
	vector<int> c;
	c.reserve(k);
	function<void()> dfs = [&]() {
		if (c.size() == k) {
			for (int i = 0; i < k; i++) {
				int idi = i * k + c[i];
				for (int j = i + 1; j < k; j++) {
					int idj = j * k + c[j];
					if (!valid[idi][idj]) return;
				}
			}
			ans++;
			return;
		}
		for (int now = 0; now <= c.size(); now++) {
			if (!can[c.size()][now]) continue;
			c.push_back(now);
			dfs();
			c.pop_back();
		}
	};
	dfs();
	cout << ans << '\n';
}