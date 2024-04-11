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
int n,m;
int dp[2005][2005],sum[2005][2005],mul[2005][2005];
void init(int x){
	sum[x][0]=dp[x][0];mul[x][0]=0;
	for(int i=1;i<=m-2;i++){
		sum[x][i]=sum[x][i-1]+dp[x][i];sum[x][i]%=mod;
		mul[x][i]=mul[x][i-1]+1ll*dp[x][i]*i%mod;mul[x][i]%=mod;
	}
}
int main(){
	cin>>n>>m;
	for(int i=0;i<=m-2;i++)dp[1][i]=1;
	init(1);
	for(int i=2;i<=n;i++){
		for(int j=0;j<=m-2;j++){
			dp[i][j]=1ll*sum[i-1][j]*(j+1)%mod-mul[i-1][j]%mod;
			if(dp[i][j]<0)dp[i][j]+=mod;
			dp[i][j]=(dp[i][j]+1)%mod;
		}
		init(i);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m-2;j++){
			ans=ans+1ll*(mod+dp[i][j]-dp[i-1][j])*dp[n-i+1][j]%mod*(m-j-1)%mod;
			ans%=mod;
		}
	}
	cout<<ans<<endl;
	return 0;
}