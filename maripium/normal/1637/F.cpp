#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	
	int N; cin >> N;
	vector<int> H(N); for (int &a : H) cin >> a;

	vector<vector<int>> adj(N);
	for (int i = 0; i < N-1; ++i) {
		int v, u; cin >> v >> u;
		adj[--v].push_back(--u);
		adj[u].push_back(v);
	}

	int64_t ans = 0;
	function<int(int, int)> dfs = [&](int v, int p) {
		int m1 = 0, m2 = 0;
		for (int u : adj[v]) if (u != p) {
			int m = dfs(u, v);
			m2 = max(m2, m);
			if (m1 < m2) swap(m1, m2);
		}
		if (p == -1) {
			ans += max(0, H[v] - m1) + max(0, H[v] - m2);
		} else {
			ans += max(0, H[v] - m1);
		}
		return max(m1, H[v]);
	};

	int root = max_element(H.begin(), H.end()) - H.begin();
	dfs(root, -1);
	cout << ans << '\n';
	return 0;
}