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

bool check(int a, int b, int c, int d) {
	int x = a * 8 + b * 4 + c * 2 + d;
	if (x == 3 || x == 5 || x == 14 || x == 15)
		return 0;
	return 1;
}
const ll MOD = 1e9 + 7;

ll dp[3100][3100];
int lcp[3100][3100];

int n;

void add(ll &a, ll b) {
	a = (a + b) % MOD;
}

int a[3100];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i) {
		dp[i][i] = 1;
		for(int j = i; j < n; ++j) {
			if (j + 1 <= n)
				add(dp[i][j + 1], dp[i][j]);
			if (j + 2 <= n)
				add(dp[i][j + 2], dp[i][j]);
			if (j + 3 <= n)
				add(dp[i][j + 3], dp[i][j]);
			if (j + 4 <= n && check(a[j], a[j + 1], a[j + 2], a[j + 3]))
				add(dp[i][j + 4], dp[i][j]);
		}
	}
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j) {
			if (a[i] != a[j])
				lcp[i][j] = 0;
			else {
				if (i == 0)
					lcp[i][j] = 1;
				else
					lcp[i][j] = 1 + lcp[i - 1][j - 1];
			}
		}
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		int mx = 0;
		for (int j = 0; j < i; ++j)
			mx = max(mx, lcp[j][i]);
		for (int j = 0; i - j + 1 > mx; ++j)
			add(ans, dp[j][i + 1]);
		cout << ans << "\n";
	}
	return 0;
}