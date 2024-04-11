#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <queue>
#include <stack>
#include <bitset>
#define y1 y11
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define NAME ""

using namespace std;
	
typedef long long ll;
typedef long double ld;

const ld PI = acos(-1.0);

const int MAXN = 2000001;

struct node
{
	node *l;
	node *r;
	int val;
	int prior;
	int key;
	int sum;
};


inline int gs(node* t)
{
	return t?(t->sum):0;
}

node* newnode(int tm, int vl)
{
	node* nn = new node();
	nn->l = nn->r = NULL;
	nn->prior = (rand() << 16) + rand();
	nn->sum = nn->val = vl;
	nn->key = tm;
	return nn;
}

typedef node* pnode;

inline void upd(pnode t)
{
	t->sum = t->val + gs(t->l) + gs(t->r);
}

void split(pnode t, pnode& l, pnode& r, int k)
{
	if (!t)
	{
		l = r = NULL;
		return;
	}
	if (t->key > k)
	{
		r = t;
		split(t->l, l, r->l, k);
	}
	else
	{
		l = t;
		split(t->r, l->r, r, k);
	}
	upd(t);
}

void merge(pnode& t, pnode l, pnode r)
{
	if (!l)
	{
		t = r;
		return;
	}
	if (!r)
	{
		t = l;
		return;
	}
	if (l->prior > r->prior)
	{
		t = l;
		merge(t->r, l->r, r);
	}
	else
	{
		t = r;
		merge(t->l, l, r->l);
	}
	upd(t);
}


int xs[MAXN];
int a[MAXN], x[MAXN], t[MAXN];
pnode root[MAXN];
pnode n1, n2, n3, n4;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d", &a[i], &t[i], &x[i]);
		xs[i] = x[i];
	}
	sort(xs, xs + n);
	int xc = unique(xs, xs + n) - xs;
	for (int i = 0; i < xc; i++) root[i] = NULL;
	for (int i = 0; i < n; i++)
	{
		x[i] = lower_bound(xs, xs + xc, x[i]) - xs;
		split(root[x[i]], n1, n2, t[i]);
		if (a[i] == 3)
		{
			printf("%d\n", gs(n1));
			merge(root[x[i]], n1, n2);
		}
		else
		{
			n4 = newnode(t[i], 1);
			if (a[i] == 2) n4->val = n4->sum = -1;
			merge(n3, n1, n4);
			merge(root[x[i]], n3, n2);
		}
	}
	return 0;
}