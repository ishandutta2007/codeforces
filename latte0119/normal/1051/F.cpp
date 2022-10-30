#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

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

int N,M;
vpint G[111111];

bool vis[111111];
bool uku[111111];

int par[20][111111];
int dep[111111];
int tdist[111111];
void dfs(int v,int p,int d,int td){
	par[0][v]=p;
	vis[v]=true;
	dep[v]=d;
	tdist[v]=td;
	for(auto &e:G[v]){
		if(e.fi==p)continue;
		if(vis[e.fi]){
			uku[v]=uku[e.fi]=true;
		}
		else{
			dfs(e.fi,v,d+1,td+e.se);
		}
	}
}

int lca(int a,int b){
	if(dep[a]<dep[b])swap(a,b);
	rep(i,20)if((dep[a]-dep[b])>>i&1)a=par[i][a];
	if(a==b)return a;
	for(int i=19;i>=0;i--)if(par[i][a]!=par[i][b])a=par[i][a],b=par[i][b];
	return par[0][a];
}


vint dist[44];
const int INF=1001001001001001001ll;
void dijkstra(int s,vint &dis){
	dis.resize(N,INF);
	dis[s]=0;
	priority_queue<pint,vpint,greater<pint>>que;
	que.emplace(0,s);
	while(que.size()){
		int d,v;
		tie(d,v)=que.top();
		que.pop();
		if(dis[v]>d)continue;
		for(auto &e:G[v]){
			if(dis[e.fi]<=d+e.se)continue;
			dis[e.fi]=d+e.se;
			que.emplace(dis[e.fi],e.fi);
		}
	}
}
signed main(){
	scanf("%lld%lld",&N,&M);
	rep(i,M){
		int a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		a--;b--;
		G[a].eb(b,c);
		G[b].eb(a,c);
	}

	dfs(0,-1,0,0);
	rep(i,19)rep(j,N){
		if(par[i][j]==-1)par[i+1][j]=-1;
		else par[i+1][j]=par[i][par[i][j]];
	}
	vint lis;
	rep(i,N)if(uku[i])lis.pb(i);
	rep(i,lis.size()){
		dijkstra(lis[i],dist[i]);
	}

	int Q;scanf("%lld",&Q);
	while(Q--){
		int a,b;
		scanf("%lld%lld",&a,&b);
		a--;b--;
		int l=lca(a,b);
		int ans=tdist[a]+tdist[b]-2*tdist[l];

		rep(i,lis.size())rep(j,lis.size()){
			chmin(ans,dist[i][a]+dist[i][lis[j]]+dist[j][b]);
		}
		printf("%lld\n",ans);
	}

	return 0;
}