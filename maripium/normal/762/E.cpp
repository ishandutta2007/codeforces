#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct node {
	node *l, *r;
	int x, y, sz;
	node(int x) : l(0), r(0), x(x), y(rng()), sz(1) {}
};

int sz(node *v) {
	if (v) {
		return v->sz;
	} else {
		return 0;
	}
}

void pull(node *v) {
	if (v) {
		v->sz = sz(v->l) + sz(v->r) + 1;
	}
}

void merge(node *&v, node *l, node *r) {
	if (!l) {
		v = r;
	} else if (!r) {
		v = l;
	} else if (l->y > r->y) {
		merge(l->r, l->r, r);
		v = l;
	} else {
		merge(r->l, l, r->l);
		v = r;
	}
	pull(v);
}

void split(node *v, node *&l, node *&r, int x) {
	if (!v) {
		l = r = 0;
	} else if (x <= v->x) {
		split(v->l, l, v->l, x);
		r = v;
	} else {
		split(v->r, v->r, r, x);
		l = v;
	}
	pull(v);
}

void add(node *&v,int x) {
	node *lv, *rv;
	split(v, lv, rv, x);
	node *mv = new node(x);
	merge(v, lv, mv);
	merge(v, v, rv);
}

int get(node *&v, int l,int r) {
	node *lv, *mv, *rv;
	split(v, lv, rv, l);
	split(rv, mv, rv, r);
	int ans = sz(mv);
	merge(v, lv, mv);
	merge(v, v, rv);
	return ans;
}

const int F = 10005;
node* root[F];

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	vector<tuple<int,int,int>> vals;
	for (int i = 0; i < n; ++i) {
		int x, r, f;
		scanf("%d %d %d", &x, &r, &f);
		vals.push_back(make_tuple(r, x, f));
	}
	sort(vals.begin(), vals.end());
	for (int f = 0; f < F; ++f) {
		root[f] = 0;
	} 
	long long ans = 0;
	for (int i = n - 1; ~i; --i) {
		int r, x, f;
		tie(r, x, f) = vals[i];
		for (int mf = max(0, f - k); mf <= min(F - 1, f + k); ++mf) {
			ans += get(root[mf], x - r, x + r + 1);
		}
		add(root[f], x);
	}
	printf("%lld\n", ans);
}