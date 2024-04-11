#include <iostream>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

const int M = 2 * (int)1e5;
int bs[M];

ll modPow(ll a, ll b) {
	if (b == 0) return 1;
	if (b & 1) return (a * modPow(a, b-1)) % MOD;
	return modPow((a*a) % MOD, b / 2);
}

int main() {
	int n, m, c;
	cin >> n >> m >> c;
	for (int i = 0; i < m; ++i) cin >> bs[i];

	// Equivalence classes are just binary strings.
	int cent = n - 2 * bs[m-1];
	for (int i = m-1; i > 0; --i) bs[i] -= bs[i-1];
	// How many different strings of length k exist? Answer is of course 
	ll res = modPow(c, cent);
	for (int i = 0; i < m; ++i) {
		ll ways = modPow(c, bs[i]);
		ways = ways + (ways * (ways - 1) / 2) % MOD;
		res = (res * ways) % MOD;
	}
	if (res < 0) res += MOD;
	cout << res << '\n';
}