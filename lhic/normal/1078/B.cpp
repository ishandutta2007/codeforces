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

const ll INF = 1e9;

ll dp[101][10020];

int cc[1000];

int n;

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		++cc[x];
	}
	int cur = 0;
	int sum = 0;
	int df = 0;
	dp[0][0] = 1;
	for (int i = 1; i <= 100; ++i) {
		if (cc[i] == 0)
			continue;
		++df;
		for (int k = cur; k >= 0; --k)
			for (int j = 0; j <= sum; ++j) {
				for (int l = 1; l <= cc[i]; ++l) {
					dp[k + l][j + l * i] = min(INF, dp[k + l][j + l * i] + dp[k][j]);
				}
			}
		cur += cc[i];
		sum += cc[i] * i;
	}
	if (df <= 2) {
		cout << n << "\n";
		return 0;
	}
	int ans = 0;
	for (int i = 1; i <= 100; ++i) {
		if (!cc[i])
			continue;
		int now = 0;
		while (now < cc[i] && dp[now + 1][(now + 1) * i] == 1)
			++now;
		ans = max(ans, now);
	}
	cout << ans << "\n";
	return 0;
}