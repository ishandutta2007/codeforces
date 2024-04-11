#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5000 + 1;
int dp[2][N];

void solve() {
	int n, m;
	cin >> n >> m;

	string s1, s2;
	cin >> s1 >> s2;

	int res = 0;
	for (int j = 1; j <= m; ++j) {
		dp[1][0] = 0;
		for (int i = 1; i <= n; ++i) {
			dp[1][i] = max(0, max(dp[1][i-1], dp[0][i]) - 1);
			if (s1[i-1] == s2[j-1]) dp[1][i] = max(dp[1][i], dp[0][i-1] + 2);
			res = max(res, dp[1][i]);
		}
		for (int i = 0; i <= n; ++i) dp[0][i] = dp[1][i];
	}
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
}