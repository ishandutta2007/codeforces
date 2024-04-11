/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#include<bits/stdc++.h>
#pragma comment("-Wl,--stack=1024000000")
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-9;
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
inline int Rand(){return rand()*32768+rand();}
int T,n,m,a[1005],b[1005];
ll sum;
vector<int>g[1005];
bool in[1005],vis[1005];
bool dfs(int x,int par){
	if(vis[x]||in[x])return true;
	vis[x]=1;sum+=b[x];
	for(auto to:g[x])if(to!=par){
		if(a[to]>=sum)continue;
		if(dfs(to,x)){
			in[x]=1;
			vis[x]=0;
			return true;
		}
	}
	vis[x]=0;sum-=b[x];
	return false;
}
bool check(int x){
	memset(in,0,sizeof in);
	memset(vis,0,sizeof vis);
	in[1]=1;sum=x;
	while(1){
		bool flag=0;
		for(int i=1;i<=n;i++)if(in[i]){
			for(auto to:g[i])if(!in[to]&&a[to]<sum){
				if(dfs(to,i))flag=1;
			}
		}
		if(!flag)return false;
		for(int i=1;i<=n;i++)if(!in[i])flag=0;
		if(flag)return true;
	}
}
int main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=2;i<=n;i++)cin>>a[i];
		for(int i=2;i<=n;i++)cin>>b[i];
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1;i<=m;i++){
			int x,y;cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		int l=0,r=INT_MAX;
		while(r-l>1){
			int mid=(r-l)/2+l;
			if(check(mid))r=mid;
			else l=mid;
		}
		cout<<r<<endl;
	}
	return 0;
}