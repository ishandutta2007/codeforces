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

inline int fpm(LL b, int e, int m)
{
	b %= m;
	LL t = 1;
	for ( ; e; e >>= 1, (b *= b) %= m)
		if (e & 1) (t *= b) %= m;
	return t;
}

const int Mod = 1e9 + 7;

const int maxk = 10100;

LL fac[maxk + 5], ifac[maxk + 5];
LL inv[maxk + 5];

inline void prepare()
{
	fac[0] = 1;
	REP(i, 0, maxk) fac[i + 1] = (LL)fac[i] * (i + 1) % Mod;
	ifac[maxk] = fpm(fac[maxk], Mod - 2, Mod);
	for (int i = maxk - 1; i >= 0; --i) ifac[i] = (LL)ifac[i + 1] * (i + 1) % Mod;
	REP(i, 1, maxk + 1) inv[i] = (LL)ifac[i] * fac[i - 1] % Mod;
}

LL dp[100];
int K;

inline void work(int x)
{
	memset(dp, 0, sizeof dp);
	dp[x] = 1;
	REP(i, 0, K)
	{
		LL sum = 0;
		for (int j = x; j >= 0; --j)
		{
			(sum += dp[j] * inv[j + 1]) %= Mod;
			dp[j] = sum;
		}
	}
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	prepare();
	LL n;
	cin >> n >> K;
	LL ans = 1;
	for (LL i = 2; i * i <= n; ++i)
	{
		if (!(n % i))
		{
			int cnt = 0;
			while (!(n % i)) ++cnt, n /= i;
			memset(dp, 0, sizeof dp);
			work(cnt);
			LL tmp = 1;
			LL ret = 0;
			REP(j, 0, cnt + 1)
			{
				(ret += tmp * dp[j] % Mod) %= Mod;
				tmp = tmp * i % Mod;
			}
			ans = ans * ret % Mod;
		}
	}
	if (n > 1)
	{
		work(1);
		ans = ans * (dp[0] + dp[1] * (n % Mod) % Mod) % Mod;
	}
	(ans += Mod) %= Mod;
	printf("%lld\n", ans);
	return 0;
}