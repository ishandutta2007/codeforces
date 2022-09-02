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

const int maxn = 50;

const int maxR = 5010;

int n, R;
int a[maxn + 5], b[maxn + 5];
double p[maxn + 5];

double dp[maxn + 5][maxR + 5];

inline bool check(const double &x)
{
	memset(dp[n], 0, sizeof dp[n]);
	for (int i = n - 1; i >= 0; --i)
	{
		REP(j, 0, R + 1)
		{
			double u = 0, v = 0;
			if (j + a[i] > R) u = x;
			else u = min(x, dp[i + 1][j + a[i]]);
			u += a[i];
			u *= p[i];
			if (j + b[i] > R) v = x;
			else v = min(x, dp[i + 1][j + b[i]]);
			v += b[i];
			v *= 1 - p[i];
			dp[i][j] = u + v;
		}
	}
	return dp[0][0] < x;
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &R);
	REP(i, 0, n) scanf("%d%d%lf", a + i, b + i, p + i), p[i] /= 100;
	double l = 0, r = 1e9;
	REP(i, 0, 70)
	{
		double mid = (l + r) / 2;
		if (check(mid)) r = mid;
		else l = mid;
	}
	printf("%.15f\n", l);
	return 0;
}