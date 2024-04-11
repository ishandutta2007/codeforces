#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
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

const int maxn = 100;

int n, K, m;

int Min[maxn + 5][maxn + 5];

int dp[maxn + 5][maxn + 5][maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	memset(Min, oo, sizeof Min);
	scanf("%d%d%d", &n, &K, &m);
	--K;
	if (!K)
	{
		printf("0\n");
		return 0;
	}
	REP(i, 0, m)
	{
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		chkmin(Min[u][v], c);
	}
	memset(dp, oo, sizeof dp);
	REP(i, 1, n + 1) REP(j, 1, n + 1) if (i != j && Min[i][j] < oo) 
	{
		chkmin(dp[1][i][j], Min[i][j]);
		if (j > i) chkmin(dp[1][n + 1][j], Min[i][j]);
		else chkmin(dp[1][0][j], Min[i][j]);
	}
	REP(i, 1, K) REP(j, 0, n + 2) REP(k, 0, n + 2) if (dp[i][j][k] < oo)
	{
		REP(l, min(j, k) + 1, max(j, k)) if (Min[k][l] < oo)
		{
			chkmin(dp[i + 1][j][l], dp[i][j][k] + Min[k][l]);
			chkmin(dp[i + 1][k][l], dp[i][j][k] + Min[k][l]);
		}
	}
	int ans = oo;
	REP(i, 0, n + 2) REP(j, 0, n + 2)
		chkmin(ans, dp[K][i][j]);
	if (ans == oo) printf("-1\n");
	else printf("%d\n", ans);
	return 0;
}