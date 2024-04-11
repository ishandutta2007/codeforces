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

const int maxn = 1010, maxd = 10;

inline int fpm(LL b, int e, int m)
{
	b %= m;
	LL t = 1;
	for ( ; e; e >>= 1, (b *= b) %= m)
		if (e & 1) (t *= b) %= m;
	return t;
}

int n, d, Mod;

int ans;

int fac[maxn + 5], ifac[maxn + 5];
int C[maxn + 5][maxn + 5];

inline void prepare()
{
	fac[0] = 1;
	REP(i, 0, maxn) fac[i + 1] = (LL)fac[i] * (i + 1) % Mod;
	ifac[maxn] = fpm(fac[maxn], Mod - 2, Mod);
	for (int i = maxn - 1; i >= 0; --i) ifac[i] = (LL)ifac[i + 1] * (i + 1) % Mod;
	REP(i, 0, maxn + 1)
	{
		C[i][0] = 1;
		REP(j, 1, i + 1) (C[i][j] = C[i - 1][j - 1] + C[i - 1][j]) %= Mod;
	}
}

int r[maxn + 5];

inline void solve()
{
	static int dp[maxn + 5][maxd + 1];
	memset(dp, 0, sizeof dp);
	r[1] = 1;
	dp[0][0] = 1;
	REP(i, 1, n)
	{
		for (int j = n - i; j >= 0; --j)
		{
			REP(k, 0, d) if (dp[j][k])
			{
				int now = 1;
				for (int l = 1; k + l < d && j + i * l <= n; ++l) 
				{ 
					now = (LL)now * (r[i] + l - 1) % Mod;
					(dp[j + i * l][k + l] += (LL)dp[j][k] * now % Mod * ifac[l] % Mod) %= Mod;
				}
			}
		}
		r[i + 1] = dp[i][d - 1];
	}
	memset(dp, 0, sizeof dp);
	dp[0][0] = 1;
	REP(i, 1, (n >> 1) + 1)
	{
		for (int j = n - i; j >= 0; --j)
		{
			REP(k, 0, d) if (dp[j][k])
			{
				int now = 1;
				for (int l = 1; k + l <= d && j + i * l <= n; ++l) 
				{ 
					now = (LL)now * (r[i] + l - 1) % Mod;
					(dp[j + i * l][k + l] += (LL)dp[j][k] * now % Mod * ifac[l] % Mod) %= Mod;
				}
			}
		}
	}
	ans = dp[n - 1][d];
	if (!(n & 1)) (ans -= (LL)r[n >> 1] * (r[n >> 1] - 1) % Mod * ((Mod + 1) >> 1) % Mod) %= Mod;
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d", &n, &d, &Mod);
	if (n <= 2)
	{
		puts("1");
		return 0;
	}
	prepare();
	solve();
	(ans += Mod) %= Mod;
	printf("%d\n", ans);
	return 0;
}