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
int n,c[100005];
vector<int>g[100005];
int mx[100005];
long long ans[100005];
map<int,int>mp[100005];
void dfs(int x,int par){
	int best=-1;
	for(auto to:g[x])if(to!=par){
		dfs(to,x);
		if(best==-1||mp[to].size()>mp[best].size())best=to;
	}
	if(best!=-1){
		mx[x]=mx[best];
		ans[x]=ans[best];
		mp[x].swap(mp[best]);
	}
	for(auto to:g[x])if(to!=par){
		for(auto p:mp[to]){
			mp[x][p.first]+=p.second;
			if(mp[x][p.first]>mx[x]){
				mx[x]=mp[x][p.first];
				ans[x]=p.first;
			}else if(mp[x][p.first]==mx[x]){
				ans[x]+=p.first;
			}
		}
	}
	auto p=make_pair(c[x],1);
	mp[x][p.first]+=p.second;
	if(mp[x][p.first]>mx[x]){
		mx[x]=mp[x][p.first];
		ans[x]=p.first;
	}else if(mp[x][p.first]==mx[x]){
		ans[x]+=p.first;
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1,-1);
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
	return 0;
}