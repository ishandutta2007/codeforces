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

const int MAXN = 1600;

vector<int> vv;

int a[MAXN];

int n, s, m, k;
int go[MAXN];
int sm[MAXN];
int dp[MAXN][MAXN];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> s >> m >> k;
	for (int i = 0; i < n; ++i)
		cin >> a[i], vv.push_back(a[i]);
	sort(ALL(vv));
	vv.resize(unique(ALL(vv)) - vv.begin());
	for (int i = 0; i < n; ++i)
		go[i] = -1;
	for (int i = 0; i < s; ++i) {
		int l, r;
		cin >> l >> r;
		--l;
		for (int i = l; i < r; ++i)
			go[i] = max(go[i], r);
	}
	int l = -1;
	int r = vv.size();
	while (r - l > 1) {
		int mid = (l + r) >> 1;
		memset(dp, 0, sizeof(dp));
		sm[0] = 0;
		for (int i = 0; i < n; ++i)
			sm[i + 1] = sm[i] + (a[i] <= vv[mid]);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j <= s; ++j) {
				dp[i + 1][j] = max(dp[i][j], dp[i + 1][j]);
				if (j < s && go[i] > i)
					dp[go[i]][j + 1] = max(dp[go[i]][j + 1], dp[i][j] + sm[go[i]] - sm[i]);
			}
		if (dp[n][m] >= k)
			r = mid;
		else
			l = mid;
	}
	if (r == vv.size())
		cout << -1 << "\n";
	else
		cout << vv[r] << "\n";
	return 0;
}