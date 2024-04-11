#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n);
	for (int i = 0; i < m; i++) {
		int v, u;
		cin >> v >> u;
		v--, u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	vector<int> a(n);
	queue<int> q;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (!a[i]) q.push(i);
	}
	vector<int> val(n, 0), ans;
	while (q.size()) {
		int v = q.front();
		q.pop();
		if (val[v] != a[v]) continue;
		ans.push_back(v);
		val[v]++;
		for (auto u : g[v]) {
			val[u]++;
			if (val[u] == a[u]) q.push(u);
		}
	}
	cout << ans.size() << '\n';
	for (auto &el : ans) cout << el + 1 << ' ';
}