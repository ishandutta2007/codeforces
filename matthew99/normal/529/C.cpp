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
#include <set>
#include <map>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
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

const int oo = 0x3f3f3f3f;

const int maxn = 100000, maxk = 200000, maxq = 200000, max0 = 4000000;

int n, m, K, Q;
pair<pair<int, int>, pair<int, int> > q[maxq + 5];
pair<int, int> a[maxk + 5];

bool ans[maxq + 5];

struct node
{
	int Min = -oo;
	node *c[2] = {0};

	void update() { Min = oo; REP(i, 0, 2) if (c[i]) Min = min(Min, c[i]->Min); else Min = -oo; }
};

node nd[max0 + 5];
int cur = 0;

node *rt = NULL;

void insert(node *&rt, const int &x, const int &y, const int &l, const int &r)
{
	if (rt == NULL) rt = nd + (cur++), *rt = node();
	if (r - l <= 1)
	{
		rt->Min = max(rt->Min, y);
		return;
	}
	int mid = (l + r) >> 1;
	if (x < mid) insert(rt->c[0], x, y, l, mid);
	else insert(rt->c[1], x, y, mid, r);
	rt->update();
}

int query(node *rt, const int &x, const int &y, const int &l, const int &r)
{
	if (!rt) return -oo;
	if (x <= l && r <= y) return rt->Min;
	int mid = (l + r) >> 1;
	int ret = oo;
	if (x < mid) ret = min(ret, query(rt->c[0], x, y, l, mid));
	if (y > mid) ret = min(ret, query(rt->c[1], x, y, mid, r));
	return ret;
}

void solve()
{
	static pair<int, int> event[(maxq << 1) + 5];
	int en = 0;
	REP(i, 0, Q) if (!ans[i]) event[en++] = mp(q[i].x.x, i << 1), event[en++] = mp(q[i].x.y, i << 1 | 1);
	sort(a, a + K);
	sort(event, event + en);
	cur = 0;
	rt = NULL;
	int j = 0;
	REP(i, 0, K + 1)
	{
		while (j < en && (i == K || event[j].x <= a[i].x))
		{
			int tmp = event[j].y >> 1;
			if (event[j].y & 1) ans[tmp] |= query(rt, q[tmp].y.x, q[tmp].y.y, 0, m) >= q[tmp].x.x;
//			else sum[tmp] = -query(rt, q[tmp].y.x, q[tmp].y.y, 0, m);
			++j;
		}
		if (i == K) break;
		insert(rt, a[i].y, a[i].x, 0, m);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d%d", &n, &m, &K, &Q);
	REP(i, 0, K) scanf("%d%d", &a[i].x, &a[i].y), --a[i].x, --a[i].y;
	REP(i, 0, Q) scanf("%d%d%d%d", &q[i].x.x, &q[i].y.x, &q[i].x.y, &q[i].y.y), --q[i].x.x, --q[i].y.x;
	solve();
	swap(n, m);
	REP(i, 0, K) swap(a[i].x, a[i].y);
	REP(i, 0, Q) swap(q[i].x.x, q[i].y.x), swap(q[i].x.y, q[i].y.y);
	solve();
	REP(i, 0, Q) puts(ans[i] ? "YES" : "NO");
	return 0;
}