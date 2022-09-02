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
const LL OO = 0x3f3f3f3f3f3f3f3fll;

const int maxn = 100, maxm = 100;

int n, m, K;
int a[maxn + 5];
int w[maxn + 5][maxm + 5];
LL dp[maxn + 5][maxn + 5][maxm + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d", &n, &m, &K);
	REP(i, 0, n) scanf("%d", a + i), --a[i];
	REP(i, 0, n)
	{
		REP(j, 0, m) scanf("%d", w[i] + j);
		if (~a[i]) memset(w[i], 0, sizeof w[i]);
	}
	memset(dp, oo, sizeof dp);
	dp[0][0][m] = 0;
	REP(i, 0, n) REP(j, 0, K + 1) REP(k, 0, m + 1) if (dp[i][j][k] < OO)
	{
		REP(l, 0, m) if (!~a[i] || l == a[i]) chkmin(dp[i + 1][j + (l != k)][l], dp[i][j][k] + w[i][l]);
	}
	LL ret = OO;
	REP(i, 0, m) chkmin(ret, dp[n][K][i]);
	if (ret == OO) puts("-1");
	else cout << ret << endl;
	return 0;
}