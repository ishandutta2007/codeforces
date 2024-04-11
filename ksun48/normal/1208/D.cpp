#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct node {
	node *l, *r;
	ll minv;
	int idx;
	ll lazy;
};

node* build(const vector<ll>& s, int lx, int rx){
	node* v = new node();
	v->lazy = 0;
	if(lx == rx){
		v->l = v->r = nullptr;
		v->minv = s[lx];
		v->idx = lx;
	} else {
		v->l = build(s, lx, (lx + rx) / 2);
		v->r = build(s, (lx + rx) / 2 + 1, rx);
		if(v->r->minv <= v->l->minv){
			v->minv = v->r->minv;
			v->idx = v->r->idx;
		} else {
			v->minv = v->l->minv;
			v->idx = v->l->idx;
		}
	}
	return v;
}

void push(node* v){
	if(v->lazy){
		if(v->l) v->l->lazy += v->lazy;
		if(v->r) v->r->lazy += v->lazy;
		v->minv += v->lazy;
		v->lazy = 0;		
	}
}

void upd(node* v, int lx, int rx, int ulx, int urx, ll val){
	push(v);
	if(rx < ulx || urx < lx) return;
	if(ulx <= lx && rx <= urx){
		assert(v->lazy == 0);
		v->lazy += val;
		push(v);
	} else {
		upd(v->l, lx, (lx + rx) / 2, ulx, urx, val);
		upd(v->r, (lx + rx) / 2 + 1, rx, ulx, urx, val);
		if(v->r->minv <= v->l->minv){
			v->minv = v->r->minv;
			v->idx = v->r->idx;
		} else {
			v->minv = v->l->minv;
			v->idx = v->l->idx;
		}
	}
}

pair<ll, int> query(node* v, int lx, int rx, int qlx, int qrx){
	push(v);
	if(qrx < lx || rx < qlx){
		return {1e16, -1};
	}
	if(qlx <= lx && rx <= qrx) return {v->minv, v->idx};
	pair<ll, int> ql = query(v->l, lx, (lx + rx) / 2, qlx, qrx);
	pair<ll, int> qr = query(v->l, (lx + rx) / 2 + 1, rx, qlx, qrx);
	if(qr.first <= ql.first){
		return qr;
	} else {
		return ql;
	}
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<ll> s(n);
	for(int i = 0; i < n; i++) cin >> s[i];
	node* segtree = build(s, 0, n-1);
	vector<int> res(n);
	for(int r = 1; r <= n; r++){
		pair<ll, int> g = query(segtree, 0, n-1, 0, n-1);
		assert(g.first == 0);
		int idx = g.second;
		res[idx] = r;
		upd(segtree, 0, n-1, idx, idx, 1e16);
		upd(segtree, 0, n-1, idx+1, n-1, -r);
	}
	for(int i = 0; i < n; i++){
		cout << res[i] << ' ';
	}
	cout << '\n';
}