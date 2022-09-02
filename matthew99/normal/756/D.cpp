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

const int Mod = 1e9 + 7;

const int maxn = 5010;

int n;
int a[maxn + 5];
int dp[maxn + 5];

char s[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	scanf("%s", s);
	REP(i, 0, n) a[i] = s[i] - 'a';
	memset(dp, 0, sizeof dp);
	static bool vis[26];
	memset(vis, 0, sizeof vis);
	REP(i, 0, n) if (!vis[a[i]]) dp[i] = 1, vis[a[i]] = 1;
	REP(i, 1, n)
	{
		static int lst[26];
		memset(lst, 0, sizeof lst);
		static int sum[maxn + 5];
		sum[0] = 0;
		REP(j, 0, n)
		{
			sum[j + 1] = (sum[j] + dp[j]) % Mod;
			dp[j] = (sum[j + 1] - sum[lst[a[j]]]) % Mod;
			lst[a[j]] = j + 1;
		}
	}
	int ans = 0;
	REP(i, 0, n) if (dp[i]) (ans += dp[i]) %= Mod;
	(ans += Mod) %= Mod;
	printf("%d\n", ans);
	return 0;
}