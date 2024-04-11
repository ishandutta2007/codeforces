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

const int maxk = 5010;

int n, K;
int S[maxk + 5][maxk + 5];

int ans;

int fac[maxk + 5], ifac[maxk + 5];

inline void prepare()
{
	fac[0] = 1;
	REP(i, 0, maxk) fac[i + 1] = (LL)fac[i] * (i + 1) % Mod;
	ifac[maxk] = fpm(fac[maxk], Mod - 2, Mod);
	for (int i = maxk - 1; i >= 0; --i) ifac[i] = (LL)ifac[i + 1] * (i + 1) % Mod;
	REP(i, 0, maxk + 1)
	{
		S[i][0] = (i == 0);
		REP(j, 1, i + 1)
		{
			S[i][j] = (S[i - 1][j - 1] + (LL)S[i - 1][j] * j) % Mod;
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
	scanf("%d%d", &n, &K);
	int cur = 1;
	ans = 0;
	REP(i, 0, min(n, K) + 1)
	{
		(ans += (LL)S[K][i] * fpm(2, n - i, Mod) % Mod * cur % Mod) %= Mod;
		cur = (LL)cur * (n - i) % Mod;
	}
	(ans += Mod) %= Mod;
	printf("%d\n", ans);
	return 0;
}