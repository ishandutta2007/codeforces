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

const int maxn = 200000, max0 = 1000000;

int fac[maxn + 5], ifac[maxn + 5];

vector<int> frac[max0 + 5];

inline int fpm(LL b, int e, int m)
{
	b %= m;
	LL t = 1;
	for ( ; e; e >>= 1, (b *= b) %= m)
		if (e & 1) (t *= b) %= m;
	return t;
}

int mu[max0 + 5], coe[max0 + 5];

inline void prepare()
{
	mu[1] = 1;
	for (int i = 1; i <= max0; ++i) for (int j = i << 1; j <= max0; j += i) mu[j] -= mu[i];
	for (int i = 1; i <= max0; ++i)
	{
		for (int j = 1; i * j <= max0; ++j)
		{
			frac[i * j].pb(i);
			if (mu[j]) (coe[i * j] += i * mu[j]) %= Mod;
		}
	}
	fac[0] = 1;
	REP(i, 0, maxn) fac[i + 1] = (LL)fac[i] * (i + 1) % Mod;
	ifac[maxn] = fpm(fac[maxn], Mod - 2, Mod);
	for (int i = maxn - 1; i >= 0; --i) ifac[i] = (LL)ifac[i + 1] * (i + 1) % Mod;
}

int cnt[max0 + 5];

int n, K, qn;

int now;

inline void add(int x)
{
	for (auto u : frac[x])
	{
		if (cnt[u] >= K - 1) (now += (LL)fac[cnt[u]] * ifac[cnt[u] - K + 1] % Mod * ifac[K - 1] % Mod * coe[u] % Mod) %= Mod;
		++cnt[u];
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	prepare();
	scanf("%d%d%d", &n, &K, &qn);
	REP(i, 0, n)
	{
		int x;
		scanf("%d", &x);
		add(x);
	}
	REP(i, 0, qn)
	{
		int x;
		scanf("%d", &x);
		add(x);
		(now += Mod) %= Mod;
		printf("%d\n", now);
	}
	return 0;
}