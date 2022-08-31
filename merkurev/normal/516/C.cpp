#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
using namespace std;


const int ST = 17;
const int LEVEL = (1 << ST);
const int SIZE = (LEVEL << 1);

int h[LEVEL];
int d[LEVEL];

struct Node
{
	long long ans;
	long long maxL;
	long long maxR;
	long long inD;
	int l, r;

	Node() : ans(0), maxL(0), maxR(0), inD(), l(), r() {}
	Node(int x) : ans(0), maxL(2 * h[x] ), maxR(2 * h[x] ), inD(), l(x), r(x + 1) {}

	void print()
	{
		fprintf(stderr, "[%d..%d), maxL = %lld, maxR = %lld, ans = %lld, inD = %lld\n", l, r, maxL, maxR, ans, inD);
	}
};



Node merge(Node l, Node r, bool pr = true)
{
	if (l.l == l.r)
		return r;
	if (r.l == r.r)
		return l;

	int md = d[l.r - 1];
	Node ans = Node();
	ans.ans = max(max(l.ans, r.ans), l.maxR + r.maxL + md);
	ans.maxL = max(l.maxL, r.maxL + l.inD + md);
	ans.maxR = max(r.maxR, l.maxR + r.inD + md);
	ans.inD = l.inD + r.inD + md;
	ans.l = l.l;
	ans.r = r.r;
	/*
	if (pr)
	{
		l.print();
		r.print();
		ans.print();
		fprintf(stderr, "\n");
	}
	*/
	return ans;
}

Node tree[SIZE];


Node query(int v, int l, int r)
{
	if (r <= tree[v].l || l >= tree[v].r)
		return Node();
	if (l <= tree[v].l && tree[v].r <= r)
		return tree[v];
	return merge(query(2 * v, l, r), query(2 * v + 1, l, r) );
}

void buildTree(int n)
{
	for (int i = LEVEL; i < LEVEL + n; i++)
		tree[i] = Node(i - LEVEL);
	for (int i = LEVEL - 1; i >= 1; i--)
		tree[i] = merge(tree[2 * i], tree[2 * i + 1], false);
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &d[i] );
	for (int i = 0; i < n; i++)
		scanf("%d", &h[i] );
	buildTree(n);

	for (int i = 0; i < m; i++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		l--;
		r--;
		Node X;
		if (l <= r)
		{
			Node L = query(1, 0, l);
			Node R = query(1, r + 1, n);
			X = merge(R, L);
		}
		else
		{
			X = query(1, r + 1, l);
		}
		printf("%lld\n", X.ans);
	}


	return 0;
}