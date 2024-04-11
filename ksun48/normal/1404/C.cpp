#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
	int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
		// Returns n if no sum is >= sum, or -1 if empty sum is.
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 25; pw; pw >>= 1) {
			if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
				pos += pw, sum -= s[pos-1];
		}
		return pos;
	}
};

struct node {
	node *l, *r;
	pair<int, int> minv;
	int lazy;
};

node* build(int lx, int rx){
	node* v = new node();
	if(lx == rx){
		v->l = v->r = nullptr;
	} else {
		v->l = build(lx, (lx + rx) / 2);
		v->r = build((lx + rx) / 2 + 1, rx);
	}
	v->minv = {int(1e7), lx};
	v->lazy = 0;
	return v;
}
void push(node* v){
	if(v->l){
		v->l->minv.first += v->lazy;
		v->r->minv.first += v->lazy;
		v->l->lazy += v->lazy;
		v->r->lazy += v->lazy;
		v->lazy = 0;
	}
}
void upd(node* v, int lx, int rx, int ulx, int urx, int del){
	if(urx < lx || rx < ulx) return;
	if(ulx <= lx && rx <= urx){
		v->minv.first += del;
		v->lazy += del;
	} else {
		push(v);
		upd(v->l, lx, (lx + rx) / 2, ulx, urx, del);
		upd(v->r, (lx + rx) / 2 + 1, rx, ulx, urx, del);
		v->minv = min(v->l->minv, v->r->minv);
	}
}
pair<int,int> query(node* v, int lx, int rx, int qlx, int qrx){
	if(qrx < lx || rx < qlx) return {1e8, -1};
	if(qlx <= lx && rx <= qrx){
		return v->minv;
	} else {
		push(v);
		return min(query(v->l, lx, (lx + rx) / 2, qlx, qrx),
					query(v->r, (lx + rx) / 2 + 1, rx, qlx, qrx));
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		a[i]--;
		a[i] = i - a[i];
		if(a[i] < 0) a[i] = int(1e7);
	}
	vector<int> x(q), y(q);
	for(int i = 0; i < q; i++){
		cin >> x[i] >> y[i];
	}
	vector<vector<int> > queries_where(n);
	vector<int> ans(q, -1);
	for(int i = 0; i < q; i++){
		queries_where[x[i]].push_back(i);
	}
	node* segtree = build(0, n-1);

	FT ft(n + 1);

	for(int i = n-1; i >= 0; i--){
		upd(segtree, 0, n-1, i, i, a[i] - int(1e7));
		while(true){
			pair<int,int> v = query(segtree, 0, n-1, 0, n-1);
			if(v.first <= 0){
				upd(segtree, 0, n-1, v.second, v.second, int(1e7));
				upd(segtree, 0, n-1, v.second+1, n-1, -1);
				ft.update(v.second, 1);
			} else {
				break;
			}
		}
		for(int g : queries_where[i]){
			ans[g] = ft.query(n - y[g]);
		}
	}
	for(int z : ans){
		cout << z << '\n';
	}
}