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
const LL OO = 0x3f3f3f3f3f3f3f3fLL;

const int maxn = 10000;
 
int n, c;
int p[maxn + 5], s[maxn + 5];

LL dp[2][maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &c);
	REP(i, 0, n) scanf("%d", p + i);
	REP(i, 0, n) scanf("%d", s + i);
	memset(dp, oo, sizeof dp);
	dp[0][0] = 0;
	REP(i, 0, n) 
	{
		int cur = i & 1;
		memset(dp[!cur], oo, sizeof dp[!cur]);
		REP(j, 0, i + 1) if (dp[cur][j] < OO)
		{
			chkmin(dp[!cur][j + 1], dp[cur][j] + s[i]);
			chkmin(dp[!cur][j], dp[cur][j] + p[i] + (LL)j * c);
		}
	}
	LL ans = OO;
	REP(i, 0, n + 1) chkmin(ans, dp[n & 1][i]);
	cout << ans << endl;
	return 0;
}