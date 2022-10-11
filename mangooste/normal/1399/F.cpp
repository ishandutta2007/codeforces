#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct event {
	int x, y, type, id;
};

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> L(n), R(n);
		vector<event> evs;
		for (int i = 0; i < n; i++) {
			cin >> L[i] >> R[i];
			evs.push_back({L[i], R[i], 0, i});
			evs.push_back({R[i], L[i], 1, i});
		}
		sort(evs.begin(), evs.end(), [](event &a, event &b) {
			if (a.x < b.x) return true;
			if (b.x < a.x) return false;
			if (a.type != b.type) return a.type < b.type;
			return a.y > b.y;
		});
		int now = 0;
		for (auto ev : evs) (ev.type ? R[ev.id] : L[ev.id]) = now++;
		vector<int> par(2 * n, -1);
		for (int i = 0; i < n; i++) {
			par[L[i]] = R[i];
			par[R[i]] = L[i];
		}
//		cout << "------------\n";
//		for (int i = 0; i < n; i++) cout << '(' << L[i] << ' ' << R[i] << ")\n";

		vector<vector<int>> dp(2 * n, vector<int>(2 * n, 0));
		auto get = [&](int L, int R) -> int {
			if (L < 0 || R >= 2 * n || L > R) return 0;
			return dp[L][R];
		};
		for (int del = 1; del < 2 * n; del++) {
			for (int i = 0; i + del < 2 * n; i++) {
				int j = i + del;
				if (par[i] > i && par[i] <= j)
					dp[i][j] = max(dp[i][j], get(i + 1, par[i] - 1) + 1 + get(par[i] + 1, j));
				if (par[j] < j && par[j] >= i)
					dp[i][j] = max(dp[i][j], get(i, par[j] - 1) + get(par[j] + 1, j - 1) + 1);
				dp[i][j] = max({dp[i][j], get(i, j - 1), get(i + 1, j)});
			}
		}
//		cout << "------------\n";
//		for (int i = 0; i < 2 * n; i++)
//			for (int j = 0; j < 2 * n; j++) cout << "dp " << i << ' ' << j << " = " << dp[i][j] << '\n';
		cout << dp[0][2 * n - 1] << '\n';
	}
}