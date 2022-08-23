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
const ll MOD = 998244353;

ll cnk[MAXN][MAXN];

int n, m, k;

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> m >> k;
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= i; ++j) {
			if (j == 0 || j == i)
				cnk[i][j] = 1;
			else
				cnk[i][j] = (cnk[i - 1][j - 1] + cnk[i - 1][j]) % MOD;
		}
	ll ans = cnk[n - 1][k];
	ans = (ans * m) % MOD;
	for (int i = 0; i < k; ++i)
		ans = (ans * (m - 1)) % MOD;
	cout << ans << "\n";
	return 0;
}