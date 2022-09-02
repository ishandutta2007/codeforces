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

const int maxn = 200000, max0 = 100000, maxabs = 1e9;

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

inline void find(node *rt, int l, int r)
{
	assert(rt);
	if (r - l <= 1)
	{
		seg_y = l;
		return;
	}
	rt->push_down();
	int mid = (l + r) >> 1;
	if (rt->c[0]->get_Max() >= seg_x) find(rt->c[0], l, mid);
	else find(rt->c[1], mid, r);
}

int n, d;
pair<int, int> a[maxn + 5];

inline bool cmp(const pair<int, int> &x, const pair<int, int> &y) { return x.y < y.y; }

inline int find(int x)
{
	if (x > rt->get_Max()) return oo;
	seg_x = x;
	seg_y = oo;
	find(rt, 0, maxabs + 1);
	return seg_y;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &d);
	REP(i, 0, n) scanf("%d%d", &a[i].x, &a[i].y), ++a[i].y, chkmax(a[i].x, 0), chkmax(a[i].y, 0);
	int now = 0;
	sort(a, a + n, cmp);
	int lst = 0;
	REP(i, 0, n)
	{
		seg_add(lst, a[i].y, now);
		int tmp = -1;
		while ((tmp = find(now + 1) + d) < a[i].y)
		{
			++now;
			chkmax(tmp, lst);
			seg_add(tmp, a[i].y, 1);
		}
		seg_add(a[i].x, a[i].y, 1);
		chkmax(lst, a[i].y);
	}
	printf("%d\n", rt->get_Max());
	return 0;
}