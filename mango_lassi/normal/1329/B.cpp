#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
	// Number of increasing arrays with increasing prefix xors
	// Each number has to have a higher first bit than the previous, everything else is arbitrary

	ll d, m;
	cin >> d >> m;
	ll res = 1;
	for (ll b = 1; b <= d; b <<= 1) {
		ll opts = min(b, d-b+1);
		res = (res * (opts + 1)) % m;
	}
	res -= 1;
	if (res < 0) res += m;
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}