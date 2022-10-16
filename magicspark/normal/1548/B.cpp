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
int t,n;
ll a[200005];
#define SIZE 262144
ll f[SIZE<<1];
void update(int x,int v){
	x+=SIZE;f[x]=v;
	while(x!=1){
		x>>=1;
		f[x]=__gcd(f[x<<1],f[x<<1|1]);
	}
}
int query(int l,int r,int k,int ql,int qr){
	if(r<ql||qr<l)return 0;
	if(ql<=l&&r<=qr){return f[k];}
	return __gcd(query(l,(l+r)/2,k<<1,ql,qr),query((l+r)/2+1,r,k<<1|1,ql,qr));
}
signed main(){
	scanf("%I64d",&t);
	while(t--){
		scanf("%I64d",&n);
		for(int i=1;i<=n;i++)scanf("%I64d",&a[i]);
		for(int i=1;i<n;i++)a[i]=abs(a[i]-a[i+1]);
		n--;
		for(int i=1;i<=n;i++)update(i,a[i]);
		int r=1,ans=0;
		for(int i=1;i<=n;i++){
			while(r<=n&&query(0,SIZE-1,1,i,r)!=1)r++;
			ans=max(ans,r-i);
		}
		printf("%I64d\n",ans+1);
	}
	return 0;
}