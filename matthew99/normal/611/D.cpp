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

const int Mod = 1e9 + 7;

const int maxn = 5000;

int n;
char s[maxn + 5];

int dp[maxn + 5][maxn + 5];
int sum[maxn + 5][maxn + 5];

int same[maxn + 5][maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	scanf("%s", s);
	for (int i = n - 1; i >= 0; --i)
		for (int j = n - 1; j >= 0; --j)
			if (s[i] != s[j]) same[i][j] = 0;
			else same[i][j] = same[i + 1][j + 1] + 1;
	memset(dp, 0, sizeof dp);
	dp[0][0] = 1;
	REP(i, 0, n + 1) sum[0][i] = 1;
	REP(i, 1, n + 1) 
	{
		REP(j, 1, i + 1)
		{
			if (s[i - j] != '0') 
			{
				dp[i][j] = sum[i - j][j];
				if (i - j - j >= 0)
				{
					int x = i - j - j, y = i - j;
					if (same[x][y] >= j) continue;
					if (s[x + same[x][y]] < s[y + same[x][y]]) (dp[i][j] += dp[i - j][j]) %= Mod;
				}
			}
		}
		REP(j, 0, n + 1) (sum[i][j + 1] = sum[i][j] + dp[i][j]) %= Mod;
	}
	int ans = 0;
	REP(i, 1, n + 1) (ans += dp[n][i]) %= Mod;
	(ans += Mod) %= Mod;
	printf("%d\n", ans);
	return 0;
}