#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct node {
	node *l, *r;
	int pr, val, sz, rev;
	node(int value = 0) : l(0), r(0), pr(rng()), val(value), sz(1) , rev(0) {}
} *root, *ll, *rr, *mm;

void reset() {
	ll = rr = mm = new node();
}

int sz(node* v) {
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

void rev(node *v) {
	if (v) {
		v->rev ^= 1;
	}
}

void push(node *v) {
	if (v && v->rev) {
		v->rev = 0;
		swap(v->l, v->r);
		rev(v->l);
		rev(v->r);
	}
}

void merge(node* &v, node *l, node *r) {
	push(l), push(r);
	if (!l || !r) {
		v = l ? l : r;
	} else if (l->pr > r->pr) {
		merge(l->r, l->r, r);
		v = l;
	} else {
		merge(r->l, l, r->l);
		v = r;
	}
	pull(v);
}

void split(node *v, node* &l, node* &r,int key) {
	if (!v) {
		return void(l = r = 0);
	}
	push(v);
	if (key <= sz(v->l)) {
		split(v->l, l, v->l, key);
		r = v;
	} else {
		split(v->r, v->r, r, key - sz(v->l) - 1);
		l = v;
	}
	pull(v);
}

void insert(int pos,int val) {
	reset();
	split(root, ll, rr, pos);
	mm->val = val;
	merge(root, ll, mm);
	merge(root, root, rr);
}

void erase(int pos) {
	reset();
	split(root, ll, rr, pos);
	split(rr, mm, rr, 1);
	merge(root, ll, rr);
}

void reverse(int l,int r) {
	reset();
	split(root, ll, rr, l);
	split(rr, mm, rr, r - l + 1);
	rev(mm);
	merge(root, ll, mm);
	merge(root, root, rr);
}

void shift(int l, int r) {
	reset();
	split(root, ll, rr, r);
	split(rr, mm, rr, 1);
	merge(root, ll, rr);
	split(root, ll, rr, l);
	merge(root, ll, mm);
	merge(root, root, rr);
}

int answer(int pos) {
	reset();
	split(root, ll, rr, pos);
	split(rr, mm, rr, 1);
	merge(root, ll, mm);
	merge(root, root, rr);
	return mm->val;
}

int main() {
	int n, q, m;
	scanf("%d %d %d", &n, &q, &m);
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		if (i == 0) {
			root = new node(a);
		} else {
			insert(i, a);
		}
	}
	while (q--) {
		int op;
		scanf("%d", &op);
		if (op == 1) {
			int l, r;
			scanf("%d %d", &l, &r);
			--l, --r;
			shift(l, r);
		} else {
			int l, r;
			scanf("%d %d", &l, &r);
			--l, --r;
			reverse(l, r);
		}
	}
	while (m--) {
		int pos;
		scanf("%d", &pos);
		--pos;
		printf("%d ", answer(pos));
	}
}