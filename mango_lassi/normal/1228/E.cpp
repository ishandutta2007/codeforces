#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

ll modPow(ll a, ll b) {
	if (b & 1) return a * modPow(a, b-1) % MOD;
	if (b == 0) return 1;
	return modPow(a*a % MOD, b >> 1);
}

const int N = 250;
ll fact[N+1];
ll inv_fact[N+1];

ll choose(int a, int b) {
	if (a < b) return 0;
	ll dv = inv_fact[b] * inv_fact[a-b] % MOD;
	return fact[a] * dv % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	fact[0] = 1;
	for (int i = 1; i <= N; ++i) fact[i] = (i * fact[i-1]) % MOD;
	for (int i = 0; i <= N; ++i) inv_fact[i] = modPow(fact[i], MOD - 2);

	ll n, k;
	cin >> n >> k;

	ll res = 0;
	for (int tot = 0; tot <= 2*n; ++tot) {
		for (int rows = 0; rows <= n; ++rows) {
			int cols = tot - rows;
			if (cols < 0 || cols > n) continue;

			ll mult = choose(n, rows) * choose(n, cols) % MOD;
			if (tot & 1) mult = (MOD - mult) % MOD;

			ll cou = modPow(k, (n - rows) * (n - cols)) * modPow(k-1, n*n - (n - rows) * (n - cols)) % MOD;
			ll add = mult * cou % MOD;

			res = (res + add) % MOD;
		}
	}
	cout << res << '\n';
}