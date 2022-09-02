#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cctype>
#include <climits>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define FOR(i, a, b) for (int i = (a), _end_ = (b); i <= _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

typedef long long LL;

const int maxn = 1e5;
const int max0 = 1e7;

const int oo = 0x3f3f3f3f;

int n, s, l;

int a[maxn + 5];

int dp[maxn + 5];

struct node
{
	node *c[2];

	int Min;

	node(): Min(0) { memset(c, 0, sizeof c); }

	void update()
	{
		Min = oo;
		REP(i, 0, 2)
			if (c[i]) Min = min(Min, c[i]->Min);
			else Min = min(Min, 0);
	}

};

node nds[max0 + 5];
int ns_tot = 0;

node *rt0, *rt1;

void modify(node *&rt, const int &x, const int &y, const int &l, const int &r)
{
	if (rt == NULL) rt = nds + (ns_tot++);
	if (LL(r) - l <= 1) 
	{
		rt->Min = y;
		return;
	}
	int mid = (LL(l) + r) >> 1;
	if (x < mid) modify(rt->c[0], x, y, l, mid);
	else modify(rt->c[1], x, y, mid, r);
	rt->update();
}

int query(node *rt, const int &x, const int &y, const int &l, const int &r)
{
	if (rt == NULL) return 0;
	if (x <= l && r <= y) return rt->Min;
	int mid = (LL(l) + r) >> 1;
	int ret = oo;
	if (x < mid) ret = min(ret, query(rt->c[0], x, y, l, mid));
	if (y > mid) ret = min(ret, query(rt->c[1], x, y, mid, r));
	return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d", &n, &s, &l);
	FOR(i, 1, n) scanf("%d", a + i);
	int t = 0;
	FOR(i, 1, n)
	{
		int tmp = oo;
		t = max(t, max(-query(rt0, INT_MIN, a[i] - s, INT_MIN, INT_MAX), -query(rt0, a[i] + s + 1, INT_MAX, INT_MIN, INT_MAX)));
		if (i - l >= t) tmp = min(oo, query(rt1, t, i - l + 1, 0, n + 1) + 1);
		modify(rt1, i, tmp, 0, n + 1);
		modify(rt0, a[i], -i, INT_MIN, INT_MAX);
		if (i == n) printf("%d\n", tmp >= oo ? -1 : tmp);
	}
	return 0;
}