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

int n, m, k;
int dp[510];
int dp2[510];
int go[510];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> m >> k;

	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		vector<int> vv;
		for (int j = 0; j < m; ++j)
			if (s[j] == '1')
				vv.push_back(j);
		for (int j = 0; j <= k; ++j)
			go[j] = m;
		for (int j = vv.size(); j <= k; ++j)
			go[j] = 0;
		for (int j = 0; j < vv.size(); ++j)
			for (int l = j; l < vv.size(); ++l) {
				go[vv.size() - 1 - l + j] = min(go[vv.size() - 1 - l + j], vv[l] - vv[j] + 1);
			}
		for (int j = 0; j <= k; ++j)
			dp2[j] = n * m;
		for (int j = 0; j <= k; ++j)
			for (int l = 0; l + j <= k; ++l) {
				dp2[j + l] = min(dp2[j + l], dp[j] + go[l]);
			}
		for (int j = 0; j <= k; ++j)
			dp[j] = dp2[j];
	}
	int ans = dp[0];
	for (int i = 0; i <= k; ++i)
		ans = min(ans, dp[i]);
	
	cout << ans << "\n";
	return 0;
}