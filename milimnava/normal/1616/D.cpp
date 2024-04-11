#include <bits/stdc++.h>
using namespace std;

int dp[50005][2][2];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		memset(dp, -0x7f, sizeof(dp));
		int n, x; cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		cin >> x;
		auto check = [&](int l, int r) {
			int sum = 0;
			for (int i = l; i <= r; i++) sum += a[i];
			return sum >= x * (r - l + 1);
		};
		dp[0][0][0] = 0; dp[0][1][0] = 1;
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < 2; j++) {
				for (int k = 0; k < 2; k++) {
					if (dp[i][j][k] == dp[50004][0][0]) continue;
					for (int t = 0; t < 2; t++) {
						if (t && j && !check(i, i + 1)) continue;
						if (t && j && k && !check(i - 1, i + 1)) continue;
						dp[i + 1][t][j] = max(dp[i + 1][t][j], dp[i][j][k] + t);
					}
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				ans = max(ans, dp[n - 1][i][j]);
			}
		}
		cout << ans << endl;
	}
	return 0;
}