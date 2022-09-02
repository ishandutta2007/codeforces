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

const int max0 = 10000000;

const int maxn = 150, maxswap = maxn * (maxn - 1) >> 1;

int n, k, s;

int a[maxn + 5];

int dp[2][maxn + 5][maxswap + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d", &n, &k, &s);
	int tot = k * (k - 1) >> 1;
	s += tot;
	s = min(s, n * (n - 1) >> 1);
	REP(i, 0, n) scanf("%d", a + i);
	memset(dp, oo, sizeof dp);
	dp[0][0][0] = 0;
	REP(i, 0, n)
	{
		int cur = i & 1, nxt = !cur;
		memset(dp[nxt], oo, sizeof dp[nxt]);
		REP(j, 0, min(i, k) + 1)
		{
			REP(sum, 0, s + 1)
				if (dp[cur][j][sum] < oo)
				{
					chkmin(dp[nxt][j][sum], dp[cur][j][sum]);
					if (j + 1 <= k && sum + i <= s) chkmin(dp[nxt][j + 1][sum + i], dp[cur][j][sum] + a[i]);
				}
		}
	}
	int ans = oo;
	REP(i, 0, s + 1) chkmin(ans, dp[n & 1][k][i]);
	printf("%d\n", ans);
	return 0;
}