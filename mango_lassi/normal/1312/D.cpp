#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

constexpr ll modPow(ll a, ll b, ll c) {
	return (b&1) ? (a * modPow(a, b-1, c) % c)
		: (b ? modPow(a*a % c, b/2, c) : 1);
}

// Struct for precalculating factorials, inverse factorials and nCr in O(n) precalculation and O(1) queries
// For large nCr's with small modulo: https://en.wikipedia.org/wiki/Lucas%27s_theorem
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
};

const int N = 2 * (int)1e5;
int pows[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	pows[0] = 1;
	for (int i = 1; i < N; ++i) pows[i] = 2 * pows[i-1] % MOD;

	FactPrecalc<MOD> fact(N+1);

	int n, m;
	cin >> n >> m;

	ll res = fact(m, n-1);
	if (n >= 2) res = (res * (n-2)) % MOD;
	if (n >= 3) res = (res * pows[n-3]) % MOD;
	cout << res << '\n';
}