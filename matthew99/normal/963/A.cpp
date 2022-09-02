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

const int Mod = 1e9 + 9;

inline int fpm(LL b, int e, int m)
{
	b %= m;
	LL t = 1;
	for ( ; e; e >>= 1, (b *= b) %= m)
		if (e & 1) (t *= b) %= m;
	return t;
}

const int maxm = 100100;

int n, a, b, m;
char s[maxm + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d%d", &n, &a, &b, &m);
	int step = (LL)fpm(a, Mod - 2, Mod) * b % Mod;
	int tmp0 = fpm(a, n, Mod);
	int tmp2 = fpm(step, m, Mod);
	int tmp1 = (tmp2 == 1 ? (n + 1) / m : LL(fpm(step, n + 1, Mod) - 1) * fpm(tmp2 - 1, Mod - 2, Mod) % Mod);
	scanf("%s", s);
	int ans = 0;
	REP(i, 0, m)
	{
		if (s[i] == '+') (ans += (LL)tmp0 * tmp1 % Mod) %= Mod;
		if (s[i] == '-') (ans -= (LL)tmp0 * tmp1 % Mod) %= Mod;
		tmp0 = (LL)tmp0 * step % Mod;
	}
	(ans += Mod) %= Mod;
	printf("%d\n", ans);
	return 0;
}