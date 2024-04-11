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
int n,m,ans;
const int inv2=modpow(2,mod-2);
int get_sum(int l,int r){
	return (l+r)%mod*((r-l+1)%mod)%mod*inv2%mod;
}
signed main(){
	cin>>n>>m;
	const int res=min(n,3000000ll);
	int lst=m;
	for(int i=0;i<=res;i++){
		int l=n/(i+1)+1,r=(i==0?m:min(m,n/i));
		lst=min(lst,l-1);
		if(l<=r){
			ans+=1ll*n%mod*((r-l+1)%mod)%mod;
			ans-=get_sum(l,r)*i%mod;
			if(ans<0)ans+=mod;
		}
	}
	for(int i=1;i<=lst;i++){
		ans+=(n%i);
		ans%=mod;
	}
	cout<<ans<<endl;
	return 0;
}