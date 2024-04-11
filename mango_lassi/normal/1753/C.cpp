#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

ll modPow(ll a, ll b) {
	if (b & 1) return modPow(a, b ^ 1) * a % MOD;
	if (b == 0) return 1;
	return modPow(a*a % MOD, b >> 1);
}

void solve() {
	int n;
	cin >> n;

	vector<int> str(n);
	for (int& c : str) cin >> c;

	int zc = 0;
	for (int c : str) zc += (c == 0);

	int oc = n - zc;
	ll wa = 0;
	for (int i = 0; i < zc; ++i) wa += (str[i] == 1);

	ll res = 0;
	ll binom = ((ll)n * (n - 1) / 2) % MOD;
	ll dv = modPow(binom, MOD - 2);
	for (; wa > 0; --wa) {
		ll prob = (wa * wa % MOD) * dv % MOD;
		
		// Expected number of attempts until event with probability p happens = x
		// -> x = 1 + (1 - p)x
		// -> x = 1 / p

		res = (res + modPow(prob, MOD - 2)) % MOD;
	}
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}