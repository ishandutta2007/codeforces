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
const int MAXN = 1e6 + 100;

int n;
vector<int> eds[MAXN];
ll a[MAXN];
int p[MAXN];
ll sm[MAXN];

void dfs1(int v) {
	sm[v] = a[v];
	for (int u: eds[v]) {
		dfs1(u);
		sm[v] += sm[u];
	}
}
int cc[MAXN];
ll dp[MAXN];
const ll MOD = 1e9 + 7;

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 1; i < n; ++i) {
		cin >> p[i];
		--p[i];
		eds[p[i]].push_back(i);
	}
	dfs1(0);
	for (int i = 0; i < n; ++i) {
		ll g = __gcd(sm[0], sm[i]);
		g = sm[0] / g;
		if (g <= n)
			++cc[g];
	}
	for (int i = n; i >= 1; --i) {
		for (int j = 2 * i; j <= n; j += i)
			cc[j] += cc[i];
	}
	dp[1] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 2 * i; j <= n; j += i)
			if (cc[j] == j)
				dp[j] = (dp[j] + dp[i]) % MOD;
	}
	ll ans = 0;
	for (int i = 1; i <= n; ++i)
		ans = (ans + dp[i]) % MOD;
	cout << ans << "\n";
	return 0;
}