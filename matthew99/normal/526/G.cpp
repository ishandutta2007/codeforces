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
#define EXIT(...) printf(__VA_ARGS__), exit(0)

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 100000, max0 = 17;

struct edge
{
	int id, g, nxt;

	edge() { }
	edge(int _id, int _g, int _nxt): id(_id), g(_g), nxt(_nxt) { }

};

edge e[(maxn << 1) + 5];
int st[maxn + 5], en = 0;

inline void add_edge(int x, int y, int z)
{
	e[en] = edge(y, z, st[x]), st[x] = en++;
}

inline bool del_edge(int x, int y)
{
	for (int *i = st + x; *i != -1; i = &e[*i].nxt)
		if (e[*i].id == y) 
		{
			*i = e[*i].nxt;
			return 1;
		}
	return 0;
}

int n;
int ori_n;

int dis[maxn + 5], fa[max0][maxn + 5], Max[maxn + 5];

void pre_dfs(int x, int f = -1)
{
	fa[0][x] = f;
	for (int i = st[x]; i != -1; i = e[i].nxt)
	{
		int y = e[i].id;
		if (y == f) continue;
		dis[y] = dis[x] + e[i].g;
		pre_dfs(y, x);
	}
}

int dfs_tot = 0;
int dfs_seq[maxn + 5];
int dfn[maxn + 5], End[maxn + 5];

void dfs(int x, int f = -1)
{
	fa[0][x] = f;
	Max[x] = dis[x];
	dfs_seq[dfn[x] = dfs_tot++] = x;
	for (int i = st[x]; i != -1; i = e[i].nxt)
	{
		int y = e[i].id;
		if (y == f) continue;
		dis[y] = dis[x] + e[i].g;
		dfs(y, x);
		chkmax(Max[x], Max[y]);
	}
	End[x] = dfs_tot;
}

int in[maxn + 5];

struct node;
 
node *newnode();
 
struct node
{
	node *c[2];

	pair<int, int> Max;
	int label;
 
	node(): Max(mp(-1, -1)), label(0) { memset(c, 0, sizeof c); }
 
	void update()
	{
		Max = mp(-1, -1);
		REP(i, 0, 2) if (c[i]) chkmax(Max, c[i]->Max);
	}

	void flag_label(int _label)
	{
		label += _label;
		Max.x += _label;
	}

	void push_down()
	{
		if (label)
		{
			REP(i, 0, 2) 
			{
				assert(c[i]);
				c[i]->flag_label(label);
			}
			label = 0;
		}
	}
 
};

const int max1 = 100000;
 
node *nd_pool;
int nd_res = 0;
 
node *newnode()
{
	if (!nd_res) nd_pool = new node[max1], nd_res = max1;
	return nd_pool + (--nd_res);
}
 
node *rt;
 
int seg_x, seg_y, seg_z;

void build(node *&rt, int l, int r)
{
	if (!rt) rt = newnode();
	if (r - l <= 1)
	{
		rt->Max = mp(dis[dfs_seq[l]], dfs_seq[l]);
		return;
	}
	int mid = (l + r) >> 1;
	build(rt->c[0], l, mid);
	build(rt->c[1], mid, r);
	rt->update();
}
 
void add(node *&rt, int l, int r)
{
	assert(rt);
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

inline bool seg_add(node *&rt, int x, int y, int z)
{
	if (x >= y) return 0;
	seg_x = x, seg_y = y, seg_z = z;
	add(rt, 0, n);
	return 1;
}

void query(node *rt, int l, int r, int sum = 0)
{
	assert(rt);
	if (seg_x <= l && r <= seg_y)
	{
		chkmax(seg_z, rt->Max.x + sum);
		return;
	}
	sum += rt->label;
	int mid = (l + r) >> 1;
	if (seg_x < mid) query(rt->c[0], l, mid, sum);
	if (seg_y > mid) query(rt->c[1], mid, r, sum);
}

inline int seg_query(node *&rt, int x, int y)
{
	if (x >= y) return 0;
	seg_x = x, seg_y = y, seg_z = 0;
	query(rt, 0, n);
	return seg_z;
}

int tot_dis[maxn + 5], pre_Min[maxn + 5], pick[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	memset(st, -1, sizeof st), en = 0;
	int qn;
	scanf("%d%d", &n, &qn);
	if (n == 1)
	{
		REP(i, 0, qn) printf("0\n");
		return 0;
	}
	ori_n = n;
	REP(i, 0, n - 1)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z), --x, --y;
		add_edge(x, y, z << 1); 
		add_edge(y, x, z << 1); 
	}
	dis[0] = 0;
	pre_dfs(0);
	int a = max_element(dis, dis + n) - dis;
	dis[a] = 0;
	pre_dfs(a);
	int b = max_element(dis, dis + n) - dis;

	assert(!(dis[b] & 1));
	int tmp = dis[b] >> 1;
	while (dis[fa[0][b]] >= tmp) b = fa[0][b];
	if (dis[b] != tmp)
	{
		assert(del_edge(fa[0][b], b));
		assert(del_edge(b, fa[0][b]));
		add_edge(fa[0][b], n, tmp - dis[fa[0][b]]);
		add_edge(n, fa[0][b], tmp - dis[fa[0][b]]);
		add_edge(b, n, dis[b] - tmp);
		add_edge(n, b, dis[b] - tmp);
		b = n;
		++n;
	}

	dis[b] = 0;
	dfs_tot = 0;
	dfs(b);

	build(rt, 0, n);
	memset(in, -1, sizeof in);
	in[b] = 0;
	tot_dis[0] = 0;
	pre_Min[0] = oo;
	REP(i, 1, n + 1)
	{
		pre_Min[i] = pre_Min[i - 1];
		tot_dis[i] = tot_dis[i - 1];
		pair<int, int> tmp = rt->Max;
		if (tmp.x)
		{
			pick[i] = tmp.y;
			chkmin(pre_Min[i], tmp.x);
			tot_dis[i] += tmp.x;
			int u = tmp.y;
			while (in[u] == -1)
			{
				in[u] = i;
				seg_add(rt, dfn[u], End[u], dis[fa[0][u]] - dis[u]);
				u = fa[0][u];
			}
		}
	}

	REP(i, 1, max0)
		REP(j, 0, n)
			if (fa[i - 1][j] == -1) fa[i][j] = fa[i - 1][j];
			else fa[i][j] = fa[i - 1][fa[i - 1][j]];

	int last_ans = 0;
	while (qn--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		(x += ori_n + last_ans - 1) %= ori_n;
		++((y += ori_n + last_ans - 1) %= ori_n);
		y <<= 1;
		chkmin(y, n);
		if (in[x] <= y) last_ans = tot_dis[y];
		else
		{
			int ans = tot_dis[y] + Max[x];
			for (int i = max0 - 1; i >= 0; --i)
				if (fa[i][x] != -1 && in[fa[i][x]] > y) x = fa[i][x];
			x = fa[0][x];
			ans -= dis[x];
			int tmp = pick[in[x]];
			ans -= min(pre_Min[y], dis[tmp] - dis[x]);
			last_ans = ans;
		}
		last_ans >>= 1;
		printf("%d\n", last_ans);
	}
	return 0;
}