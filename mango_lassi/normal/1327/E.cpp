#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

constexpr ll modPow(ll a, ll b, ll c) {
	return (b&1) ? (a * modPow(a, b-1, c) % c)
		: (b ? modPow(a*a % c, b/2, c) : 1);
}

const int N = 2 * (int)1e5;
ll tp[N+3];
ll inv[N+3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	tp[0] = 1;
	for (int i = 1; i <= n+2; ++i) tp[i] = (tp[i-1] * 10) % MOD;

	inv[0] = 1;
	inv[1] = modPow(10, MOD - 2, MOD);
	for (int i = 2; i <= n+2; ++i) inv[i] = (inv[i-1] * inv[1]) % MOD;

	for (int m = 1; m <= n; ++m) {
		// Number of segments of length m = 10^n * Expected number of segments of length m
		// = sum over i, probability that a segment of length exactly m starts from i
		// = 10 * (1/10^m) * 9/10 * 9/10 (ends must have different colors)

		ll base = 10 * ((tp[n] * inv[m]) % MOD) % MOD;
		ll res = 0;

		// Neither endpoint at end of number
		ll cou0 = max(0, n-m-1);
		ll mult0 = base * ((9 * 9 * inv[2]) % MOD) % MOD;
		res = (res + cou0 * mult0) % MOD;

		// One endpoint at end of number
		ll cou1 = (n != m ? 2 : 0);
		ll mult1 = base * ((9 * inv[1]) % MOD) % MOD;
		res = (res + cou1 * mult1) % MOD;

		// Both endpoints at end of number
		ll cou2 = (n == m ? 1 : 0);
		res = (res + cou2 * base) % MOD;

		cout << res << ' ';
	}
	cout << '\n';
}