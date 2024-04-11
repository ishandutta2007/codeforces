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

inline int fpm(LL b, int e, int m)
{
	b %= m;
	LL t = 1;
	for ( ; e; e >>= 1, (b *= b) %= m)
		if (e & 1) (t *= b) %= m;
	return t;
}

const int Mod = 1e9 + 7;
const int oo = 0x3f3f3f3f;

const int maxn = 200000;

int n;

struct node;
 
node *newnode();
 
struct node
{
	node *c[2];

	int sum;
	int label;
 
	node(): sum(0), label(1) { memset(c, 0, sizeof c); }
 
	void update()
	{
		sum = 0;
		REP(i, 0, 2) if (c[i]) (sum += c[i]->sum) %= Mod;
	}

	void flag_label(int _label)
	{
		label = (LL)label * _label % Mod;
		sum = (LL)sum * _label % Mod;
	}

	void push_down()
	{
		if (label)
		{
			REP(i, 0, 2) c[i]->flag_label(label);
			label = 1;
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
 
node *rt;
 
int seg_x, seg_y, seg_z;
 
void add(node *&rt, int l, int r)
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

inline bool seg_add(int x, int y, int z)
{
	if (x >= y) return 0;
	seg_x = x, seg_y = y, seg_z = z;
	add(rt, 0, n);
	return 1;
}

inline void query(node *rt, int l, int r)
{
	if (seg_x <= l && r <= seg_y)
	{
		(seg_z += rt->sum) %= Mod;
		return;
	}
	int mid = (l + r) >> 1;
	rt->push_down();
	if (seg_x < mid) query(rt->c[0], l, mid);
	if (seg_y > mid) query(rt->c[1], mid, r);
}

inline int seg_query(int x, int y)
{
	if (x >= y) return 0;
	seg_x = x, seg_y = y, seg_z = 0;
	query(rt, 0, n);
	return seg_z;
}

int pos[maxn + 5];
int v[maxn + 5];

inline void build(node *&rt, int l, int r)
{
	rt = newnode();
	if (r - l <= 1) 
	{
		rt->sum = v[pos[l]];
		return;
	}
	int mid = (l + r) >> 1;
	build(rt->c[0], l, mid);
	build(rt->c[1], mid, r);
	rt->update();
}

struct edge
{
	int id, nxt;

	edge() { }
	edge(int _id, int _nxt): id(_id), nxt(_nxt) { }

};

edge e[maxn + 5];
int st[maxn + 5], en = 0;

inline void add_edge(int x, int y)
{
	e[en] = edge(y, st[x]), st[x] = en++;
}

int dfn[maxn + 5], End[maxn + 5];
int tot = 0;
int w[maxn + 5];

int seq[maxn + 5], deg[maxn + 5];
int fa[maxn + 5];

void dfs(int x, int now)
{
	pos[dfn[x] = tot++] = x;
	v[x] = (LL)w[x] * now % Mod;
	for (int i = st[x]; i != -1; i = e[i].nxt)
	{
		int y = e[i].id;
		dfs(y, (LL)now * deg[y] % Mod);
	}
	End[x] = tot;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	memset(st, -1, sizeof st), en = 0;
	int m;
	scanf("%d%d", w, &m);
	n = 1;
	REP(i, 0, m)
	{
		int ty, p, v;
		scanf("%d", &ty);
		if (ty == 1) scanf("%d%d", &p, &v), --p, fa[n] = p, ++deg[p], add_edge(p, n), seq[i] = n << 1, w[n++] = v;
		else scanf("%d", &p), --p, seq[i] = p << 1 | 1;
	}
	REP(i, 0, n) ++deg[i];
	dfs(0, deg[0]);
	build(rt, 0, n);
	vector<int> ans;
	for (int i = m - 1; i >= 0; --i)
	{
		int x = seq[i] >> 1;
		if (seq[i] & 1)
		{
			int tmp = seg_query(dfn[x], dfn[x] + 1);
			int tmp0 = seg_query(dfn[x], End[x]);
			tmp = (LL)tmp * fpm(w[x], Mod - 2, Mod) % Mod * fpm(deg[x], Mod - 2, Mod) % Mod;
			ans.pb((LL)tmp0 * fpm(tmp, Mod - 2, Mod) % Mod);
		}
		else
		{
			seg_add(dfn[x], dfn[x] + 1, 0);
			x = fa[x];
			int lyc = (LL)(deg[x] - 1) * fpm(deg[x], Mod - 2, Mod) % Mod;
			--deg[x];
			seg_add(dfn[x], End[x], lyc);
		}
	}
	reverse(ALL(ans));
	for (auto it : ans) printf("%d\n", it);
	return 0;
}