#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	ll x, y;
	cin >> x >> y;

	// (n MOD x) = (y MOD n)
	// Not symmetric!

	// If y < x, return x + y
	// If y >= x:
	// 	Assume y = ax + b
	// 	Output n = ax + b / 2

	ll res;
	if (y < x) {
		res = x + y;
	} else {
		ll r = y % x;
		res = y - (r / 2);
	}
	cout << res << '\n';
	assert((res % x) == (y % res));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int q;
	cin >> q;
	for (int qi = 0; qi < q; ++qi) solve();
}