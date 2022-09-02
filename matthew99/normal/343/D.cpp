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
#define LAST(x) ((x)[SZ(x) - 1])

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int __buffsize = 100000;
char __buff[__buffsize];
char *__buffs, *__buffe;

#define getc() (__buffs == __buffe ? fread(__buff, 1, __buffsize, stdin), __buffe = __buff + __buffsize, *((__buffs = __buff)++): *(__buffs++))

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

const int Mod = 1e9 + 7;

const int maxn = 500000;

struct node;

node *newnode();
 
struct node
{
	node *c[2];

	int Max;
	int label;
 
	node(): Max(-1), label(-1) { memset(c, 0, sizeof c); }

	void flag_label(int _label)
	{
		chkmax(Max, _label);
		chkmax(label, _label);
	}

	void push_down()
	{
		if (label != -1)
		{
			REP(i, 0, 2)
			{
				if (!c[i]) c[i] = newnode();
				c[i]->flag_label(label);
			}
			label = -1;
		}
	}

	void update()
	{
		Max = -1;
		REP(i, 0, 2) if (c[i]) chkmax(Max, c[i]->Max);
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

node *rt0, *rt1;

int n;

int seg_x, seg_y, seg_z;

void add(node *&rt, int l, int r)
{
	if (!rt) rt = newnode();
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

void query(node *rt, int l, int r)
{
	if (!rt) return;
	if (seg_x <= l && r <= seg_y)
	{
		chkmax(seg_z, rt->Max);
		return;
	}
	int mid = (l + r) >> 1;
	rt->push_down();
	if (seg_x < mid) query(rt->c[0], l, mid);
	if (seg_y > mid) query(rt->c[1], mid, r);
}

int seg_query(node *rt, int x, int y)
{
	seg_x = x, seg_y = y, seg_z = -1;
	query(rt, 0, n);
	return seg_z;
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

int dfn[maxn + 5], End[maxn + 5], dfs_tot = 0;

void dfs(int x, int f = -1)
{
	dfn[x] = dfs_tot++;
	for (int i = st[x]; i != -1; i = e[i].nxt)
	{
		int y = e[i].id;
		if (y == f) continue;
		dfs(y, x);
	}
	End[x] = dfs_tot;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	memset(st, -1, sizeof st), en = 0;
	Read(n);
	REP(i, 0, n - 1)
	{
		int x, y;
		Read(x), --x;
		Read(y), --y;
		add_edge(x, y), add_edge(y, x);
	}
	dfs(0);
	seg_add(rt0, 0, n, 0);
	int m;
	Read(m);
	REP(i, 0, m)
	{
		int c, x;
		Read(c), Read(x), --x;
		if (c == 1) seg_add(rt1, dfn[x], End[x], i + 1);
		else if (c == 2) seg_add(rt0, dfn[x], dfn[x] + 1, i + 1);
		else
		{
			int tmp0 = seg_query(rt0, dfn[x], End[x]), tmp1 = seg_query(rt1, dfn[x], dfn[x] + 1);
			if (tmp0 > tmp1) puts("0");
			else puts("1");
		}
	}
	return 0;
}