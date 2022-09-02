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

const int __buffsize = 100000;
char __buff[__buffsize];
char *__buffs, *__buffe;

#define getc() (__buffs == __buffe ? fread(__buff, 1, __buffsize, stdin), __buffe = __buff + __buffsize, *((__buffs = __buff)++) : *(__buffs++))

template<typename T> inline T &Read(T &x)
{
	static char c;
	while (1) 
	{ 
		c = getc(); 
		if (c == '-' || (c >= '0' && c <= '9')) break; 
	}
	bool flag = c == '-';
	x = flag ? 0 : c - '0';
	while (1)
	{
		c = getc();
		if (c < '0' || c > '9') break;
		(x *= 10) += c - '0';
	}
	if (flag) x = -x;
	return x;
}

#undef getc

const int maxn = 100100, maxm = 100100;

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

inline void add_biedge(int x, int y)
{
	add_edge(x, y), add_edge(y, x);
}

int n, m, qn;

int fa[maxn + 5];
int sz[maxn + 5], Max[maxn + 5], cur[maxn + 5];

int dfs_seq[maxn + 5], dfs_tot;

int dep[maxn + 5];

void dfs(int x)
{
	fa[x] = -1;
	dep[x] = 0;
	int u = x;
	bool flag = 0;
	while (u != -1)
	{
		if (!flag)
		{
			dfs_seq[dfs_tot++] = u;
			sz[u] = 1;
			Max[u] = -1;
			cur[u] = st[u];
			flag = 1;
		}
		for (int &i = cur[u]; i != -1; i = e[i].nxt)
		{
			const int &v = e[i].id;
			if (v == fa[u]) continue;
			dep[v] = dep[u] + 1;
			fa[v] = u;
			u = v;
			i = e[i].nxt;
			flag = 0;
			break;
		}
		if (flag)
		{
			int v = u; u = fa[u];
			if (u != -1)
			{
				sz[u] += sz[v];
				if (Max[u] == -1 || sz[v] > sz[Max[u]]) Max[u] = v;
			}
		}
	}
}

int hseq[maxn + 5];
int dfn[maxn + 5], End[maxn + 5];
int tot = 0;

void heavy_first_dfs(int x)
{
	hseq[dfn[x] = tot++] = x;
	if (Max[x] != -1) heavy_first_dfs(Max[x]);
	for (int i = st[x]; i != -1; i = e[i].nxt)
	{
		int y = e[i].id;
		if (y == fa[x] || y == Max[x]) continue;
		heavy_first_dfs(y);
	}
	End[x] = tot;
}

int now;

int c[maxm + 5];

inline void upd(pair<LL, int> &a, const pair<LL, int> &b)
{
	if (a.x > b.x) a = b;
	else if (a.x == b.x && ~a.y && c[b.y] < c[a.y]) a = b;
}

struct node
{
	node *c[2];
	pair<LL, int> Min;
	LL label;

	node(): Min(mp(LLONG_MAX, -1)) { memset(c, 0, sizeof c); }

	void update()
	{
		Min = mp(LLONG_MAX, -1);
		REP(i, 0, 2) if (c[i]) upd(Min, c[i]->Min);
	}

	void flag_label(const LL &_label)
	{
		label += _label;
		if (Min.x != LLONG_MAX) Min.x += _label;
	}

	void push_down()
	{
		if (label)
		{
			REP(i, 0, 2) if (c[i]) c[i]->flag_label(label);
			label = 0;
		}
	}

};

const int max0 = 100000;

node *nd_pool;
int nd_res = 0;

node *newnode()
{
	if (!nd_res) nd_pool = new node[max0], nd_res = max0;
	return nd_pool + (--nd_res);
}

int seg_x, seg_y, seg_z;
LL seg_delta;
pair<LL, int> seg_ret;

vector<int> all[maxn + 5];

void build(node *&rt, int l, int r)
{
	if (!rt) rt = newnode();
	if (r - l <= 1) 
	{
		if (all[hseq[l]].empty()) rt->Min = mp(LLONG_MAX, -1);
		else rt->Min = mp(all[hseq[l]].back(), all[hseq[l]].back());
		return;
	}
	int mid = (l + r) >> 1;
	build(rt->c[0], l, mid);
	build(rt->c[1], mid, r);
	rt->update();
}

