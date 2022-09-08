#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

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


void solve(const FactPrecalc& fp, const vector<ll>& dp0, const vector<ll>& dp1) {
	int n;
	cin >> n;

	// 	|p_i - p^{-1}_i| <= 1		for all i
	// <=>	|p_{p_i} - p^{-1}_{p_i}| <= 1	for all i
	// <=>  |p_{p_i} - i| <= 1		for all i

	ll res = 0;
	for (int y = 0; 2*y <= n; ++y) {
		int x = n-2*y;
		ll add = (dp0[x] * dp1[y] % MOD) * fp(n-y, y) % MOD;
		res = (res + add) % MOD;
	}
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	const int N = 3 * (int)1e5;
	FactPrecalc fp(N + 100, MOD);

	vector<ll> dp0(N + 1, 1), dp1(N + 1, 0);
	dp1[0] = 1;

	for (int i = 2; i <= N; ++i) dp0[i] = (dp0[i-1] + (i-1)*dp0[i-2]) % MOD;
	for (int i = 2; i <= N; i += 2) dp1[i] = (2 * (i-1) * dp1[i-2]) % MOD;

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve(fp, dp0, dp1);
}