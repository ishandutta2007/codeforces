#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;
const int C = 2 * (int)1e5;

ll mAdd(ll a, ll b) {
	return (a + b >= MOD ? a + b - MOD : a + b);
}
ll mSub(ll a, ll b) {
	return (a >= b ? a - b : a + MOD - b);
}
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

class Fenwick {
	private:
		vector<ll> val;
	public:
		Fenwick(int n) : val(n+1, 0) {}

		// Adds v to index i
		void add(int i, ll v) {
			if (v < 0) v = MOD - v;
			for (++i; i < val.size(); i += i & -i) val[i] = mAdd(val[i], v);
		}

		// Calculates prefix sum up to index i
		ll get(int i) {
			ll res = 0;
			for (++i; i > 0; i -= i & -i) res = mAdd(res, val[i]);
			return res;
		}
		ll get(int a, int b) { return mSub(get(b), get(a-1)); }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	FactPrecalc binom(C, MOD);

	int n, m;
	cin >> n >> m;

	vector<int> cou(C + 1, 0);
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		++cou[a];
	}

	ll prod_inv_fact = 1;
	for (int i = 1; i <= C; ++i) prod_inv_fact = (prod_inv_fact * binom.inv(cou[i])) % MOD;

	Fenwick fenw(C + 1);
	for (int i = 1; i <= C; ++i) {
		if (cou[i] > 0) {
			ll v = binom[cou[i]] * binom.inv(cou[i] - 1) % MOD;
			fenw.add(i, v);
		}
	}

	bool can_eq = 1;
	ll res = 0;
	for (int i = 0; i < m; ++i) {
		int v;
		cin >> v;
		
		if (i < n && can_eq) {
			// Count those that equal at indices < i, and are smaller at i
			ll mult = fenw.get(v - 1) * binom[n-1 - i] % MOD;
			ll add = (mult * prod_inv_fact) % MOD;
			res = mAdd(res, add);

			if (cou[v] > 0) {
				ll val = binom[cou[v]] * binom.inv(cou[v] - 1) % MOD;
				prod_inv_fact = (prod_inv_fact * val) % MOD;
			
				fenw.add(v, mSub(0, val));
				--cou[v];
				if (cou[v] > 0) {
					val = binom[cou[v]] * binom.inv(cou[v] - 1) % MOD;
					fenw.add(v, val);
				}
			} else {
				can_eq = 0;
			}
		}
	}

	if (n < m && can_eq) res = mAdd(res, 1);
	cout << res << '\n';
}