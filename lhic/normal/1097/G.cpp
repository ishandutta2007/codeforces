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

const ll MOD = 1e9 + 7;

/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/


const int MAXN = 120000;
const int MX = 205;
int n, k;

vector<int> eds[MAXN];

int sz[MAXN];

void dfs0(int v, int p) {
	vector<int> vv;
	for (int u: eds[v]) {
		if (u != p)
			vv.push_back(u);
	}
	eds[v] = vv;
	sz[v] = 1;
	for (int u: eds[v]) {
		dfs0(u, v);
		sz[v] += sz[u];
	}
	sort(eds[v].begin(), eds[v].end(), [] (int a, int b) { return sz[a] > sz[b]; });
}

ll dp[MAXN][MX];

ll tmp[MX];
ll tmp2[MX];

void mv(ll *a) {
	for (int i = MX - 1; i > 0; --i)
		a[i] = (a[i] + i * a[i - 1]) % MOD;
}

ll cnk[MX][MX];

void mult(ll *a, ll *b, ll *c) {
	int sza = 0, szb = 0;
	for (int i = 0; i < MX; ++i)
		if (a[i] != 0)
			sza  = i;
	for (int i = 0; i < MX; ++i)
		if (b[i] != 0)
			szb = i;
	if (sza < szb)
		swap(sza, szb), swap(a, b);
	for (int i = 0; i < MX; ++i)
		c[i] = 0;
	for (int i = 0; i <= sza; ++i)
		for (int j = 0; j + i < MX && j <= szb; ++j) {
			c[i + j] = (c[i + j] + a[i] * b[j] % MOD * cnk[i + j][i]) % MOD;
		}
}

void dfs1(int v) {
	dp[v][0] = 2;
	for (int u: eds[v]) {
		dfs1(u);
		for (int i = 0; i < MX; ++i)
			tmp[i] = dp[u][i];
		tmp[0] = (tmp[0] - 1 + MOD) % MOD;
		mv(tmp);
		tmp[0] = (tmp[0] + 1) % MOD;
		mult(dp[v], tmp, tmp2);
		for (int i = 0; i < MX; ++i)
			dp[v][i] = tmp2[i];
	}
}

ll aans[MX];

void dfs2(int v) {
	dp[v][0] = (dp[v][0] + MOD - 1) % MOD;
	for (int u: eds[v]) {
		for (int i = 0; i < MX; ++i)
			tmp[i] = dp[u][i];
		tmp[0] = (tmp[0] - 1 + MOD) % MOD;
		mv(tmp);
		for (int i = 0; i < MX; ++i)
			dp[v][i] = (dp[v][i] - tmp[i] + MOD) % MOD;
	}
	for (int i = 0; i < MX; ++i)
		aans[i] = (aans[i] + dp[v][i]) % MOD;
	for (int u: eds[v])
		dfs2(u);
}

ll s[MX][MX];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	for (int i = 0; i < MX; ++i)
		for (int j = 0; j < MX; ++j) {
			if (j == 0 || j == i)
				cnk[i][j] = 1;
			else if (j > i)
				cnk[i][j] = 0;
			else
				cnk[i][j] = (cnk[i - 1][j] + cnk[i - 1][j - 1]) % MOD;
		}
	cin >> n >> k;
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	dfs0(0, -1);
	dfs1(0);
	dfs2(0);
	s[0][0] = 1;
	for (int n = 1; n < MX; ++n)
		for (int k = 1; k <= n; ++k)
			s[n][k] = (k * s[n - 1][k] + s[n - 1][k - 1]) % MOD;
	ll ans = 0;
	for (int i = 0; i <= k; ++i)
		ans = (ans + s[k][i] * aans[i]) % MOD;
	cout << ans << "\n";
	return 0;
}