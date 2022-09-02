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

#ifdef __WIN32
#define LLFORMAT "I64"
#define Rand() ((rand() << 15) | rand())
#else
#define LLFORMAT "ll"
#define Rand() (rand())
#endif

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 200000, maxm = 100000;

struct node
{
	node *c[2], *p;
	bool rev;
	int Min;
	int val;

	node(): p(NULL), rev(0), Min(INT_MAX) { memset(c, 0, sizeof c); }

	void update()
	{
		Min = val;
		REP(i, 0, 2) if (c[i]) chkmin(Min, c[i]->Min);
	}

	void flag_rev()
	{
		rev ^= 1;
		swap(c[0], c[1]);
	}

	void push_down()
	{
		if (rev)
		{
			REP(i, 0, 2) if (c[i]) c[i]->flag_rev();
			rev = 0;
		}
	}

	int get_pos()
	{
		if (!this || !p) return 2;
		REP(i, 0, 2) if (p->c[i] == this) return i;
		return 2;
	}

	bool is_root()
	{
		return get_pos() >= 2;
	}

	void setc(node *u, const int &v)
	{
		if (this && v < 2) c[v] = u;
		if (u) u->p = this;
	}

	void rotate()
	{
		node *p = this->p;
		bool mark = get_pos();
		p->p->setc(this, p->get_pos());
		p->setc(c[mark ^ 1], mark);
		setc(p, mark ^ 1);
		p->update();
	}

	void relax()
	{
		static node *tmp[maxn + 5];
		int top = 0;
		node *u = this;
		while (!u->is_root()) tmp[top++] = u, u = u->p;
		u->push_down(); while (top) tmp[--top]->push_down();
	}

	void splay()
	{
		relax();
		for ( ; !is_root(); rotate())
			if (!p->is_root()) ((p->p->c[0] == p) == (p->c[0] == this) ? p : this)->rotate();
		update();
	}

	node *access()
	{
		node *u = this, *v = NULL;
		for ( ; u; v = u, u = u->p) u->splay(), u->setc(v, 1), u->update();
		splay();
		return v;
	}

	void be_root()
	{
		access();
		flag_rev();
	}
};

node nd[maxn + 5];

inline int query(int x, int y)
{
	node *u = nd + x, *v = nd + y;
	u->be_root(), v->access();
	return v->Min;
}

inline void modify(int x, int w)
{
	node *u = nd + x;
	u->access(), u->val = w, u->update();
}

struct edge
{
	int id, nxt;

	edge() { }
	edge(int _id, int _nxt): id(_id), nxt(_nxt) { }

};

edge e[(maxm << 1) + 5];
int st[maxn + 5], en = 0;

inline void add_edge(int x, int y) { e[en] = edge(y, st[x]), st[x] = en++; }
inline void add_biedge(int x, int y) { add_edge(x, y), add_edge(y, x); }

int n, m, qn;
int N;

int fa[maxn + 5];

int tot;
int dfn[maxn + 5], low[maxn + 5];
int belong[maxn + 5];

int seq[maxn + 5];

int w[maxn + 5];
multiset<int> now[maxn + 5];

struct data
{
	int ty, x, y;

	data() { }
	data(int _ty, int _x, int _y): ty(_ty), x(_x), y(_y) { }

};

data q[maxm + 5];

int get(int x) { return belong[x] == x ? x : belong[x] = get(belong[x]); }

int _fa[maxn + 5];

bool ok[maxm + 5];
int lca[maxm + 5];
vector<pair<int, int> > all[maxn + 5];
vector<int> allq[maxn + 5];

int _get(int x) { return _fa[x] == x ? x : _fa[x] = _get(_fa[x]); }

bool in[maxn + 5];

void dfs(int x, int f = -1)
{
	in[x] = 1;
	seq[dfn[x] = low[x] = tot++] = x;
	belong[x] = x;
	fa[x] = f;
	if (~f) nd[x].p = nd + f;
	for (auto u : all[x])
	{
		if (!~dfn[u.x]) continue;
		if (in[u.x]) lca[u.y] = u.x;
		else
		{
			int t = _get(u.x);
			lca[u.y] = fa[t];
			if (low[t] < dfn[lca[u.y]]) ok[u.y] = 1;
		}
		allq[lca[u.y]].pb(u.y);
	}
	allq[x].clear();
	for (int i = st[x]; ~i; i = e[i].nxt)
	{
		int y = e[i].id;
		if (y == f) continue;
		if (!~dfn[y]) 
		{
			dfs(y, x), chkmin(low[x], low[y]);
			if (low[y] < dfn[x]) 
			{
				for (auto u : allq[x]) ok[u] = 1;
				belong[y] = x;
			}
			else
			{
				belong[N] = belong[y] = N;
				nd[y].p = nd + N;
				nd[N].p = nd + x;
				++N;
			}
			allq[x].clear();
		}
		else chkmin(low[x], dfn[y]);
	}
	for (int i = st[x]; ~i; i = e[i].nxt)
	{
		int y = e[i].id;
		if (fa[y] == x) _fa[y] = x;
	}
	in[x] = 0;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	memset(st, -1, sizeof st), en = 0;
	scanf("%d%d%d", &n, &m, &qn);
	REP(i, 0, n) scanf("%d", w + i);
	REP(i, 0, m)
	{
		int x, y;
		scanf("%d%d", &x, &y), --x, --y;
		add_biedge(x, y);
	}
	REP(i, 0, qn)
	{
		static char s[100];
		int x, y;
		scanf("%s%d%d", s, &x, &y);
		if (s[0] == 'A')
		{
			in[i] = 0;
			--x, --y;
			q[i] = data(0, x, y);
			all[x].pb(mp(y, i));
			all[y].pb(mp(x, i));
		}
		else if (s[0] == 'C')
		{
			--x;
			q[i] = data(1, x, y);
		}
	}
	REP(i, 0, n) _fa[i] = i;
	memset(dfn, -1, sizeof dfn), tot = 0;
	N = n;
	dfs(0);
	REP(i, 0, N) get(i);
	REP(i, 0, n) now[belong[i]].insert(w[i]);
	REP(i, 0, N) nd[i].val = (belong[i] == i ? *now[i].begin() : w[i]), nd[i].update();
	REP(i, 0, qn)
	{
		if (q[i].ty)
		{
			int tmp = belong[q[i].x];
			modify(q[i].x, q[i].y);
			int from = *now[tmp].begin();
			now[tmp].erase(now[tmp].find(w[q[i].x]));
			w[q[i].x] = q[i].y;
			now[tmp].insert(w[q[i].x]);
			int to = *now[tmp].begin();
			if (from != to) modify(tmp, to);
		}
		else
		{
			int ans = query(q[i].x, q[i].y);
			if (ok[i]) chkmin(ans, min(*now[belong[lca[i]]].begin(), w[seq[low[lca[i]]]]));
			printf("%d\n", ans);
		}
	}
	return 0;
}