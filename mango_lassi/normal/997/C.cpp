#include <iostream>
using namespace std;

const int MOD = 998244353;
typedef long long ll;
const int N = (int)1e6;

ll modpow(ll a, ll b) {
	if (b & 1) return (a * modpow(a, b-1)) % MOD;
	if (b == 0) return 1;
	return modpow((a*a)%MOD, b/2);
}

ll inv(ll v) {
	return modpow(v, MOD-2);
}

int fact[N + 1];
int inv_fact[N + 1];
int choose[N+1];
ll n;

void precalc() {
	fact[0] = 1;
	inv_fact[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fact[i] = ((ll)fact[i-1] * i) % MOD;
		inv_fact[i] = inv(fact[i]);
	}
	for (int i = 0; i <= n; ++i) {
		ll div = ((ll)inv_fact[i] * inv_fact[n-i]) % MOD;
		choose[i] = (fact[n] * div) % MOD;
	}
}

int main() {

	// Inclusion-exclusion!
	//   -ANS
	// = BASE + \sum{i = 1 to n} \sum{j = 1 to n} 3 * (-1)^{i+j} (n choose i) (n choose j) 3^((n-i)(n-j))
	// = BASE + \sum{i = 1 to n} 3 * -1^(i) (n choose i) (\sum{j = 0 to n} (n choose j) (-1)^j (3^(n-i))^(n-j)) - 3^((n-i)n))
	// = BASE + \sum{i = 1 to n} 3 * -1^(i) (n choose i) (3^(n-i) - 1)^n - 3^((n-i)n)

	cin >> n;
	precalc();

	// Calc the sum
	ll res = 0;
	for (int i = 1; i <= n; ++i) {
		ll mult = (3 * (i % 2 == 0 ? 1 : -1) * (ll)choose[i]) % MOD;
		ll val = (mult * (modpow(modpow(3, n-i)-1, n) - modpow(3, (n-i)*n))) % MOD;
		res += val;
	}
	
	// Calc the base
	for (int i = 1; i <= n; ++i) {
		ll mult = (2 * (i % 2 == 0 ? 1 : -1) * (ll)choose[i]) % MOD;
		ll pows = (modpow(3, i) * modpow(3, n * (n-i))) % MOD;
		res += (mult * pows) % MOD;
	}
	
	// Negate and output
	res = (MOD + (-res % MOD)) % MOD;
	cout << res << '\n';
}