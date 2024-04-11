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

const int maxn = 100000, max0 = 17;
const int max1 = 10000000;

struct edge
{
	int id, nxt;

	edge() { }
	edge(const int &_id, const int &_nxt): id(_id), nxt(_nxt) { }

};

int n, m, q;
int st[maxn + 5];
int en;
edge e[(maxn << 1) + 5];

int fa[max0][maxn + 5];

vector<int> val[maxn + 5];

inline void add_edge(const int &x, const int &y)
{
	e[en] = edge(y, st[x]), st[x] = en++;
}

void init()
{
	memset(st, -1, sizeof st), en = 0;
	scanf("%d%d%d", &n, &m, &q);
	REP(i, 0, n - 1)
	{
		static int x, y;
		scanf("%d%d", &x, &y), --x, --y;
		add_edge(x, y);
		add_edge(y, x);
	}
	REP(i, 0, m)
	{
		int x;
		scanf("%d", &x), --x;
		val[x].pb(i + 1);
	}
}

struct node
{
	node *c[2];

	int sum;

	node() { memset(c, 0, sizeof c); }

	int get_sum() { return !this ? 0 : sum; }

	node *getc(int k) { return !this ? NULL : c[k]; }

};

int nd_cur = 0;
node nd[max1 + 5];

node *rt[maxn + 5], *rt0[maxn + 5];

int dep[maxn + 5];

void add(node *&rt, const int &x, const int &l, const int &r)
{
	if (!rt) rt = nd + (nd_cur++);
	else
	{
		node tmp = *rt;
		rt = nd + (nd_cur++);
		*rt = tmp;
	}
	++rt->sum;
	if (r - l <= 1) return;
	int mid = (l + r) >> 1;
	if (x < mid) add(rt->c[0], x, l, mid);
	else add(rt->c[1], x, mid, r);
}

void dfs(const int &x, const int &f = -1)
{
	for (auto it : val[x]) add(rt[x], it, 0, maxn + 5), add(rt0[x], it, 0, maxn + 5);
	fa[0][x] = f;
	for (int i = st[x]; i != -1; i = e[i].nxt)
	{
		const int &y = e[i].id;
		if (y == f) continue;
		dep[y] = dep[x] + 1;
		rt[y] = rt[x];
		dfs(y, x);
	}
}

int lca(int x, int y)
{
	int u = x, v = y;
	if (dep[x] > dep[y]) swap(x, y);
	for (int i = 0; dep[x] != dep[y]; ++i)
		if ((dep[y] - dep[x]) >> i & 1) y = fa[i][y];
	int s = max0 - 1;
	while (x != y)
	{
		for ( ; s && fa[s][y] == fa[s][x]; --s);
		if (x == -1 || y == -1)
		{
			debug("%d %d\n", u, v);
			exit(1);
		}
		x = fa[s][x];
		y = fa[s][y];
	}
	return x;
}

int find(int x, int y, int d, int id)
{
	++id;
	node *rtx = rt[x], *rty = rt[y], *rtd = rt[d], *rtdd = rt0[d];
	int l = 0, r = maxn + 5;
	while (r - l > 1)
	{
		int mid = (l + r) >> 1;
		int tmp = rtx->getc(0)->get_sum() + rty->getc(0)->get_sum() - (rtd->getc(0)->get_sum() << 1) + (rtdd->getc(0)->get_sum());
		if (tmp < id)
		{
			id -= tmp;
			l = mid;
			rtx = rtx->getc(1);
			rty = rty->getc(1);
			rtd = rtd->getc(1);
			rtdd = rtdd->getc(1);
		}
		else
		{
			r = mid;
			rtx = rtx->getc(0);
			rty = rty->getc(0);
			rtd = rtd->getc(0);
			rtdd = rtdd->getc(0);
		}
	}
	return l;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	init();
	rt[0] = NULL;
	dfs(0);
	REP(i, 1, max0)
		REP(j, 0, n)
			if (fa[i - 1][j] == -1) fa[i][j] = fa[i - 1][j];
			else fa[i][j] = fa[i - 1][fa[i - 1][j]];
	REP(i, 0, q)
	{
		int x, y, a;
		scanf("%d%d%d", &x, &y, &a), --x, --y;
		int d = lca(x, y);
		int tot = rt[x]->get_sum() + rt[y]->get_sum() - (rt[d]->get_sum() << 1) + SZ(val[d]);
		printf("%d ", min(a, tot));
		REP(i, 0, min(a, tot)) printf("%d ", find(x, y, d, i));
		printf("\n");
	}
	return 0;
}