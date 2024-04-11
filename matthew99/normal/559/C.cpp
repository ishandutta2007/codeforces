#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define FOR(i, a, b) for (int i = (a), _end_ = (b); i <= _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define EXIT(...) printf(__VA_ARGS__), exit(0)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;

template<typename T> T &Read(T &x)
{
	static char c;
	while (!isdigit(c = getchar()));
	x = c - '0';
	while (isdigit(c = getchar())) (x *= 10) += c - '0';
	return x;
}

const int maxn = 200000, maxm = 2000;

int fpm(LL b, int e, const int &m)
{
	LL t = 1;
	for ( ; e; e >>= 1, (b *= b) %= m)
		if (e & 1) (t *= b) %= m;
	return t;
}

const int Mod = 1e9 + 7;

int ans;

int fac[maxn + 5];
int revfac[maxn + 5];

int h, w, m;

pair<int, int> a[maxm + 5];
int dp[maxm + 5];

inline int C(const int &n, const int &m)
{
	return fac[n] * (LL)revfac[m] % Mod * (LL)revfac[n - m] % Mod;
}

inline int calc(int n, int m)
{
	return C(n + m, n);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fac[0] = 1;
	REP(i, 0, maxn)
		fac[i + 1] = fac[i] * (LL)(i + 1) % Mod;
	revfac[maxn] = fpm(fac[maxn], Mod - 2, Mod);
	for (int i = maxn - 1; i >= 0; --i)
		revfac[i] = revfac[i + 1] * (LL)(i + 1) % Mod;
	scanf("%d%d%d", &h, &w, &m);
	REP(i, 0, m) scanf("%d%d", &a[i].x, &a[i].y), --a[i].x, --a[i].y;
	a[m++] = mp(h - 1, w - 1);
	sort(a, a + m);
	REP(i, 0, m)
	{
		dp[i] = calc(a[i].x, a[i].y);
		REP(j, 0, i)
			if (a[j].x <= a[i].x && a[j].y <= a[i].y)
				(dp[i] -= calc(a[i].x - a[j].x, a[i].y - a[j].y) * (LL)dp[j] % Mod) %= Mod;
	}
	ans = (dp[m - 1] + Mod) % Mod;
	printf("%d\n", ans);
	return 0;
}