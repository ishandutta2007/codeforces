#include <bits/stdc++.h>

using namespace std;

const int INF = (int) 1e9;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> g(n);
	for (int i = 0; i < m; i++) {
		int v, u, type;
		cin >> v >> u >> type;
		v--; u--;
		g[u].emplace_back(v, type);
	}
	vector<array<int, 2>> dist(n, {INF, INF});
	dist.back() = {0, 0};
	set<pair<int, int>> q;
	q.emplace(0, n - 1);
	while (q.size()) {
		auto [d, v] = *q.begin();
		q.erase(q.begin());
		if (d != max(dist[v][0], dist[v][1]))
			continue;
		for (auto [u, type] : g[v])
			if (dist[u][type] > d + 1) {
				dist[u][type] = d + 1;
				q.emplace(max(dist[u][0], dist[u][1]), u);
			}
	}
	int ans = max(dist[0][0], dist[0][1]);
	cout << (ans == INF ? -1 : ans) << '\n';
	for (int i = 0; i < n; i++)
		cout << (dist[i][0] > dist[i][1] ? '0' : '1');
	cout << '\n';
}