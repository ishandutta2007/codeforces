#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	const int64_t INF = 1e18;

	int N, M; cin >> N >> M;
	vector<vector<pair<int, int>>> adj(N);
	for (int i = 0; i < M; ++i) {
		int v, u, c; cin >> v >> u >> c;
		adj[v].emplace_back(u, c);
	}
	for (int s = 0; s < N; ++s) {
		vector<int64_t> dist(N, INF);
		dist[s] = 0;
		vector<bool> used(N);
		for (int _ = 0; _ < N; ++_) {
			int v = -1;
			for (int i = 0; i < N; ++i) {
				if (used[i]) continue;
				if (v == -1 || dist[i] < dist[v]) {
					v = i;
				}
			}
			used[v] = true;
			vector<int64_t> dist2(N, INF);
			for (auto [u, c] : adj[v]) {
				u = (u + dist[v]) % N;
				dist2[u] = min(dist2[u], dist[v] + c);
			}
			for (int z = 0; z < 2 * N; ++z) {
				dist2[(z + 1) % N] = min(dist2[(z + 1) % N], dist2[z % N] + 1);
			}
			for (int u = 0; u < N; ++u) dist[u] = min(dist[u], dist2[u]);
		}
		for (int v = 0; v < N; ++v) cout << dist[v] << " \n"[v == N - 1];
	}
	return 0;
}