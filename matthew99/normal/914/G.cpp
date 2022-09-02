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

const int maxbit = 17;
const int maxabs = 1 << maxbit;

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
int a[maxn + 5];

int cntab[maxabs + 5];
int cntc[maxabs + 5];
int cntde[maxabs + 5];

int tmp[maxabs + 5];

int f[maxabs + 5];
int ret[maxn + 5];

int ans;

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) 
	{
		scanf("%d", a + i);
		++cntc[a[i]];
	}
	REP(i, 0, maxabs)
	{
		int j = i;
		cntab[i] = 0;
		while (1)
		{
			(cntab[i] += (LL)cntc[j] * cntc[i ^ j] % Mod) %= Mod;
			if (!j) break;
			j = (j - 1) & i;
		}
	}
	memcpy(tmp, cntc, sizeof tmp);
	fwt(tmp, maxabs);
	REP(i, 0, maxabs) tmp[i] = (LL)tmp[i] * tmp[i] % Mod;
	fwt(tmp, maxabs);
	int inv = fpm(maxabs, Mod - 2, Mod);
	REP(i, 0, maxabs) cntde[i] = (LL)tmp[i] * inv % Mod;
	f[0] = 0, f[1] = 1;
	REP(i, 2, maxabs) f[i] = (f[i - 1] + f[i - 2]) % Mod;
	REP(i, 0, maxabs)
	{
		cntab[i] = (LL)cntab[i] * f[i] % Mod;
		cntc[i] = (LL)cntc[i] * f[i] % Mod;
		cntde[i] = (LL)cntde[i] * f[i] % Mod;
	} 
	REP(j, 0, maxbit) REP(i, 0, maxabs)
		if (!(i >> j & 1))
		{
			(cntab[i] += cntab[i | (1 << j)]) %= Mod;
			(cntc[i] += cntc[i | (1 << j)]) %= Mod;
			(cntde[i] += cntde[i | (1 << j)]) %= Mod;
		}
	REP(i, 1, maxabs)
	{
		int val = (LL)cntab[i] * cntc[i] % Mod * cntde[i] % Mod;
		int cnt = __builtin_popcount(i);
		if (!(cnt & 1)) cnt = -cnt;
		(ans += (LL)val * cnt % Mod) %= Mod;
	}
	(ans += Mod) %= Mod;
	printf("%d\n", ans);
	return 0;
}