#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 1e6 + 100;
const int PW = 21;
const int SZ = (1 << PW);
const int LSZ = (1 << (PW - 1) );

struct Node
{
	int x, y, i, add;
	Node() : x(), y(), i(), add() {}
	Node(int x, int y, int i, int add) : x(x), y(y), i(i), add(add) {}
	bool operator < (const Node &A) const // better
	{
		if (y != A.y)
			return y > A.y;
		return i < A.i;
	}
};

Node tree[SZ];
int lasti[SZ];

int x[LSZ], y[LSZ];
int prv[LSZ];

int ans[maxn];

void build_tree()
{
	for (int i = 0; i < LSZ; i++)
	{
		tree[i + LSZ] = Node(x[i], y[i], i, 0);
	}
	for (int i = LSZ - 1; i >= 1; i--)
	{
		tree[i] = min(tree[2 * i], tree[2 * i + 1] );
	}
}


void push(int v)
{
	tree[v].y += tree[v].add;
	if (v < LSZ)
	{
		tree[2 * v].add += tree[v].add;
		tree[2 * v + 1].add += tree[v].add;
	}
	tree[v].add = 0;
}
void add(int v, int tl, int tr, int l, int r, int val)
{
	if (l >= tr || r <= tl)
		return;
	push(v);
	if (l <= tl && tr <= r)
	{
		tree[v].add += val;
		return;
	}
	int tm = (tl + tr) / 2;
	add(2 * v, tl, tm, l, r, val);
	add(2 * v + 1, tm, tr, l, r, val);

	push(2 * v);
	push(2 * v + 1);
	tree[v] = min(tree[2 * v], tree[2 * v + 1] );
}

void no()
{
	printf("-1\n");
	exit(0);
}

const int inf = 3e6;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	memset(lasti, -1, sizeof lasti);
	memset(prv, -1, sizeof prv);
	memset(ans, -1, sizeof ans);

	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &x[i], &y[i] );
		x[i]--;

	/*	if (prv[x[i] ] != -1)
		{
			if (y[i] != i - prv[x[i] ] )
				no();
		}*/
		prv[x[i] ] = i;

		y[i]--;
	}

	build_tree();

	for (int it = 0; it < m; it++)
	{
		push(1);
		int i = tree[1].i;
		if (tree[1].y < 0)
				continue;
		if (ans[tree[1].y] != -1)
			no();
		ans[tree[1].y] = tree[1].x;

		int li = lasti[x[tree[1].i] ];
		if (li != -1)
		{
			int d = i - li;
			add(1, 0, LSZ, li, li + 1, 0);
			int val = tree[LSZ + li].y;
			int some = tree[1].y + inf - val;
			fprintf(stderr, "some = %d, d = %d\n", some, d);
			if (some != d)
				no();
		}
		lasti[x[tree[1].i] ] = i;

		add(1, 0, LSZ, i, LSZ, -1);
		add(1, 0, LSZ, i, i + 1, -inf);

	}


	int it = 0;
	for (int i = 0; i < n; i++)
	{
		if (ans[i] == -1)
		{
			while (prv[it] != -1)
				it++;
			ans[i] = it;
			it++;
		}
		if (ans[i] >= n)
			no();
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d ", ans[i] + 1);
	}

	return 0;
}