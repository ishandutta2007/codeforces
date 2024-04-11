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

const int maxn = 100100, maxm = 100100;

int fac[maxn + 5], ifac[maxn + 5];

inline int fpm(LL b, int e, int m)
{
	b %= m;
	LL t = 1;
	for ( ; e; e >>= 1, (b *= b) %= m)
		if (e & 1) (t *= b) %= m;
	return t;
}

int w;
int pw26[maxn + 5];
int pww[maxn + 5];

inline void prepare()
{
	w = (LL)25 * fpm(26, Mod - 2, Mod) % Mod;
	pw26[0] = pww[0] = 1;
	REP(i, 0, maxn) pw26[i + 1] = (LL)pw26[i] * 26 % Mod, pww[i + 1] = (LL)pww[i] * w % Mod;
	fac[0] = 1;
	REP(i, 0, maxn) fac[i + 1] = (LL)fac[i] * (i + 1) % Mod;
	ifac[maxn] = fpm(fac[maxn], Mod - 2, Mod);
	for (int i = maxn - 1; i >= 0; --i) ifac[i] = (LL)ifac[i + 1] * (i + 1) % Mod;
}

struct data
{
	int n, m, id;

	data() { }
	data(int _n, int _m, int _id): n(_n), m(_m), id(_id) { }

	friend bool operator<(const data &x, const data &y) { return x.m < y.m; }

};

data q[maxm + 5];
int qn = 0;

int ans[maxm + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	prepare();
	int m;
	scanf("%d", &m);
	static char s[maxn + 5];
	scanf("%s", s);
	int now = strlen(s);
	REP(i, 0, m)
	{
		int ty;
		scanf("%d", &ty);
		if (ty == 1)
		{
			scanf("%s", s);
			now = strlen(s);
		}
		else
		{
			int x;
			scanf("%d", &x);
			q[qn] = data(x, now, qn);
			++qn;
		}
	}
	sort(q, q + qn);
	for (int i = 0; i < qn; )
	{
		int j = i;
		static int f[maxn + 5];
		int m = q[i].m;
		REP(i, 0, m) f[i] = 0;
		REP(k, m, maxn + 1)
			f[k] = (f[k - 1] + (LL)fac[k - 1] * ifac[k - m] % Mod * ifac[m - 1] % Mod * pww[k - m] % Mod) % Mod;
		while (j < qn && q[j].m == q[i].m)
		{
			if (q[j].n < q[j].m) ans[q[j].id] = 0;
			else ans[q[j].id] = (LL)pw26[q[j].n - q[j].m] * f[q[j].n] % Mod;
			++j;
		}
		i = j;
	}
	REP(i, 0, qn) (ans[i] += Mod) %= Mod;
	REP(i, 0, qn) printf("%d\n", ans[i]);
	return 0;
}