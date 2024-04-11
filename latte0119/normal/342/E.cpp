#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
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

struct CentroidDecomposition{
	int N;
	vector<vector<int>>G;
	vector<vector<int>>T;
	vector<int>used,sz;
	int r;
	void set(int n){
		N=n;
		G.resize(N);
		T.resize(N);
	}
	void addEdge(int a,int b){
		G[a].push_back(b);
		G[b].push_back(a);
	}

	int calcSubtreeSize(int v,int p){
		sz[v]=1;
		for(auto u:G[v]){
			if(u==p||used[u])continue;
			sz[v]+=calcSubtreeSize(u,v);
		}
		return sz[v];
	}

	pair<int,int>findCentroid(int v,int p,int ov){
		pair<int,int>ret(N,-1);
		int mx=ov-sz[v];
		for(auto u:G[v]){
			if(u==p||used[u])continue;
			ret=min(ret,findCentroid(u,v,ov));
			mx=max(mx,sz[u]);
		}
		ret=min(ret,pair<int,int>(mx,v));
		return ret;
	}

	void dfs(int v,int p){
		calcSubtreeSize(v,-1);
		v=findCentroid(v,-1,sz[v]).second;
		used[v]=true;
		if(p==-1)r=v;
		else T[p].push_back(v);
		for(auto u:G[v])if(!used[u])dfs(u,v);
	}

	void decompose(){
		used.resize(N);
		sz.resize(N);
		dfs(0,-1);
	}

	inline int root()const{
		return r;
	}
	vector<int>&operator[](int i){
		return T[i];
	}
};
CentroidDecomposition ct;


const int INF=1001001001001001001ll;

vint G[111111];
int ti[111111];
vint qs[111111];
int ans[111111];

bool used[111111];
void enumerate(int v,int p,int d,vpint &lis){
	lis.eb(ti[v],d);
	for(auto u:G[v])if(u!=p&&!used[u])enumerate(u,v,d+1,lis);
}

void calc(int v,int p,int d,vpint &lis){
	for(auto t:qs[v]){
		int k=lower_bound(all(lis),pint(t,-1))-lis.begin()-1;
		if(k>=0)chmin(ans[t],d+lis[k].se);
	}

	for(auto u:G[v])if(u!=p&&!used[u])calc(u,v,d+1,lis);
}

void dfs(int v){
	vpint lis;
	enumerate(v,-1,0,lis);
	sort(all(lis));
	vpint nex;
	for(auto &pr:lis){
		if(nex.size()==0||nex.back().se>pr.se)nex.eb(pr);
	}
	lis=nex;

	calc(v,-1,0,lis);

	used[v]=true;
	for(auto u:ct[v])dfs(u);
	used[v]=false;
}

signed main(){
	int N,Q;
	scanf("%lld%lld",&N,&Q);
	ct.set(N);
	rep(i,N-1){
		int a,b;
		scanf("%lld%lld",&a,&b);
		a--;b--;
		ct.addEdge(a,b);
		G[a].pb(b);G[b].pb(a);
	}
	ct.decompose();

	fill_n(ti,N,Q);
	ti[0]=-1;
	fill_n(ans,Q,INF);
	rep(i,Q){
		int t,v;
		scanf("%lld%lld",&t,&v);
		v--;
		if(t==1){
			ti[v]=i;
		}
		else{
			qs[v].pb(i);
		}
	}

	dfs(ct.root());
	rep(i,Q)if(ans[i]!=INF)printf("%lld\n",ans[i]);
	return 0;
}