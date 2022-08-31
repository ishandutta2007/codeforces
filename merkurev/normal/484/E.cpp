#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int maxn = 1e5 + 100;
int h[maxn];
pair <int,int> a[maxn];

struct Node
{
	int l, r;
	int maxLen, lenL, lenR;
	Node() : l(), r(), maxLen(), lenL(), lenR() {}
	Node(int _l, int _r, int _maxLen, int _lenL, int _lenR) : l(_l), r(_r), maxLen(_maxLen), lenL(_lenL), lenR(_lenR) {}
};


const int ST = 17;
const int LEVEL = (1 << ST);
const int MX = 1e7;

Node tree[MX];
int treesz = 0;

int newNode()
{
	if (treesz == MX)
		throw 42;
	tree[treesz++] = Node();
	return treesz - 1;
}
int newNode(int l, int r, int maxLen, int lenL, int lenR)
{
	tree[treesz++] = Node(l, r, maxLen, lenL, lenR);
	return treesz - 1;
}

void builtTree(int root, int hi = ST)
{
	if (hi == 0)
		return;
	tree[root].l = newNode();
	tree[root].r = newNode();
	builtTree(tree[root].l, hi - 1);
	builtTree(tree[root].r, hi - 1);
}

int merge(int l, int r, int hlen)
{
	int nl = tree[l].lenL;
	if (nl == hlen)
		nl += tree[r].lenL;
	int nr = tree[r].lenR;
	if (nr == hlen)
		nr += tree[l].lenR;
	int nm = max(max(tree[l].maxLen, tree[r].maxLen), tree[l].lenR + tree[r].lenL);
	return newNode(l, r, nm, nl, nr);
}

int getW(int root, int l, int r, int tl = 0, int tr = LEVEL)
{
	if (tr <= l || tl >= r)
		return newNode();
	if (l <= tl && tr <= r)
		return root;
	int tm = (tl + tr) / 2;
	int L = getW(tree[root].l, l, r, tl, tm);
	int R = getW(tree[root].r, l, r, tm, tr);

	
	return merge(L, R, tm - tl);
}

int setValue(int root, int pos, int tl = 0, int tr = LEVEL)
{
	if (tl == pos && tr == tl + 1)
	{
		return newNode(0, 0, 1, 1, 1);
	}
	int tm = (tl + tr) / 2;
	int r = tree[root].r;
	int l = tree[root].l;
	if (pos < tm)
	{
		l = setValue(tree[root].l, pos, tl, tm);
	}
	else
	{
		r = setValue(tree[root].r, pos, tm, tr);
	}
	return merge(l, r, tm - tl); 
}

int root[maxn];

void print(int v, string s = "")
{
	printf("%s[%d .. %d .. %d]\n", s.c_str(), tree[v].lenL, tree[v].maxLen, tree[v].lenR);
	if (tree[v].l != 0)
	{
		print(tree[v].l, s + "   ");
		print(tree[v].r, s + "   ");
	}
}


int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &h[i] );
		a[i] = make_pair(h[i], i);
	}
	root[0] = newNode();
	builtTree(root[0] );

	sort(a, a + n);
	reverse(a, a + n);
	for (int i = 0; i < n; i++)
	{
		root[i + 1] = setValue(root[i], a[i].second);
	}
	int _sz = treesz;
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		int _l, _r, _w;
		scanf("%d%d%d", &_l, &_r, &_w);
		int l = 0, r = n;
		
		while (r - l > 1)
		{
			treesz = _sz;
			int m = (l + r) / 2;
			if (tree[getW(root[m], _l - 1, _r) ].maxLen >= _w)
				r = m;
			else
				l = m;
		}
		printf("%d\n", a[l].first);
	}



	return 0;
}