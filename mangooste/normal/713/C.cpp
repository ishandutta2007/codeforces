#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int INF = 2e9;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] -= i;
	}
	vector<int> b = a;
	sort(b.begin(), b.end());
	b.resize(unique(b.begin(), b.end()) - b.begin());
	int m = b.size();
	vector<ll> dp(m, 0);
	for (int i = 0; i < n; i++) {
		vector<ll> new_dp(m);
		ll mn = 1e18;
		for (int j = 0; j < m; j++) {
			mn = min(mn, dp[j]);
			new_dp[j] = mn + abs(a[i] - b[j]);
		}
		swap(dp, new_dp);
	}
	cout << *min_element(dp.begin(), dp.end());
}