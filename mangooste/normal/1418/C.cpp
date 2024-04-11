#include <bits/stdc++.h>

using namespace std;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (auto &x : a)
			cin >> x;
		vector<array<int, 2>> dp(n + 1, {0, 0});
		const int INF = n;
		for (int i = n - 1; i >= 0; i--) {
			dp[i] = {INF, INF};
			for (int tp = 0; tp < 2; tp++)
				for (int cnt = 1; cnt <= 2 && i + cnt <= n; cnt++) {
					int s = a[i] + (cnt == 1 ? 0 : a[i + 1]);
					dp[i][tp] = min(dp[i][tp], dp[i + cnt][tp ^ 1] + tp * s);
				}
		}
		cout << dp[0][1] << '\n';
	}
}