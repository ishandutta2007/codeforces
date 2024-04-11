#include <bits/stdc++.h>
using namespace std;

mt19937 mt(48);
using ll = int64_t;

struct node{
	ll sz, v, p, lazy;
	node *l, *r;
	node(ll _v): sz(1), v(_v), p(mt()), lazy(0), l(nullptr),r(nullptr) {}
};

void push(node* t){
	if(t == nullptr) return;
	// unlazy a node, gives correct values of sum, set0, lazy -> 0
	if(t->lazy){
		if(t->l != nullptr){
			t->l->lazy += t->lazy;
		}
		if(t->r != nullptr){
			t->r->lazy += t->lazy;
		}
		t->v += t->lazy;
		t->lazy = 0;
	}
}

ll sz(node* t){
	push(t);
	return (t == nullptr ? 0 : t->sz);
}
void upd(node* t){ // computes fully correct values of sum, sz
	if(t == nullptr) return;
	push(t); push(t->l); push(t->r);
	t->sz = 1+sz(t->l)+sz(t->r);
}
void split(node *t, node *&l, node *&r, ll k){ // splits into [0,k-1] and [k,?]
	push(t);
	if(t == nullptr){
		l = nullptr;
		r = nullptr;
	} else if(sz(t->l) < k){
		split(t->r,t->r,r,k-sz(t->l)-1);
		l = t;
	} else {
		split(t->l,l,t->l,k);
		r=t;
	}
	upd(t);
}
void splitv(node *t, node *&l, node *&r, ll v){ // splits into <= v and > v
	push(t);
	if(t == nullptr){
		l = nullptr;
		r = nullptr;
	} else if(t->v <= v){
		splitv(t->r,t->r,r,v);
		l = t;
	} else {
		splitv(t->l,l,t->l,v);
		r=t;
	}
	upd(t);
}
void merge(node *&t, node *l, node *r){
	push(l);
	push(r);
	if(l == nullptr){
		t = r;
	} else if(r == nullptr){
		t = l;
	} else if(l->p < r->p){
		merge(l->r, l->r,r);
		t = l;	
	} else {
		merge(r->l,l,r->l);
		t=r;
	}
	upd(t);
}

void pt(node *r){
	push(r);
	if(r == nullptr) return;
	pt(r->l);
	cerr << r->v << ' ';
	pt(r->r);
}

namespace std {

template<class Fun>
class y_combinator_result {
	Fun fun_;
public:
	template<class T>
	explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

	template<class ...Args>
	decltype(auto) operator()(Args &&...args) {
		return fun_(std::ref(*this), std::forward<Args>(args)...);
	}
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

} // namespace std
int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	vector<pair<ll, ll> > a;
	ll del = 0;
	for(int i = 0; i < n; i++){
		ll x, y;
		cin >> x >> y;
		ll X = x + y;
		ll Y = x - y;
		if(abs(Y) > X){
			del += abs(Y) - X;
			Y = Y / abs(Y) * X;
		}
		a.push_back({X, Y});
	}
	sort(a.begin(), a.end());
	ll prev = 0;
	node* treap = nullptr;
	for(int q = 0; q < 2; q++){
		node* v = new node(0);
		merge(treap, treap, v);
	}
	ll lv = 0;
	ll rv = 0;
	for(auto [X, Y] : a){
		{
			node *l, *r;
			int len = sz(treap);
			split(treap, l, r, len/2);
			l->lazy -= (X - prev);
			r->lazy += (X - prev);
			merge(treap, l, r);
		}
		{
			node *l, *r;
			splitv(treap, l, r, Y);
			node* v = new node(Y);
			merge(l, l, v);
			v = new node(Y);
			merge(l, l, v);
			merge(treap, l, r);
		}
		prev = X;
		lv += abs(-X - Y);
		rv += abs(X - Y);
	}
	vector<ll> z;
	y_combinator(
		[&](auto self, node* r) -> void {
			if(r){
				push(r);
				self(r->l);
				z.push_back(r->v);
				self(r->r);
			}
		}
	)(treap);
	// for(ll x : z){
	// 	cerr << x << ' ';
	// }
	// cerr << '\n';
	ll ans = lv;
	ll cur = lv;
	for(int i = -n; i <= n; i++){
		cur += (z[n+i+1] - z[n+i]) * ll(i);
		ans = min(ans, cur);
	}
	assert(cur == rv);
	ans /= 2;
	ans += del;
	cout << ans << '\n';
}