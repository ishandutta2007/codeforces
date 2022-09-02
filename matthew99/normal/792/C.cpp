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

const int maxl = 100100;

int n;
char s[maxl + 5];

int dp[maxl + 5][3];
int pre[maxl + 5][3];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%s", s);
	n = strlen(s);
	memset(dp, -1, sizeof dp);
	memset(pre, -1, sizeof pre);
	dp[0][0] = 0;
	REP(i, 0, n) REP(j, 0, 3) if (~dp[i][j])
	{
		if (chkmax(dp[i + 1][j], dp[i][j])) pre[i + 1][j] = 0;
		if (s[i] == '0' && !dp[i][j]) continue; 
		if (chkmax(dp[i + 1][(j + s[i] - '0') % 3], dp[i][j] + 1)) pre[i + 1][(j * 10 + s[i] - '0') % 3] = 1;
	}
	if (!dp[n][0])
	{
		REP(i, 0, n) if (s[i] == '0')
		{
			puts("0");
			return 0;
		}
		puts("-1");
		return 0;
	}
	vector<char> ans;
	int u = n, v = 0;
	while (u)
	{
		int tmp = pre[u][v];
		--u;
		if (tmp) ans.pb(s[u]), v = (v + 3 - (s[u] - '0') % 3) % 3;
	}
	reverse(ALL(ans));
	for (auto c : ans) putchar(c);
	return 0;
}