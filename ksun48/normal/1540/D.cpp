#include <bits/stdc++.h>
using namespace std;

// Either globally or in a single class:
static char buf[450 << 20];
void* operator new(size_t s) {
	static size_t i = sizeof buf;
	assert(s < i);
	return (void*)&buf[i -= s];
}
void operator delete(void*) {}

mt19937 mt(48);
using ll = int;

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
void splitv(node *t, node *&l, node *&r, ll v){
	push(t);
	if(t == nullptr){
		l = nullptr;
		r = nullptr;
	} else if(t->v < v){
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

void pt(node *r, vector<int>& x){
	if(r == nullptr) return;
	push(r);
	pt(r->l, x);
	x.push_back(r->v);
	pt(r->r, x);
}

const int B = 100;
const int R = int(1e5) / B + 1;
vector<int> res[R];

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> b(n);
	for(int i = 0; i < n; i++){
		cin >> b[i];
		b[i] = i - b[i];
	}

	auto compute = [&](int x){
		int st = (x / B) * B;
		int en = min(st + B, n);
		node* treap = nullptr;
		for(int j = st; j < en; j++){
			node *l, *r;
			splitv(treap, l, r, b[j]);
			node* v = new node(b[j]);
			if(r) r->lazy += 1;
			merge(v, v, r);
			merge(treap, l, v);
		}
		res[x/B].clear();
		pt(treap, res[x/B]);
	};
	for(int i = 0; i < n; i += B){
		compute(i);
	}
	vector<int> ans;
	int Q;
	cin >> Q;
	for(int q = 0; q < Q; q++){
		int type;
		cin >> type;
		if(type == 1){
			int i, x;
			cin >> i >> x;
			i--;
			b[i] = i-x;
			compute(i);
		} else {
			int k;
			cin >> k;
			k--;
			int cur = b[k];
			k++;
			while(k < n && (k % B)){
				if(cur >= b[k]){
					cur++;
				}
				k++;
			}
			while(k < n){
				vector<int>& r = res[k/B];
				int s = -1;
				int e = (int)r.size();
				while(s + 1 < e){
					int m = (s + e) / 2;
					if(r[m] - m > cur){
						e = m;
					} else {
						s = m;
					}
				}
				cur += e;
				k += B;
			}
			ans.push_back(cur);
		}
	}
	for(int cur : ans) cout << (cur+1) << '\n';
}