#include <bits/stdc++.h>
using namespace std;
int n, m, f, k;
int ask;
class query{
public:
	int t, d, x, y, a;
	void input(){
		cin>>t;
		if(t<3) cin>>x;
		if(t<2) cin>>y;
		d=f;
		if(t==3) f++;
		if(t==2) ask++;
		a=ask;
	}
} q[500001];
int rt[100001];
int root(int u){
	while(rt[u]>0) u=rt[u];
	return u;
}
void unite(int u, int v, vector <pair <int, int>> &rb){
	u=root(u);
	v=root(v);
	if(u==v) return;
	if(rt[u]>rt[v]) swap(u, v);
	rb.push_back({u, rt[u]});
	rb.push_back({v, rt[v]});
	rt[u]+=rt[v];
	rt[v]=u;
}
class segmentTree{
public:
	using pointer=segmentTree*;
	int l, r, m;
	pointer left, right;
	vector <pair <int, int>> add, restore;
	vector <int> query;
	segmentTree(int l, int r): l(l), r(r), m((l+r)/2){
		if(l!=r){
			left=new segmentTree(l, m);
			right=new segmentTree(m+1, r);
		}
		else{
			left=right=nullptr;
		}
	}
	void make(int u, int v, int p, int q){
		if(l>v||r<u) return;
		if(u<=l&&v>=r){
			add.push_back({p, q});
		}
		else{
			left->make(u, v, p, q);
			right->make(u, v, p, q);
		}
	}
	void addQuery(int u, int x){
		if(l==r){
			query.push_back(x);
		}
		else{
			if(m>=u) left->addQuery(u, x);
			else right->addQuery(u, x);
		}
	}
	void solve(){
		for(auto p: add) unite(p.first, p.second, restore);
		add.clear();
		for(int p: query) cout<<-rt[root(p)]<<'\n';
		query.clear();
		if(l!=r){
			left->solve();
			right->solve();
		}
		while(!restore.empty()){
			auto p=restore.back();
			restore.pop_back();
			rt[p.first]=p.second;
		}
	}
};
segmentTree::pointer tree;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++)	q[i].input();	
	if(ask==0) return 0;
	tree=new segmentTree(1, ask);
	for(int i=1, last=1, fa=0; i<=m; i++){
		while((last<m)&&(q[last+1].d-q[i].d<k)) last++;
		while((fa<=m)&&(q[fa].a<=q[i].a)) fa++;
		if(q[i].t==1) if(fa<=last) tree->make(q[fa].a, q[last].a, q[i].x, q[i].y); 
		if(q[i].t==2) tree->addQuery(q[i].a, q[i].x);
	}
	for(int i=1; i<=n; i++) rt[i]=-1;
	tree->solve();
}