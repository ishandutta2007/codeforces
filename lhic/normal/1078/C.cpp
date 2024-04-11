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
const ll MOD = 998244353;

int n;

vector<int> eds[MAXN];

ll dp[MAXN][3];

void dfs1(int v, int p) {
	dp[v][0] = 1;
	for (int u: eds[v]) {
		if (u == p)
			continue;
		dfs1(u, v);
		dp[v][2] = (dp[v][2] * (dp[u][0] + 2 * dp[u][2]) + dp[v][1] * (dp[u][0] + dp[u][1]) + dp[v][0] * (dp[u][0] + dp[u][1])) % MOD;
		dp[v][1] = (dp[v][1] * (dp[u][0] + 2 * dp[u][2]) + dp[v][0] * dp[u][2]) % MOD;
		dp[v][0] = (dp[v][0] * (dp[u][0] + dp[u][2])) % MOD;
	}
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	dfs1(0, -1);
	ll ans = (dp[0][0] + dp[0][2]) % MOD;
	cout << ans << "\n";
	return 0;
}