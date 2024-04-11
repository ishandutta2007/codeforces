#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, l, r, x, i;
long long A[75005], B[75005], a, b, y, last = 0;
struct TFunc
{
	int x, y, a, b, i;
	inline bool operator < (const TFunc &b)
	{
		return x < b.x;
	}
} q[2][75005];
struct TNode
{
	long long y, a, b;
	TNode *l, *r;
	TNode() {}
	TNode(long long val_y, long long val_a, long long val_b)
	{
		y = val_y;
		a = val_a;
		b = val_b;
		l = r = nullptr;
	}
} *root[2][75005];

void build(TNode *cur, int l, int r)
{
	if (l == r)
		return;
	int m = (l + r) / 2;
	cur -> l = new TNode(0, 0, 0); build(cur -> l, l, m);
	cur -> r = new TNode(0, 0, 0); build(cur -> r, m + 1, r);
}

void upd(TNode *cur, TNode *prev, int l, int r, int i, int v)
{
	if (l == r)
		return;
	int m = (l + r) / 2;
	if (q[v][i].i <= m)
	{
		cur -> r = prev -> r;
		cur -> l = new TNode(prev -> l -> y + q[v][i].y, prev -> l -> a + q[v][i].a, prev -> l -> b + q[v][i].b);
		upd(cur -> l, prev -> l, l, m, i, v);
	}
	else
	{
		cur -> l = prev -> l;
		cur -> r = new TNode(prev -> r -> y + q[v][i].y, prev -> r -> a + q[v][i].a, prev -> r -> b + q[v][i].b);
		upd(cur -> r, prev -> r, m + 1, r, i, v);
	}
}

void que(TNode *cur, int l, int r, int L, int R)
{
	if (l > R || r < L)
		return;
	if (L <= l && r <= R)
	{
		a -= cur -> a; b -= cur -> b; y += cur -> y;
		return;
	}
	int m = (l + r) / 2;
	que(cur -> l, l, m, L, R);
	que(cur -> r, m + 1, r, L, R);
}

int BS_1(int x)
{
	int l = 1, r = n, m;
	while (l <= r)
	{
		m = (l + r) / 2;
		if (q[0][m].x >= x)
			r = m - 1;
		else l = m + 1;
	}
	return l;
}

int BS_2(int x)
{
	int l = 1, r = n, m;
	while (l <= r)
	{
		m = (l + r) / 2;
		if (q[1][m].x >= x)
			r = m - 1;
		else l = m + 1;
	}
	return r;
}

int main(int argc, char** argv)
{
	A[0] = B[0] = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d%d%d%I64d%I64d%d", &q[0][i].x, &q[1][i].x, &q[0][i].y, &a, &b, &q[1][i].y);
		q[0][i].a = q[1][i].a = a; q[0][i].b = q[1][i].b = b; q[0][i].i = q[1][i].i = i;
		A[i] = A[i - 1] + a; B[i] = B[i - 1] + b;
	}
	root[0][n + 1] = new TNode(0, 0, 0); build(root[0][n + 1], 1, n);
	root[1][0] = new TNode(0, 0, 0); build(root[1][0], 1, n);
	sort(q[0] + 1, q[0] + n + 1);
	for (i = n; i >= 1; i--)
	{
		root[0][i] = new TNode(root[0][i + 1] -> y + q[0][i].y, root[0][i + 1] -> a + q[0][i].a, root[0][i + 1] -> b + q[0][i].b);
		upd(root[0][i], root[0][i + 1], 1, n, i, 0);
	}
	sort(q[1] + 1, q[1] + n + 1);
	for (i = 1; i <= n; i++)
	{
		root[1][i] = new TNode(root[1][i - 1] -> y + q[1][i].y, root[1][i - 1] -> a + q[1][i].a, root[1][i - 1] -> b + q[1][i].b);
		upd(root[1][i], root[1][i - 1], 1, n, i, 1);
	}
	scanf("%d", &m);
	while (m--)
	{
		scanf("%d%d%d", &l, &r, &x);
		x = (last + x) % 1000000000;
		a = A[r] - A[l - 1]; b = B[r] - B[l - 1]; y = 0;
		que(root[0][BS_1(x)], 1, n, l, r);
		que(root[1][BS_2(x)], 1, n, l, r);
		printf("%I64d\n", (last = a * x + b + y));
	}
	return 0;
}