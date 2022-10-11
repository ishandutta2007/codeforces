#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n, m, b, mod;
	cin >> n >> m >> b >> mod;
	vector<int> a(n);
	for (auto &x : a) cin >> x;
	vector<vector<int>> dp(m + 1, vector<int>(b + 1, 0));
	dp[0][0] = 1 % mod;
	for (int i = 0; i < n; i++) {
		vector<vector<int>> ndp(m + 1, vector<int>(b + 1, 0));
		for (int lines = 1; lines <= m; lines++) {
			for (int bugs = a[i]; bugs <= b; bugs++) {
				ndp[lines][bugs] = (ndp[lines][bugs] + dp[lines - 1][bugs - a[i]]) % mod;
				ndp[lines][bugs] = (ndp[lines][bugs] + ndp[lines - 1][bugs - a[i]]) % mod;
			}
		}
		for (int lines = 0; lines <= m; lines++) {
			for (int bugs = 0; bugs <= b; bugs++)
				ndp[lines][bugs] = (ndp[lines][bugs] + dp[lines][bugs]) % mod;
		}
		dp = ndp;
	}
	int ans = 0;
	for (int i = 0; i <= b; i++) ans = (ans + dp.back()[i]) % mod;
	cout << ans << '\n';
}