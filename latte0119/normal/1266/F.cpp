#include<bits/stdc++.h>
using namespace std;


#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second

using vint=vector<int>;
using pint=pair<int,int>;
using vpint=vector<pint>;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

template<class A,class B>
ostream& operator<<(ostream& ost,const pair<A,B>&p){
	ost<<"{"<<p.first<<","<<p.second<<"}";
	return ost;
}

template<class T>
ostream& operator<<(ostream& ost,const vector<T>&v){
	ost<<"{";
	for(int i=0;i<v.size();i++){
		if(i)ost<<",";
		ost<<v[i];
	}
	ost<<"}";
	return ost;
}


template<class W>
struct WeightedTree{
	struct Edge{
		int to;
		W cost;
		Edge(int to,W cost):to(to),cost(cost){}
	};

	int V;
	int root;
	int E;
	vector<vector<Edge>>G;

	vector<int>par_,dep_,sz_,head_;
	vector<int>tin_,tout_,vs_;
	vector<W>dist_;
	WeightedTree(int V=0,int root=0):V(V),root(root),G(V),par_(V),sz_(V),dep_(V),head_(V),dist_(V),tin_(V),tout_(V),vs_(V),E(0){}
	void set(int v){
		*this=WeightedTree(v);
	}

	void addEdge(int a,int b,W c=W(1)){
		assert(a<V&&b<V);
		assert(E+1<V);
		G[a].push_back(Edge(b,c));
		G[b].push_back(Edge(a,c));
		E++;
	}

	void dfs(int v,int p,int d,W c){
		par_[v]=p;
		dep_[v]=d;
		sz_[v]=1;
		dist_[v]=c;

		for(auto &e:G[v]){
			if(e.to==p)continue;
			dfs(e.to,v,d+1,c+e.cost);
			sz_[v]+=sz_[e.to];
			if(G[v][0].to==p||sz_[e.to]>sz_[G[v][0].to])swap(G[v][0],e);
		}
	}

	void dfs_hld(int v,int &tt){
		vs_[tt]=v;
		tin_[v]=tt++;
		for(auto &e:G[v]){
			if(e.to==par_[v])continue;
			head_[e.to]=(e.to==G[v][0].to)?head_[v]:e.to;
			dfs_hld(e.to,tt);
		}
		tout_[v]=tt;
	}
	void init(){
		dfs(root,-1,0,W(0));
		int tt=0;
		dfs_hld(root,tt);
	}

	inline int lca(int u,int v)const{
		while(head_[u]!=head_[v]){
			if(dep_[head_[u]]<dep_[head_[v]])swap(u,v);
			u=par_[head_[u]];
		}
		return dep_[u]<dep_[v]?u:v;
	}

	
	inline int ancestor(int v,int k){
		while(v!=-1){
			if(dep_[v]-dep_[head_[v]]<k){
				k-=dep_[v]-dep_[head_[v]]+1;
				v=par_[head_[v]];
				continue;
			}
			return vs_[tin_[v]-k];
		}
		return -1;
	}
	

	inline int par(int v)const{
		return par_[v];
	}

	inline int size(int v)const{
		return sz_[v];
	}
	inline int len(int a,int b=0)const{
		int l=lca(a,b);
		return dep_[a]+dep_[b]-2*dep_[l];
	}
	inline W dist(int a,int b)const{
		int l=lca(a,b);
		return dist_[a]+dist_[b]-2*dist_[l];
	}

	inline W dist(int a)const{
		return dist_[a];
	}

	inline int dep(int v)const{
		return dep_[v];
	}
	inline int tin(int v)const{
		return tin_[v];
	}
	inline int tout(int v)const{
		return tout_[v];
	}

	inline int vs(int k)const{
		return vs_[k];
	}
	inline int heavy(int v)const{
		if(G[v].size()==0||G[v][0].to==par_[v])return -1;
		return G[v][0].to;
	}

	vector<Edge>& operator[](int i){
		return G[i];
	}
};
WeightedTree<int>wt;
int N;
int H[555555];

void predfs(int v,int p){
	H[v]=0;
	for(auto &e:wt[v]){
		if(e.to==p)continue;
		predfs(e.to,v);
		chmax(H[v],H[e.to]+1);
	}
}

int ans[555555];
int diam;


vint cnt[555555];

void reCalc(int v,int p){
	vint hs;
	for(auto &e:wt[v]){
		if(e.to==p)continue;
		hs.pb(H[e.to]+1);
	}
	cnt[v]=hs;
	sort(all(cnt[v]));
}


namespace DSUOnTree{
	void dfs(int v,int p,int up,bool keep){
		chmax(diam,up);
		vpint lis;
		lis.eb(0,-1);
		for(auto &e:wt[v]){
			if(e.to==p)continue;
			lis.eb(H[e.to]+1,e.to);
		}
		sort(all(lis));
		reverse(all(lis));

		for(auto &e:wt[v]){
			if(e.to==p)continue;
			int nexup=up;
			if(lis[0].se==e.to)chmax(nexup,lis[1].fi);
			else chmax(nexup,lis[0].fi);
			dfs(e.to,v,nexup+1,false);
		}

		reCalc(v,p);

		if(cnt[v].size()<=1)return;
		for(auto &e:wt[v]){
			if(e.to==p)continue;
			int LIM;
			if(cnt[v].back()==H[e.to]+1)LIM=cnt[v][cnt[v].size()-2];
			else LIM=H[e.to];


			for(int i=1;i<=LIM;i++){
				
				int num=0;
				if(up>=i)num++;
				num+=cnt[v].size()-(lower_bound(all(cnt[v]),i)-cnt[v].begin());
				num+=cnt[e.to].size()-(lower_bound(all(cnt[e.to]),i)-cnt[e.to].begin());
				num--;
				chmax(ans[i*2],num);
			}
		}


		int LIM=cnt[v][cnt[v].size()-2]+1;
		for(int i=1;i<=LIM;i++){
			int num=0;
			if(up>=i)num++;
			num+=cnt[v].size()-(lower_bound(all(cnt[v]),i)-cnt[v].begin());
			chmax(ans[i*2],num);
			
			if(up==i-1){
				num++;
			}
			else if(binary_search(all(cnt[v]),i-1))num++;
			chmax(ans[i*2-1],num);
		}

	}
	void solve(){
		dfs(0,-1,0,false);
	}
}
signed main(){
	scanf("%d",&N);
	wt.set(N);
	rep(i,N-1){
		int a,b;
		scanf("%d%d",&a,&b);
		a--;b--;
		wt.addEdge(a,b);
	}
	wt.init();
	predfs(0,-1);

	DSUOnTree::solve();
	for(int i=2;i<=diam;i++)chmax(ans[i],2);
	for(int i=1;i<=N;i++)chmax(ans[i],1);

	rep(i,N)chmax(ans[1],wt[i].size()+1);

	for(int i=1;i<=N;i++){
		if(i>1)printf(" ");
		printf("%d",ans[i]);
	}
	puts("");
	return 0;
}