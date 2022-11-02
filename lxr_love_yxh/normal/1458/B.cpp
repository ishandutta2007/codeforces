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
int n;
int a[105],b[105];
int dp[105][10005],tdp[105][10005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		b[i]*=2;
	}
	memset(dp,0xf7,sizeof dp);
	dp[0][0]=0;
	for(int t=1;t<=n;t++){
		memset(tdp,0xf7,sizeof tdp);
		for(int i=0;i<=n;i++){
			for(int j=10000;j>=0;j--){
				if(j+a[i]<=10000)tdp[i+1][j+a[t]]=max(tdp[i+1][j+a[t]],dp[i][j]+b[t]);
				tdp[i][j]=max(tdp[i][j],dp[i][j]+b[t]/2);
			}
		}
		memcpy(dp,tdp,sizeof dp);
	}
	for(int i=1;i<=n;i++){
		int ans=0;
		for(int j=0;j<=10000;j++)if(dp[i][j]>0){
//			cerr<<j<<" "<<dp[i][j]<<endl;
			ans=max(ans,min(j*2,dp[i][j]));
		}
		cout<<ans/2.0<<" ";
	}
	return 0;
}