#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()

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
const int MAXN = 120;

int n, m, k;
int a[MAXN][MAXN];
int dp[MAXN];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> a[j][i];
	swap(n, m);
	pair<int, int> ans = {0, 0};
	for (int i = 0; i < n; ++i) {
		pair<int, int> now = {0, 0};
		dp[0] = 0;
		for (int j = 0; j < m; ++j) {
			dp[j + 1] = dp[j] + a[i][j];
		}
		for (int i = 0; i < m; ++i) {
			int r = min(m, i + k);
			pair<int, int> tmp = {dp[r] - dp[i], dp[i]};
			if (tmp.first > now.first || (tmp.first == now.first && tmp.second < now.second))
				now = tmp;
		}
		ans.first += now.first;
		ans.second += now.second;
	}
	cout << ans.first << " " << ans.second << "\n";
	return 0;
}