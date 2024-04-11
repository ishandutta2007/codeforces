#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
   
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<vector<int>> adj(N);
		for (int i = 0; i < N - 1; ++i) {
			int v, u; cin >> v >> u;
			adj[--v].push_back(--u);
			adj[u].push_back(v);
		}

		vector<int> ans(N);

		function<void(int, int, int)> dfs = [&](int v, int p, int w) {
			ans[v] = int(adj[v].size()) * w;
			for (int u : adj[v]) if (u != p) {
				dfs(u, v, -w);
			}
		};

		dfs(0, -1, 1);
		for (int i = 0; i < N; ++i) cout << ans[i] << " \n"[i == N - 1];
	}   
}