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

inline int fpm(LL b, int e, int m)
{
	b %= m;
	LL t = 1;
	for ( ; e; e >>= 1, (b *= b) %= m)
		if (e & 1) (t *= b) %= m;
	return t;
}

const int maxn = 310;

int fac[maxn + 5], ifac[maxn + 5];
int ways[maxn + 5][maxn + 5];
int C[maxn + 5][maxn + 5];

inline void prepare()
{
	REP(i, 0, maxn + 1)
	{
		C[i][0] = 1;
		REP(j, 1, i + 1) (C[i][j] = C[i - 1][j - 1] + C[i - 1][j]) %= Mod;
	}
	fac[0] = 1;
	REP(i, 0, maxn) fac[i + 1] = (LL)fac[i] * (i + 1) % Mod;
	ifac[maxn] = fpm(fac[maxn], Mod - 2, Mod);
	for (int i = maxn - 1; i >= 0; --i) ifac[i] = (LL)ifac[i + 1] * (i + 1) % Mod;
	ways[0][0] = 1;
	REP(i, 0, maxn + 1) 
	{
		REP(j, 0, maxn + 1) if (ways[i][j])
		{
			REP(k, 1, maxn - j + 1)
			{
				(ways[i + 1][j + k] -= (LL)ways[i][j] * fac[j + k] % Mod * ifac[j] % Mod) %= Mod;
			}
		}
	}
}

int n;

map<vector<int>, int> num;

int dp[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	prepare();

	scanf("%d", &n);
	REP(i, 0, n)
	{
		int x;
		scanf("%d", &x);
		vector<int> factor;
		for (int j = 2; j * j <= x; ++j)
		{
			if (!(x % j))
			{
				int cnt = 0;
				while (!(x % j)) x /= j, cnt ^= 1;
				if (cnt) factor.pb(j);
			}
		}
		if (x > 1) factor.pb(x);
		sort(ALL(factor));
		++num[factor];
	}
	memset(dp, 0, sizeof dp);
	dp[0] = 1;
	for (auto u : num)
	{
		int tmp = u.y;
		for (int i = n - 1; i >= 0; --i) if (dp[i])
		{
			REP(j, 1, tmp + 1) if (i + j <= n)
			{
				(dp[i + j] += (LL)dp[i] * ways[j][tmp] % Mod * C[i + j][i] % Mod) %= Mod;
			}
			dp[i] = 0;
		}
	}
	int ans = 0;
	REP(i, 0, n + 1) (ans += dp[i]) %= Mod;
	if (n & 1) ans = -ans;
	(ans += Mod) %= Mod;
	printf("%d\n", ans);
	return 0;
}