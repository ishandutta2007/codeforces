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
#define int long long
#pragma comment("-Wl,--stack=1024000000")
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-9;
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
int n,dp[5005][5005],mintime[5005],x[5005],t[5005];
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>t[i]>>x[i];
	memset(mintime,inf,sizeof mintime);
	mintime[0]=0;dp[0][0]=1;
	for(int i=0;i<n;i++){
		if(t[i]>=mintime[i]){
			int pos=i;
			while(pos<=n&&x[pos]==x[i]){
				pos++;
				mintime[pos]=min(mintime[pos],max(mintime[i]+abs(x[pos]-x[i]),t[i]));
			}
//			cerr<<i<<" "<<pos<<" "<<x[i]<<" "<<x[i+1]<<endl;
//			assert(pos==i+1);
//			mintime[i+1]=min(mintime[i+1],max(mintime[i]+abs(x[i+1]-x[i]),t[i]));
			for(int j=i+2;j<=n;j++){
				if(mintime[i]+2*abs(x[j]-x[i])<=t[i])dp[i][j]=1;
				if(max(mintime[i]+abs(x[j]-x[i]),t[i])+abs(x[j]-x[i+1])<=t[i+1])dp[i+1][j]=1;
			}
		}
		if(t[i]+abs(x[i+1]-x[i])<=t[i+1])for(int j=i+2;j<=n;j++)dp[i+1][j]|=dp[i][j];
		if(dp[i][i+1]&&i+2<=n){
			mintime[i+2]=min(mintime[i+2],max(t[i]+abs(x[i+2]-x[i]),t[i+1]));
			for(int j=i+3;j<=n;j++)dp[i+2][j]|=max(t[i]+abs(x[j]-x[i]),t[i+1])+abs(x[j]-x[i+2])<=t[i+2];
		}
	}
	puts(mintime[n]<=t[n]||dp[n-1][n]?"YES":"NO");
	return 0;
}