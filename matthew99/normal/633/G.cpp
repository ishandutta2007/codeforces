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

const int maxn = 100000, maxm = 1000;

typedef bitset<maxm> S;

int n, m;

S pr;
 
struct node
{
	node *c[2];

	S sum;
	int label;
 
	node(): label(0) { memset(c, 0, sizeof c); }
 
	void update()
	{
		sum = S();
		REP(i, 0, 2) 
			if (c[i]) sum |= c[i]->sum;
	}

	void flag_label(int _label)
	{
		(label += _label) %= m;
		sum = (sum >> (m - _label)) | (sum << _label);
	}

	void push_down()
	{
		REP(i, 0, 2) 
			if (c[i]) c[i]->flag_label(label);
		label = 0;
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

node *rt;

int seg_x, seg_y, seg_z;
S seg_ret;

void add(node *rt, int l, int r)
{
	if (!rt) return;
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

void query(node *rt, int l, int r)
{
	if (!rt) return;
	if (seg_x <= l && r <= seg_y)
	{
		seg_ret |= rt->sum;
		return;
	}
	int mid = (l + r) >> 1;
	rt->push_down();
	if (seg_x < mid) query(rt->c[0], l, mid);
	if (seg_y > mid) query(rt->c[1], mid, r);
}

inline bool seg_add(int x, int y, int z)
{
	if (x >= y) return 0;
	seg_x = x, seg_y = y, seg_z = z;
	add(rt, 0, n);
	return 1;
}

inline int seg_query(int x, int y)
{
	if (x >= y) return 0;
	seg_x = x, seg_y = y;
	seg_ret = S();
	query(rt, 0, n);
	return (seg_ret & pr).count();
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

int dfs_seq[maxn + 5], dfs_tot = 0;
int dfn[maxn + 5], End[maxn + 5];

int a[maxn + 5];

void dfs(int x, int f = -1)
{
	dfn[x] = dfs_tot;
	dfs_seq[dfs_tot++] = x;
	for (int i = st[x]; i != -1; i = e[i].nxt)
	{
		int y = e[i].id;
		if (y == f) continue;
		dfs(y, x);
	}
	End[x] = dfs_tot;
}

void build(node *&rt, int l, int r)
{
	if (!rt) rt = newnode();
	if (r - l <= 1)
	{
		rt->sum[a[dfs_seq[l]]] = 1;
		return;
	}
	int mid = (l + r) >> 1;
	build(rt->c[0], l, mid);
	build(rt->c[1], mid, r);
	rt->update();
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	memset(st, -1, sizeof st), en = 0;
	Read(n), Read(m);
	REP(i, 2, m)
	{
		pr[i] = 1;
		REP(j, 2, i) if (!(i % j)) { pr[i] = 0; break; }
	}
	REP(i, 0, n) Read(a[i]), a[i] %= m;
	REP(i, 0, n - 1)
	{
		int x, y;
		Read(x), Read(y), --x, --y;
		add_edge(x, y), add_edge(y, x);
	}
	dfs(0);
	build(rt, 0, n);
	int qn;
	Read(qn);
	REP(i, 0, qn)
	{
		int ty, v, x;
		Read(ty);
		if (ty == 1)
		{
			Read(v), Read(x), --v, x %= m;
			seg_add(dfn[v], End[v], x);
		}
		else
		{
			Read(v), --v;
			printf("%d\n", seg_query(dfn[v], End[v]));		
		}
	}
	return 0;
}