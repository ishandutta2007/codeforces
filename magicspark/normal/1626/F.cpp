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
const int mod=998244353;
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
int n,a[10000005],x,y,k,m;
int dp[720725][20];
int main(){
	cin>>n>>a[0]>>x>>y>>k>>m;
	for(int i=1;i<n;i++)a[i]=(1ll*a[i-1]*x+y)%m;
	int ans=0;
	for(int i=0;i<n;i++){
		int tms=a[i]/720720*720720;
		ans=(ans+1ll*k*modpow(n,mod-2)%mod*tms)%mod;
		a[i]%=720720;dp[a[i]][1]++; 
	}
	ans=1ll*ans*modpow(n,k)%mod;
	const int inv=1;
	const int flag=n-1;
	for(int i=1;i<k;i++){
		for(int j=0;j<720720;j++){
			dp[j-j%i][i+1]=(dp[j-j%i][i+1]+1ll*dp[j][i]*inv)%mod;
			dp[j][i+1]=(dp[j][i+1]+1ll*dp[j][i]*flag)%mod;
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<720720;j++){
//			if(dp[j][i])cerr<<j<<" "<<i<<" "<<dp[j][i]<<endl; 
			ans=(ans+1ll*dp[j][i]*modpow(n,k-i)%mod*j)%mod;
		}
	}
	cout<<ans<<endl;
	return 0;
}