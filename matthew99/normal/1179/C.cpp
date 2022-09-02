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

const int maxn = 300100;
const int maxabs = 1.01e6;
 
struct node
{
	node *c[2];

	int Min;
	int label;
 
	node(): Min(0), label(0) { memset(c, 0, sizeof c); }
 
	void update()
	{
		Min = oo;
		REP(i, 0, 2) 
			chkmin(Min, c[i]->Min);
	}

	void flag_label(int _label)
	{
		label += _label;
		chkmin(label, oo);
		Min += _label;
		chkmin(Min, oo);
	}

	void push_down()
	{
		if (label)
		{
			REP(i, 0, 2) 
			{
				c[i]->flag_label(label);
			}
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
 
int seg_x, seg_y, seg_z;
int seg_ret;

void build(node *&rt, int l, int r)
{
	rt = newnode();
	if (r - l <= 1) return;
	int mid = (l + r) >> 1;
	build(rt->c[0], l, mid);
	build(rt->c[1], mid, r);
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

inline void query(node *rt, int l, int r)
{
	if (r - l <= 1)
	{
		seg_ret = l;
		return;
	}
	int mid = (l + r) >> 1;
	rt->push_down();
	if (rt->c[1]->Min < 0) query(rt->c[1], mid, r);
	else query(rt->c[0], l, mid);
}
 
node *rt;
int n, m;

int a[maxn + 5], b[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	build(rt, 0, maxabs);
	REP(i, 0, n) 
	{
		scanf("%d", a + i);
		seg_x = 0, seg_y = a[i] + 1, seg_z = -1;
		add(rt, 0, maxabs);
	}
	REP(i, 0, m) 
	{
		scanf("%d", b + i);
		seg_x = 0, seg_y = b[i] + 1, seg_z = 1;
		add(rt, 0, maxabs);
	}
	int qn;
	scanf("%d", &qn);
	REP(i, 0, qn)
	{
		int ty, x, y;
		scanf("%d%d%d", &ty, &x, &y), --x;
		if (ty == 1)
		{
			seg_x = 0, seg_y = a[x] + 1, seg_z = 1;
			add(rt, 0, maxabs);
			a[x] = y;
			seg_x = 0, seg_y = a[x] + 1, seg_z = -1;
			add(rt, 0, maxabs);
		}
		else
		{
			seg_x = 0, seg_y = b[x] + 1, seg_z = -1;
			add(rt, 0, maxabs);
			b[x] = y;
			seg_x = 0, seg_y = b[x] + 1, seg_z = 1;
			add(rt, 0, maxabs);
		}
		if (rt->Min >= 0) printf("-1\n");
		else
		{
			query(rt, 0, maxabs);
			printf("%d\n", seg_ret);
		}
	}
	return 0;
}