#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

ll count(ll v, ll n) {
	ll res = 0;
	ll mult = 1;
	if (! (v & 1)) {
		v >>= 1;
		--res;
	}
	for (ll mult = 1;; mult *= 2) {
		ll off = min(mult, n+1 - mult * v);
		if (off <= 0) break;
		res += off;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll k, n;
	cin >> n >> k;

	ll m = n;
	bool found = false;
	while(! found) {
		for (int j = 0; j <= 3; ++j) {
			ll off = count(m-j, n);
			if (off >= k) {
				cout << m-j << '\n';
				found = true;
				break;
			}
		}
		m /= 2;
	}
}