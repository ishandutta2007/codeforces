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

const int maxn = 100100;

int fac[maxn + 5], ifac[maxn + 5];

inline void prepare()
{
	fac[0] = 1;
	REP(i, 0, maxn) fac[i + 1] = (LL)fac[i] * (i + 1) % Mod;
	ifac[maxn] = fpm(fac[maxn], Mod - 2, Mod);
	for (int i = maxn - 1; i >= 0; --i) ifac[i] = (LL)ifac[i + 1] * (i + 1) % Mod;
}

int food[maxn + 5];
int nolim[maxn + 5];
int haslim[maxn + 5];

int C(int x, int y) { assert(y >= 0 && y <= x); return (LL)fac[x] * ifac[y] % Mod * ifac[x - y] % Mod; }

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	prepare();
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c), ++c;
	food[0] = (a == 0);
	REP(i, 1, a + 1) food[i] = C(a - 1, i - 1);
	nolim[0] = (b == 0);
	REP(i, 1, b + 1) nolim[i] = C(b - 1, i - 1);
	haslim[0] = (b == 0);
	REP(i, 1, b / c + 1) haslim[i] = C(b - (c - 1) * i - 1, i - 1);
	int tot = 0, like = 0;
	REP(i, 0, a + 1) REP(j, i - 1, i + 2) if (j >= 0 && j <= b)
	{
		int dtot = (LL)food[i] * nolim[j] % Mod, dlike = (LL)food[i] * haslim[j] % Mod;
		if (i == j) (dtot <<= 1) %= Mod, (dlike <<= 1) %= Mod;
		(tot += dtot) %= Mod;
		(like += dlike) %= Mod;
	}
	int ans = (LL)like * fpm(tot, Mod - 2, Mod) % Mod;
	(ans += Mod) %= Mod;
	printf("%d\n", ans);
	return 0;
}