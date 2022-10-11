#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &el : a) {
		cin >> el;
	}
	vector<ll> pref(n, a[0]);
	for (int i = 1; i < n; i++) {
		pref[i] = pref[i - 1] + a[i];
	}
	vector<ll> dp(n, 0);
	ll mx = pref.back();
	for (int i = n - 2; i >= 0; i--) {
		dp[i] = mx;
		mx = max(mx, pref[i] - dp[i]);
	}
	cout << dp[0];
}