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

struct node
{
	node *c[2];

	int Max;
	int label;
 
	node(): Max(0), label(0) { memset(c, 0, sizeof c); }
 
	void update()
	{
		Max = -oo;
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
			REP(i, 0, 2) if (c[i]) c[i]->flag_label(label);
			label = 0;
		}
	}
 
};

const int max0 = 100000;
 
node *nd_pool;
int nd_res = 0;
 
inline node *newnode()
{
	if (!nd_res) nd_pool = new node[max0], nd_res = max0;
	return nd_pool + (--nd_res);
}

void build(node *&rt, int l, int r)
{
	rt = newnode();
	if (r - l <= 1) return;
	int mid = (l + r) >> 1;
	build(rt->c[0], l, mid);
	build(rt->c[1], mid, r);
}
 
int seg_x, seg_y, seg_z, seg_ret;
 
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

void find(node *rt, int l, int r)
{
	if (!rt) rt = newnode();
	if (r - l <= 1) { seg_ret = l; return; }
	rt->push_down();
	int mid = (l + r) >> 1;
	if (rt->c[1]->Max > 0) find(rt->c[1], mid, r);
	else find(rt->c[0], l, mid);
}
 
node *rt;

int wh[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	build(rt, 0, n);
	REP(i, 0, n)
	{
		int x, y;
		scanf("%d", &x), --x;
		scanf("%d", &y);
		if (y) scanf("%d", wh + x);
		seg_x = 0, seg_y = x + 1;
		seg_z = y ? 1 : -1;
		add(rt, 0, n);
		if (rt->Max > 0) find(rt, 0, n), printf("%d\n", wh[seg_ret]);
		else printf("-1\n");
	}
	return 0;
}