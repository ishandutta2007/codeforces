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
int n,a[5005],ans[10005];
signed f[5005][10005];
int pre[20005],inv[20005];
int get_mul(int l,int r){
	return pre[r]*inv[l-1]%mod; 
}
template<class T>inline void add(T &x,int y){
	x+=y;if(x>=mod)x-=mod;
}
inline int Inv(int x){
	return modpow(x,mod-2,mod);
}
signed main(){
	cin>>n;pre[0]=1;inv[0]=1;
	for(int i=1;i<n;i++)cin>>a[i],pre[i]=pre[i-1]*a[i]%mod,inv[i]=modpow(pre[i],mod-2);
	for(int i=n;i<=2e4;i++)pre[i]=inv[i]=0;
	f[n][0]=1;
	const int inv2=(mod+1)/2;
	for(int i=n-1;i>=1;i--){
		for(int j=0;j<=n+n-2;j++)f[i][j+2]=(ll)f[i+1][j]*a[i]%mod*a[i]%mod;
		for(int j=0;j<=n+n-2;j++){
			add(f[i][j+1],2ll*get_mul(i,i+j)%mod);
		}
		f[i][0]=1;
	}
	for(int i=1;i<=n-1;i++){
		f[i][0]=f[i][1]=0;
		for(int j=0;j<=n+n-2;j++){
			f[i][j+2]=f[i+1][j];
		}
		/*
		for(int j=0;j<=n+n-2;j++){
			cerr<<i<<" "<<j<<" "<<f[i][j]<<endl;
		}
		*/
	}
	for(int i=1;i<=n-1;i++){
		for(int j=0;j<=n+n-2;j++){
			f[i][j]=(ll)f[i][j]*a[i]%mod*(a[i]-1)%mod*inv2%mod;
		}
		for(int j=0;j<=n+n-2;j++){
			add(f[i][j+1],get_mul(i,i+j)%mod);
		}
		for(int j=1;j<=n*2-2;j++){
			add(ans[j],(ll)f[i][j]*pre[i-1]%mod);
		}
	}
	for(int i=1;i<=n+n-2;i++)cout<<ans[i]<<" ";
	return 0;
}