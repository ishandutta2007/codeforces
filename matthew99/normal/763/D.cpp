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

const int maxn = 100100;

LL key;
LL pw[(maxn << 1) + 5];

inline LL get_lucky()
{
	while (1)
	{
		LL x = 1;
		REP(i, 1, 64) if (rand() >> 10 & 1) x |= 1LL << i;
		LL val = x;
		bool failed = 0;
		REP(i, 0, 30) 
		{
			val *= val;
			if (val == 1) { failed = 1; break; }
		}
		if (failed) continue;
		return x;
	}
	assert(0);
	return -1;
}

struct edge
{
	int id, nxt;

	edge() { }
	edge(int _id, int _nxt): id(_id), nxt(_nxt) { }

};

edge e[(maxn << 1) + 5];
int st[maxn + 5], en = 0;

inline void add_edge(int x, int y)
{
	e[en] = edge(y, st[x]), st[x] = en++;
}

int n;

int sz[maxn + 5];
int Max[maxn + 5];

void pre_dfs(int x, int f = -1)
{
	sz[x] = 1;
	Max[x] = 0;
	for (int i = st[x]; i != -1; i = e[i].nxt)
	{
		int y = e[i].id;
		if (y == f) continue;
		pre_dfs(y, x);
		sz[x] += sz[y];
		chkmax(Max[x], sz[y]);
	}
}

LL w[maxn + 5];

int id[maxn + 5];
int dep[maxn + 5];

void dfs0(int x, int f = -1)
{
	vector<pair<int, LL> > v;
	sz[x] = 1;
	for (int i = st[x]; i != -1; i = e[i].nxt)
	{
		int y = e[i].id;
		if (y == f) continue;
		dep[y] = dep[x] + 1;
		dfs0(y, x);
		v.pb(mp(sz[y], w[y]));
		sz[x] += sz[y];
	}
	sort(ALL(v));
	w[x] = 1;
	for (auto &u : v) (w[x] *= pw[u.x << 1]) += u.y;
	w[x] *= key;
}

int cnt[maxn + 5];

int tot = 0;

int ansp = -1, ans = -1;

void dfs1(int x, int f = -1)
{
	if (!--cnt[id[x]]) --tot;
	if (chkmax(ans, tot + dep[x] + 1)) ansp = x;
	for (int i = st[x]; i != -1; i = e[i].nxt)
	{
		int y = e[i].id;
		if (y == f) continue;
		dfs1(y, x);
	}
	if (!cnt[id[x]]++) ++tot;
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	key = get_lucky();
	pw[0] = 1;
	REP(i, 0, maxn) pw[i + 1] = pw[i] * key;
	memset(st, -1, sizeof st), en = 0;
	scanf("%d", &n);
	REP(i, 0, n - 1)
	{
		int x, y;
		scanf("%d%d", &x, &y), --x, --y;
		add_edge(x, y); 
		add_edge(y, x); 
	}
	pre_dfs(0);
	int rt = -1;
	REP(i, 0, n)
	{
		chkmax(Max[i], n - sz[i]);
		if (rt == -1 || Max[i] < Max[rt]) rt = i;
	}
	dep[rt] = 0;
	dfs0(rt);
	static LL ww[maxn + 5];
	memcpy(ww, w, sizeof ww);
	sort(ww, ww + n);
	REP(i, 0, n) id[i] = lower_bound(ww, ww + n, w[i]) - ww;
	memset(cnt, 0, sizeof cnt);
	REP(i, 0, n) if ((sz[i] << 1) <= n) 
	{
		if (!cnt[id[i]]++) ++tot;
	}
	dfs1(rt);
	printf("%d\n", ansp + 1);
	return 0;
}