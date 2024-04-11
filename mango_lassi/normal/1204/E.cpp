#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 998244853;

const int N = 2000;
ll fact[2*N+1];
ll inv[2*N+1];

ll modPow(ll a, ll b) {
	ll res = 1;
	for (; b > 0; b /= 2) {
		if (b & 1) res = (res * a) % MOD;
		a = (a * a) % MOD;
	}
	return res;
}
ll choose(ll a, ll b) {
	if (b < 0) return 0;
	ll dv = inv[a-b] * inv[b] % MOD;
	ll res = fact[a] * dv % MOD;
	return res;
}
ll calc(ll a, ll b) {
	ll res = choose(a+b, b) - choose(a+b, min(a, b) - 1);
	return (res < 0 ? res + MOD : res);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	fact[0] = 1;
	for (int i = 1; i <= n+m; ++i) fact[i] = (fact[i-1] * i) % MOD;
	for (int i = 0; i <= n+m; ++i) inv[i] = modPow(fact[i], MOD-2);

	// 2. Calc answer
	ll res = 0;
	for (int i = 1; i <= n+m; ++i) {
		for (int s = (i & 1); s <= i; s += 2) {
			// Count terms where the last position with maximum prefix sum s is i
			int a = (i+s) / 2;
			int b = i - a;
			int ra = n-a;
			int rb = m-b;
			if (ra < 0 || rb < 0) continue;
			
			ll mult = s * calc(a, b) % MOD;
			if (i == n+m) {
				res = (res + mult) % MOD;
			} else if (ra < rb) {
				res = (res + mult * calc(ra, rb-1)) % MOD;
			}
		}
	}
	cout << res << '\n';
}