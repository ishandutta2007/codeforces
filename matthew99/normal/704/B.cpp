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

const int maxn = 5010;

LL dp[2][(maxn << 1) + 5];

int n, S, T;
int p[maxn + 5];
int a[maxn + 5], b[maxn + 5], c[maxn + 5], d[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d", &n, &S, &T), --S, --T;
	REP(i, 0, n) scanf("%d", p + i);
	REP(i, 0, n) scanf("%d", a + i);
	REP(i, 0, n) scanf("%d", b + i);
	REP(i, 0, n) scanf("%d", c + i);
	REP(i, 0, n) scanf("%d", d + i);
	memset(dp[0], oo, sizeof dp[0]);
	dp[0][0] = 0;
	REP(i, 0, n) 
	{
		int cur = i & 1;
		int nxt = !cur;
		memset(dp[nxt], oo, sizeof dp[nxt]);
		REP(j, 0 + (i > 0), n << 1 | 1) if (dp[cur][j] < OO)
		{
			if (i != S && i != T)
			{
				if (j >= 2) chkmin(dp[nxt][j - 2], dp[cur][j] + (p[i] << 1) + a[i] + c[i]);
				chkmin(dp[nxt][j + 2], dp[cur][j] - (p[i] << 1) + b[i] + d[i]);
				if ((i > S) ^ (i > T) && j == 1)
				{
					if (S < T) chkmin(dp[nxt][j], dp[cur][j] + a[i] + d[i]);
					else chkmin(dp[nxt][j], dp[cur][j] + b[i] + c[i]);
				}
				else chkmin(dp[nxt][j], dp[cur][j] + min(a[i] + d[i], b[i] + c[i]));
			}
			else if (i == S)
			{
				if (j >= 1) chkmin(dp[nxt][j - 1], dp[cur][j] + p[i] + c[i]);
				chkmin(dp[nxt][j + 1], dp[cur][j] - p[i] + d[i]);
			}
			else if (i == T)
			{
				if (j >= 1) chkmin(dp[nxt][j - 1], dp[cur][j] + p[i] + a[i]);
				chkmin(dp[nxt][j + 1], dp[cur][j] - p[i] + b[i]);
			}
		}
	}
	printf("%I64d\n", dp[n & 1][0]);
	return 0;
}