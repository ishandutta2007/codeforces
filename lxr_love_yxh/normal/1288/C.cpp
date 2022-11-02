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
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n,m;
int c[2005][2005];
int func(int nn,int mm){
	return c[nn+mm-1][mm];
}
signed main(){
	for(int i=0;i<=2000;i++){
		c[i][0]=c[i][i]=1;
		for(int j=1;j<i;j++)c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	}
	cin>>n>>m;
	int ans=0;
	for(int mxa=1;mxa<=n;mxa++){
		for(int mnb=mxa;mnb<=n;mnb++){
			ans+=(ll)func(mxa,m-1)*func(n-mnb+1,m-1)%mod;
			ans%=mod;
		}
	}
	cout<<ans<<endl;
	return 0;
}