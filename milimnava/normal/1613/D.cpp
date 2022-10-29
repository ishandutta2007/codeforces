#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

inline int norm(int x) {
	return x >= mod ? x - mod : x;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		vector<int> a(n + 1), cnt(n + 1, 0);
		for (int i = 1; i <= n; i++) cin >> a[i];
		vector<int> r(n + 1, 0), Pow(n + 1, 0);
		for (int i = n; i >= 1; i--) {
			r[i] = cnt[a[i]];
			if (a[i] >= 2) r[i] += cnt[a[i] - 2];
			++cnt[a[i]];
		}
		vector<int> dp(n + 1, 0);
		Pow[0] = 1;
		for (int i = 1; i <= n; i++) Pow[i] = norm(Pow[i - 1] * 2);
		dp[0] = 1;
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] >= 1) {
				sum = (sum + 1ll * dp[a[i] - 1] * Pow[r[i]]) % mod;
			}
			if (a[i] != n) {
				dp[a[i] + 1] = norm(dp[a[i] + 1] * 2);
				dp[a[i] + 1] = norm(dp[a[i] + 1] + dp[a[i]]);
			}
		}
		for (int i = 0; i <= n; i++) {
			sum = norm(sum + dp[i]);
		}
		cout << norm(sum + mod - 1) << endl;
	}
	return 0;
}