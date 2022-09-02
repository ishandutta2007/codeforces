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

const int maxn = 2510;

const int maxabs = 100100;

int n;
int a[maxn + 5];

int dp[maxabs + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	int sum = 0;
	REP(i, 0, n) scanf("%d", a + i), sum += a[i];
	dp[0] = 0;
	dp[1] = (LL)(sum - 1) * (sum - 1) % Mod * fpm(sum, Mod - 2, Mod) % Mod;
	REP(i, 2, maxabs + 1)
	{
		dp[i] = ((LL)2 * dp[i - 1] - dp[i - 2] - (LL)(sum - 1) % Mod * fpm(sum - i + 1, Mod - 2, Mod) % Mod) % Mod;
	}
	int ans = 0;
	REP(i, 0, n) (ans += dp[a[i]]) %= Mod;
	(ans += Mod) %= Mod;
	printf("%d\n", ans);
	return 0;
}