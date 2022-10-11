#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> edges(m);
	for (auto &[v, u] : edges) {
		cin >> v >> u;
		v--, u--;
	}
	string ans(n, 'A');
	for (int rev = 0; rev < 2; rev++) {
		vector<vector<int>> g(n);
		vector<int> deg(n, 0);
		for (auto [v, u] : edges) {
			if (rev) {
				swap(v, u);
			}
			g[v].push_back(u);
			deg[u]++;
		}
		vector<int> mn(n);
		iota(mn.begin(), mn.end(), 0);
		queue<int> q;
		for (int i = 0; i < n; i++) {
			if (!deg[i]) {
				q.push(i);
			}
		}
		while (q.size()) {
			int v = q.front();
			q.pop();
			deg[v] = -1;
			if (mn[v] < v) {
				ans[v] = 'E';
			}
			for (auto u : g[v]) {
				mn[u] = min(mn[u], mn[v]);
				deg[u]--;
				if (!deg[u]) {
					q.push(u);
				}
			}
		}
		if (*max_element(deg.begin(), deg.end()) >= 0) {
			cout << -1;
			return 0;
		}
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		res += (ans[i] == 'A');
	}
	cout << res << '\n' << ans;
}