void add(node *rt, int l, int r)
{
	if (seg_x <= l && r <= seg_y)
	{
		rt->flag_label(seg_z);
		return;
	}
	int mid = (l + r) >> 1;
	rt->push_down();
	if (seg_x < mid) add(rt->c[0], l, mid);
	if (seg_y > mid) add(rt->c[1], mid, r);
	rt->update();
}

void del(node *rt, int l, int r)
{
	if (r - l <= 1)
	{
		if (seg_delta == LLONG_MAX) rt->Min.x = LLONG_MAX;
		else rt->Min.x += seg_delta;
		rt->Min.y = all[hseq[l]].empty() ? -1 : all[hseq[l]].back();
		return;
	}
	int mid = (l + r) >> 1;
	rt->push_down();
	if (seg_x < mid) del(rt->c[0], l, mid);
	else del(rt->c[1], mid, r);
	rt->update();
}

void query(node *&rt, int l, int r)
{
	if (seg_x <= l && r <= seg_y)
	{
		upd(seg_ret, rt->Min);
		return;
	}
	int mid = (l + r) >> 1;
	rt->push_down();
	if (seg_x < mid) query(rt->c[0], l, mid);
	if (seg_y > mid) query(rt->c[1], mid, r);
}

node *rt;

int top[maxn + 5];

inline int lca(int x, int y)
{
	while (top[x] != top[y])
	{
		if (dep[top[x]] > dep[top[y]]) swap(x, y);
		y = fa[top[y]];
	}
	return dep[x] < dep[y] ? x : y;
}

inline void query(int x, int y)
{
	int d = lca(x, y);
	seg_z = 1;
	while (1)
	{
		int nxt = dep[top[x]] < dep[d] ? d : top[x];
		seg_x = dfn[nxt];
		seg_y = dfn[x] + 1;
		query(rt, 0, n);
		if (nxt == d) break;
		x = fa[nxt];	
	}
	while (1)
	{
		int nxt = dep[top[y]] < dep[d] ? d : top[y];
		seg_x = dfn[nxt];
		seg_y = dfn[y] + 1;
		query(rt, 0, n);
		if (nxt == d) break;
		y = fa[nxt];	
	}
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	memset(st, -1, sizeof st), en = 0;
	Read(n), Read(m), Read(qn);
	REP(i, 0, n - 1)
	{
		int u, v;
		Read(u), Read(v), --u, --v;
		add_biedge(u, v);
	}
	REP(i, 0, m) Read(c[i]), --c[i];
	for (int i = m - 1; i >= 0; --i) all[c[i]].pb(i);
	dfs(0);
	top[0] = 0;
	REP(i, 1, n)
		if (sz[dfs_seq[i]] && Max[fa[dfs_seq[i]]] == dfs_seq[i]) top[dfs_seq[i]] = top[fa[dfs_seq[i]]];
		else top[dfs_seq[i]] = dfs_seq[i];
	heavy_first_dfs(0);
	build(rt, 0, n);
	REP(i, 0, qn)
	{
		int ty;
		Read(ty);
		if (ty == 1)
		{
			int u, v, K;
			Read(u), Read(v), Read(K);
			--u, --v;
			vector<int> ans;
			while (K--)
			{
				seg_ret = mp(LLONG_MAX, -1);
				query(u, v);
				if (!~seg_ret.y) break;
				ans.pb(seg_ret.y);
				seg_x = dfn[c[seg_ret.y]];
				vector<int> &tmp = all[c[seg_ret.y]];
				tmp.pop_back();
				if (tmp.empty()) seg_delta = LLONG_MAX;
				else seg_delta = tmp.back() - seg_ret.y;
				del(rt, 0, n);
			}
			printf("%d", SZ(ans));
			for (auto x : ans) printf(" %d", x + 1);
			printf("\n");
		}
		else if (ty == 2)
		{
			int u, K;
			Read(u), Read(K), --u;
			seg_x = dfn[u], seg_y = End[u], seg_z = K;
			add(rt, 0, n);
		}
	}
	return 0;
}