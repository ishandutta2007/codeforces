#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// This is just the same as counting the number of ascending arrays of length 2m
	// The answer is (n+2m-1 choose n-1)

	int n, m;
	cin >> n >> m;

	FactPrecalc<MOD> fact(n+2*m);
	cout << fact(n+2*m-1, n-1) << '\n';
}