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


/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/
const int MAXN = 310000;

int n;
int a[MAXN];
int sm[MAXN];
int cc[2];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	for (int i = 0; i < n; ++i) {
		ll x;
		cin >> x;
		while (x) {
			if (x % 2 == 1)
				++a[i];
			x /= 2;
		}
	}
	sm[0] = 0;
	for (int i = 0; i < n; ++i)
		sm[i + 1] = (sm[i] ^ (a[i] % 2));
	ll ans = 0;
	for (int i = n - 1; i >= 0; --i) {
		int mx = 0;
		int cs = 0;
		for (int j = i; j < n && j < i + 64; ++j) {
			mx = max(mx, a[j]);
			cs += a[j];
			if ((cs & 1) == 0 && cs >= 2 * mx)
				++ans;
		}
		if (i + 65 <= n)
			++cc[sm[i + 65]];
		ans += cc[sm[i]];
	}
	cout << ans << "\n";
	return 0;
}