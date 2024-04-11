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

const int maxk = 1000002;

inline int fpm(LL b, int e, int m)
{
	b %= m;
	LL t = 1;
	for ( ; e; e >>= 1, (b *= b) %= m)
		if (e & 1) (t *= b) %= m;
	return t;
}

int fac[maxk + 5], ifac[maxk + 5];

inline void prepare()
{
	fac[0] = 1;
	REP(i, 0, maxk) fac[i + 1] = (LL)fac[i] * (i + 1) % Mod;
	ifac[maxk] = fpm(fac[maxk], Mod - 2, Mod);
	for (int i = maxk - 1; i >= 0; --i) ifac[i] = (LL)ifac[i + 1] * (i + 1) % Mod;
}


int n, k;

int sum[maxk + 5];

inline int calc(int n, int k)
{
	if (!k) return n % Mod;
	++n, ++k;
	sum[0] = 0;
	vector<int> pr;
	static bool vis[maxk + 5];
	static int sum[maxk + 5], val[maxk + 5];
	memset(vis, 0, sizeof(vis[0]) * k);
	val[0] = 0;
	val[1] = 1;
	for (int i = 2; i < k; ++i)
	{
		if (!vis[i]) pr.pb(i), val[i] = fpm(i, k - 1, Mod);
		for (int j = 0, _end_ = SZ(pr); j < _end_ && i * pr[j] < k; ++j)
		{
			vis[i * pr[j]] = 1;
			val[i * pr[j]] = (LL)val[i] * val[pr[j]] % Mod;
			if (!(i % pr[j])) break;
		}
	}
	sum[0] = 0;
	REP(i, 0, k) sum[i + 1] = (sum[i] + val[i]) % Mod;
	if (n <= k) return sum[n] % Mod;
	else
	{
		int ans = 0;
		static int pre[maxk + 5], suf[maxk + 5];
		pre[0] = 1;
		REP(i, 0, k) pre[i + 1] = (LL)pre[i] * (n - i) % Mod;
		suf[k] = 1;
		for (int i = k; i > 0; --i) suf[i - 1] = (LL)suf[i] * (n - i) % Mod;
		REP(i, 0, k + 1)
		{
			int tmp = sum[i] * (LL)pre[i] % Mod * suf[i] % Mod * ifac[k - i] % Mod * ifac[i] % Mod;
			if ((k - i) & 1) (ans -= tmp) %= Mod;
			else (ans += tmp) %= Mod;
		}
		return ans;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	prepare();
	scanf("%d%d", &n, &k);
	printf("%d\n", (calc(n, k) + Mod) % Mod);
	return 0;
}