#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cassert>
#include <cctype>
#include <cmath>
#include <iostream>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define FOR(i, a, b) for (int i = (a), _end_ = (b); i <= _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define EXIT(...) printf(__VA_ARGS__), exit(0)
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define x first
#define y second

using namespace std;

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 100000, maxm = 100000, max0 = 10000000;

int n, m;
int a[maxn + 5];

struct node
{
	node *c[2];
	int cnt;
	bool rev;

	node(): cnt(0), rev(0) { memset(c, 0, sizeof c); }

	void flag_rev(const int &len) { cnt = len - cnt; rev ^= 1; }

	void update()
	{
		cnt = 0;
		REP(i, 0, 2)
			if (c[i]) cnt += c[i]->cnt;
	}

	void push_down(const int &);
};

node nd[max0 + 5];
int nd_tot = 0;

void node::push_down(const int &len)
{
	if (!rev) return;
	int len0 = len >> 1;
	REP(i, 0, 2)
	{
		if (!c[i]) c[i] = nd + (nd_tot++);
		c[i]->flag_rev(len0);
		len0 = len - len0;
	}
	rev = 0;
}

void insert(node *&rt, const int &x, const int &y, const int &l, const int &r)
{
	if (y <= x) return;
	if (rt == NULL) rt = nd + (nd_tot++);
	if (x <= l && r <= y)
	{
		rt->flag_rev(r - l);
		return;
	}
	rt->push_down(r - l);
	int mid = (l + r) >> 1;
	if (x < mid) insert(rt->c[0], x, y, l, mid);
	if (y > mid) insert(rt->c[1], x, y, mid, r);
	rt->update();
}

int query(node *rt, const int &x, const int &y, const int &l, const int &r)
{
	if (y <= x) return 0;
	if (rt == NULL) return 0;
	if (x <= l && r <= y) return rt->cnt;
	rt->push_down(r - l);
	int mid = (l + r) >> 1;
	int ret = 0;
	if (x < mid) ret += query(rt->c[0], x, y, l, mid);
	if (y > mid) ret += query(rt->c[1], x, y, mid, r);
	return ret;
}

pair<int, int> seg[maxm + 5];

bool cmp(const int &x, const int &y) { return seg[x].y < seg[y].y; }

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	REP(i, 0, n) scanf("%d", a + i);
	sort(a, a + n);
	REP(i, 0, m)
	{
		scanf("%d%d", &seg[i].x, &seg[i].y);
		seg[i].x = lower_bound(a, a + n, seg[i].x) - a;
		seg[i].y = upper_bound(a, a + n, seg[i].y) - a;
	}
	sort(seg, seg + m);
	static int pos[maxm + 5];
	REP(i, 0, m) pos[i] = i;
	sort(pos, pos + m, cmp);
	int j = 0, k = 0;
	LL ans = n * LL(n - 1) * (n - 2) / 6;
	node *rt = NULL;
	REP(i, 0, n)
	{
		while (seg[j].x <= i && j < m) insert(rt, seg[j].x, seg[j].y, 0, n), ++j;
		while (seg[pos[k]].y <= i && k < m) insert(rt, seg[pos[k]].x, seg[pos[k]].y, 0, n), ++k;
		int ret = query(rt, i + 1, n, 0, n) + i - query(rt, 0, i, 0, n);
		ans -= ret * LL(ret - 1) >> 1;
	}
	cout << ans << endl;
	return 0;
}