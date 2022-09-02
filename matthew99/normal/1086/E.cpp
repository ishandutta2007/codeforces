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

const int maxn = 2010;

int A[maxn + 5][maxn + 5];
int C[maxn + 5][maxn + 5];

int fac[maxn + 5];

int n;
int a[maxn + 5][maxn + 5];

int dp[maxn + 5];
int ways[maxn + 5][maxn + 5];

inline void prepare()
{
	REP(i, 0, maxn + 1)
	{
		C[i][0] = 1;
		REP(j, 1, i + 1)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % Mod;
	}
	REP(i, 0, maxn + 1)
	{
		A[i][0] = 1;
		REP(j, 0, i)
			A[i][j + 1] = (LL)A[i][j] * (i - j) % Mod;
	}
	REP(i, 0, maxn + 1) fac[i] = A[i][i];
	dp[0] = 1;
	REP(i, 1, maxn + 1)
	{
		dp[i] = 0;
		REP(j, 2, i + 1)
			(dp[i] += (LL)dp[i - j] * A[i - 1][j - 1] % Mod) %= Mod;
	}
	REP(i, 0, maxn + 1)
	{
		ways[i][0] = dp[i];
		REP(j, 1, i + 1)
		{
			ways[i][j] = (ways[i][j - 1] + ways[i - 1][j - 1]) % Mod;
		}
	}
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	prepare();
	scanf("%d", &n);
	REP(i, 0, n) REP(j, 0, n) scanf("%d", a[i] + j), --a[i][j];
	int ans = 0;
	int tmp = 1;
	for (int i = n - 1; i >= 0; --i)
	{
		static int fen0[maxn + 5], fen1[maxn + 5];
		memset(fen0, 0, sizeof fen0);
		memset(fen1, 0, sizeof fen1);
		static bool vis[maxn + 5];
		memset(vis, 0, sizeof vis);
		int chain = 0;
		REP(j, 0, n)
		{
			for (int k = a[i][j] + 1; k <= n; k += k & -k) ++fen0[k];
			int cnt0 = 0;
			for (int k = a[i][j]; k > 0; k -= k & -k) cnt0 += fen0[k];
			if (!i)
			{
				(ans += (LL)(a[i][j] - cnt0) * fac[n - j - 1] % Mod * tmp % Mod) %= Mod;
			}
			else
			{
				if (!vis[a[i - 1][j]]) ++chain;

				int cnt1 = 0;
				for (int k = a[i][j]; k > 0; k -= k & -k) cnt1 += fen1[k];
				if (!vis[a[i - 1][j]] && a[i - 1][j] < a[i][j]) ++cnt0;

				(ans += (LL)(a[i][j] - cnt0 - cnt1) * ways[n - j - 1][chain] % Mod * tmp % Mod) %= Mod;
				(ans += (LL)cnt1 * ways[n - j - 1][chain - 1] % Mod * tmp % Mod) %= Mod;

				if (!vis[a[i - 1][j]]) for (int k = a[i - 1][j] + 1; k <= n; k += k & -k) ++fen1[k];
				vis[a[i - 1][j]] = 1;

				if (vis[a[i][j]]) 
				{
					for (int k = a[i][j] + 1; k <= n; k += k & -k) --fen1[k];
					--chain;
				}
				vis[a[i][j]] = 1;
			}
		}
		tmp = (LL)tmp * dp[n] % Mod;
	}
	(ans += Mod) %= Mod;
	printf("%d\n", ans);
	return 0;
}