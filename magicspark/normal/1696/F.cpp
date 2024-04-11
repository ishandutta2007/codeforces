/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1e9+7;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#define eprintf(...) 0
#else
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#endif
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){int ret=1;do{if(y&1)ret=(ll)ret*x%md;x=(ll)x*x%md;}while(y>>=1);return ret;}
inline int Rand(){return rand()*32768+rand();}
int T,n,tot;
bool f[105][105][105],vis[105];
int dist[105][105];
vector<int>g[105];
void dfs(int x,int par){
	if(vis[x]){
		tot=inf;
		return;
	}
	tot++;vis[x]=1;
	for(int i=1;i<=n;i++)if(i!=par&&f[x][par][i]){
//		cerr<<x<<" "<<i<<" "<<par<<" "<<vis[i]<<endl;
		g[x].push_back(i);
		g[i].push_back(x);
		dfs(i,x);
	}
}
bool check(int x,int y){
	for(int i=1;i<=n;i++)g[i].clear();
	g[x].push_back(y);g[y].push_back(x);
	tot=0;
	memset(vis,0,sizeof vis);
//	cerr<<"check: "<<x<<" "<<y<<endl;
	dfs(x,y);
	dfs(y,x);
//	cerr<<tot<<endl;
	return tot==n;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>T;
	while(T--){
		cin>>n;
		memset(f,0,sizeof f);
		bool ff=1;
		for(int i=1;i<n;i++)for(int j=1;j<=n-i;j++){
			string s;cin>>s;s=" "+s;
			for(int k=1;k<=n;k++)if(s[k]=='1'&&(i==k||i+j==k))ff=0;
			for(int k=1;k<=n;k++)f[k][i][i+j]=f[k][i+j][i]=(s[k]=='1');
		}
		if(!ff){
			cout<<"No"<<endl;
			continue;
		}
		bool hv=0;
		for(int i=2;i<=n;i++)if(check(1,i)){
			hv=1;memset(dist,inf,sizeof dist);
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dist[i][j]=(i==j?0:inf);
		for(int i=1;i<=n;i++)for(auto to:g[i])dist[i][to]=1;
		for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
		for(int i=1;i<n;i++)for(int j=1;j<=n-i;j++){
			for(int k=1;k<=n;k++)if((f[k][i][i+j])!=(dist[k][i]==dist[k][i+j]))hv=0;
		}
		if(hv)break;
		}
		if(hv){
			cout<<"Yes"<<endl;
			for(int i=1;i<=n;i++)for(auto to:g[i])if(i<to)cout<<i<<" "<<to<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}