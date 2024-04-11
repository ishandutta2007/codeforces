/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
int n,lmt,can,a[200005];
__int128 dp[200005];
vector<int>g[200005];
void dfs(int x){
	if(!g[x].size())dp[x]=lmt;
	else dp[x]=0;
	for(auto to:g[x]){
		dfs(to);
		dp[x]+=dp[to];
	}
	if(dp[x]<a[x])can=0;
}
bool check(int val){
	can=1;lmt=val;dfs(1);return can;
}
void init(int x){
	for(auto to:g[x]){
		init(to);
		a[x]+=a[to];
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=2;i<=n;i++){
		int p;cin>>p;
		g[p].push_back(i);
	}
	for(int i=1;i<=n;i++)cin>>a[i];
	init(1);
	int l=-1,r=2.1e14;
	while(r-l>1){
		int mid=(l+r)/2;
		if(check(mid))r=mid;
		else l=mid;
	}
	cout<<r<<endl;
	return 0;
}