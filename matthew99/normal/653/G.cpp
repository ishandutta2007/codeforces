#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define EXIT(...) printf(__VA_ARGS__), exit(0)
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

const int maxn = 300000, maxabs = 300000;

int n;
int a[maxn + 5];

int ans;

vector<int> cnt[maxabs + 5];

int fac[maxn + 5], ifac[maxn + 5];
int pw[maxn + 5];

inline int fpm(LL b, int e, int m)
{
	b %= m;
	LL t = 1;
	for ( ; e; e >>= 1, (b *= b) %= m)
		if (e & 1) (t *= b) %= m;
	return t;
}

inline void prepare()
{
	fac[0] = 1;
	REP(i, 0, maxn) fac[i + 1] = (LL)fac[i] * (i + 1) % Mod;
	ifac[maxn] = fpm(fac[maxn], Mod - 2, Mod);
	for (int i = maxn - 1; i >= 0; --i) ifac[i] = (LL)ifac[i + 1] * (i + 1) % Mod;
	pw[0] = 1;
	REP(i, 0, maxn) pw[i + 1] = (pw[i] << 1) % Mod;
}

inline int C(int x, int y) { if (x < y) return 0; return (LL)fac[x] * ifac[y] % Mod * ifac[x - y] % Mod; }

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	prepare();
	scanf("%d", &n);
	REP(i, 0, n) 
	{
		scanf("%d", a + i);
		int u = a[i];
		for (int j = 2; j * j <= u; ++j)
		{
			if (!(u % j))
			{
				int k = 0;
				while (!(u % j))
				{
					u /= j;
					++k;
				}
				cnt[j].pb(k);
			}
		}
		if (u > 1) cnt[u].pb(1);
	}
	static int coe[maxn + 5];
	coe[0] = (pw[n - 1] - 1) % Mod;
	REP(i, 0, n - 1) coe[i + 1] = (coe[i] - (LL)C(n - 1, i) - C(n - 1, i + 1)) % Mod;
	ans = 0;
	REP(i, 2, maxabs + 1)
		if (SZ(cnt[i]))
		{
			sort(ALL(cnt[i]), greater<int>());
			REP(j, 0, SZ(cnt[i])) (ans += (LL)cnt[i][j] * coe[j] % Mod) %= Mod;
		}
	(ans += Mod) %= Mod;
	printf("%d\n", ans);
	return 0;
}