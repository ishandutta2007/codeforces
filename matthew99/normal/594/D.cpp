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

const int maxn = 200000, maxm = 200000, max0 = 2000000;
const int maxabs = 1000000;

int n;
int a[maxn + 5];

int N = 0;
int b[max0 + 5];

int lst[maxabs + 5];

int pos[maxm + 5];
int p[maxn + 5];

pair<int, int> q[maxm + 5];
int ans[maxm + 5];
int pre[max0 + 5];
bool ok[max0 + 5];

inline bool cmp(int x, int y)
{
	return q[x].y > q[y].y;
}

int c[max0 + 5];

inline void mul(int x, int y)
{
	for (int i = x + 1; i <= N; i += i & -i)
		c[i] = (LL)c[i] * y % Mod;
}

inline int query(int x)
{
	int ret = 1;
	for (int i = x; i > 0; i -= i & -i)
		ret = (LL)ret * c[i] % Mod;
	return ret;
}

inline int fpm(LL b, int e, int m)
{
	b %= m;
	LL t = 1;
	for ( ; e; e >>= 1, (b *= b) %= m)
		if (e & 1) (t *= b) %= m;
	return t;
}

int w[maxabs + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	static int pro[maxn + 5];
	pro[0] = 1;
	REP(i, 0, n) scanf("%d", a + i), pro[i + 1] = (LL)pro[i] * a[i] % Mod;
	REP(i, 1, maxabs + 1) w[i] = (LL)fpm(i, Mod - 2, Mod) * (i - 1) % Mod;
	pos[0] = 0;
	REP(i, 0, n)
	{
		int x = a[i];
		for (int j = 2; j * j <= x; ++j)
		{
			if (!(x % j))
			{
				b[N++] = j;
				while (!(x % j)) x /= j;
			}
		}
		if (x > 1) b[N++] = x;
		p[i + 1] = N;
	}
	REP(i, 1, N + 1) c[i] = 1;
	int m;
	scanf("%d", &m);
	REP(i, 0, m)
	{
		int l, r;
		scanf("%d%d", &l, &r), --l;
		ans[i] = (LL)pro[r] * fpm(pro[l], Mod - 2, Mod) % Mod;
		q[i] = mp(p[l], p[r]);
	}
	REP(i, 0, m) pos[i] = i;
	sort(pos, pos + m, cmp);
	memset(lst, -1, sizeof lst);
	REP(i, 0, N) ok[i] = 1;
	REP(i, 0, N)
	{
		if (lst[b[i]] >= 0) ok[lst[b[i]]] = 0;
		pre[i] = lst[b[i]];
		lst[b[i]] = i;
	}
	REP(i, 0, N) if (ok[i]) mul(i, w[b[i]]);
	int lst = N;
	REP(i, 0, m)
	{
		int l = q[pos[i]].x, r = q[pos[i]].y;
		while (lst > r)
		{
			--lst;
			if (pre[lst] != -1) mul(pre[lst], w[b[pre[lst]]]);
		}
		ans[pos[i]] = (LL)ans[pos[i]] * query(r) % Mod * fpm(query(l), Mod - 2, Mod) % Mod;
		(ans[pos[i]] += Mod) %= Mod;
	}
	REP(i, 0, m) printf("%d\n", ans[i]);
	return 0;
}