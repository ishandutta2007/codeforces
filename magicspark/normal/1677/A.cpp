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
int T,n,a[5005];
int pre[5005][5005],suf[5005][5005];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=0;i<=n+1;i++)for(int j=0;j<=n+1;j++)pre[i][j]=suf[i][j]=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=n;j++)pre[i][j]=pre[i-1][j];
			for(int j=a[i];j<=n;j++)pre[i][j]++;
		}
		for(int i=n;i>=1;i--){
			for(int j=0;j<=n;j++)suf[i][j]=suf[i+1][j];
			for(int j=a[i];j<=n;j++)suf[i][j]++;
		}
		ll ans=0;
		for(int b=1;b<=n;b++){
			for(int c=b+1;c<=n;c++){
				ans+=1ll*pre[b-1][a[c]]*suf[c+1][a[b]];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}