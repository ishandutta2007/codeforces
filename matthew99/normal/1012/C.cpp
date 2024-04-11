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

#ifdef __WIN32
#define LLFORMAT "I64"
#define Rand() ((rand() << 15) | rand())
#else
#define LLFORMAT "ll"
#define Rand() (rand())
#endif

template<typename T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;
const LL OO = 0x3f3f3f3f3f3f3f3fLL;

const int maxn = 5010;

int n;
int a[maxn + 5];
LL dp[maxn + 5][(maxn >> 1) + 5][3];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d", a + i);
	memset(dp, oo, sizeof dp);
	dp[0][0][0] = 0;
	REP(i, 0, n) REP(j, 0, min(i, (n + 1) >> 1) + 1) REP(k, 0, 3) if (dp[i][j][k] < OO)
	{
		if (!k)
		{
			chkmin(dp[i + 1][j][0], dp[i][j][k]);
			chkmin(dp[i + 1][j + 1][1], dp[i][j][k] + (i ? max(0, a[i - 1] - (a[i] - 1)): 0));
		}
		else if (k == 1)
		{
			chkmin(dp[i + 1][j][2], dp[i][j][k] + max(0, a[i] - (a[i - 1] - 1)));
		}
		else if (k == 2)
		{
			chkmin(dp[i + 1][j][0], dp[i][j][k]);
			chkmin(dp[i + 1][j + 1][1], dp[i][j][k] - max(0, a[i - 1] - (a[i - 2] - 1)) + max(0, a[i - 1] - (min(a[i], a[i - 2]) - 1)));
		}
	}
	REP(i, 1, ((n + 1) >> 1) + 1)
	{
		LL Min = LLONG_MAX;
		REP(j, 0, 3) chkmin(Min, dp[n][i][j]);
		printf("%" LLFORMAT "d ", Min);
	}
	return 0;
}