/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
#define int long long 
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#endif
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n,color[5005],sz[5005],par[5005],dep[5005];
vector<pair<int,int> >g[5005];

void dfs(int x,int p,int d,int col){
	par[x]=p;sz[x]=1;color[x]=col;dep[x]=d;
	for(int i=0;i<g[x].size();i++){
		int to=g[x][i].first,co=g[x][i].second;
		if(to!=p){
			dfs(to,x,d+co,col);
			sz[x]+=sz[to];
		}
	}
}
int Min[2];
bool debug=false;
void dfs2(int x,int p,int size_all,int delta){
	Min[color[x]]=min(Min[color[x]],delta);
	for(int i=0;i<g[x].size();i++){
		int to=g[x][i].first,co=g[x][i].second;
		if(to!=p){
			dfs2(to,x,size_all,delta-(2*sz[to]-size_all)*g[x][i].second);
		}
	}
}
int solve(int x,int y,int v){
	dfs(x,y,0,1);//x->1
	dfs(y,x,0,0);//y->0
	int ans=v*sz[x]*sz[y];
	for(int i=1;i<=n;i++)if(i!=x&&i!=y){
		ans+=(dep[i]-dep[par[i]])*sz[i]*((color[i]?sz[x]:sz[y])-sz[i]);
	}
	memset(Min,0x3f3f3f3f3f3f3f3f,sizeof Min);
	int sum=0;
	for(int i=1;i<=n;i++){
		if(color[i]==1){
			sum+=dep[i];
		}
	}
	dfs2(x,y,sz[x],sum);
	sum=0;
	for(int i=1;i<=n;i++){
		if(color[i]==0){
			sum+=dep[i];
		}
	}
	dfs2(y,x,sz[y],sum);
	ans+=Min[0]*sz[x]+Min[1]*sz[y];
	return ans;
}

signed main(){
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y,z;cin>>x>>y>>z;
		g[x].push_back(make_pair(y,z));
		g[y].push_back(make_pair(x,z));
	}
	int ans=1e18;
	for(int i=1;i<=n;i++){
		for(int j=0;j<g[i].size();j++){
			int x=i,y=g[i][j].first;
			if(x<y)ans=min(ans,solve(x,y,g[i][j].second));
		}
	}
	cout<<ans<<endl;
	return 0;
}