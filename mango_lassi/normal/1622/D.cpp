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


void solve() {
	int n, k;
	cin >> n >> k;
	FactPrecalc binom(n, MOD);

	string str;
	cin >> str;

	vector<int> inds = {-1};
	for (int i = 0; i < n; ++i) {
		if (str[i] == '1') inds.push_back(i);
	}
	inds.push_back(n);
	int m = (int)inds.size();

	ll res = 0;
	if (k > 0 && m >= k + 2) {
		ll tot = 0;
		for (int cou = k; cou >= k - 1; --cou) {
			int dif = k - cou;
			for (int a = 1 + dif; a + cou < m - dif; ++a) {
				int b = a + cou - 1;
				int len = inds[b+1] - inds[a-1] - 1;
				
				ll val = binom(len, cou);
				ll mult = (dif & 1) ? MOD - 1 : 1;
				// cerr << "[" << inds[a-1] + 1 << ' ' << inds[b+1]-1 << "]: " << mult << '\n';
				tot = (tot + mult) % MOD;
				res = (res + val * mult) % MOD;
			}
		}

		// If it's position is good enough,
		//	It has dif + 1 overlapping intervals of length k
		//	and dif + 2 overlapping intervals of length k-1
		res = (res + MOD - tot + 1) % MOD; // Subtract overcounting case where nothing moves
	} else {
		res = 1;
	}
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
	for (int ti = 0; ti < t; ++ti) solve();
}