#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int d, m;
		cin >> d >> m;
		int max_bit = 31 - __builtin_clz(d);
		vector<ll> dp(max_bit + 1, 0);
		for (int i = 0; i < max_bit; i++) {
			dp[i] = (1 << i) % m;
		}
		for (int i = 0; i < max_bit; i++) {
			if ((d >> i) % 2) {
				dp.back() = (dp.back() + (1 << i)) % m;
			}
		}
		dp.back() = (dp.back() + 1) % m;
		for (int i = 1; i <= max_bit; i++) {
			dp[i] = (dp[i] + dp[i - 1] * (dp[i] + 1)) % m;
		}
		cout << dp.back() << '\n';
	}
}