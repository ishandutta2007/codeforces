#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;
const int N = 1e5;

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
		ll operator()(int a, int b) const {
			if (a < b) return 0;
			ll div = (ll)inv_fact[a-b] * inv_fact[b] % P;
			return fact[a] * div % P;
		}
		ll operator[](int i) const { return fact[i]; }
		ll inv(int i) const { return inv_fact[i]; }
};

void solve(const FactPrecalc<MOD>& binom) {
	int n;
	cin >> n;

	string str;
	cin >> str;

	int zeros = 0, pairs = 0;
	for (int i = 0; i < n; ++i) {
		if (str[i] == '0') ++zeros;
		else if (i + 1 < n && str[i] == '1' && str[i+1] == '1') {
			++pairs;
			++i;
		}
	}
	cout << binom(zeros + pairs, pairs) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	FactPrecalc<MOD> binom(N + 10);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve(binom);
}