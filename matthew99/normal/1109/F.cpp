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

template<typename T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxN = 200100;

struct node
{
	node *c[2], *p;
	bool rev;

	node(): p(NULL), rev(0) { memset(c, 0, sizeof c); }

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
		node *_p = this->p;
		bool mark = get_pos();
		_p->p->setc(this, _p->get_pos());
		_p->setc(c[mark ^ 1], mark);
		setc(_p, mark ^ 1);
	}

	void relax()
	{
		static node *tmp[maxN + 5];
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
	}

	node *access()
	{
		node *u = this, *v = NULL;
		for ( ; u; v = u, u = u->p) u->splay(), u->setc(v, 1);
		splay();
		return v;
	}

	void be_root()
	{
		access();
		flag_rev();
	}

};

node nd[maxN + 5];

inline bool same(int x, int y)
{
	node *u = nd + x;
	node *v = nd + y;
	u->be_root(), v->access();
	return u->is_root() == 0;
}

inline void link(int x, int y)
{
	node *u = nd + x;
	node *v = nd + y;
	u->be_root(), v->access();
	u->p = v;
	u->access();
}

inline void cut(int x, int y)
{
	node *u = nd + x;
	node *v = nd + y;
	u->be_root(), v->access();
	v->setc(NULL, 0);
	u->p = NULL;
}

const int walk[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int maxn = 1010;

int N;
int n, m;
pair<int, int> where[maxN + 5];

int a[maxn + 5][maxn + 5];

bool in[maxN + 5];

inline bool check(int id)
{
	int x = where[id].x, y = where[id].y;
	vector<pair<int, int> > added;
	bool ret = 1;
	REP(i, 0, 4)
	{
		int u = x + walk[i][0], v = y + walk[i][1];
		if (u < 0 || u >= n || v < 0 || v >= m) continue;
		if (in[a[u][v]])
		{
			if (same(id, a[u][v]))
			{
				ret = 0;
				break;
			}
			link(id, a[u][v]);
			added.pb(mp(id, a[u][v]));
		}
	}
	for (auto u : added) cut(u.x, u.y);
	return ret;
}

inline void add(int id)
{
	int x = where[id].x, y = where[id].y;
	REP(i, 0, 4)
	{
		int u = x + walk[i][0], v = y + walk[i][1];
		if (u < 0 || u >= n || v < 0 || v >= m) continue;
		if (in[a[u][v]])
		{
			link(id, a[u][v]);
		}
	}
	in[id] = 1;
}

inline void del(int id)
{
	in[id] = 0;
	int x = where[id].x, y = where[id].y;
	REP(i, 0, 4)
	{
		int u = x + walk[i][0], v = y + walk[i][1];
		if (u < 0 || u >= n || v < 0 || v >= m) continue;
		if (in[a[u][v]])
		{
			cut(id, a[u][v]);
		}
	}
}

struct seg_node
{
	seg_node *c[2];

	int Min, Min_cnt;
	int label;
 
	seg_node(): Min(oo), Min_cnt(0), label(0) { memset(c, 0, sizeof c); }
 
	void update()
	{
		Min = oo, Min_cnt = 0;
		REP(i, 0, 2) 
		{
			if (chkmin(Min, c[i]->Min)) Min_cnt = c[i]->Min_cnt;
			else if (Min == c[i]->Min) Min_cnt += c[i]->Min_cnt;
		}
	}

	void flag_label(int _label)
	{
		Min += _label;
		label += _label;
	}

	void push_down()
	{
		if (label)
		{
			REP(i, 0, 2) c[i]->flag_label(label);
			label = 0;
		}
	}
 
};

const int max0 = 100000;
 
seg_node *nd_pool;
int nd_res = 0;
 
inline seg_node *newnode()
{
	if (!nd_res) nd_pool = new seg_node[max0], nd_res = max0;
	return nd_pool + (--nd_res);
}
 
int seg_x, seg_y, seg_z;

void build(seg_node *&rt, int l, int r)
{
	rt = newnode();
	if (r - l <= 1) 
	{
		rt->Min = l;
		rt->Min_cnt = 1;
		return;
	}
	int mid = (l + r) >> 1;
	build(rt->c[0], l, mid);
	build(rt->c[1], mid, r);
	rt->update();
}
 
void add(seg_node *rt, int l, int r)
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

int seg_Min, seg_Min_cnt;

inline void query(seg_node *rt, int l, int r)
{
	if (seg_x <= l && r <= seg_y)
	{
		if (chkmin(seg_Min, rt->Min)) seg_Min_cnt = rt->Min_cnt;
		else if (seg_Min == rt->Min) seg_Min_cnt += rt->Min_cnt;
		return;
	}
	int mid = (l + r) >> 1;
	rt->push_down();
	if (seg_x < mid) query(rt->c[0], l, mid);
	if (seg_y > mid) query(rt->c[1], mid, r);
}
 
seg_node *rt;

int lim[maxN + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	REP(i, 0, n) REP(j, 0, m)
	{
		int x;
		scanf("%d", &x), --x;
		a[i][j] = x;
		where[x] = mp(i, j);
	}
	N = n * m;
	{
		int j = 0;
		REP(i, 0, N)
		{
			while (j < N && check(j)) add(j++);
			lim[i] = j;
			del(i);
		}
	}
	build(rt, 0, N);
	LL ans = 0;
	for (int i = N - 1; i >= 0; --i)
	{
		int x = where[i].x, y = where[i].y;
		REP(j, 0, 4)
		{
			int u = x + walk[j][0], v = y + walk[j][1];
			if (u < 0 || u >= n || v < 0 || v >= m) continue;
			if (a[u][v] > a[x][y])
			{
				seg_x = a[u][v], seg_y = N, seg_z = -1;
				add(rt, 0, N);
			}
		}
		seg_x = i, seg_y = lim[i], seg_Min = oo, seg_Min_cnt = 0;
		query(rt, 0, N);
		if (seg_Min - i == 0) ans += seg_Min_cnt;
	}
	printf("%lld\n", ans);
	return 0;
}