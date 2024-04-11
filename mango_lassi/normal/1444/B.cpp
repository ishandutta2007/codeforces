#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

constexpr ll modPow(ll a, ll b, ll c) {
	return (b&1) ? (a * modPow(a, b-1, c) % c)
		: (b ? modPow(a*a % c, b/2, c) : 1);
}

template<int P>
struct FactPrecalc {
	private:
		vector<int> fact;
		vector<int> inv_fact;
	public:
		FactPrecalc(int n) : fact(n+1, 1), inv_fact(n+1, 1) {
			for (int i = 2; i <= n; ++i) fact[i] = (ll)fact[i-1] * i % P;
			inv_fact[n] = modPow(fact[n], P-2, P);
			for (int i = n-1; i >= 0; --i) inv_fact[i] = (ll)inv_fact[i+1] * (i+1) % P;
		}
		const ll operator()(int a, int b) const {
			if (a < b) return 0;
			ll div = (ll)inv_fact[a-b] * inv_fact[b] % P;
			return fact[a] * div % P;
		}
		const ll operator[](int i) const { return fact[i]; }
		ll inv(int i) const { return inv_fact[i]; }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	// Assume the values are 1, ..., 2n
	// How many times is value k subtracted?
	// 	- When it is in the increasing list?
	//		-> Say the increasing list has A values > k, and
	//			the decreasing list has B values > k. Then
	//			we must have A + B >= n
	//	- When it is in the decreasing list?
	//		-> Say the increasing list has A values > k, and 
	//			the decreasing list has B values > k. Then
	//			we must have A + B >= n
	//	-> Numbers 1, ..., n are always subtracted, numbers n+1, ..., 2n are never subtracted!

	vector<ll> vals(2*n);
	for (ll& v : vals) cin >> v;
	sort(vals.begin(), vals.end());

	ll sum = 0;
	for (int i = 0; i < n; ++i) sum -= vals[i];
	for (int i = n; i < 2*n; ++i) sum += vals[i];
	sum %= MOD;
	if (sum < 0) sum += MOD;

	FactPrecalc<MOD> fp(2*n);
	ll mult = fp(2*n, n);
	sum = (sum * mult) % MOD;

	cout << sum << '\n';
}