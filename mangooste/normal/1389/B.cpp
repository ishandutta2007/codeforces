#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll INF = 1e15;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, k, z;
		cin >> n >> k >> z;
		vector<int> a(n);
		for (auto &el : a) {
			cin >> el;
		}

		vector<vector<ll>> dp(n, vector<ll>(z + 1, -INF));
		dp[0][0] = a[0];

		for (int i = 1; i < n; i++) {
			for (int cnt = 0; cnt <= z; cnt++) {
				for (int was = 0; was <= cnt; was++) {
					dp[i][cnt] = max(dp[i][cnt], dp[i - 1][was] + a[i] + (cnt - was) * (a[i] + a[i - 1]));
				}
			}
		}

		ll ans = -INF;
		for (int i = 1; i < n; i++) {
			for (int cnt = 0; cnt <= z; cnt++) {
				if (i + cnt * 2 == k) {
					ans = max(ans, dp[i][cnt]);
				}
				if (i + cnt * 2 == k - 1 && cnt != z) {
					ans = max(ans, dp[i][cnt] + a[i - 1]);
				}
			}
		}

		cout << ans << '\n';
	}
}