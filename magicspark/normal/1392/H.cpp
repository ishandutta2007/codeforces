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
int modpow(int x,int y,int md=mod){int ret=1;do{if(y&1)ret=(ll)ret*x%md;x=(ll)x*x%md;}while(y>>=1);return ret;}
inline int Rand(){return rand()*32768+rand();}
int n,m,fact[2000005],inv[2000005]; 
signed main(){
	cin>>n>>m;fact[0]=1;
	for(int i=1;i<=2e6;i++)fact[i]=fact[i-1]*i%mod;
	inv[2000000]=modpow(fact[2000000],mod-2);
	for(int i=2e6-1;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod;
	int v1=(1ll+n*modpow(m+1,mod-2)%mod)%mod,v2=1;
	for(int i=1;i<=n;i++){
		(v2+=m*fact[i-1]%mod*inv[i]%mod)%=mod;
	}
	cout<<v1*v2%mod<<endl;
	return 0;
}