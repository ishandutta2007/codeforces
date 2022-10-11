#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 998244353;

inline int add(int a, int b) {
	a += b;
	return a - MOD * (a >= MOD);
}

inline int mult(int a, int b) {
	return (ll) a * b % MOD;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (auto &el : a) {
		cin >> el;
	}

	for (int i = 0; i < n; i++) {
		a.push_back(a[i]);
	}
	a.insert(a.begin(), 0);

	vector<int> dp(2 * n + 1, 0);
	dp[n] = 1;

	for (int i = 1; i <= n; i++) {
		vector<int> loc(2 * n + 1, 0);

		if (a[i] != a[i + 1]) {
			for (int j = 0; j <= 2 * n; j++) {
				if (j) {
					loc[j] = add(loc[j], dp[j - 1]);
				}
				if (j != 2 * n) {
					loc[j] = add(loc[j], dp[j + 1]);
				}
			}
		}

		for (int j = 0; j <= 2 * n; j++) {
			loc[j] = add(loc[j], mult(dp[j], max(0, k - 2 * (a[i] != a[i + 1]))));
		}

		dp = loc;
	}

	int ans = 0;
	for (int i = n + 1; i <= 2 * n; i++) {
		ans = add(ans, dp[i]);
	}

	cout << ans << '\n';
}