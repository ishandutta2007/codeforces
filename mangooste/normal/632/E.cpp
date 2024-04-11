#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (auto &el : a) {
		cin >> el;
	}
	sort(a.begin(), a.end());
	a.resize(unique(a.begin(), a.end()) - a.begin());
	n = a.size();
	for (int i = 1; i < n; i++) {
		a[i] -= a[0];
	}
	int m = a.back() * k + 1;
	vector<int> dp(m, 1e9);
	dp[0] = 0;
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			if (i >= a[j] && dp[i] > dp[i - a[j]] + 1) {
				dp[i] = dp[i - a[j]] + 1;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		if (dp[i] <= k) {
			cout << a[0] * k + i << ' ';
		}
	}
}