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

const int maxn = 100000, maxabs = 300000;

struct data
{
	int l, v, r;

	data() { }
	data(int _l, int _v, int _r): l(_l), v(_v), r(_r) { }

};

int n;
data a[maxn + 5];

int posl[maxn + 5], posv[maxn + 5];

inline bool cmpl(int x, int y) { return a[x].l < a[y].l; }
inline bool cmpv(int x, int y) { return a[x].v < a[y].v; }

struct node;
 
node *newnode();
 
struct node
{
	node *c[2];

	int Max;
	int label;
 
	node(): Max(0), label(0) { memset(c, 0, sizeof c); }
 
	void update()
	{
		Max = 0;
		REP(i, 0, 2) 
			if (c[i]) chkmax(Max, c[i]->Max);
	}

	void flag_label(int _label)
	{
		label += _label;
		Max += _label;
	}

	void push_down()
	{
		if (label)
		{
			REP(i, 0, 2) 
			{
				if (!c[i]) c[i] = newnode();
				c[i]->flag_label(label);
			}
			label = 0;
		}
	}

	inline int get_Max() { return this ? Max : 0; }

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

inline bool seg_add(int x, int y, int z)
{
	if (x >= y) return 0;
	seg_x = x, seg_y = y, seg_z = z;
	add(rt, 0, maxabs + 1);
	return 1;
}

int ansa, ansb;

int Maxp;

inline void find_Max(node *rt, int l, int r)
{
	if (!rt) return;
	Maxp = l;
	if (r - l <= 1) return;
	int mid = (l + r) >> 1;
	rt->push_down();
	if (rt->c[0]->get_Max() < rt->c[1]->get_Max()) find_Max(rt->c[1], mid, r);
	else find_Max(rt->c[0], l, mid);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d%d%d", &a[i].l, &a[i].v, &a[i].r), ++a[i].r, posl[i] = i, posv[i] = i;
	sort(posl, posl + n, cmpl);
	sort(posv, posv + n, cmpv);
	int j = 0;
	int ans = 0;
	REP(i, 0, n)
	{
		while (j < n && a[posl[j]].l <= a[posv[i]].v) 
		{
			seg_add(a[posl[j]].v, a[posl[j]].r, 1);
			++j;
		}
		if (rt) 
		{
			if (chkmax(ans, rt->Max))
			{
				ansa = a[posv[i]].v;
				find_Max(rt, 0, maxabs + 1);
				ansb = Maxp;
			}
		}
		seg_add(a[posv[i]].v, a[posv[i]].r, -1);
	}
	printf("%d\n", ans);
	int tot = 0;
	REP(i, 0, n) if (a[i].l <= ansa && a[i].v >= ansa && a[i].v <= ansb && a[i].r > ansb) printf("%d ", i + 1), ++tot;
	printf("\n");
	return 0;
}