#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>
#include <random>


typedef long long ll;
typedef long double ld;

using namespace std;

mt19937 rnd(101);
const int MX = 1e7;

struct node {
	node *l, *r;
	int sz;
	int xx;
	int x;
	int d;
	int d2;
	node() {
		l = r = 0;
		x = d = d2 = 0;
		xx = 0;
		sz = 1;
	}
};

void upd(node *v) {
	v->sz = 1 + (v->l ? v->l->sz : 0) + (v->r ? v->r->sz : 0);
}

node mem[MX + 100000];
int us[MX + 100000];
int ndcnt;

node *newnode() {
	return &mem[ndcnt++];
}

node *push(node *v) {
	if (!v)
		return v;
	node *v2 = newnode();
	*v2 = *v;
	if (!v->d && !v->d2)
		return v2;
	v2->d = 0;
	v2->d2 = 0;
	if (v2->l) {
		v2->l = newnode();
		*(v2->l) = *(v->l);
		v2->l->d += v->d;
		v2->l->x += v->d;
		v2->l->d2 += v->d2;
		v2->l->xx += v->d2;
	}
	if (v2->r) {
		v2->r = newnode();
		*(v2->r) = *(v->r);
		v2->r->d += v->d;
		v2->r->x += v->d;
		v2->r->d2 += v->d2;
		v2->r->xx += v->d2;
	}
	return v2;
}

node *merge(node *l, node *r) {
	if (!l)
		return r;
	if (!r)
		return l;
	if ((int)(rnd() % (l->sz + r->sz)) < l->sz) {
		l = push(l);
		l->r = merge(l->r, r);
		upd(l);
		return l;
	}
	else {
		r = push(r);
		r->l = merge(l, r->l);
		upd(r);
		return r;
	}
}

inline int sz(node *v) {
	return v ? v->sz : 0;
}

void split(node *v, int k, node *&l, node *&r) {
	if (!v) {
		l = r = 0;
		return;
	}
	v = push(v);
	if (v->xx >= k) {
		split(v->l, k, l, v->l);
		upd(v);
		r = v;
	}
	else {
		split(v->r, k, v->r, r);
		upd(v);
		l = v;
	}
}

int get(node *v, int x) {
	if (!v)
		return -100000000;
	if (x < v->xx) {
		return get(v->l, x - v->d2) + v->d;
	}
	else {
		int ans = get(v->r, x - v->d2);
		if (ans < 0)
			return v->x;
		else
			return ans + v->d;
	}
}


int n;
pair<int, int> a[220000];
node *root;

vector<node> vv;

void dfs(int v) {
	if (us[v] != -1)
		return;
	us[v] = vv.size();
	vv.push_back(mem[v]);
	if (mem[v].l) {
		dfs(mem[v].l - mem);
		vv[us[v]].l = mem + us[mem[v].l - mem];
	}
	if (mem[v].r) {
		dfs(mem[v].r - mem);
		vv[us[v]].r = mem + us[mem[v].r - mem];
	}
}

void rebuild() {
	vv.clear();
	fill(us, us + MX + 100000, -1);
	int st = root - mem;
	dfs(st);
	cerr << vv.size() << "\n";
	st = us[st];
	for (int i = 0; i < (int)vv.size(); ++i)
		mem[i] = vv[i];
	ndcnt = vv.size();
	root = mem + st;
}


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d%d", &a[i].second, &a[i].first), a[i].first = -a[i].first;
	sort(a, a + n);
	root = newnode();
	int sz = 1e9 + 100;
	for (int i = n - 1; i >= 0; --i) {
		int x = a[i].second;
		node *l1, *r1;
		split(root, x, l1, r1);
		if (root) {
			node *tmp = newnode();
			*tmp = *root;
			root = tmp;
			root->d += 1, root->x += 1;
			root->d2 += x, root->xx += x;
		}
		root = merge(l1, root);
		split(root, sz, root, l1);
		if (ndcnt > MX)
			rebuild();
	}
	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; ++i) {
		int b;
		scanf("%d", &b);
		printf("%d ", get(root, b));
	}
	printf("\n");
	return 0;
}