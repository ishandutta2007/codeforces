#include <bits/stdc++.h>

typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1e9 + 7;

ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}

const int MX = 2100000;

ll fc[MX];
ll bfc[MX];
ll cg[MX];


ll cnk(int n, int k) {
	if (k > n)
		return 0;
	return fc[n] * bfc[k] % MOD * bfc[n - k] % MOD;
}

int n, k;

int main() {
	cin >> n >> k;
	if (n <= k + 1) {
		cout << 0 << "\n";
		return 0;
	}
	fc[0] = 1;
	for (int i = 1; i < MX; ++i)
		fc[i] = (fc[i - 1] * i) % MOD;
	bfc[MX - 1] = pw(fc[MX - 1], MOD - 2);
	for (int i = MX - 2; i >= 0; --i)
		bfc[i] = (bfc[i + 1] * (i + 1)) % MOD;

	for (int i = 0; i <= k; ++i)
		cg[i] = fc[i];
	for (int i = k + 1; i <= n; ++i) {
		cg[i] = cg[i - 1] * i - cnk(i - 1, k) * fc[k] % MOD * cg[i - k - 1] % MOD + MOD;
		cg[i] %= MOD;
	}
	ll ans = 0;
	for (int i = k + 1; i <= n; ++i) {
		ll cb = cnk(i - 1, k) * fc[k] % MOD * cg[i - k - 1] % MOD;
		cb = cb * cnk(n - 1, i) % MOD * fc[n - i] % MOD;
		ans = (ans + cb) % MOD;
	}
	cout << ans << "\n";
	return 0;
}