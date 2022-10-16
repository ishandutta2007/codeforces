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
int dp[404][202],pre[404];
int T,n,a[202]; 
int main(){
	cin>>T;
	while(T--){
		memset(pre,0,sizeof pre);
		memset(dp,inf,sizeof dp);
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i],pre[a[i]]++;
		for(int i=1;i<=n*2;i++)pre[i]+=pre[i-1];
		dp[0][0]=0;
		for(int i=0;i<2*n;i++){
			for(int j=0;j<=n;j++){
				dp[i+1][j]=min(dp[i+1][j],dp[i][j]+abs(pre[i]-j));
				dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+abs(pre[i]-j));
			}
		}
		cout<<dp[2*n][n]<<endl;
	}
	return 0;
}