#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

const ll MOD = ll(1e9) + 7;

ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}

const int MX = (int)1e6 + 100;

int bb[MX];
vector<int> primes;
ll fc[MX];
ll bfc[MX];

ll cnk(int n, int k) {
	if (k > n)
		return 0;
	return fc[n] * bfc[k] % MOD * bfc[n - k] % MOD;
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	fc[0] = 1;
	for (int i = 1; i < MX; ++i)
		fc[i] = (fc[i - 1] * i) % MOD;
	bfc[MX - 1] = pw(fc[MX - 1], MOD - 2);
	for (int i = MX - 2; i >= 0; --i) {
		bfc[i] = (bfc[i + 1] * (i + 1)) % MOD;
	}
	for (int i = 1; i < MX; ++i)
		bb[i] = i;
	for (int i = 2; i < MX; ++i) {
		if (bb[i] == i)
			primes.push_back(i);
		for (int x: primes) {
			if (x > bb[i] || x * i >= MX)
				break;
			bb[x * i] = x;
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int x, y;
		cin >> x >> y;
		ll ans = 1;
		while (x != 1) {
			int cnt = 0;
			int go = bb[x];
			while (x % go == 0)
				x /= go, ++cnt;
			ans = (ans * cnk(cnt + y - 1, cnt)) % MOD;
		}
		cout << ans * pw(2, y - 1) % MOD << "\n";
	}
	return 0;
}