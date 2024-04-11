#include <iostream>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ll l, r, x, y;
	cin >> l >> r >> x >> y;
	// gcd(a', b') = x
	// lca(a', b') = y
	// -> a' = ax
	// -> b' = bx
	// gcd(a, b) = 1
	// ab = y/x
	if (y % x != 0) {
		cout << "0\n";
	} else {
		int res = 0;
		y /= x;
		for (ll a = 1; a*a <= y; ++a) {
			if (y % a != 0) continue;

			ll b = y / a;

			if (! (l <= a*x && a*x <= r)) continue;
			if (! (l <= b*x && b*x <= r)) continue;
			if (gcd(a, b) != 1) continue;
			// now:
			// l <= a', b' <= r
			// gcd(a', b') = x
			// lca(a', b') = y
			res += 2 - (a == b);
		}
		cout << res << '\n';
	}
}