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

const int maxn = 1.01e6;

inline int fpm(LL b, int e, int m)
{
	b %= m;
	LL t = 1;
	for ( ; e; e >>= 1, (b *= b) %= m)
		if (e & 1) (t *= b) %= m;
	return t;
}

int n, m;

int fac[maxn + 5], ifac[maxn + 5];

inline void prepare()
{
	fac[0] = 1;
	REP(i, 0, maxn) fac[i + 1] = (LL)fac[i] * (i + 1) % Mod;
	ifac[maxn] = fpm(fac[maxn], Mod - 2, Mod);
	for (int i = maxn - 1; i >= 0; --i) ifac[i] = (LL)ifac[i + 1] * (i + 1) % Mod;
}

inline int C(int x, int y) { if (y > x) return 0; return (LL)fac[x] * ifac[y] % Mod * ifac[x - y] % Mod; }

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	prepare();
	int ans = 0;
	scanf("%d%d", &n, &m);
	int coe = 1;
	REP(i, 1, n)
	{
		int cnt = 0;
		if (i == n - 1) cnt = 1;
		else cnt = (LL)fpm(n, n - i - 2, Mod) * (i + 1) % Mod;
		int tmp = (LL)cnt * fpm(m, n - 1 - i, Mod) % Mod;
		tmp = (LL)tmp * C(m - 1, i - 1) % Mod;
		tmp = (LL)tmp * coe % Mod;
		(ans += tmp) %= Mod;
		coe = (LL)coe * (n - 1 - i) % Mod;
	}
	(ans += Mod) %= Mod;
	printf("%d\n", ans);
	return 0;
}