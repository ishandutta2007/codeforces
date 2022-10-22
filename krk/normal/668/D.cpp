#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;

int Random() { return rand() << 15 | rand(); }

int Random(int l, int r) { return Random() % (r - l + 1) + l; }

typedef struct node *pnode;
struct node {
	int prior, val, mycnt, cnt;
	pnode l, r;
	node(int val = 0, int mycnt = 1): val(val), prior(Random()), mycnt(mycnt), cnt(mycnt), l(NULL), r(NULL) {}
};

int Cnt(pnode it) { return it? it->cnt : 0; }

void Update(pnode it) 
{
	if (it) it->cnt = Cnt(it->l) + Cnt(it->r) + it->mycnt;
}

void Merge(pnode &t, pnode l, pnode r) {
	if (!l || !r) t = l? l: r;
	else if (l->prior > r->prior)
		Merge(l->r, l->r, r), t = l;
	else Merge(r->l, l, r->l), t = r;
	Update(t);
}

void Split(pnode t, pnode &l, pnode &r, int val) {
	if (!t) return void(l = r = 0);
	if (val < t->val)
		Split(t->l, l, t->l, val), r = t;
	else Split(t->r, t->r, r, val), l = t;
	Update(t);
}

const int Maxn = 1000005;

int n;
int a[Maxn], t[Maxn], x[Maxn];
vector <int> un;
pnode T[Maxn];

void Insert(pnode &tr, int val, int mycnt)
{
	pnode a, b; Split(tr, a, b, val);
	Merge(a, a, new node(val, mycnt));
	Merge(tr, a, b);
}

int Get(pnode &tr, int val)
{
	pnode a, b; Split(tr, a, b, val);
	int res = Cnt(a);
	Merge(tr, a, b);
	return res;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &a[i], &t[i], &x[i]);
		un.push_back(x[i]);
	}
	sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
	for (int i = 0; i < n; i++) {
		x[i] = lower_bound(un.begin(), un.end(), x[i]) - un.begin();
		if (a[i] == 1) Insert(T[x[i]], t[i], 1);
		else if (a[i] == 2) Insert(T[x[i]], t[i], -1);
		else printf("%d\n", Get(T[x[i]], t[i]));
	}
	return 0;
}