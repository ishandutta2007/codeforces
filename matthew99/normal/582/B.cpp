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

const int maxn = 300;

int n, T;
int a[maxn + 5];

int dp[maxn + 5][maxn + 5];

int f[maxn + 5][maxn + 5];

void mul(int a[maxn + 5][maxn + 5], int b[maxn + 5][maxn + 5])
{
	static int ans[maxn + 5][maxn + 5];
	memset(ans, -oo, sizeof ans);
	REP(i, 0, maxn)
		REP(j, 0, maxn)
			REP(k, 0, maxn)
				chkmax(ans[i][k], a[i][j] + b[j][k]);
	REP(i, 0, maxn)
		REP(j, 0, maxn)
			a[i][j] = ans[i][j];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &T);
	REP(i, 0, n) scanf("%d", a + i), --a[i];
	REP(i, 0, n)
	{
		dp[i][i] = 1;
		REP(j, i + 1, n)
		{
			dp[i][j] = -oo;
			REP(k, i, j)
				if (a[k] <= a[j]) chkmax(dp[i][j], dp[i][k] + 1);
		}
	}
	memset(f, -oo, sizeof f);
	REP(i, 0, n)
		REP(j, i, n)
			chkmax(f[a[i]][a[j]], dp[i][j]);
	REP(j, 0, maxn)
		for (int i = j; i >= 0; --i)
			chkmax(f[i][j], f[i + 1][j]);
	int ans = 0;
	static int tmp[maxn + 5][maxn + 5];
	memset(tmp, -oo, sizeof tmp);
	REP(i, 0, n) tmp[i][i] = 0;
	for ( ; T; T >>= 1, mul(f, f))
		if (T & 1) mul(tmp, f);
	REP(i, 0, n)
		REP(j, 0, n)
			if (tmp[i][j] >= 0)
				debug("%d %d: %d\n", i, j, tmp[i][j]);
	REP(i, 0, maxn)
		REP(j, 0, maxn)
			chkmax(ans, tmp[i][j]);
	printf("%d\n", ans);
	return 0;
}