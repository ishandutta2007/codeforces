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

const int maxn = 64;

int n;
double win[maxn + 5][maxn + 5];

double dp[maxn + 5][maxn + 5][maxn + 5];
double p[maxn + 5][maxn + 5][maxn + 5];

void work(int l, int r)
{
	if (r - l <= 1) 
	{
		p[l][r][l] = 1;
		return;	
	}
	int mid = (l + r) >> 1;
	work(l, mid);
	work(mid, r);
	REP(i, l, mid) REP(j, mid, r)
	{
		p[l][r][i] += p[l][mid][i] * p[mid][r][j] * win[i][j];
		p[l][r][j] += p[l][mid][i] * p[mid][r][j] * win[j][i];
	}
	REP(i, l, mid) REP(j, mid, r)
	{
		chkmax(dp[l][r][i], dp[l][mid][i] + dp[mid][r][j] + ((r - l) >> 1) * p[l][r][i]);
		chkmax(dp[l][r][j], dp[l][mid][i] + dp[mid][r][j] + ((r - l) >> 1) * p[l][r][j]);
	}
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n), n = 1 << n;
	REP(i, 0, n) REP(j, 0, n) scanf("%lf", win[i] + j), win[i][j] /= 100;
	memset(dp, 0, sizeof dp);
	memset(p, 0, sizeof p);
	work(0, n);
	double ans = 0;
	REP(i, 0, n) chkmax(ans, dp[0][n][i]);
	printf("%.15f\n", ans);
	return 0;
}