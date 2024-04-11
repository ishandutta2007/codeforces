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
#define EXIT(...) printf(__VA_ARGS__), exit(0)

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 100;

int n;
int t[maxn + 5], w[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d%d", t + i, w + i);
	static bool dp[maxn + 5][(maxn << 1) + 5][(maxn << 1) + 5];
	memset(dp, 0, sizeof dp);
	dp[0][0][0] = 1;
	REP(i, 0, n) REP(j, 0, n << 1 | 1) REP(k, 0, n << 1 | 1)
		if (dp[i][j][k])
		{
			dp[i + 1][j + t[i]][k] = 1;
			if (k + w[i] <= (n << 1)) dp[i + 1][j][k + w[i]] = 1;
		}
	int ans = oo;
	REP(i, 0, n << 1 | 1) REP(j, 0, i + 1)
		if (dp[n][i][j]) chkmin(ans, i);
	printf("%d\n", ans);
	return 0;
}