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
		vector<int> a(n);
		for (auto &el : a) {
			cin >> el;
		}
		vector<int> dp(n, 0);
		dp[n - 1] = 1;
		for (int i = n - 2; i >= 0; i--) {
			if (a[i] == 1) {
				dp[i] = dp[i + 1] ^ 1;
			} else {
				dp[i] = 1;
			}
		}
		cout << (dp[0] ? "First\n" : "Second\n");
	}
}