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

const int maxn = 10100, maxabs = 10100;

int n, l, r;
pair<int, int> a[maxn + 5];

int dp[maxn + 5][2];

inline bool cmp(const pair<int, int> &x, const pair<int, int> &y)
{
	if (x.y != y.y) return x.y < y.y;
	return x.x > y.x;
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d", &n, &l, &r);
	REP(i, 0, n) scanf("%d", &a[i].x);
	REP(i, 0, n) scanf("%d", &a[i].y);
	sort(a, a + n, cmp);
	memset(dp, -1, sizeof dp);
	dp[0][0] = 0;
	REP(i, 0, n)
	{
		for (int j = maxabs; j >= 0; --j) for (int k = 1; k >= 0; --k)
			if (dp[j][k] >= 0)
			{
				chkmax(dp[j][k || a[i].y], dp[j][k]);
				chkmax(dp[j + a[i].x][k], dp[j][k] + (a[i].y && j >= l && j <= r));
			}
	}
	int ans = 0;
	REP(i, 0, maxabs + 1) REP(j, 0, 2) if (dp[i][j] >= 0)
	{
		chkmax(ans, dp[i][j] + (j && i >= l && i <= r));
	}
	printf("%d\n", ans);
	return 0;
}