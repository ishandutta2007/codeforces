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
//#pragma comment("-Wl,--stack=1024000000")
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
int n,mn;
vector<pair<int,int> >g[3003];
int dfs(int x,int p,int cur,int mv){
	int ret=0;mn=min(mn,cur-mv);
	for(auto to:g[x])if(to.first!=p){
		ret+=(to.second>0);
		ret+=dfs(to.first,x,cur-to.second,max(mv,cur-to.second));
	}
	return ret;
}
signed main(){
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		g[x].push_back(make_pair(y,-1));
		g[y].push_back(make_pair(x,1));
	}
	int ans=1e9;
	for(int i=1;i<=n;i++){
		mn=inf;ans=min(ans,dfs(i,-1,0,0)+mn);
//		cerr<<i<<" "<<dfs(i,-1,0,0)<<" "<<mn<<endl;
	}
	cout<<ans<<endl;
	return 0;
}