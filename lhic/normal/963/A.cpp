#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;


const ll MOD = 1e9 + 9;

ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	ll n, a, b;
	int k;
	cin >> n >> a >> b >> k;
	ll x = 0;
	for (int i = 0; i < k; ++i) {
		char c;
		cin >> c;
		ll t;
		if (c == '+')
			t = 1;
		else
			t = -1;
		x = (x + t * pw(a, k - 1 - i) * pw(b, i) % MOD + MOD) % MOD;
	}
	a = pw(a, k);
	b = pw(b, k);
	ll t = (n + 1) / k;
	if (a == b) {
		cout << x * t % MOD * pw(a, t - 1) % MOD << "\n";
	}
	else {
		if (a < b)
			swap(a, b);
		cout << x * (pw(a, t) - pw(b, t) + MOD) % MOD * pw(a - b, MOD - 2) % MOD << "\n";
	}
	return 0;
}