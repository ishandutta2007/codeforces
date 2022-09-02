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

const int maxn = 20;

inline void fwt(int *a, int n)
{
	for (int i = 2; i <= n; i <<= 1)
		for (int j = 0; j < n; j += i)
		{
			REP(k, 0, i >> 1) 
			{
				int tmpl = a[j + k], tmpr = a[j + (i >> 1) + k];
				a[j + k] = (tmpl + tmpr) % Mod;
				a[j + (i >> 1) + k] = (tmpl - tmpr) % Mod;
			}
		}
}

int n;
int N;
int f[(1 << maxn) + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	static char s[(1 << maxn) + 5];
	scanf("%d", &n);
	N = 1 << n;
	scanf("%s", s);
	REP(i, 0, N) f[i] = s[i] - '0';
	fwt(f, N);
	REP(i, 0, N) f[i] = (LL)f[i] * f[i] % Mod;
	fwt(f, N);
	int invN = fpm(N, Mod - 2, Mod);
	int ans = 0;
	REP(i, 0, N)
	{
		f[i] = (LL)f[i] * invN % Mod;
		int tmp = f[i];
		REP(j, 0, n) if (!(i >> j & 1)) (tmp <<= 1) %= Mod;
		(ans += tmp) %= Mod;
	}
	ans = ((LL)ans * 3) % Mod;
	(ans += Mod) %= Mod;
	printf("%d\n", ans);
	return 0;
}