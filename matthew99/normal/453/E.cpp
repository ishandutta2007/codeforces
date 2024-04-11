#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define mp make_pair
#define x first
#define y second
#define debug(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

typedef long long LL;

const int maxn = 1e5, maxm = 1e5, max0 = 1e6;

struct data
{
	int s, m, r;
};

data a[maxn + 5];
int n, m;

void init()
{
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d%d%d", &a[i].s, &a[i].m, &a[i].r);
}

struct que
{
	int l, r, t;
	int ret;

	que() { }
	que(const int &_l, const int &_r, const int &_t, const int &_ret): l(_l), r(_r), t(_t), ret(_ret) { }

	friend bool operator < (const que &x, const que &y)
	{
		return x.t < y.t;
	}

};

LL ans[maxm + 5];

que q0[max0 + 5], q1[max0 + 5];
int cnt0 = 0, cnt1 = 0;

struct node
{
	bool has_label;
	int label;
	node *c[2];

	node(): has_label(0), label(-2) { memset(c, 0, sizeof c); }

	void push_down();
	
};

node node_memory[max0 + 5];
int node_cur = 0;

node *rt = NULL;

node *get()
{
	return node_memory + (node_cur++);
}

void node::push_down()
{
	if (label != -2)
	{
		REP(i, 0, 2) 
		{
			if (!c[i]) c[i] = get();
			c[i]->label = label;
			c[i]->has_label = 1;
		}
		label = -2;
	}
}

pair<pair<int, int>, int> all_seg[maxn + 5];
int all_seg_cnt = 0;

void clear_all_label(node *rt, const int &l, const int &r)
{
	if (rt == NULL || !rt->has_label) return;
	rt->has_label = 0;
	if (rt->label != -2)
	{
		all_seg[all_seg_cnt++] = mp(mp(l, r), rt->label);
		rt->label = 0;
		return;
	}
	int mid = (l + r) >> 1;
	clear_all_label(rt->c[0], l, mid);
	clear_all_label(rt->c[1], mid, r);
}

void insert(node *&rt, const int &x, const int &y, const int &z, const int &l = 0, const int &r = maxn)
{
	if (rt == NULL) rt = get();
	if (x <= l && r <= y)
	{
		clear_all_label(rt, l, r);
		rt->has_label = 1, rt->label = z;
		return;
	}
	rt->has_label = 1;
	rt->push_down();
	int mid = (l + r) >> 1;
	if (x < mid) insert(rt->c[0], x, y, z, l, mid);
	if (y > mid) insert(rt->c[1], x, y, z, mid, r);
}

void prepare()
{
	insert(rt, 0, n, -1);
	scanf("%d", &m);
	REP(i, 0, m)
	{
		static int l, r, t;
		scanf("%d%d%d", &t, &l, &r), --l;
		all_seg_cnt = 0;
		insert(rt, l, r, t);
		for (int j = 0; j < all_seg_cnt; )
		{
			const int &l = all_seg[j].x.x, &val = all_seg[j].y;
			int r;
			while (j < all_seg_cnt && all_seg[j].y == val) r = all_seg[j++].x.y;
			if (val != -1) q0[cnt0++] = que(l, r, t - val, i);
			else q1[cnt1++] = que(l, r, t, i);
		}
	}
}

pair<int, int> ev[maxn + 5];
int evn = 0;

LL sum0[maxn + 5], sum1[maxn + 5];

void add(const int &x, const int &y, LL *sum)
{
	for (int i = x + 1; i <= n; i += i & -i) sum[i] += y;
}

LL query_pre(const int &x, LL *sum)
{
	LL ret = 0;
	for (int i = x; i > 0; i -= i & -i) ret += sum[i];
	return ret;
}

LL query(const int &l, const int &r, const int &t)
{
	LL tmp0 = query_pre(r, sum0) - query_pre(l, sum0), tmp1 = query_pre(r, sum1) - query_pre(l, sum1);
	return tmp1 + tmp0 * t;
}

void work(que *q1, const int &cnt1)
{
	memset(sum0, 0, sizeof sum0);
	memset(sum1, 0, sizeof sum1);
	REP(i, 0, n) add(i, a[i].r, sum0), add(i, a[i].s, sum1);
	evn = 0;
	REP(i, 0, n)
		if (a[i].r) ev[evn++] = mp((a[i].m - a[i].s + a[i].r - 1) / a[i].r, i);
	sort(ev, ev + evn);
	sort(q1, q1 + cnt1);
	int j = 0;
	REP(i, 0, cnt1)
	{
		while (j < evn && ev[j].x <= q1[i].t)
		{
			add(ev[j].y, -a[ev[j].y].r, sum0);
			add(ev[j].y, a[ev[j].y].m - a[ev[j].y].s, sum1);
			++j;
		}
		ans[q1[i].ret] += query(q1[i].l, q1[i].r, q1[i].t);
	}
}

void solve()
{
	memset(ans, 0, sizeof ans);
	work(q1, cnt1);
	REP(i, 0, n) a[i].s = 0;
	work(q0, cnt0);
}

void output()
{
	REP(i, 0, m) printf("%I64d\n", ans[i]);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	init();
	prepare();
	solve();
	output();
	return 0;
}