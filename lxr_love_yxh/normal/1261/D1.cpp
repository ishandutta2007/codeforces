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
const int mod=998244353;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#define eprintf(...) 0
#else
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#endif
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n,k;
int h[2005];
int dp[2005][4005];
const int BASE=2002;
inline void add(int &x,int y){
	x+=y;if(x>=mod)x-=mod;
}
signed main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>h[i];
	dp[0][BASE]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<4005;j++){
			if(dp[i][j]){
				//get f[i+1]
				if(h[i+1]==h[(i+1)%n+1]){
					add(dp[i+1][j],dp[i][j]*k%mod);
				}else{
					add(dp[i+1][j+1],dp[i][j]);
					add(dp[i+1][j-1],dp[i][j]);
					add(dp[i+1][j],dp[i][j]*(k-2)%mod);
				}
			}
		}
	}
	int ans=0;
	for(int i=BASE+1;i<4005;i++)add(ans,dp[n][i]);
	cout<<ans<<endl;
	return 0;
}