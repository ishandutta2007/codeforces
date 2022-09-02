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

inline int fpm(LL b, int e, int m)
{
	b %= m;
	LL t = 1;
	for ( ; e; e >>= 1, (b *= b) %= m)
		if (e & 1) (t *= b) %= m;
	return t;
}

const int Mod = 1e9 + 7;

const int maxn = 1510;
const int maxk = 100100;

int n, m, K;
int p;

int dp[maxn + 5][maxn + 5];

inline void init()
{
	int a, b;
	scanf("%d%d%d%d%d", &n, &m, &a, &b, &K);
	p = (LL)a * fpm(b, Mod - 2, Mod) % Mod;
}

int fac[maxk + 5], ifac[maxk + 5];
int w[maxn + 5], sumw[maxn + 5];

inline void prepare()
{
	fac[0] = 1;
	REP(i, 0, maxk) fac[i + 1] = (LL)fac[i] * (i + 1) % Mod;
	ifac[maxk] = fpm(fac[maxk], Mod - 2, Mod);
	for (int i = maxk - 1; i >= 0; --i) ifac[i] = (LL)ifac[i + 1] * (i + 1) % Mod;
	int tmp = fpm(1 - p, K, Mod);
	int step = (LL)p * fpm(1 - p, Mod - 2, Mod) % Mod;
	sumw[0] = 0;
	REP(i, 0, m)
	{
		w[i] = (LL)tmp * fac[K] % Mod * ifac[i] % Mod * ifac[K - i] % Mod;
		(sumw[i + 1] = sumw[i] + w[i]) %= Mod;
		tmp = (LL)tmp * step % Mod;
	}
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	init();
	prepare();
	if (p == 1)
	{
		printf("%d\n", (K << 1) < m);
		return 0;
	}
	dp[0][m] = 1;
	REP(i, 0, n)
	{
		REP(j, 0, m) (dp[i][j + 1] += dp[i][j]) %= Mod;
		int tmp = 0;
		REP(j, 0, m + 1)
		{
			dp[i + 1][j] = ((LL)sumw[j] * (dp[i][m] - dp[i][m - j]) - tmp) % Mod * w[m - j] % Mod;
			(tmp += (LL)w[j] * dp[i][j] % Mod) %= Mod;
		}
	}
	int ans = 0;
	REP(i, 0, m + 1) (ans += dp[n][i]) %= Mod;
	(ans += Mod) %= Mod;
	printf("%d\n", ans);
	return 0;
}