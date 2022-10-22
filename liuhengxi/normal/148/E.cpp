#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, m, x[105], a[105], b[105], c[105], f[105][105], dp[105][10005];

signed main() {

	cin >> n >> m;

	for (int i = 1; i <= n; i ++) {
		cin >> x[i];
		for (int j = 1; j <= x[i]; j++) cin >> a[j];
		b[0] = 0; for (int j = 1; j <= x[i]; j++) b[j] = b[j - 1] + a[j];
		c[x[i] + 1] = 0;
		for (int j = x[i]; j; j--) c[j] = c[j + 1] + a[j];
		for (int j = 1; j <= x[i]; j++) for (int k = 0; k <= j; k++)
			f[i][j] = max(f[i][j], b[k] + c[x[i] - (j - k) + 1]);
	}

	for (int i = 1; i <= n; i++) for (int j = 0; j <= x[i]; j++) for (int k = j; k <= m; k++)
		dp[i][k] = max(dp[i][k], dp[i - 1][k - j] + f[i][j]);

	cout << dp[n][m] << endl;

	return 0;

}