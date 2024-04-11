#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = (ll)1e9 + 7;
const int N = (int)1e6;
ll two_pow[N + 1];

ll modPow(ll a, ll b) {
	if (b & 1) return modPow(a, b ^ 1) * a % MOD;
	if (b == 0) return 1;
	return modPow(a*a % MOD, b >> 1);
}

void solve() {
	int n;
	cin >> n;
	
	// Person i wins IFF
	//	1. He's going left
	//	2. Nobody with a larger index wins
	//	3. [i/2, i-1] are all going right

	ll cur = 2;
	vector<ll> adds(n, 0), ways(n, 0);
	adds[n-1] = MOD - 2;

	for (int i = n-1; i >= 0; --i) {
		int j = (i + 1) / 2;
		ll mult = two_pow[j];
		ways[i] = (cur * two_pow[j]) % MOD;
		
		adds[j] = (adds[j] + MOD - cur) % MOD;
		cur = (cur + cur + adds[i]) % MOD;
	}

	// for (int i = 0; i < n; ++i) cout << ways[i] << ' '; cout << '\n';

	ll dv = modPow(two_pow[n], MOD - 2);
	for (int i = 0; i < n; ++i) cout << (ways[i] * dv) % MOD << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	two_pow[0] = 1;
	for (int n = 1; n <= N; ++n) two_pow[n] = (two_pow[n-1] * 2) % MOD;

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}