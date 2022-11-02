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
int ans[111111];
void col(int v,int d){
	ans[v]=d;
	for(auto u:ct[v])col(u,d+1);
}
signed main(){
	int N;scanf("%lld",&N);
	ct.set(N);
	rep(i,N-1){
		int a,b;
		scanf("%lld%lld",&a,&b);
		a--;b--;
		ct.addEdge(a,b);
	}

	ct.decompose();
	col(ct.root(),0);
	rep(i,N){
		if(i)printf(" ");
		printf("%c",(char)(ans[i]+'A'));
	}
	puts("");
	return 0;
}