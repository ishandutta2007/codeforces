#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
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

const int maxn = 2000000;

int n, k;
LL l;
int a[maxn + 5];

int fac[maxn + 5], ifac[maxn + 5];

int fpm(LL b, int e, int m)
{
	LL t = 1;
	for ( ; e; e >>= 1, (b *= b) %= m)
		if (e & 1) (t *= b) %= m;
	return t;
}

inline void prepare()
{
	fac[0] = 1;
	REP(i, 0, maxn + 2) fac[i + 1] = (LL)fac[i] * (i + 1) % Mod;	
	ifac[maxn + 2] = fpm(fac[maxn + 2], Mod - 2, Mod);
	for (int i = maxn + 1; i >= 0; --i) ifac[i] = (LL)ifac[i + 1] * (i + 1) % Mod;
}

inline int C(int x, int y)
{
	if (x < y) return 0;
	return fac[x] * (LL)ifac[y] % Mod * ifac[x - y] % Mod;
}

vector<vector<int> > dp;

map<int, int> all;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	prepare();
	scanf("%d%I64d%d", &n, &l, &k);
	vector<int> v;
	REP(i, 0, n) scanf("%d", a + i), v.pb(a[i]);
	dp.resize(n + 5);
	REP(i, 0, n + 5) dp[i].resize(k + 5);
	sort(ALL(v));
	dp[0][0] = 1;
	for (int i = 0; i < n; )
	{
		int j = i;
		while (v[j] == v[i]) ++j;
		dp[j][0] = 1;
		REP(a, 1, k + 1) dp[j][a] = (dp[i][a] + (LL)(j - i) * dp[j][a - 1]) % Mod;
		i = j;
	}
	LL tot = l / n;
	int res = l % n;
	int ans = 0;
	REP(i, 1, k + 1)
		(ans += dp[n][i] * (max(0LL, tot - i + 1) % Mod) % Mod) %= Mod;
	REP(i, 0, res)
	{
		int lyc = upper_bound(ALL(v), a[i]) - v.begin();
		REP(j, 0, k)
			(ans += dp[lyc][j] * (j <= tot)) %= Mod;
	}
	(ans += Mod) %= Mod;
	printf("%d\n", ans);
	return 0;
}