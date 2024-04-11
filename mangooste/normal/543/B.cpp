#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int INF = 1e9;

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
	array<int, 2> s, t, len;
	for (int i = 0; i < 2; i++) {
		cin >> s[i] >> t[i] >> len[i];
		s[i]--, t[i]--;
	}

	auto bfs = [&](int v) -> vector<int> {
		vector<int> dist(n, INF);
		dist[v] = 0;
		queue<int> q;
		q.push(v);
		while (q.size()) {
			int v = q.front();
			q.pop();
			for (auto u : g[v]) {
				if (dist[u] > dist[v] + 1) {
					dist[u] = dist[v] + 1;
					q.push(u);
				}
			}
		}
		return dist;
	};
	array<vector<int>, 2> dist_s, dist_t;
	for (int i = 0; i < 2; i++) {
		dist_s[i] = bfs(s[i]);
		dist_t[i] = bfs(t[i]);
	}

	for (int i = 0; i < 2; i++) {
		if (dist_s[i][t[i]] > len[i]) return cout << "-1\n", 0;
	}
	int mn = dist_s[0][t[0]] + dist_s[1][t[1]];
	auto process = [&]() {
		for (int v = 0; v < n; v++) {
			vector<int> dist_v = bfs(v);
			for (int u = 0; u < n; u++) {
				bool ok = true;
				for (int i = 0; i < 2; i++) ok &= (dist_v[u] + dist_s[i][v] + dist_t[i][u] <= len[i]);
				if (ok) mn = min(mn, dist_s[0][v] + dist_v[u] + dist_t[0][u] + dist_s[1][v] + dist_t[1][u]);
			}
		}
	};
	process();
	swap(s[0], t[0]);
	swap(dist_s[0], dist_t[0]);
	process();
	cout << m - mn << '\n';
}