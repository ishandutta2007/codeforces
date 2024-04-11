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

template<typename T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 110;

int n;
int a[maxn + 5];

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d", a + i), --a[i];
	REP(i, 0, n) if (~a[i]) a[i] &= 1;
	static int dp[maxn + 5][maxn + 5][2];
	memset(dp, oo, sizeof dp);
	dp[0][0][0] = 0;
	REP(i, 0, n)
		REP(u, 0, 2)
		{
			if (~a[i] && u != a[i]) continue;
			REP(j, 0, i + 1) REP(k, 0, 2)
				if (dp[i][j][k] < oo)
				{
					int tmp = dp[i][j][k] + (i > 0 ? (k != u) : 0);
					chkmin(dp[i + 1][j + u][u], tmp);
				}
		}
	printf("%d\n", min(dp[n][n >> 1][0], dp[n][n >> 1][1]));
	return 0;
}