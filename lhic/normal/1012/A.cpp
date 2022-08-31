#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO

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
const int MAXN = 210000;

ll a[MAXN];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	int n;
	cin >> n;
	for (int i = 0; i < 2 * n; ++i) 
		cin >> a[i];
	sort(a, a + 2 * n);
	ll ans = (a[n - 1] - a[0]) * (a[2 * n - 1] - a[n]);
	for (int i = 1; i < n; ++i) {
		ans = min(ans, (a[2 * n - 1] - a[0]) * (a[i + n - 1] - a[i]));
	}
	cout << ans << "\n";
	return 0;
}