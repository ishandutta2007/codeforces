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
int n,val,pos,fact[1005],inv[1005];
int C(int nn,int mm){
	return 1ll*fact[nn]*inv[mm]%mod*inv[nn-mm]%mod;
}
int main(){
	fact[0]=1;
	for(int i=1;i<=1000;i++)fact[i]=1ll*fact[i-1]*i%mod;
	for(int i=0;i<=1000;i++)inv[i]=modpow(fact[i],mod-2);
	cin>>n>>val>>pos;pos++;
	int l=0,r=n,cl=0,cr=0;
	while(l<r){
		int mid=(l+r)/2;
		if(mid>=pos)r=mid,cr++;
		else l=mid+1,cl++;
	}
	cout<<1ll*C(val-1,cl-1)*C(n-val,cr)%mod*fact[n-cl-cr]%mod*fact[cl-1]%mod*fact[cr]%mod<<endl;
	return 0;
}