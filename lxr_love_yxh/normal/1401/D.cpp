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
inline int Rand(){return rand()*32768+rand();}
int T,n;
vector<int>g[100005];
int sz[100005];
vector<ll>vec;
void dfs(int x,int par){
	sz[x]=0;
	for(auto to:g[x])if(to!=par){
		dfs(to,x);sz[x]+=sz[to];
	}
	sz[x]++;
	if(x-1)vec.push_back((ll)sz[x]*(n-sz[x]));
}
signed main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1;i<n;i++){
			int x,y;cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		vec.clear();dfs(1,-1);
		sort(vec.rbegin(),vec.rend());
		vector<int>p;
		int m;cin>>m;
		while(m--){
			int x;cin>>x;
			p.push_back(x);
		}
		while(p.size()<vec.size()){
			p.push_back(1);
		}
		
//		for(int i=1;i<=n;i++)cerr<<i<<" "<<sz[i]<<endl;
		sort(p.begin(),p.end());
		int cnt=p.size()-vec.size()+1,mul=1;
		while(cnt--){
			mul=mul*p.back()%mod;p.pop_back();
		}
		p.insert(p.begin(),mul);
		sort(p.rbegin(),p.rend()-1);
		int ans=0;
		for(int i=0;i<vec.size();i++){
//			cerr<<vec[i]<<" "<<p[i]<<endl;
			ans+=(ll)vec[i]%mod*p[i]%mod;
			ans%=mod;
		}
		cout<<ans<<endl;
	}
	return 0;
}