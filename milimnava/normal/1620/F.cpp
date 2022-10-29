#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		vector<int> a(n), dp[2], pos(n + 1);
		for (int i = 0; i <= 1; i++) dp[i].resize(n, INF);
		for (int i = 0; i < n; i++) cin >> a[i], pos[a[i]] = i;
		dp[0][0] = dp[1][0] = -INF;
		for (int i = 1; i < n; i++) {
			for (int j = 0; j <= 1; j++) {
				if (dp[j][i - 1] == INF) continue;
				for (int k = 0; k <= 1; k++) {
					int prei = (j ? a[i - 1] : -a[i - 1]);
					int nowi = (k ? a[i] : -a[i]);
					if (prei < nowi) dp[k][i] = min(dp[k][i], dp[j][i - 1]);
					if (dp[j][i - 1] < nowi) dp[k][i] = min(dp[k][i], prei);
				}
			}
		}
		if (dp[0][n - 1] == INF && dp[1][n - 1] == INF) {
			cout << "NO" << '\n';
			continue;
		}
		vector<int> ans(n);
		int now = (dp[1][n - 1] != INF);
		for (int i = n - 1; i >= 1; i--) {
			ans[i] = now ? a[i] : -a[i];
			if (abs(dp[now][i]) == a[i - 1]) now = (dp[now][i] > 0);
			else now = (dp[0][i - 1] != dp[now][i]);
		}
		ans[0] = now ? a[0] : -a[0];
		cout << "YES" << '\n';
		for (int i = 0; i < n; i++) cout << ans[i] << ' ';
		cout << '\n';
	}
	return 0;
}