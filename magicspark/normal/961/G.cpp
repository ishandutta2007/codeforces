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
int n,m;
int w[200005];
int fact[200005],inv[200005];
int C(int x,int y){
	return fact[x]*inv[y]%mod*inv[x-y]%mod;
}
int S(int x,int y){
	if(y>x)return 0;
	int ret=0;
	for(int k=0;k<=y;k++){
		if(k&1)ret=(ret-C(y,k)*modpow(y-k,x,mod)%mod+mod)%mod;
		else ret=(ret+C(y,k)*modpow(y-k,x,mod)%mod)%mod;
	}
	return ret*inv[y]%mod;
}
signed main(){
	cin>>n>>m;int ans=0;fact[0]=1;inv[0]=1;
	for(int i=1;i<=2e5;i++)fact[i]=fact[i-1]*i%mod,inv[i]=modpow(fact[i],mod-2);
	for(int i=1;i<=n;i++){
		cin>>w[i];ans+=w[i];ans%=mod;
	}
	ans=ans*(S(n-1,m-1)+(n+m-1)*S(n-1,m)%mod)%mod;
	cout<<ans<<endl;
	return 0;
}