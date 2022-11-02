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
int x[77],y[77],a1,a2,b1,b2;
int sx,sy,t,n;
inline int mabs(int x){return x<0?-x:x;}
signed main(){
	cin>>x[0]>>y[0]>>a1>>a2>>b1>>b2;cin>>sx>>sy>>t;
	for(int i=1;i<=70;i++){
		x[i]=x[i-1]*a1+b1;y[i]=y[i-1]*a2+b2;
		if(x[i]>=2e16||y[i]>=2e16){
			n=i;break;
		}
	}
	int ans=0;
	for(int i=0;i<=n;i++){
		int cur=t-mabs(sx-x[i])-mabs(sy-y[i]);
		for(int l=0;l<=i;l++){
			for(int r=i;r<=n;r++){
				int L=abs(x[i]-x[l])+abs(y[i]-y[l]),R=abs(x[i]-x[r])+abs(y[i]-y[r]);
				int need=min(L,R)+L+R;
				if(need<=cur){
					ans=max(ans,r-l+1);
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}