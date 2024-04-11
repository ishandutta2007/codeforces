#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	ll n;
	cin >> n;

	ll ans = 0;
	for (ll bit = 0; (1ll << bit) < n; bit++) {
		ll p = (1ll << bit);
		ans += ((n - 1 - p) / (p * 2) + 1) * p;
	}

	cout << ans;
}