#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}


  
template<class W,int lg=1>
struct WeightedTree{
	struct Edge{
		int to;
		W cost;
		Edge(int to,W cost):to(to),cost(cost){}
	};

	int V;
	int root;
	vector<vector<Edge>>G;

	vector<vector<int>>par;
	vector<int>dep,sz,head;
	vector<int>tin,tout;
	vector<W>dist;
	WeightedTree(int V=0,int root=0):V(V),root(root),G(V),par(lg,vector<int>(V)),sz(V),dep(V),head(V),dist(V),tin(V),tout(V){}

	void addEdge(int a,int b,W c=W(1)){
		G[a].push_back(Edge(b,c));
		G[b].push_back(Edge(a,c));
	}

	void dfs(int v,int p,int d,W c){
		par[0][v]=p;
		dep[v]=d;
		sz[v]=1;
		dist[v]=c;

		for(auto &e:G[v]){
			if(e.to==p)continue;
			dfs(e.to,v,d+1,c+e.cost);
			sz[v]+=sz[e.to];
			if(G[v][0].to==p||sz[e.to]>sz[G[v][0].to])swap(G[v][0],e);
		}
	}

	void dfs_hld(int v,int &tt){
		tin[v]=tt++;
		for(auto &e:G[v]){
			if(e.to==par[0][v])continue;
			head[e.to]=(e.to==G[v][0].to)?head[v]:e.to;
			dfs_hld(e.to,tt);
		}
		tout[v]=tt;
	}
	void init(){
		dfs(root,-1,0,W(0));
		int tt=0;
		dfs_hld(root,tt);

		for(int i=0;i+1<lg;i++){
			for(int j=0;j<V;j++){
				if(par[i][j]==-1)par[i+1][j]=-1;
				else par[i+1][j]=par[i][par[i][j]];
			}
		}
	}

	// 1<<lg >=N-1!!!!!
	int getLCA(int u,int v){
		
		if(dep[u]<dep[v])swap(u,v);
		rep(i,lg)if((dep[u]-dep[v])>>i&1)u=par[i][u];
		if(u==v)return u;

		for(int i=lg-1;i>=0;i--)if(par[i][u]!=par[i][v])u=par[i][u],v=par[i][v];
		return par[0][v];
	}

	int getLength(int a,int b=0){
		int l=getLCA(a,b);
		return dep[a]+dep[b]-2*dep[l];
	}
	W getDistance(int a,int b=0){
		int l=getLCA(a,b);
		return dist[a]+dist[b]-2*dist[l];
	}

	int getParent(int v,int k=0){
		return par[k][v];
	}
	int getDepth(int v){
		return dep[v];
	}
	int getIn(int v){
		return tin[v];
	}
	int getOut(int v){
		return tout[v];
	}
};

WeightedTree<int>T;

const int SEG=1<<20;
int dat[SEG*2],put[SEG*2];
void add(int a,int b,int x,int k=0,int l=0,int r=SEG){
	if(r<=a||b<=l)return;
	if(a<=l&&r<=b){
		put[k]+=x;
		return;
	}
	add(a,b,x,k*2+1,l,(l+r)/2);
	add(a,b,x,k*2+2,(l+r)/2,r);
	dat[k]=max(dat[k*2+1]+put[k*2+1],dat[k*2+2]+put[k*2+2]);
}

int query(int a,int b,int k=0,int l=0,int r=SEG){
	if(r<=a||b<=l)return 0;
	if(a<=l&&r<=b)return dat[k]+put[k];
	return max(query(a,b,k*2+1,l,(l+r)/2),query(a,b,k*2+2,(l+r)/2,r))+put[k];
}

signed main(){
	int N,K;
	scanf("%lld%lld",&N,&K);
	vector<int>A(N);rep(i,N)scanf("%lld",&A[i]);

	T=WeightedTree<int>(N+1,N);
	vector<int>stk;
	for(int i=N-1;i>=0;i--){
		while(stk.size()&&A[stk.back()]<=A[i])stk.pop_back();
		if(stk.size()){
			T.addEdge(i,stk.back());
		}
		else{
			T.addEdge(N,i);
		}
		stk.push_back(i);
	}
	int sum=0;
	rep(i,N+1)sum+=T.G[i].size();
	T.init();
	rep(i,K-1){
		add(T.getIn(i),T.getOut(i),1);
	}
	for(int i=0;i+K<=N;i++){
		add(T.getIn(i+K-1),T.getOut(i+K-1),1);
		if(i)printf(" ");
		printf("%lld",query(T.getIn(N),T.getOut(N)));
		add(T.getIn(i),T.getOut(i),-1);
	}

	return 0;
}