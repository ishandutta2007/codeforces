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
typedef long long llong;
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

const int MAXN = 120000;
const int INF = 1e9;

int ans[MAXN];

void go(int *a, int n, int *b) {
	for (int i = 0; i <= n; ++i)
		ans[i] = INF;
	ans[0] = 0;
	for (int i = 0; i < n; ++i) {
		int x = upper_bound(ans, ans + n + 1, a[i]) - ans;
		ans[x] = a[i];
		b[i] = x;
	}
}

int n, m;
int ad[MAXN];
int a[MAXN];
int dp1[MAXN];
int dp2[MAXN];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		int l, r;
		cin >> l >> r;
		--l, --r;
		++ad[l];
		--ad[r + 1];
	}
	int now = 0;
	for (int i = 0; i < m; ++i)
		now += ad[i], a[i] = now;
	go(a, m, dp1);
	reverse(a, a + m);
	go(a, m, dp2);
	reverse(a, a + m);
	reverse(dp2, dp2 + m);
	int ans = 0;
	for (int i = 0; i < m; ++i)
		ans = max(ans, dp1[i] + dp2[i] - 1);
	cout << ans << "\n";
	return 0;
}