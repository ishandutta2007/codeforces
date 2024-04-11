#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 9;

ll modPow(ll a, ll b) {
	if (b == 0) return 1;
	if (b & 1) return a * modPow(a, b-1) % MOD;
	return modPow(a*a % MOD, b / 2);
}

// 1 + a + ... + a^b = (a^(b+1) - 1) / (a - 1)
ll geom(ll a, ll b) {
	if (a == 1) return b+1;
	else if (a == 0) return 1;
	ll divi = (modPow(a, b+1) + MOD - 1) % MOD;
	ll divs = modPow((a+MOD-1) % MOD, MOD-2);
	return divi*divs % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll n, a, b, k;
	cin >> n >> a >> b >> k;

	ll t0 = modPow(a, n);
	a = modPow(a, MOD-2);
	ll ab = a*b % MOD;
	ll mult = modPow(ab % MOD, k);
	ll sp = 0;

	string str;
	cin >> str;
	for (int i = 0; i < k; ++i) {
		if (str[i] == '+') {
			sp += t0;
		} else {
			sp += (MOD - t0) % MOD;
		}
		t0 = (t0 * ab) % MOD;
	}
	sp %= MOD;

	ll res = sp * geom(mult, (n+1)/k - 1) % MOD;
	cout << res << '\n';
}