#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cassert>
#include <map>
#include <vector>
#include <queue>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define SZ(x) (int((x).size()))

using namespace std;

template<typename T0, typename T1> bool chkmin(T0 &a, const T1 &b) { return a > b ? a = b, 1 : 0; }
template<typename T0, typename T1> bool chkmax(T0 &a, const T1 &b) { return a < b ? a = b, 1 : 0; }

const int oo = 0x3f3f3f3f, Max_val = 314000000;

const int maxn = 1000000, maxm = 200000, max0 = 30000000;

pair<int, int> p[maxn + 5];

int n, m;

pair<pair<int, int>, pair<int, int> > q[(maxm << 1) + 5];
int ans[maxm + 5];

struct node
{
	int val;
	node *c[2];

	node(): val(0) { memset(c, 0, sizeof c); }
};

node nd[max0 + 5];
int tot_nd = 0;

void insert(node *&rt, const int &x, const int &l = 0, const int &r = maxn)
{
	if (rt == NULL) rt = nd + (tot_nd++);
	else
	{
		node tmp = *rt;
		rt = nd + (tot_nd++);
		*rt = tmp;
	}
	++rt->val;
	if (r - l <= 1) return;
	int mid = (l + r) >> 1;
	if (x < mid) insert(rt->c[0], x, l, mid);
	else insert(rt->c[1], x, mid, r);
}

int query(node *rt, const int &x, const int &y, const int &l = 0, const int &r = maxn)
{
	if (rt == NULL) return 0;
	if (x <= l && r <= y) return rt->val;
	int mid = (l + r) >> 1;
	int ret = 0;
	if (x < mid) ret += query(rt->c[0], x, y, l, mid);
	if (y > mid) ret += query(rt->c[1], x, y, mid, r);
	return ret;
}

node *rt[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n)
	{
		static int x;
		scanf("%d", &x), --x;
		p[x].x = i;
	}
	REP(i, 0, n)
	{
		static int x;
		scanf("%d", &x), --x;
		p[x].y = i;
	}
	sort(p, p + n);
	int j = 0;
	rt[0] = NULL;
	REP(i, 0, n)
	{
		rt[i + 1] = rt[i];
		while (j < n && p[j].x == i) insert(rt[i + 1], p[j++].y);
	}
	scanf("%d", &m);
	int lst = 0;
	REP(i, 0, m)
	{
		static int x0, y0, x1, y1;
		scanf("%d%d%d%d", &x0, &y0, &x1, &y1), --x0, --y0, --x1, --y1;
		(x0 += lst) %= n, (y0 += lst) %= n, (x1 += lst) %= n, (y1 += lst) %= n;
		if (x0 > y0) swap(x0, y0);
		if (x1 > y1) swap(x1, y1);
		lst = query(rt[y0 + 1], x1, y1 + 1) - query(rt[x0], x1, y1 + 1);
		printf("%d\n", lst);
		++lst;
	}
	return 0;
}