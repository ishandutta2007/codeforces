#include <bits/stdc++.h>
using namespace std;

struct node {
	int lx, rx;
	node *l, *r;
	int minv;
	int cnt;
	int lazy;
};

node* build(int lx, int rx, vector<int>& a){
	node* v = new node();
	v->lx = lx; v->rx = rx;
	if(lx == rx){
		v->l = v->r = 0;
		v->lazy = 0;
		v->minv = a[lx];
		v->cnt = 1;
	} else {
		int mx = (lx + rx) / 2;
		v->l = build(lx, mx, a);
		v->r = build(mx + 1, rx, a);
		v->minv = min(v->l->minv, v->r->minv);
		v->cnt = (v->minv == v->l->minv ? v->l->cnt : 0) + (v->minv == v->r->minv ? v->r->cnt : 0);
		v->lazy = 0;
	}
	return v;
}

void push(node *v){
	if(!v || v->lazy == 0) return;
	v->minv += v->lazy;
	if(v->l) v->l->lazy += v->lazy;
	if(v->r) v->r->lazy += v->lazy;
	v->lazy = 0;
}

const int maxv = int(1e9);

pair<int,int> min_query(node *v, int lx, int rx){
	push(v);
	if(!v || rx < v->lx || v->rx < lx) return {maxv, 0};
	if(lx <= v->lx && v->rx <= rx) return {v->minv, v->cnt};
	pair<int,int> a = min_query(v->l, lx, rx);
	pair<int,int> b = min_query(v->r, lx, rx);
	if(a.first == b.first) return {a.first, a.second + b.second};
	return (a < b) ? a : b;
}

void upd(node *v, int lx, int rx, int del){
	push(v);
	if(!v || rx < v->lx || v->rx < lx) return;
	if(lx <= v->lx && v->rx <= rx){
		v->lazy += del;
		push(v);
		return;
	}
	upd(v->l, lx, rx, del);
	upd(v->r, lx, rx, del);
	push(v->l);
	v->minv = min(v->l->minv, v->r->minv);
	v->cnt = (v->minv == v->l->minv ? v->l->cnt : 0) + (v->minv == v->r->minv ? v->r->cnt : 0);
}


int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	const int M = int(1e6) + 1;

	const int INF = int(1e8);
	int n, q;
	cin >> n >> q;
	vector<int> a(n+2);
	for(int i = 1; i <= n; i++) cin >> a[i];
	a[0] = M;
	a[n+1] = 0;
	vector<int> st(M+1, INF);
	for(int i = 1; i <= n; i++) st[a[i]] = 0;
	node* segtree = build(0, M, st);
	for(int i = 0; i <= n; i++){
		int f = a[i];
		int g = a[i+1];
		if(f > g) swap(f, g);
		upd(segtree, f, g-1, 1);
	}
	for(int _ = 0; _ < q; _++){
		int pos, x;
		cin >> pos >> x;
		for(int j = 0; j < 2; j++){
			int f = a[pos-j];
			int g = a[pos+1-j];
			if(f > g) swap(f, g);
			upd(segtree, f, g-1, -1);
		}
		upd(segtree, a[pos], a[pos], INF);
		a[pos] = x;
		upd(segtree, a[pos], a[pos], -INF);
		for(int j = 0; j < 2; j++){
			int f = a[pos-j];
			int g = a[pos+1-j];
			if(f > g) swap(f, g);
			upd(segtree, f, g-1, 1);
		}
		pair<int,int> minv = min_query(segtree, 0, M);
		assert(minv.first >= 1);
		cout << (minv.first == 1 ? minv.second : 0) << '\n';
	}
}