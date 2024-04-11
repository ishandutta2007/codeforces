#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = (ll)1e9 + 7;

constexpr ll modPow(ll a, ll b, ll c) {
	return (b&1) ? (a * modPow(a, b-1, c) % c)
		: (b ? modPow(a*a % c, b/2, c) : 1);
}

// For large nCr's with small modulo: https://en.wikipedia.org/wiki/Lucas%27s_theorem
template<int P>
struct FactPrecalc {
	private:
		vector<int> fact, inv_fact;
	public:
		FactPrecalc(int n) : fact(n+1, 1), inv_fact(n+1, 1) {
			for (int i = 2; i <= n; ++i) fact[i] = (ll)fact[i-1] * i % P;
			inv_fact[n] = modPow(fact[n], P-2, P);
			for (int i = n-1; i >= 0; --i) inv_fact[i] = (ll)inv_fact[i+1] * (i+1) % P;
		}
		ll operator()(ll a, ll b) const {
			if (a < b) return 0;
			ll div = (ll)inv_fact[a-b] * inv_fact[b] % P;
			return fact[a] * div % P;
		}
		ll operator[](int i) const { return fact[i]; }
		ll inv(int i) const { return inv_fact[i]; }
};

void solve(const FactPrecalc<MOD>& binom) {
	int n, k;
	cin >> n >> k;

	// DP[a][b]: number of ways to turn on b lights in an interval of length a, s.t. no two within k-1 of eachother are turned on
	// DP[a][b] = (a + (k-1) - b*(k-1) choose b)
	// ANS = \sum_{b = 1}^{n} b * DP[n][b] / binom(n, b)


	vector<ll> probs(n+1, 0);
	for (int b = 1; b < n; ++b) {
		ll ways = binom(n + k-1 - b * (k-1), b);
		if (ways == 0) break;
		ll mult = modPow(binom(n, b), MOD - 2, MOD);
		probs[b] = ways * mult % MOD;
	}

	ll res = 0;
	for (int b = 1; b < n; ++b) {
		ll sub = probs[b] - probs[b+1];
		if (sub < 0) sub += MOD;

		res = (res + (b + 1) * sub) % MOD;
	}

	res = (res % MOD);
	if (res < 0) res += MOD;
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	const int N = 1e5;
	FactPrecalc<MOD> binom(3*N);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve(binom);
}