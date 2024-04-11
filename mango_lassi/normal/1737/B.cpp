#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll calc(ll a) {
	if (a == 0) return 0;

	// Luxury numbers: for some x, either
	// 1. y = x^2
	// 2. y = x^2 + x
	// 3. y = x^2 + 2x

	ll low = 1, high = (ll)1e9 + 7;
	while(low != high) {
		ll mid = (low + high + 1) >> 1;
		if (mid*mid <= a) low = mid;
		else high = mid - 1;
	}

	ll x = low;
	ll res = 3*(x - 1) + 1;
	if (x*x + x <= a) ++res;
	if (x*x + 2*x <= a) ++res;
	return res;
}

void solve() {
	ll a, b;
	cin >> a >> b;

	ll res = calc(b) - calc(a-1);
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}