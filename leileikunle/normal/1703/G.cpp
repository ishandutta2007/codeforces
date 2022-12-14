#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define int long long
#define all(a) a.begin(),a.end()
using pii = pair<int, int>;
const int N = 1e5 + 10, M = N, inf = 1e18, mod = 998244353;

void solve() {

	int n, k, ans(0);
	cin >> n >> k;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	vector<vector<int> > dp(n + 2, vector<int>(32, -inf));

	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 31; j++) {
			if (!j) dp[i][j] = max(dp[i][j], dp[i - 1][j] - k + a[i]);
			else dp[i][j] = max(dp[i - 1][j] - k + (a[i] >> j), dp[i - 1][j - 1] + (a[i] >> j));
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << endl;

}
signed main() {
	cin.tie(0) -> ios::sync_with_stdio(false);
	int tt = 1;
	cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}