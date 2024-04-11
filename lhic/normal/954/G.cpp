#ifndef BZ
#ifndef __clang__
#pragma GCC optimize "-O3"
#endif
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

const int MAXN = 510000;

int n, R;
ll k;
ll a[MAXN];
ll b[MAXN];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> R >> k;
	R = min(R, n - 1);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	ll l = 0;
	ll r = 2e18;
	while (r - l > 1) {
		ll mid = (l + r) >> 1;
		ll cur = 0;
		copy(a, a + n, b);
		for (int i = 0; i < R; ++i)
			cur += b[i];
		ll ans = 0;
		for (int i = 0; i < n; ++i) {
			if (i + R < n)
				cur += b[i + R];
			if (cur < mid) {
				ll go = mid - cur;
				b[min(n - 1, i + R)] += go;
				ans += go;
				cur += go;
				if (ans > k)
					break;
			}
			if (i - R >= 0)
				cur -= b[i - R];
		}
		if (ans <= k)
			l = mid;
		else
			r = mid;
	}
	cout << l << "\n";
	return 0;
}