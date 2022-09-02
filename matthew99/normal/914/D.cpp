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

const int maxn = 500100;
 
struct node
{
	node *c[2];

	int d;
 
	node(): d(0) { memset(c, 0, sizeof c); }
 
	void update()
	{
		d = 0;
		REP(i, 0, 2) 
			if (c[i]) d = __gcd(d, c[i]->d);
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

int n;
int a[maxn + 5];
 
void build(node *&rt, int l, int r)
{
	rt = newnode();
	if (r - l <= 1)
	{
		rt->d = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(rt->c[0], l, mid);
	build(rt->c[1], mid, r);
	rt->update();
}

int seg_x, seg_y, seg_q, seg_ret;
 
void modify(node *rt, int l, int r)
{
	if (r - l <= 1)
	{
		rt->d = seg_y;
		return;
	}
	int mid = (l + r) >> 1;
	if (seg_x < mid) modify(rt->c[0], l, mid);
	else modify(rt->c[1], mid, r);
	rt->update();
} 

void query_go(node *rt, int l, int r)
{
	if (seg_x <= l)
	{
		if (!(rt->d % seg_q)) return;
		if (r - l <= 1)
		{
			seg_ret = l;
			return;
		}
	}
	int mid = (l + r) >> 1;
	if (seg_x < mid) query_go(rt->c[0], l, mid);
	if (seg_ret == n) query_go(rt->c[1], mid, r);
}

void query_gcd(node *rt, int l, int r)
{
	if (seg_x <= l && r <= seg_y)
	{
		seg_ret = __gcd(seg_ret, rt->d);
		return;
	}
	int mid = (l + r) >> 1;
	if (seg_x < mid) query_gcd(rt->c[0], l, mid);
	if (seg_y > mid) query_gcd(rt->c[1], mid, r);
}

node *rt;

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d", a + i);
	rt = NULL;
	build(rt, 0, n);
	int qn;
	scanf("%d", &qn);
	REP(i, 0, qn)
	{
		int ty, l, r, x, y;
		scanf("%d", &ty);
		if (ty == 1)
		{
			scanf("%d%d%d", &l, &r, &x), --l;
			seg_x = l, seg_y = r;
			seg_ret = n;
			seg_q = x;
			query_go(rt, 0, n);
			seg_x = seg_ret + 1;
			if (seg_x >= seg_y)
			{
				puts("YES");
			}
			else
			{
				seg_ret = 0;
				query_gcd(rt, 0, n);
				if (!(seg_ret % x)) puts("YES");
				else puts("NO");
			}
		}
		else
		{
			scanf("%d%d", &x, &y), --x;
			seg_x = x, seg_y = y;
			modify(rt, 0, n);
		}
	}
	return 0;
}