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
int fact[3333333],inv[3333333],f[3333333],n,q;
int C(int nn,int mm){
	return 1ll*fact[nn]*inv[mm]%mod*inv[nn-mm]%mod;
}
int main(){
	fact[0]=1;
	for(int i=1;i<3333333;i++)fact[i]=1ll*fact[i-1]*i%mod;
	inv[3333332]=modpow(fact[3333332],mod-2);
	for(int i=3333331;i>=0;i--)inv[i]=1ll*inv[i+1]*(i+1)%mod;
	scanf("%d%d",&n,&q);
	const int inv3=modpow(3,mod-2);
	f[0]=n+1;f[1]=(1ll*C(3*n+3,2)*inv3-f[0]+mod)%mod;
	for(int i=2;i<=3*n;i++){
		f[i]=(1ll*(C(3*n+3,i+1)-f[i-2]+mod)*inv3%mod-f[i-1]+mod)%mod;
	}
	while(q--){
		int x;scanf("%d",&x);printf("%d\n",f[x]);
	}
	return 0;
}