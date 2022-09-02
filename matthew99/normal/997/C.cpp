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

const int maxn = 1000000;

inline int fpm(LL b, int e, int m)
{
	b %= m;
	LL t = 1;
	for ( ; e; e >>= 1, (b *= b) %= m)
		if (e & 1) (t *= b) %= m;
	return t;
}

int fac[maxn + 5], ifac[maxn + 5];

inline void prepare()
{
	fac[0] = 1;
	REP(i, 0, maxn) fac[i + 1] = (LL)fac[i] * (i + 1) % Mod;
	ifac[maxn] = fpm(fac[maxn], Mod - 2, Mod);
	for (int i = maxn - 1; i >= 0; --i) ifac[i] = (LL)ifac[i + 1] * (i + 1) % Mod;
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	prepare();
	int n;
	scanf("%d", &n);
	int ans = fpm(fpm(3, n, Mod), n, Mod);
	REP(i, 0, n + 1)
	{
		int tmp = (LL)fac[n] * ifac[i] % Mod * ifac[n - i] % Mod;
		if (i & 1) tmp = -tmp;
		int ways = 0;
		if (i > 0) 
		{
			ways = (LL)3 * fpm((fpm(3, n - i, Mod) - 1) % Mod, n, Mod) % Mod;
			(ways += (LL)fpm(fpm(3, n - i, Mod), n, Mod) * (fpm(3, i, Mod) - 3) % Mod) %= Mod;
		}
		else
		{
			ways = (LL)fpm(((fpm(3, n - i, Mod)) - 3) % Mod, n, Mod) % Mod;
		}
		(ans -= (LL)ways * tmp % Mod) %= Mod;
	}
	(ans += Mod) %= Mod;
	printf("%d\n", ans);
	return 0;
}