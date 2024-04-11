#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<int> par;
vector<LL> pwgt;
vector<vector<int> > ch;

struct node {
	node *l, *r;
	LL minv;
	LL lazy;
	int lx, rx;
};
vector<vector<int> > query_loc;
vector<int> ql, qr;
vector<LL> answers;

vector<LL> st_dist;

vector<int> sidx, eidx;
void precomp(int v, LL x){
	x += pwgt[v];
	sidx[v] = eidx[v] = v;
	if(ch[v].size() == 0){
		st_dist[v] = x;
	} else {
		st_dist[v] = 1e17;
	}
	for(int w : ch[v]){
		precomp(w, x);
		sidx[v] = min(sidx[v], sidx[w]);
		eidx[v] = max(eidx[v], eidx[w]);
	}
}

node* segtree;

void push(node *v){
	if(v != nullptr && v->lazy){
		v->minv += v->lazy;
		if(v->l != nullptr){
			v->l->lazy += v->lazy;
			v->r->lazy += v->lazy;
		}
		v->lazy = 0;
	}
}
void upd(node *v, int lx, int rx, LL val){
	push(v);
	if(rx < v->lx) return;
	if(v->rx < lx) return;
	if(lx <= v->lx && v->rx <= rx){
		v->lazy += val;
		push(v);
		return;
	}
	upd(v->l, lx, rx, val);
	upd(v->r, lx, rx, val);	
	v->minv = min(v->l->minv, v->r->minv);
}
LL query(node *v, int lx, int rx){
	push(v);
	if(rx < v->lx) return 1e17;
	if(v->rx < lx) return 1e17;
	if(lx <= v->lx && v->rx <= rx){
		return v->minv;
	}
	return min(query(v->l, lx, rx), query(v->r, lx, rx));
}

node* build(int lx, int rx){
	node *v = new node();
	v->lx = lx; v->rx = rx;
	v->lazy = 0;
	if(lx == rx){
		v->minv = st_dist[lx];
		v->l = v->r = nullptr;
	} else {
		v->l = build(lx, (lx + rx) / 2);
		v->r = build((lx + rx) / 2 + 1, rx);
		v->minv = min(v->l->minv, v->r->minv);
	}
	return v;
}


int n, q;
void dfs(int v){
	// change distances;
	int s = sidx[v];
	int e = eidx[v];
	LL wgt = pwgt[v];
	upd(segtree, 0, n-1, wgt);
	upd(segtree, s, e, - 2 * wgt);

	for(int w : query_loc[v]){
		answers[w] = query(segtree, ql[w], qr[w]);
	}
	for(int w : ch[v]){
		dfs(w);
	}
	// change distances back
	upd(segtree, 0, n-1, - wgt);
	upd(segtree, s, e, 2 * wgt);
}


int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> q;
	par.resize(n);
	ch.resize(n);
	pwgt.resize(n);
	par[0] = -1;
	pwgt[0] = 0;
	st_dist.resize(n);
	for(int i = 1; i < n; i++){
		cin >> par[i] >> pwgt[i];
		par[i]--;
		ch[par[i]].push_back(i);
	}
	sidx.resize(n);
	eidx.resize(n);
	precomp(0, 0);

	segtree = build(0, n-1);

	query_loc.resize(n);
	ql.resize(q); qr.resize(q);
	answers.assign(q, -1);
	for(int i = 0; i < q; i++){
		int v, l, r;
		cin >> v >> l >> r;
		v--; l--; r--;
		query_loc[v].push_back(i);
		ql[i] = l; qr[i] = r;
	}
	dfs(0);
	for(int i = 0; i < q; i++){
		cout << answers[i] << '\n';
	}
}