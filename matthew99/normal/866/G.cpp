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

const int maxan = 12, maxbn = 110;
const int maxm = 260;

inline int fpm(LL b, int e, int m)
{
	b %= m;
	LL t = 1;
	for ( ; e; e >>= 1, (b *= b) %= m)
		if (e & 1) (t *= b) %= m;
	return t;
}

inline void conv(int *a, int n, int *b, int m)
{
	REP(i, 0, n) (a[i] += Mod) %= Mod;
	REP(i, 0, m) (b[i] += Mod) %= Mod;
	static LL tmp[(maxm << 1) + 5];
	memset(tmp, 0, sizeof tmp);
	REP(i, 0, n) REP(j, 0, m) tmp[i + j] += tmp[i + j] < 0 ? (LL)a[i] * b[j] : (LL)(a[i] - Mod) * b[j];
	REP(i, 0, n + m) a[i] = tmp[i] % Mod;
}

inline void poly_mod(int *a, int n, int *b, int m)
{
	int inv = fpm(b[m - 1], Mod - 2, Mod);
	static int ret[maxm + 5];
	memset(ret, 0, sizeof(ret[0]) * m);
	for (int i = n - 1; i >= 0; --i)
	{
		rotate(ret, ret + m - 1, ret + m);
		ret[0] = a[i];
		if (ret[m - 1])
		{
			int tmp = (LL)ret[m - 1] * inv % Mod;
			REP(j, 0, m) (ret[j] -= (LL)tmp * b[j] % Mod) %= Mod;
		}
	}
	memcpy(a, ret, sizeof(a[0]) * m);
}

inline void get(int *step, LL n, int *a, int *ans, int m)
{
	static int foo[(maxm << 1) + 5];
	static int bar[(maxm << 1) + 5];
	memcpy(foo, step, sizeof(foo[0]) * m);
	memset(bar, 0, sizeof(bar[0]) * m);
	bar[0] = 1;
	for ( ; n; n >>= 1, conv(foo, m, foo, m), poly_mod(foo, m << 1, a, m)) 
		if (n & 1) 
		{
			conv(bar, m, foo, m), poly_mod(bar, m << 1, a, m);
		}
	memcpy(ans, bar, sizeof(ans[0]) * m);
}

LL n;
int an, bn;
int a[maxan + 5], b[maxbn + 5], c[maxm + 5];

int dp[maxm + 5];
int ret[maxm + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> an >> bn >> n;
	REP(i, 0, an) cin >> a[i];
	int m = 0;
	REP(i, 0, bn) cin >> b[i], chkmax(m, b[i]);
	++m;
	++c[m - 1];
	REP(i, 0, bn) --c[m - b[i] - 1];
	memset(dp, 0, sizeof dp);
	dp[0] = 1;
	REP(i, 1, m)
	{
		REP(j, 0, bn)
			if (i >= b[j])
				(dp[i] += dp[i - b[j]]) %= Mod;
	}
	static int one[maxm + 5];
	static int tmp[maxm + 5];
	memset(one, 0, sizeof one);
	one[1] = 1;
	memset(ret, 0, sizeof ret);
	REP(i, 0, an)
	{
		get(one, a[i], c, tmp, m);
		REP(j, 0, m) (ret[j] += tmp[j]) %= Mod;
	}
	get(ret, n, c, tmp, m);
	int ans = 0;
	REP(i, 0, m) (ans += (LL)tmp[i] * dp[i] % Mod) %= Mod;
	(ans += Mod) %= Mod;
	printf("%d\n", ans);
	return 0;
}