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

vector<int> eds[120000];
int was[120000];
int dp[12000];
int dp2[12000];
int w[120000];
int b[120000];
int W;
int n, m;
vector<int> vv;

void dfs1(int v) {
	was[v] = 1;
	vv.push_back(v);
	for (int u: eds[v])
		if (!was[u])
			dfs1(u);
}

int main() {
	cin >> n >> m >> W;
	for (int i = 0; i < n; ++i)
		cin >> w[i];
	for (int i = 0; i < n; ++i)
		cin >> b[i];
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	for (int i = 0; i < n; ++i) {
		if (was[i])
			continue;
		vv.clear();
		dfs1(i);
		int smw = 0;
		int smb = 0;
		for (int i = 0; i <= W; ++i)
			dp2[i] = dp[i];
		for (int i: vv) {
			smw += w[i];
			smb += b[i];
			for (int j = 0; j <= W - w[i]; ++j)
				dp2[j + w[i]] = max(dp2[j + w[i]], dp[j] + b[i]);
		}
		for (int j = 0; j <= W - smw; ++j)
			dp2[j + smw] = max(dp2[j + smw], dp[j] + smb);
		for (int i = 0; i <= W; ++i)
			dp[i] = dp2[i];
	}
	cout << dp[W] << "\n";
	return 0;
}