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

const int max0 = 50, maxn = 1000;

int n, x;
double p, q;

double a[maxn + 5][max0 + 5];
double b[maxn + 5][max0 + 5];

double dp[maxn + 5][max0 + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &x);
	p = x / 1e9, q = 1 - p;
	REP(i, 1, maxn + 1)
		REP(j, 1, max0)
		{
			if (j == 1) a[i][j] += p;
			if (j == 2) a[i][j] += q, b[i][j] += q;
			a[i][j] += a[i - 1][j - 1] * a[i][j - 1];
			b[i][j] += a[i - 1][j - 1] * b[i][j - 1];
		}
	for (int i = maxn; i >= 1; --i)
		REP(j, 1, max0) a[i][j] *= 1 - a[i - 1][j], b[i][j] *= 1 - a[i - 1][j];
	REP(i, 1, max0) dp[maxn][i] = i;
	for (int i = maxn - 1; i >= 0; --i) REP(j, 1, max0) 
	{
		double sum = 0;
		REP(k, 1, max0)
		{
			if (j == k) continue;
			int pos = maxn - i;
			if (j == 1) dp[i][j] += b[pos][k] * dp[i + 1][k], sum += b[pos][k];
			else if (j > k) dp[i][j] += a[pos][k] * dp[i + 1][k], sum += a[pos][k];
		}
		(dp[i][j] /= sum) += j;
	}
	double ans = 0;
	if (n <= maxn) REP(i, 1, max0) ans += a[n][i] * dp[maxn - n + 1][i];
	else
	{
		double sum0 = 0, sum1 = 0;
		REP(i, 1, max0) sum0 += a[maxn][i] * dp[0][i];
		REP(i, 1, max0) sum1 += a[maxn - 1][i] * dp[1][i];
		ans = sum1 + (sum0 - sum1) * (n - maxn + 1);
	}
	printf("%.15f\n", ans);
	return 0;
}