#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = (int)1e9 + 7;

const int N = 20;
ll inv[N+1];

ll modPow(ll a, ll b) {
	if (b & 1) return a * modPow(a, b-1) % MOD;
	if (b == 0) return 1;
	return modPow(a*a % MOD, b / 2);
}

ll choose(ll a, int b) {
	ll res = 1;
	for (int i = 0; i < b; ++i) {
		ll over = (a-i) % MOD;
		ll mult = (over * inv[b-i]) % MOD;
		res = (res * mult) % MOD;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	ll s;
	cin >> n >> s;
	for (int i = 1; i <= n; ++i) inv[i] = modPow(i, MOD-2);

	vector<ll> fs(n);
	for (int i = 0; i < n; ++i) cin >> fs[i];

	// Stars and Stripes inclusion-exclusion
	ll ans = 0;
	for (int mask = 0; mask < (1<<n); ++mask) {
		ll tot = s;
		int parity = 1;
		for (int j = 0; j < n; ++j) {
			if (mask & (1<<j)) {
				tot -= fs[j]+1;
				parity *= -1;
			}
		}
		if (tot < 0) continue;
		ans += parity * choose(tot + n-1, n-1);
	}
	ans %= MOD;
	if (ans < 0) ans += MOD;
	cout << ans << '\n';
}