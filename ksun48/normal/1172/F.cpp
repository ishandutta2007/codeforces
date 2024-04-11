#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, m;
ll p;

struct node {
	node *l, *r;
	ll offset;
	vector<ll> dips;
};

ll apply_func(node* v, ll m){
	int s = -1;
	int e = (int)v->dips.size();
	while(s + 1 < e){
		int mid = (s + e) / 2;
		if(v->dips[mid] <= m){
			s = mid;
		} else {
			e = mid;
		}
	}
	m += v->offset;
	return m - p * e;
}

node* build(int lx, int rx, const vector<ll> &a){
	node* v = new node();
	if(lx == rx){
		v->l = v->r = nullptr;
		v->offset = a[lx];
		v->dips = {p - a[lx]};
	} else {
		v->l = build(lx, (lx + rx) / 2, a);
		v->r = build((lx + rx) / 2 + 1, rx, a);
		// combine these
		v->offset = v->l->offset + v->r->offset;

		ll cur = v->l->offset;

		int idx = 0;
		while(idx < (int)v->r->dips.size() && v->r->dips[idx] - cur < v->l->dips.front()){
			v->dips.push_back(v->r->dips[idx] - cur);
			idx += 1;
		}
		for(int i = 0; i < (int)v->l->dips.size(); i++){
			ll x = v->l->dips[i];
			if(idx > 0 && v->r->dips[idx-1] >= x + cur - p){
				idx -= 1;
			} else {
				v->dips.push_back(x);
			}
			cur -= p;
			ll lim = (i + 1 == (int)(v->l->dips.size())) ? ll(2e18) : v->l->dips[i+1];
			while(idx < (int)v->r->dips.size() && v->r->dips[idx] - cur < lim){
				v->dips.push_back(v->r->dips[idx] - cur);
				idx += 1;
			}
		}
		v->offset = v->l->offset + v->r->offset;
	}
	return v;
}

// v->l->offset + q >= v->r->dips[idx] -> ok

ll apply(node *v, int lx, int rx, int qlx, int qrx, ll m){
	if(qrx < lx || rx < qlx) return m;
	if(qlx <= lx && rx <= qrx){
		return apply_func(v, m);
	} else {
		m = apply(v->l, lx, (lx + rx) / 2, qlx, qrx, m);
		m = apply(v->r, (lx + rx) / 2 + 1, rx, qlx, qrx, m);
		return m;
	}
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> p;
	vector<ll> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	node* segtree = build(0, n-1, a);
	for(int i = 0; i < m; i++){
		int l, r;
		cin >> l >> r;
		l--; r--;
		cout << apply(segtree, 0, n-1, l, r, 0) << '\n';
	}
}