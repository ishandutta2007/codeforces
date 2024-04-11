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

int N,K;
vint G[1111111];
int dep[1111111];
int mi[1111111];
bool ok[1111111];
void dfs(int v,int d){
	dep[v]=d;
	mi[v]=1001001001;
	if(G[v].size()==0)mi[v]=dep[v];
	for(auto u:G[v]){
		dfs(u,d+1);
		chmin(mi[v],mi[u]);
	}
	if(mi[v]-K<dep[v])ok[v]=true;
}

int num[1111111];
void dfs2(int v){
	if(G[v].size()==0){
		num[v]=1;
	}
	for(auto u:G[v]){
		dfs2(u);
		num[v]+=num[u];
	}
	if(!ok[v])num[v]=0;
}

int ans;
void dfs3(int v,int p){
	int sum=p;
	for(auto u:G[v])if(ok[u])sum+=num[u];
	chmax(ans,sum);
	for(auto u:G[v]){
		if(ok[u])sum-=num[u];
		dfs3(u,sum);
		if(ok[u])sum+=num[u];
	}
}

signed main(){
	scanf("%lld%lld",&N,&K);
	for(int i=1;i<N;i++){
		int p;scanf("%lld",&p);p--;
		G[p].pb(i);
	}

	dfs(0,0);
	dfs2(0);
	dfs3(0,0);
	cout<<ans<<endl;
	return 0;
}