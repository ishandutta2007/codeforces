#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct node {
	LL minv;
	LL lx, rx;
	node *l, *r;
	LL lazy;
};

void push(node *v){
	if(v == nullptr) return;
	if(v->lazy == 0) return;
	v->minv += v->lazy;
	if(v->l != nullptr){
		v->l->lazy += v->lazy;
	}
	if(v->r != nullptr){
		v->r->lazy += v->lazy;
	}
	v->lazy = 0;
}


void pull(node *v){
	if(v->l == nullptr) return;
	push(v->l);
	push(v->r);
	v->minv = min(v->l->minv, v->r->minv);
}

node *build(LL lx, LL rx){
	node *v = new node();
	v->minv = 0;
	v->lazy = 0;
	v->lx = lx; v->rx = rx;
	if(lx == rx){
		v->l = v->r = nullptr;
	} else {
		v->l = build(lx, (lx+rx)/2);
		v->r = build((lx+rx)/2 + 1, rx);
	}
	return v;
}

void upd(node *v, LL lx, LL rx, LL dv){
	if(v == nullptr) return;
	if(rx < v->lx || v->rx < lx) return;
	push(v);
	if(lx <= v->lx && v->rx <= rx){
		v->lazy += dv;
		return;
	}
	upd(v->l, lx, rx, dv);
	upd(v->r, lx, rx, dv);
	pull(v);
}

LL query(node *v, LL lx, LL rx){
	if(v == nullptr || rx < v->lx || v->rx < lx) return 1e10;
	push(v);
	if(lx <= v->lx && v->rx <= rx){
		return v->minv;
	}
	return min(query(v->l, lx, rx), query(v->r, lx, rx));
}


int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	LL n;
	cin >> n;
	vector<LL> a(n);
	LL dsum = 0;
	for(LL i = 0; i < n; i++){
		cin >> a[i];
		dsum += a[i];
	}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());

	vector<pair<LL,LL> > ss;
	for(LL i = 0; i < n; i++){
		ss.push_back({a[i], -i});
	}
	sort(ss.begin(), ss.end());
	reverse(ss.begin(), ss.end());
	vector<LL> order;
	for(LL i = 0; i < n; i++){
		order.push_back(-ss[i].second);
	}

	node *segtree = build(0, n);
	vector<LL> initval(n+1, 0);
	LL p = dsum;
	LL other = 0;
	map<LL,LL> stuff;
	for(LL q = n; q >= 1; q--){
		LL b = stuff[q+1];
		other -= b;
		stuff[q+1] = 0;
		stuff[q] += b;

		initval[q] = q*(q-1) - p + other;
		upd(segtree, q, q, initval[q]);
		p -= a[q-1];
		LL ff = min(a[q-1], q);
		other += ff;
		stuff[ff]++;
	}

	vector<LL> possible;
	for(LL j = 0; j <= n; j++){
		LL z =  query(segtree, 1, n);
		if(query(segtree, 1, n) >= 0){
			if((dsum + j) % 2 == 0){
				possible.push_back(j);
			}
		}
		// check possible;
		if(j == n) break;
		LL pos = order[j]+1;
		if(a[pos-1] == 0) break;
		a[pos-1]--;

		upd(segtree, pos, n, 1);
		upd(segtree, a[pos-1]+1, pos-1, -1);
		// add one to all segtree >= pos;
		// subtract one from some range
	}
	for(LL x : possible){
		cout << x << " ";
	}
	if(possible.empty()){
		cout << -1;
	}
	cout << endl;
}