/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC target("avx,tune=native")
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
#endif
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n;
int a[505];
const int magic=32000;
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	ll ans=1e18;
	for(int base=1;base<=magic;base++){
		bool can=true;ll cnt=0;
		for(int j=1;j<=n;j++){
			int div=a[j]/base,rem=a[j]%base;
			if(rem>div){can=false;break;}
			cnt+=(a[j]+base)/(base+1);
		}
		if(can)ans=min(ans,cnt);
	}
	for(int sz=1;sz<=magic;sz++){
		int base=a[1]/sz;if(!base)continue;
		bool can=true;ll cnt=0;
		for(int j=1;j<=n;j++){
			int div=a[j]/base,rem=a[j]%base;
			if(rem>div){can=false;break;}
			cnt+=(a[j]+base)/(base+1);
		}
		if(can)ans=min(ans,cnt);
		base=a[1]/sz-1;if(base<=0)continue;
		can=true;cnt=0;
		for(int j=1;j<=n;j++){
			int div=a[j]/base,rem=a[j]%base;
			if(rem>div){can=false;break;}
			cnt+=(a[j]+base)/(base+1);
		}
		if(can)ans=min(ans,cnt);
	}
	cout<<ans<<endl;
	return 0;
}