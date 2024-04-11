#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int Mod = 1e9 + 7;

const int maxn = 200, maxk = 1000;

int n, K, a[maxn + 5];

int dp[maxn + 5][maxn + 5][maxk + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &K);
	REP(i, 0, n) scanf("%d", a + i);
	sort(a, a + n);
	dp[0][0][0] = 1;
	REP(i, 0, n) REP(j, 0, i + 1) REP(k, 0, K + 1)
		if (dp[i][j][k])
		{
			if (i + j < n)
			{
				int tmp = k + a[i + j] - a[i];
				if (tmp <= K) (dp[i + 1][j][tmp] += (LL)dp[i][j][k] * (j + 1) % Mod) %= Mod;
			}
			if (i + j + 1 < n)
			{
				int tmp = k + a[i + j + 1] + a[i + j] - (a[i] << 1);
				if (tmp <= K) (dp[i + 1][j + 1][tmp] += dp[i][j][k]) %= Mod;
			}
			if (j) (dp[i + 1][j - 1][k] += (LL)dp[i][j][k] * j % Mod) %= Mod;
		}
	int ans = 0;
	REP(i, 0, K + 1) 
		if (dp[n][0][i]) (ans += dp[n][0][i]) %= Mod;
	printf("%d\n", ans);
	return 0;
}