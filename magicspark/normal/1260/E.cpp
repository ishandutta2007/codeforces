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
int n;
int a[1<<18|1];
int dp[20][1<<18|1];
signed main(){
	cin>>n;int pos=0;
	int lg=log2(n)-1;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)if(a[i]==-1)pos=i;
	for(int i=1;i<=pos;i++)a[i]=0;
	memset(dp,inf,sizeof dp);
	dp[lg][n-1]=a[n];
	for(int i=n-1;i>=2;i--){
		int sum=0;
		for(int cur=lg;cur>=0;cur--){
			sum+=1<<cur;
			if(sum<(n-i))continue;
			if(sum>(n-i))dp[cur][i-1]=min(dp[cur][i-1],dp[cur][i]);
			if(cur)dp[cur-1][i-1]=min(dp[cur-1][i-1],dp[cur][i]+a[i]);
		}
	}
	cout<<dp[0][1]<<endl;
	return 0;
}