#include <bits/stdc++.h>

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
const ll MOD = 1e9 + 7;

void add(ll &a, ll b) {
	a = (a + b) % MOD;
}
ll dp[3][MAXN][11];
ll tmp[3][11];

int was[MAXN];
vector<int> eds[MAXN];
int n;
ll k;
int x;
ll m;

void dfs1(int v) {
	was[v] = 1;
	dp[0][v][0] = k - 1;
	dp[1][v][1] = 1;
	dp[2][v][0] = m - k;
	for (int u: eds[v]) {
		if (was[u])
			continue;
		dfs1(u);
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j <= x; ++j)
				tmp[i][j] = 0;
		for (int i = 0; i <= x; ++i) {
			for (int j = 0; i + j <= x; ++j) {
				add(tmp[0][i + j], dp[0][v][i] * (dp[0][u][j] + dp[1][u][j] + dp[2][u][j]));
				add(tmp[1][i + j], dp[1][v][i] * (dp[0][u][j]));
				add(tmp[2][i + j], dp[2][v][i] * (dp[0][u][j] + dp[2][u][j]));
			}
		}
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j <= x; ++j)
				dp[i][v][j] = tmp[i][j];
	}
}

int main() {
	scanf("%d%lld", &n, &m);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	scanf("%lld%d", &k, &x);
	dfs1(0);
	ll ans = 0;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j <= x; ++j)
			add(ans, dp[i][0][j]);
	cout << ans << "\n";
	return 0;
}