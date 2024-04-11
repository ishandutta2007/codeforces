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
const int MAXN = 2100;

int n, m;
ll a[MAXN];
ll aa[MAXN];
ll b[MAXN];
ll bb[MAXN];
ll x;

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int j = 0; j < m; ++j)
		cin >> b[j];
	cin >> x;
	for (int i = 1; i <= n; ++i)
		aa[i] = x + 1;
	for (int i = 1; i <= m; ++i)
		bb[i] = x + 1;
	for (int i = 0; i < n; ++i) {
		ll sum = 0;
		for (int j = i; j < n; ++j) {
			sum += a[j];
			aa[j - i + 1] = min(aa[j - i + 1], sum);
		}
	}
	for (int i = 0; i < m; ++i) {
		ll sum = 0;
		for (int j = i; j < m; ++j) {
			sum += b[j];
			bb[j - i + 1] = min(bb[j - i + 1], sum);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			if (aa[i] * bb[j] <= x)
				ans = max(ans, i * j);
		}
	cout << ans << "\n";
	return 0;
}