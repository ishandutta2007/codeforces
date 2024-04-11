#include <bits/stdc++.h>
using namespace std;

struct node {
	node *l, *r;
	int sum, pref1, pref2, suff1, suff2, split, best;
};


//  1    2
// ---- ++++

node* build(int lx, int rx){
	node *v = new node();
	v->sum = v->best = v->suff1 = v->suff2 = v->pref1 = v->pref2 = v->split = 0;
	if(lx == rx){
		v->l = v->r = nullptr;
	} else {
		v->l = build(lx, (lx+rx) / 2);
		v->r = build((lx+rx)/2 + 1, rx);
	}
	return v;
}

void upd(node *v, int lx, int rx, int x, int val){
	if(x < lx || rx < x) return;
	if(lx == rx){
		v->sum = val;
		v->pref1 = v->suff2 = v->best = v->split = abs(v->sum);
		v->pref2 = max(v->sum, 0);
		v->suff1 = max(-v->sum, 0);
	} else {
		upd(v->l, lx, (lx + rx) / 2, x, val);
		upd(v->r, (lx + rx) / 2 + 1, rx, x, val);
		v->sum = v->l->sum + v->r->sum;
		v->pref1 = max(v->l->pref1, max(v->l->split + v->r->pref2, -v->l->sum + v->r->pref1));
		v->pref2 = max(v->l->pref2, v->l->sum + v->r->pref2);
		v->suff1 = max(v->r->suff1, v->l->suff1 - v->r->sum);
		v->suff2 = max(v->r->suff2, max(v->l->suff1 + v->r->split, v->l->suff2 + v->r->sum));
		v->split = max(v->l->split + v->r->sum, -v->l->sum + v->r->split);
		v->best = max(max(v->l->best, v->r->best), 
			max(v->l->suff1 + v->r->pref1, v->l->suff2 + v->r->pref2));
	}
}

int main(){
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	n = s.size();
	node* segtree = build(0, n-1);
	for(int i = 0; i < n; i++){
		if(s[i] == '('){
			upd(segtree, 0, n-1, i, 1);
		} else {
			upd(segtree, 0, n-1, i, -1);
		}
	}
	for(int i = 0; i <= q; i++){
		cout << segtree->best << '\n';
		if(i == q) continue;
		for(int _ = 0; _ < 2; _++){
			int a;
			cin >> a;
			a--;
			s[a] ^= '(' ^ ')';
			if(s[a] == '('){
				upd(segtree, 0, n-1, a, 1);
			} else {
				upd(segtree, 0, n-1, a, -1);
			}
		}
	}
}