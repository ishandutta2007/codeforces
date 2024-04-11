#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	// floor(a / b) = a % b = x
	// (a - x) / b = x
	// a-x = bx
	// a/(b+1) = x

	// -> a must be a multiple of b+1
	// 	Let a = k(b+1)
	// -> k = floor(k + k/b)
	// -> k < b

	// -> a = k(b+1) works for all 1 <= k < b
	// -> ans = \sum_{b = 1}^{y} min(x / (b+1), b-1)

	ll x, y;
	cin >> x >> y;

	ll ans = 0;
	ll b = 1;
	while(b <= y && x / (b+1) > b-1) {
		ans += b-1;
		++b;
	}
	while(b <= y) {
		// floor(x / (nb+1)) < floor(x / (b+1))
		ll k = x / (b+1);
		if (k == 0) break;

		ll nxt_b = min(y+1, x / k);
		ans += (nxt_b - b) * k;
		
		// cerr << b << ' ' << nxt_b << ' ' << k << endl;
		b = nxt_b;
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}