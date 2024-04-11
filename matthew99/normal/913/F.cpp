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

const int Mod = 998244353;

inline int fpm(LL b, int e, int m)
{
	b %= m;
	LL t = 1;
	for ( ; e; e >>= 1, (b *= b) %= m)
		if (e & 1) (t *= b) %= m;
	return t;
}

const int maxn = 2010;

int n, p;
int f[maxn + 5], g[maxn + 5];

int dp[maxn + 5][maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	{
		int tmp_a, tmp_b;
		scanf("%d%d", &tmp_a, &tmp_b);
		p = (LL)tmp_a * fpm(tmp_b, Mod - 2, Mod) % Mod;
	}
	f[1] = 0, g[1] = 1;
	dp[1][1] = 1;
	REP(i, 2, n + 1)
	{
		g[i] = 1;
		REP(j, 1, i)
			if (dp[i - 1][j])
			{
				(dp[i][j] += (LL)dp[i - 1][j] * fpm(1 - p, j, Mod) % Mod) %= Mod;
				(dp[i][j + 1] += (LL)dp[i - 1][j] * fpm(p, i - 1 - j, Mod) % Mod) %= Mod;
			}
		(dp[i][1] += fpm(p, i - 1, Mod)) %= Mod;
		REP(j, 1, i) if (dp[i][j])
		{
			(f[i] += (LL)g[j] * dp[i][j] % Mod * (f[j] + f[i - j] + j * (j - 1) / 2 + j * (i - j)) % Mod) %= Mod;
			(g[i] -= (LL)g[j] * dp[i][j] % Mod) %= Mod;
		}
		(f[i] += (LL)g[i] * (i * (i - 1) / 2) % Mod) %= Mod;
		f[i] = (LL)f[i] * fpm(1 - g[i], Mod - 2, Mod) % Mod;
	}
	int ans = f[n];
	(ans += Mod) %= Mod;
	printf("%d\n", ans);
	return 0;
}