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
const int MAXN = 320000;

int n, s;
int a[MAXN];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> s;
	rep(i, 0, n) {
		cin >> a[i];
	}
	sort(a, a + n);
	ll ans = 0;
	int x = n / 2;
	for (int i = 0; i < x; ++i)
		if (a[i] > s)
			ans += a[i] - s;
	ans += abs(a[x] - s);
	for (int i = x + 1; i < n; ++i)
		if (a[i] < s)
			ans += s - a[i];
	cout << ans << "\n";
	return 0;
}