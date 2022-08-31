#include <bits/stdc++.h>
using namespace std;

struct node {
	node *l, *r;
	int sum;
	int max_psum;
	int min_psum;
};
 
void init(node* v, int r){
	if(r >= 0){
		v->sum = r;
		v->max_psum = r;
		v->min_psum = 0;
	} else if(r < 0){
		v->sum = r;
		v->max_psum = 0;
		v->min_psum = r;
	} else assert(false);
}
 
void upd(node* v){
	assert(v->l && v->r);
	v->sum = v->l->sum + v->r->sum;
	v->max_psum = max(v->l->max_psum, v->l->sum + v->r->max_psum);
	v->min_psum = min(v->l->min_psum, v->l->sum + v->r->min_psum);
}

node* build(int lx, int rx, const vector<int>& s){
	node *v = new node();
	if(lx == rx){
		v->l = v->r = nullptr;
		init(v, s[lx]);
	} else {
		v->l = build(lx, (lx + rx) / 2, s);
		v->r = build((lx + rx) / 2 + 1, rx, s);
		upd(v);
	}
	return v;
}
 
void upd(node* v, int lx, int rx, int x, int c){
	if(x < lx || rx < x) return;
	if(lx == rx){
		init(v, c);
	} else {
		upd(v->l, lx, (lx + rx) / 2, x, c);
		upd(v->r, (lx + rx) / 2 + 1, rx, x, c);
		upd(v);
	}
}

const int MAXM = 1100000;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	vector<int> diff;
	diff.assign(MAXM, 0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	vector<int> b(m);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < m; i++) cin >> b[i];
	for(int i = 0; i < n; i++){
		diff[a[i]] += 1;
	}
	for(int i = 0; i < m; i++){
		diff[b[i]] -= 1;
	}
	node* segtree = build(0, MAXM-1, diff);
	int q;
	cin >> q;
	for(int _ = 0; _ < q; _++){
		int t, i, x;
		cin >> t >> i >> x;
		i -= 1;
		if(t == 1){
			diff[a[i]] -= 1;
			upd(segtree, 0, MAXM-1, a[i], diff[a[i]]);
			a[i] = x;
			diff[a[i]] += 1;
			upd(segtree, 0, MAXM-1, a[i], diff[a[i]]);
		} else {
			diff[b[i]] += 1;
			upd(segtree, 0, MAXM-1, b[i], diff[b[i]]);
			b[i] = x;
			diff[b[i]] -= 1;
			upd(segtree, 0, MAXM-1, b[i], diff[b[i]]);
		}
		if(segtree->sum - segtree->min_psum <= 0){
			cout << -1 << '\n';
		} else {
			int lx = 0;
			int rx = MAXM - 1;
			int csum = 0;
			node* cur = segtree;
			while(lx < rx){
				if(cur->r->sum - cur->r->min_psum + csum > 0){
					cur = cur->r;
					lx = (lx + rx) / 2 + 1;
				} else {
					csum += cur->r->sum;
					cur = cur->l;
					rx = (lx + rx) / 2;
				}
			}
			assert(lx == rx);
			cout << lx << '\n';
		}
	}
}