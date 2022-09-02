#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <cctype>
#include <cassert>
#include <ctime>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define FOR(i, a, b) for (int i = (a), _end_ = (b); i <= _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;

const int maxn = 200000, maxq = 200000, max0 = 13000000;

const int oo = 0x3f3f3f3f;

int n, m;

pair<int, int> seg[maxn + 5];

int ans[maxq + 5];

vector<pair<int, int> > all[maxn + 5];

struct node
{
	node *c[2];
	int sum;
	bool label;

	node(): sum(0), label(0) { memset(c, 0, sizeof c); }

	void update()
	{
		sum = 0;
		REP(i, 0, 2)
			if (c[i]) sum += c[i]->sum;
	}

	void flag_fill(const int &len)
	{
		sum = len;
		label = 1;
	}

	void push_down(const int &);
};

node nd[max0 + 5];
int nd_tot = 0;

void node::push_down(const int &len)
{
	if (!label) return;
	int len0 = len >> 1;
	REP(i, 0, 2)
	{
		if (!c[i]) c[i] = nd + (nd_tot++);
		c[i]->flag_fill(len0);
		len0 = len - len0;
	}
	label = 0;
}

void insert(node *&rt, const int &x, const int &y, const int &l = 0, const int &r = oo)
{
	if (y <= x) return;
	if (rt == NULL) rt = nd + (nd_tot++);
	if (rt->sum == r - l) return;
	if (!rt->sum && x <= l && r <= y)
	{
		rt->flag_fill(r - l);
		return;
	}
	rt->push_down(r - l);
	int mid = (l + r) >> 1;
	if (x < mid) insert(rt->c[0], x, y, l, mid);
	if (y > mid) insert(rt->c[1], x, y, mid, r);
	rt->update();
}

int query(node *rt, const int &x, const int &y, const int &l = 0, const int &r = oo)
{
	if (y <= x) return 0;
	if (rt == NULL) return 0;
	if (x <= l && r <= y) return rt->sum;
	rt->push_down(r - l);
	int ret = 0;
	int mid = (l + r) >> 1;
	if (x < mid) ret += query(rt->c[0], x, y, l, mid);
	if (y > mid) ret += query(rt->c[1], x, y, mid, r);
	return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n)
		scanf("%d%d", &seg[i].x, &seg[i].y), seg[i].y += seg[i].x;
	scanf("%d", &m);
	REP(i, 0, m)
	{
		static int l, r;
		scanf("%d%d", &l, &r), --l, --r;
		all[l].pb(mp(r, i));
	}
	node *rt = NULL;
	for (int i = n - 1; i >= 0; --i)
	{
		insert(rt, seg[i].x, seg[i].y);
		REP(j, 0, SZ(all[i])) ans[all[i][j].y] = max(0, seg[all[i][j].x].x - seg[i].y - query(rt, seg[i].y, seg[all[i][j].x].x));
	}
	REP(i, 0, m) printf("%d\n", ans[i]);
	return 0;
}