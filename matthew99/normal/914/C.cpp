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

template<typename T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 1010;

const int Mod = 1e9 + 7;

char s[maxn + 5];
int K;

int ans;

int cnt[1010];

int dp[1010][1010][2];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%s", s);
	scanf("%d", &K);
	if (K == 0)
	{
		printf("1\n");
	}
	else
	{
		cnt[1] = 1;
		REP(i, 2, 1010)
			cnt[i] = cnt[__builtin_popcount(i)] + 1;
		dp[0][0][0] = 1;
		int len = strlen(s);
		REP(i, 0, len)
		{
			REP(j, 0, i + 1) REP(k, 0, 2)
				if (dp[i][j][k])
				{
					(dp[i + 1][j][k | (s[i] == '1')] += dp[i][j][k]) %= Mod;
					if (k || s[i] == '1')
					{
						(dp[i + 1][j + 1][k] += dp[i][j][k]) %= Mod;
					}
				}
		}
		REP(i, 0, len + 1)
			if (cnt[i] == K)
			{
				(ans += dp[len][i][0]) %= Mod;
				(ans += dp[len][i][1]) %= Mod;
			}
		if (K == 1) (--ans) %= Mod;
		(ans += Mod) %= Mod;
		printf("%d\n", ans);
	}
	return 0;
}