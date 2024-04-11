#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

ll modInv(ll a, ll b = MOD - 2) {
	if (b & 1) return a * modInv(a, b-1) % MOD;
	if (b == 0) return 1;
	return modInv(a*a % MOD, b / 2);
}

const int N = 2 * (int)1e5;
ll fact[N+1];
ll inv_fact[N+1];

ll choose(int a, int b) {
	if (a < b) return 0;
	ll dv = inv_fact[b] * inv_fact[a-b] % MOD;
	return fact[a] * dv % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	fact[0] = 1;
	for (int i = 1; i <= N; ++i) fact[i] = (fact[i-1] * i) % MOD;
	for (int i = 0; i <= N; ++i) inv_fact[i] = modInv(fact[i]);

	int n;
	ll k;
	cin >> n >> k;
	
	vector<ll> hs(n);
	for (int i = 0; i < n; ++i) cin >> hs[i];

	int cou = 0;
	ll mult = 1;
	for (int i = 0; i < n; ++i) {
		if (hs[i] != hs[(i+1)%n]) {
			++cou;
		} else {
			mult = (mult * k) % MOD;
		}
	}

	//  4         1
	//  3       1
	//  2     1   4
	//  1   1   3
	//  0 1   2   6
	// -1   1   3
	// -2     1   4
	// -3       1
	// -4         1
	//    0 1 2 3 4

	// If ans[i] == ans[i+1], val[i] doesn't matter, multiply answer by k
	// If ans[i] != ans[i+1], there are k-2 ways to add 0, one way to add 1 and one way to add -1.
	// "cou" positions each

	ll res = 0;
	const ll two_inv = modInv(2);
	for (int c = cou; c > 0; --c) {
		ll add = modInv(2, c);
		if (c % 2 == 0) add -= choose(c, c/2);
		add = add * two_inv % MOD;
		if (add < 0) add += MOD;

		ll tmp = mult * choose(cou, c) % MOD;
		res += tmp * add % MOD;
		mult = (mult * (k-2)) % MOD;
	}
	res %= MOD;
	cout << res << '\n';
}