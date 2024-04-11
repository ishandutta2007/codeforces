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

struct node;
 
node *newnode();
 
struct node
{
	node *c[2];

	LL Min;
	int Min_cnt;
	LL label;
 
	node(): label(0) { memset(c, 0, sizeof c); }

	void flag_label(LL _label)
	{
		Min += _label;
		label += _label;
	}
 
	void update()
	{
		Min = LLONG_MAX, Min_cnt = 0;
		REP(i, 0, 2) 
			if (c[i])
			{
				if (chkmin(Min, c[i]->Min)) Min_cnt = c[i]->Min_cnt;
				else if (Min == c[i]->Min) Min_cnt += c[i]->Min_cnt;
			}
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
 
node *newnode()
{
	if (!nd_res) nd_pool = new node[max0], nd_res = max0;
	return nd_pool + (--nd_res);
}

const int maxn = 300000;

LL ans = 0;

int n;
int a[maxn + 5];
 
node *rt;
 
int seg_x, seg_y, seg_z;

void build(node *&rt, int l, int r)
{
	if (!rt) rt = newnode(), rt->Min = 1, rt->Min_cnt = r - l;
	if (r - l <= 1) return;
	int mid = (l + r) >> 1;
	build(rt->c[0], l, mid);
	build(rt->c[1], mid, r);
}
 
void add(node *rt, int l, int r)
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

inline bool seg_add(int x, int y, int z)
{
	if (x >= y) return 0;
	seg_x = x, seg_y = y, seg_z = z;
	add(rt, 0, n);
	return 1;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n)
	{
		int x, y;
		scanf("%d%d", &x, &y), --x, --y;
		a[x] = y;
	}
	build(rt, 0, n);
	vector<int> stk0, stk1;
	stk0.pb(-1), stk1.pb(-1);
	REP(i, 0, n)
	{
		while (SZ(stk0) > 1 && a[LAST(stk0)] > a[i]) seg_add(stk0[SZ(stk0) - 2] + 1, i, a[LAST(stk0)] - a[i]), stk0.pop_back();
		stk0.pb(i);
		while (SZ(stk1) > 1 && a[LAST(stk1)] < a[i]) seg_add(stk1[SZ(stk1) - 2] + 1, i, a[i] - a[LAST(stk1)]), stk1.pop_back();
		stk1.pb(i);
		seg_add(0, i + 1, -1);
		assert(!rt->Min);
		ans += rt->Min_cnt;
	}
	printf("%I64d\n", ans);
	return 0;
}