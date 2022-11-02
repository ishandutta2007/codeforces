/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
#define int long long
#pragma comment("-Wl,--stack=1024000000")
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#define eprintf(...) 0
#else
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#endif
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){int ret=1;do{if(y&1)ret=(ll)ret*x%md;x=(ll)x*x%md;}while(y>>=1);return ret;}
int n;
vector<int>g[3005];
vector<pair<int,int> >edge;
int sz[3005][3005];
int dist[3003][3003];
void dfs_init(int x,int p,int st){
	for(auto to:g[x])if(to!=p){
		dist[st][to]=dist[st][x]+1;dfs_init(to,x,st);sz[st][x]+=sz[st][to];
	}
	sz[st][x]++;
}
int mem[3005][3005];
int dfs(int x,int y){
	if(x>y)swap(x,y);//x<=y
	if(~mem[x][y])return mem[x][y];
	if(x==y){
		return mem[x][y]=0;
	}
	int ret=0;
	for(auto to:g[x]){
		if(dist[y][to]<dist[y][x]){
			ret=max(ret,dfs(to,y)+sz[x][y]*sz[y][x]);
		}
	}
	for(auto to:g[y]){
		if(dist[x][to]<dist[x][y]){
			ret=max(ret,dfs(x,to)+sz[x][y]*sz[y][x]);
		}
	}
	return mem[x][y]=ret;
}
signed main(){
	memset(mem,-1,sizeof mem);
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(int i=1;i<=n;i++)dfs_init(i,-1,i);
	int ans=0;
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)if(g[i].size()==1&&g[j].size()==1)ans=max(ans,dfs(i,j));
	cout<<ans<<endl;
	return 0;
}