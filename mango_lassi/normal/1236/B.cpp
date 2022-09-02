#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

ll modPow(ll a, ll b) {
	if (b & 1) return a * modPow(a, b - 1) % MOD;
	if (b == 0) return 1;
	return modPow(a*a % MOD, b / 2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll n, m;
	cin >> n >> m;
	// RES = 2^{nm} - (n choose 1) 2^{(n-1)m} + (n choose 2) 2^{(n-2)m} ... +- (n choose n) 2^{0m}
	// = (2^{m} - 1)^{n}
	ll res = modPow(2, m) - 1;
	res = modPow(res, n);
	if (res < 0) res += MOD;
	cout << res << '\n';
}