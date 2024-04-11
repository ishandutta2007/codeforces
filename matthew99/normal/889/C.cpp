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

const int Mod = 1e9 + 7;

inline int fpm(LL b, int e, int m)
{
	b %= m;
	LL t = 1;
	for ( ; e; e >>= 1, (b *= b) %= m)
		if (e & 1) (t *= b) %= m;
	return t;
}

const int maxn = 1000100;

int fac[maxn + 5], ifac[maxn + 5];

inline void prepare()
{
	fac[0] = 1;
	REP(i, 0, maxn) fac[i + 1] = (LL)fac[i] * (i + 1) % Mod;
	ifac[maxn] = fpm(fac[maxn], Mod - 2, Mod);
	for (int i = maxn - 1; i >= 0; --i) ifac[i] = (LL)ifac[i + 1] * (i + 1) % Mod;
}

int n, K;

int f[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	prepare();
	scanf("%d%d", &n, &K);
	int tmp = 1;
	REP(i, 1, K + 1) tmp = (LL)tmp * i % Mod;
	REP(i, K + 1, n + 1)
	{
		f[i] = (LL)i * f[i - 1] % Mod;
		(f[i] += (LL)(fac[i - K - 1] - f[i - K - 1]) % Mod * tmp % Mod) %= Mod;
		tmp = (LL)tmp * fpm(i - K, Mod - 2, Mod) % Mod;
		tmp = (LL)tmp * i % Mod;
	}
	int ans = 0;
	int pre = 1;
	for (int i = n - 1; i >= 1; --i)
	{
		(ans += (LL)pre * f[i] % Mod) %= Mod;
		pre = (LL)pre * i % Mod;
	}
	(ans += Mod) %= Mod;
	printf("%d\n", ans);
	return 0;
}