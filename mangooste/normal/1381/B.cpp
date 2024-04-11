#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> p(2 * n);
		for (auto &el : p) {
			cin >> el;
			el = 2 * n - el;
		}
		p.push_back(-1);
		vector<int> lens;
		int last = 0;
		for (int i = 1; i < p.size(); i++) {
			if (p[i] < p[last]) {
				lens.push_back(i - last);
				last = i;
			}
		}
		vector<char> dp(n + 1, 0);
		dp[0] = 1;
		for (int i = 0; i < lens.size(); i++) {
			vector<char> new_dp = dp;
			for (int j = lens[i]; j <= n; j++) {
				new_dp[j] = (new_dp[j] || dp[j - lens[i]]);
			}
			dp = new_dp;
		}
		cout << (dp[n] ? "YES\n" : "NO\n");
	}
}