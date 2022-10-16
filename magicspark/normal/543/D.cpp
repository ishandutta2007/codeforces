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
int n,p[200005];
vector<int>g[200005];
int dp[200005][2];
void add(int &x,int y){
	x+=y;if(x>=mod)x-=mod;
}
void sub(int &x,int y){
	x-=y;if(x<0)x+=mod;
}
void mul(int &x,int y){
	x=1ll*x*y%mod;
}
int divide(int x,int y){
	return 1ll*x*modpow(y,mod-2)%mod;
}
void dfs(int x){
	dp[x][0]=dp[x][1]=1;
	for(auto to:g[x]){
		dfs(to);
		mul(dp[x][0],dp[to][0]);
		mul(dp[x][1],(dp[to][1]+dp[to][0])%mod);
	}
}
int ans[200005];
int get(vector<int>&v,int pos){
	if(pos<0||pos>=v.size())return 1;
	else return v[pos];
}
void go(int x,int dp0,int dp1){
	cerr<<x<<" "<<dp0<<" "<<dp1<<endl;
	if(x!=1){
		mul(dp[x][0],dp0);
		mul(dp[x][1],(dp0+dp1)%mod);
	}
	add(ans[x],dp[x][1]);
	vector<int>pref[2],suf[2];
	int tot=0;
	for(auto to:g[x]){
		for(int j=0;j<2;j++){
			pref[j].push_back(dp[to][j]+(j==1?dp[to][0]:0));
			suf[j].push_back(dp[to][j]+(j==1?dp[to][0]:0));
		}
		tot++;
	}
	for(int van=0;van<2;van++){
		for(int i=1;i<pref[van].size();i++)pref[van][i]=1ll*pref[van][i-1]*pref[van][i]%mod;
		for(int i=(int)suf[van].size()-2;i>=0;i--)suf[van][i]=1ll*suf[van][i+1]*suf[van][i]%mod;
	}
//	cerr<<x<<" "<<pref[0].size()<<" "<<suf[0].size()<<endl;
	tot=0;
	for(auto to:g[x]){
		go(to,1ll*get(pref[0],tot-1)*get(suf[0],tot+1)%mod*dp0%mod,1ll*get(pref[1],tot-1)*get(suf[1],tot+1)%mod*(dp0+dp1)%mod);
		tot++;
	}
}
int main(){
	cin>>n;
	for(int i=2;i<=n;i++)cin>>p[i],g[p[i]].push_back(i);
	dfs(1);go(1,1,0);
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
	return 0;
}