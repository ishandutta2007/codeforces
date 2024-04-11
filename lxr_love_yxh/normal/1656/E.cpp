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
int t,n,sum[100005],val[100005];
vector<int>g[100005];
void dfs(int x,int par,int dep){
	for(auto to:g[x])if(to!=par){
		dfs(to,x,dep+1);sum[x]+=sum[to];
	}
	if(dep&1){
		//target=1
		val[x]=g[x].size();
	}else{
		val[x]=-((int)g[x].size());
	}
} 
int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1;i<=n;i++)sum[i]=val[i]=0;
		for(int i=1;i<n;i++){
			int x,y;cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		int root=1;
		for(int i=1;i<=n;i++)if(g[i].size()==1)root=i;
		dfs(root,-1,0);
		for(int i=1;i<=n;i++)cout<<val[i]<<" ";cout<<endl;
	}
	return 0;
}