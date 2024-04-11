#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define FOR(i, a, b) for (int i = (a), _end_ = (b); i <= _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define EXIT(...) printf(__VA_ARGS__), exit(0)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;

template<typename T> T &Read(T &x)
{
	static char c;
	while (!isdigit(c = getchar()));
	x = c - '0';
	while (isdigit(c = getchar())) (x *= 10) += c - '0';
	return x;
}

const int max0 = 10000000;

int n, nq;

struct node
{
	node *c[2] = {0};
	int Max = 0;
	int label = 0;

	void flag_label(const int &z)
	{
		label = max(label, z);
		Max = max(Max, z);
	}
};

node nd[max0 + 5];
int cur = 0;

void modify(node *&rt, const int &x, const int &y, const int &z, const int &l, const int &r)
{
	if (!rt) rt = nd + (cur++);
	if (x <= l && r <= y) 
	{
		rt->flag_label(z);
		return;
	}
	REP(i, 0, 2)
	{
		if (!rt->c[i]) rt->c[i] = nd + (cur++);
		rt->c[i]->flag_label(rt->label);
	}
	rt->Max = max(rt->Max, z);
	rt->label = 0;
	int mid = (l + r) >> 1;
	if (x < mid) modify(rt->c[0], x, y, z, l, mid);
	if (y > mid) modify(rt->c[1], x, y, z, mid, r);
}

int query(node *rt, const int &x, const int &y, const int &l, const int &r)
{
	if (!rt) return 0;
	if (x <= l && r <= y) return rt->Max;
	REP(i, 0, 2)
	{
		if (!rt->c[i]) rt->c[i] = nd + (cur++);
		rt->c[i]->flag_label(rt->label);
	}
	int mid = (l + r) >> 1;
	int ret = 0;
	if (x < mid) ret = max(ret, query(rt->c[0], x, y, l, mid));
	if (y > mid) ret = max(ret, query(rt->c[1], x, y, mid, r));
	return ret;
}

node *rt[2];

set<pair<pair<int, int>, char> > all;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &nq);
	REP(i, 0, nq)
	{
		static int x, y;
		static char c;
		scanf("%d%d %c", &x, &y, &c);
		if (all.count(mp(mp(x, y), c))) 
		{
			printf("0\n");
			continue;
		}
		all.insert(mp(mp(x, y), c));
		if (c == 'U')
		{
			int tmp = query(rt[0], x - 1, x, 0, n + 1);
			printf("%d\n", y - tmp);
			modify(rt[1], tmp, y, x, 0, n + 1);
		}
		else 
		{
			int tmp = query(rt[1], y - 1, y, 0, n + 1);
			printf("%d\n", x - tmp);
			modify(rt[0], tmp, x, y, 0, n + 1);
		}
	}
	return 0;
}