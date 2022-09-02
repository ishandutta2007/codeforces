#include <iostream>
using namespace std;
using ll = long long;
const ll MOD = (ll)1e9 + 7;

ll incseq(ll h) {
	h %= MOD;
	return (h * (h + MOD - 1)) % MOD;
}

ll getsum(ll h) {
	ll even_len = 0;
	ll odd_len = 0;
	for (int j = 0; h > 0; ++j) {
		ll add = min(h, (ll)1 << j);
		h -= add;
		if (j & 1) even_len += add;
		else odd_len += add;
	}

	ll res = odd_len % MOD;
	res = (res + 2 * even_len) % MOD;
	res = (res + incseq(even_len)) % MOD;
	res = (res + incseq(odd_len)) % MOD;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll l, r;
	cin >> l >> r;

	ll res = (getsum(r) - getsum(l-1)) % MOD;
	if (res < 0) res += MOD;
	cout << res << '\n';
}