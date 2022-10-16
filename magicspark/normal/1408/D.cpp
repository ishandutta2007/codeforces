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
int n,m;
int a[2005],b[2005];
int c[2005],d[2005];
int mx[1000005];
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=m;i++){
		cin>>c[i]>>d[i];
	}
	memset(mx,0,sizeof mx);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(c[j]>=a[i]&&d[j]>=b[i]){
				mx[c[j]-a[i]]=max(mx[c[j]-a[i]],d[j]-b[i]+1);
			}
		}
	}
	int ans=inf,Max=0;
	for(int i=1e6;i>=0;i--){
		Max=max(Max,mx[i]);
		ans=min(ans,i+Max);
	}
	cout<<ans<<endl;
	return 0;
}