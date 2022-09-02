//O(n log ^ 2n)
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
const LL OO = 0x3f3f3f3f3f3f3f3fLL;

const int maxn = 100000;

int n, K;
int a[maxn + 5], b[maxn + 5];

LL p0[maxn + 5], p1[maxn + 5];

struct node
{
	LL Maxv, Mind, Maxp, Maxcost;

	LL label;

	node *c[2];
	
	node(): Maxv(-OO), Mind(0), Maxp(-OO), Maxcost(0) { memset(c, 0, sizeof c); }

	void update()
	{
		Maxv = Maxp = -OO;
		Maxcost = 0;
		REP(i, 0, 2) if (c[i]) chkmax(Maxv, c[i]->Maxv), chkmax(Maxp, c[i]->Maxp), chkmax(Maxcost, c[i]->Maxcost);
	}

	void flag_label(LL _label)
	{
		label += _label;
		Maxv += _label;
		Mind += _label;
		Maxcost += _label;
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

node nd[(maxn << 1) + 5];
int cur = 0;

node *rt;

inline node *newnode() { return nd + (cur++); }

int seg_x, seg_y;
LL seg_z;
LL seg_Max;
int seg_ret;
LL qmind_ret;

void qmind(node *rt)
{
	if (!rt) return;
	if (!rt->c[0] && !rt->c[1]) chkmin(qmind_ret, seg_Max - rt->Maxp);
	else
	{
		if (rt->c[0]->Maxv >= seg_Max) chkmin(qmind_ret, rt->c[1]->Mind), qmind(rt->c[0]);
		else chkmin(qmind_ret, seg_Max - rt->c[0]->Maxp), qmind(rt->c[1]);
	}
}

inline void updmd(node *rt)
{
	seg_Max = rt->c[0]->Maxv, qmind_ret = OO;
	qmind(rt->c[1]);
	rt->c[1]->Mind = qmind_ret;
}

void build(node *&rt, int l, int r)
{
	rt = newnode();
	if (r - l <= 1)
	{
		rt->Maxv = rt->Maxp = p1[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(rt->c[0], l, mid);
	build(rt->c[1], mid, r);
	rt->update();
	updmd(rt);
}

void add(node *rt, int l, int r)
{
	if (!rt) return;
	if (seg_x <= l && r <= seg_y)
	{
		rt->flag_label(seg_z);
		return;
	}
	rt->push_down();
	int mid = (l + r) >> 1;
	if (seg_x < mid) add(rt->c[0], l, mid);
	if (seg_y > mid) add(rt->c[1], mid, r);
	rt->update();
	updmd(rt);
}

LL qmax_ret;

void qmax(node *rt, int l, int r)
{
	if (!rt) return;
	if (seg_x <= l && r <= seg_y)
	{
		chkmax(qmax_ret, rt->Maxv);
		return;
	}
	rt->push_down();
	int mid = (l + r) >> 1;
	if (seg_x < mid) qmax(rt->c[0], l, mid);
	if (seg_y > mid) qmax(rt->c[1], mid, r);
}

void query(node *rt, int l, int r)
{
	if (!rt) return;
	if (seg_x <= l && r <= seg_y)
	{
		qmind_ret = OO;
		qmind(rt);
		if (qmind_ret > K) return;
		chkmax(seg_ret, l);
	}
	rt->push_down();
	int mid = (l + r) >> 1;
	if (seg_y > mid)
	{
		LL tmp = seg_Max;
		qmax_ret = -OO;
		qmax(rt->c[0], l, mid);
		chkmax(seg_Max, qmax_ret);
		query(rt->c[1], mid, r);
		seg_Max = tmp;
	}
	if (seg_ret < mid && seg_x < mid) query(rt->c[0], l, mid);
}

int find_ret = 0;

void find(node *rt, int l, int r)
{
	if (!rt) return;
	if (r - l <= 1) return;
	rt->push_down();
	int mid = (l + r) >> 1;
	if (rt->c[0]->Maxcost > K) find(rt->c[0], l, mid);
	else find_ret = mid, find(rt->c[1], mid, r);
}

vector<int> chd[maxn + 5];
int fa[maxn + 5];

int ans = 0;

void dfs(int x)
{
	if (~fa[x]) seg_x = fa[x] - 1, seg_y = n, seg_z = p0[x] - p0[fa[x]], add(rt, 0, n); 
	find_ret = 0;
	find(rt, 0, n);
	seg_x = x, seg_y = find_ret + 1, seg_Max = -OO, seg_ret = x;
	query(rt, 0, n);
	chkmax(ans, seg_ret - x + 1);
	for (auto y : chd[x]) dfs(y);
	if (~fa[x]) seg_x = fa[x] - 1, seg_y = n, seg_z = p0[fa[x]] - p0[x], add(rt, 0, n);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &K);
	REP(i, 0, n - 1) scanf("%d", a + i);
	a[n - 1] = 0;
	REP(i, 0, n) scanf("%d", b + i);
	p0[0] = p1[0] = 0;
	REP(i, 0, n - 1) p0[i + 1] = p0[i] + b[i] - a[i], p1[i + 1] = p1[i] + b[i + 1] - a[i];
	static int stk[maxn + 5];
	int tot = 0;
	for (int i = n - 1; i >= 0; --i)
	{
		while (tot && p0[stk[tot - 1]] >= p0[i]) --tot;
		if (tot) chd[stk[tot - 1]].pb(i), fa[i] = stk[tot - 1];
		else fa[i] = -1;
		stk[tot++] = i;
	}
	build(rt, 0, n);
	REP(i, 0, n) if (!~fa[i]) dfs(i);
	printf("%d\n", ans);
	return 0;
}