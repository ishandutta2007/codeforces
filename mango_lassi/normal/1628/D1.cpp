#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = (ll)1e9 + 7;
const ll two_inv = (MOD + 1) / 2;

constexpr ll modPow(ll a, ll b, ll c) {
	return (b&1) ? (a * modPow(a, b-1, c) % c)
		: (b ? modPow(a*a % c, b/2, c) : 1);
}

struct FactPrecalc {
	private:
		const int P;
		vector<int> fact, inv_fact;
	public:
		FactPrecalc(int n, int p) : P(p), fact(n+1, 1), inv_fact(n+1, 1) {
			for (int i = 2; i <= n; ++i) fact[i] = (ll)fact[i-1] * i % P;
			inv_fact[n] = modPow(fact[n], P-2, P);
			for (int i = n-1; i >= 0; --i) inv_fact[i] = (ll)inv_fact[i+1] * (i+1) % P;
		}

		ll operator()(ll a, ll b) const {
			if (a < b) return 0;
			ll div = (ll)inv_fact[a-b] * inv_fact[b] % P;
			return div * fact[a] % P;
		}
		ll operator[](int i) const { return fact[i]; }
		ll inv(int i) const { return inv_fact[i]; }
};

void solve(const FactPrecalc& binom) {
	int n, m;
	ll k;
	cin >> n >> m >> k;

	if (n == m) {
		cout << k*n % MOD << '\n';
	} else {
		ll res = 0, mult = 1;
		for (int i = 1; i <= m; ++i) {
			mult = (mult * 2) % MOD;
			ll val = mult * (i * k % MOD) % MOD;
			res = (res + binom(n-1-i, m-i) * val) % MOD;
		}
		cout << modPow(two_inv, n, MOD) * res % MOD << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	const int N = 1e6;
	FactPrecalc binom(2*N, MOD);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve(binom);
}