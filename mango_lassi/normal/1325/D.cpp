#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll u, v;
	cin >> u >> v;

	// when is it IMPOSSIBLE?
	//	1. Xor is larger than sum: xor is always at most as large
	//	2. Different parity: xor and sum are the same operation mod 2
	// when is it possible with 0?
	//	1. When both numbers are 0
	// when is it possible with 1?
	//	1. When u == v
	// when is it possible with 2?
	//	Exactly when u = 111x0 and v = 1000x0 for some length

	if (u > v || (u % 2 != v % 2)) {
		cout << -1 << '\n';
	} else if (u == 0 && v == 0) {
		cout << 0 << '\n';
	} else if (u == v) {
		cout << 1 << '\n' << u << '\n';
	} else {
		ll a = u;
		v -= u;

		int need = 0;
		ll b = 0, c = 0;
		for (ll j = 1ll << 62; j > 0; j >>= 1) {
			if (v & j) ++need;
			if (need >= 2) {
				b ^= j;
				if (! (a & j)) a ^= j;
				else c ^= j;
				need -= 2;
			}
			need *= 2;
		}

		if (c == 0) cout << 2 << '\n' << a << ' ' << b << '\n';
		else cout << 3 << '\n' << a << ' ' << b << ' ' << c << '\n';
	}
}