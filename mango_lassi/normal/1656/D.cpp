#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	ll n;
	cin >> n;

	// Say n = 2^t * x
	// We are done if n >= 2^t * (2^{t + 1} + 1)	-> if x >= 2^{t + 1} + 1 -> if x >= 2^{t + 1} + 1
	// We are done if n >= x(x + 1) / 2		-> if (x + 1) / 2 <= 2^t -> if x <= 2^{t + 1} - 1
	// -> If x != 1, we are done, as x has to be odd

	// Attempt even numbers
	for (ll j = 0;; ++j) {
		ll bit = 1ll << j;
		ll mod = 1ll << (j + 1);
		ll minv = mod * (mod + 1) / 2;
		if (n < minv) break;
		if (n & bit) {
			cout << mod << '\n';
			return;
		}
	}

	// Attempt x
	ll x = n;
	while(x % 2 == 0) x /= 2;

	if (x == 1) cout << -1 << '\n';
	else cout << x << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}