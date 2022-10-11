#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 201;

ll dp[N][N][N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	array<int, 3> n;
	for (auto &x : n) cin >> x;
	array<vector<int>, 3> a;
	for (int i = 0; i < 3; i++) {
		a[i].resize(n[i]);
		for (auto &x : a[i]) cin >> x;
		sort(a[i].rbegin(), a[i].rend());
	}
	for (int n0 = 0; n0 <= n[0]; n0++) {
		for (int n1 = 0; n1 <= n[1]; n1++) {
			for (int n2 = 0; n2 <= n[2]; n2++) {
				dp[n0][n1][n2] = 0;
				if (n0 && n1) dp[n0][n1][n2] = max(dp[n0][n1][n2], dp[n0 - 1][n1 - 1][n2] + a[0][n0 - 1] * a[1][n1 - 1]);
				if (n0 && n2) dp[n0][n1][n2] = max(dp[n0][n1][n2], dp[n0 - 1][n1][n2 - 1] + a[0][n0 - 1] * a[2][n2 - 1]);
				if (n1 && n2) dp[n0][n1][n2] = max(dp[n0][n1][n2], dp[n0][n1 - 1][n2 - 1] + a[1][n1 - 1] * a[2][n2 - 1]);
				if (n0) dp[n0][n1][n2] = max(dp[n0][n1][n2], dp[n0 - 1][n1][n2]);
				if (n1) dp[n0][n1][n2] = max(dp[n0][n1][n2], dp[n0][n1 - 1][n2]);
				if (n2) dp[n0][n1][n2] = max(dp[n0][n1][n2], dp[n0][n1][n2 - 1]);
			}
		}
	}
	cout << dp[n[0]][n[1]][n[2]] << '\n';
}