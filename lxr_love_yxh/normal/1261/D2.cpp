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
int h[200005],fact[200005],inv[200005];
int C(int nn,int mm){
	return fact[nn]*inv[mm]%mod*inv[nn-mm]%mod; 
}
inline void add(int &x,int y){
	x+=y;x%=mod;
}
int pw2[200005];
signed main(){
	int obj=0;fact[0]=1;pw2[0]=1;
	for(int i=1;i<=2e5;i++)fact[i]=fact[i-1]*i%mod;
	for(int i=1;i<=2e5;i++)pw2[i]=pw2[i-1]*2ll%mod;
	inv[200000]=modpow(fact[200000],mod-2);
	for(int i=200000-1;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod;
	int no_use=0;
	#ifndef LOCAL
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>h[i];
	for(int i=1;i<=n;i++)if(h[i]!=h[i%n+1])obj++;
	no_use=n-obj;n=obj;
	#else
	n=3;k=5;no_use=2;
	#endif
	k-=2;
	int invk1=modpow((k+1)%mod,mod-2),val=C(n-1,0)*modpow(k,max(n-1,0ll))%mod,ans=n*val%mod,i;
	for(i=2;i+i-1<=n;i++){
		int Pw=modpow(k,n-i-i+1);
		val=val+C(n-i+1,i-1)*Pw%mod*k%mod+C(n-i,i-1)*Pw%mod;
		val%=mod;val=val*invk1%mod;
//		cerr<<i<<" "<<val<<endl;
		add(ans,C(n,i)*val%mod);
	}
	int vv=1;
	for(int j=n;j>=i;j--){
		add(ans,vv*C(n,j)%mod);
		vv=vv*(k+1)%mod;
	}
	cout<<ans*modpow((k+2)%mod,no_use)%mod<<endl;
	return 0;
}