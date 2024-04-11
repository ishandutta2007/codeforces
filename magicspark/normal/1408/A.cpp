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
int T,n,a[105],b[105],c[105],ans[105];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		memset(ans,-1,sizeof ans);
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)cin>>b[i];
		for(int i=1;i<=n;i++)cin>>c[i];
		for(int i=1;i<=n;i++){
			if(ans[i-1]==a[i]){
				ans[i]=b[i];
			}else ans[i]=a[i];
		}
		if(a[n]!=ans[n-1]&&a[n]!=ans[1])ans[n]=a[n];
		if(b[n]!=ans[n-1]&&b[n]!=ans[1])ans[n]=b[n];
		if(c[n]!=ans[n-1]&&c[n]!=ans[1])ans[n]=c[n];
		for(int i=1;i<=n;i++)cout<<ans[i]<<" ";cout<<endl;
	}
	return 0;
}