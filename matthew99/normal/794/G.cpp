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

int ex_gcd(const int &a, const int &b, int &x, int &y)
{
	if (!b)
	{
		x = 1, y = 0;
		return a;
	}
	int d = ex_gcd(b, a % b, y, x);
	y -= a / b * x;
	return d;
}

const int Mod = 1e9 + 7;

inline int fpm(LL b, int e, int m)
{
	b %= m;
	LL t = 1;
	for ( ; e; e >>= 1, (b *= b) %= m)
		if (e & 1) (t *= b) %= m;
	return t;
}

const int maxn = 600100;

int fac[maxn + 5], ifac[maxn + 5];

int pw2[maxn + 5];

int mu[maxn + 5], phi[maxn + 5];

inline void prepare()
{
	fac[0] = 1;
	REP(i, 0, maxn) fac[i + 1] = (LL)fac[i] * (i + 1) % Mod;
	ifac[maxn] = fpm(fac[maxn], Mod - 2, Mod);
	for (int i = maxn - 1; i >= 0; --i) ifac[i] = (LL)ifac[i + 1] * (i + 1) % Mod;
	pw2[0] = 1;
	REP(i, 0, maxn) pw2[i + 1] = (pw2[i] << 1) % Mod;
	mu[1] = 1;
	for (int i = 1; i <= maxn; ++i)
		for (int j = (i << 1); j <= maxn; j += i)
			mu[j] -= mu[i];
	for (int i = 1; i <= maxn; ++i)
		for (int j = 1; j * i <= maxn; ++j)
			phi[i * j] += mu[i] * j;
}

inline int getC(int x, int y)
{
	return (LL)fac[x] * ifac[y] % Mod * ifac[x - y] % Mod;
}

int n;
int aa, ab, ae, ba, bb, be;
int an, bn;
char a[maxn + 5], b[maxn + 5];

int ans;

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	prepare();
	scanf("%s", a);
	scanf("%s", b);
	scanf("%d", &n);
	an = strlen(a), bn = strlen(b);
	REP(i, 0, an) 
		if (a[i] == 'A') ++aa;
		else if (a[i] == 'B') ++ab;
	REP(i, 0, bn) 
		if (b[i] == 'A') ++ba;
		else if (b[i] == 'B') ++bb;
	ae = an - aa - ab;
	be = bn - ba - bb;
	int orix = aa - ba;
	REP(i, 0, ae + be + 1)
	{
		int tmp = getC(ae + be, i);
		int delta = i - be;
		int coex = orix + delta, coey = (an - bn) - coex;
		int val = 0;
		if (!coex && !coey) 
		{
			assert(an == bn);
			val = (LL)(pw2[n + 1] - 2) * (pw2[n + 1] - 2) % Mod;
			int ways = 1;
			REP(j, 0, an) 
				if (a[j] != '?' && b[j] != '?')
				{
					if (a[j] != b[j]) { ways = 0; break; }
				}
				else if (a[j] == '?' && b[j] == '?') (ways <<= 1) %= Mod;
			(ans += (LL)ways * val % Mod) %= Mod;
			val = 0;
			REP(j, 1, n + 1)
			{
				int tmp0 = phi[j];
				if (j > 1) (tmp0 <<= 1) %= Mod;
				(val += (LL)tmp0 * (pw2[n / j + 1] - 2) % Mod) %= Mod;
			}
			(ans += (LL)(tmp - ways) * val % Mod) %= Mod;
		}
		else if (coex && coey)
		{
			if (coex < 0) coex = -coex;
			else coey = -coey;
			if (coey < 0) continue;
			int d = __gcd(coex, coey);
			coex /= d, coey /= d;
			val = pw2[n / max(coex, coey) + 1] - 2;
			(ans += (LL)tmp * val % Mod) %= Mod;
		}
	}
	(ans += Mod) %= Mod;
	printf("%d\n", ans);
	return 0;
}