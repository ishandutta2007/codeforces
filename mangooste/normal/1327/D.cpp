#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> p(n), c(n);
		for (auto &el : p) {
			cin >> el;
			el--;
		}
		for (auto &el : c) {
			cin >> el;
		}

		vector<vector<int>> g(n);
		for (int i = 0; i < n; i++) {
			g[i].push_back(p[i]);
			g[p[i]].push_back(i);
		}

		int ans = 1e9;
		vector<char> used(n, 0);

		for (int i = 0; i < n; i++) {
			if (used[i]) {
				continue;
			}

			vector<int> cycle;
			int v = i;
			while (!used[v]) {
				cycle.push_back(v);
				used[v] = 1;
				for (auto u : g[v]) {
					if (!used[u]) {
						v = u;
						break;
					}
				}
			}

			auto relax = [&](int d) {
				vector<char> dp(cycle.size());
				for (int i = 0; i < d; i++) {
					dp[i] = 1;
				}
				for (int i = d; i < cycle.size(); i++) {
					dp[i] = (dp[i - d] && c[cycle[i]] == c[cycle[i - d]]);
				}
				for (int i = cycle.size() - d; i < cycle.size(); i++) {
					if (dp[i]) {
						ans = min(ans, d);
						break;
					}
				}
			};

			for (int i = 1; i * i <= cycle.size(); i++) {
				if (cycle.size() % i == 0) {
					relax(i);
					relax(cycle.size() / i);
				}
			}
		}

		cout << ans << '\n';
	}
}