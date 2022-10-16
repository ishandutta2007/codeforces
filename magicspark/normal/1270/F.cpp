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
#pragma comment("-Wl,--stack=1024000000")
using namespace std;
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
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
string s;
int pref[200005],nxt[200005];
signed cnt[(int)1e8+5],vec[200005],sz;
const int MAGIC=450;
const int add=9e7;
signed main(){
	cin>>s;s=" "+s;
	for(int i=1;i<s.size();i++){
		pref[i]=pref[i-1]+(s[i]=='1');
	}
	const int n=s.size()-1;
	nxt[n+1]=inf;
	for(int i=n;i>=0;i--){
		nxt[i]=s[i+1]=='1'?i+1:nxt[i+1];
	}
	ll ans=0;
	for(int i=1;i<MAGIC;i++){
		sz=0;
		for(int j=0;j<=n;j++){
			cnt[j-pref[j]*i+add]++;
			vec[sz++]=j-pref[j]*i+add;
		}
		for(int j=0;j<sz;j++){
			ans+=(ll)cnt[vec[j]]*(cnt[vec[j]]-1)/2;
			cnt[vec[j]]=0;
		}
	}
	for(int i=1;i<=n;i++){
		vector<int>one;
		int now=i-1;
		//init one
		for(int j=1;j<=505;j++){
			one.push_back(nxt[now]);
			now=nxt[now];if(now==inf)break;
		}
		#ifdef LOCAL
		for(auto x:one)cerr<<x<<" ";cerr<<endl;
		#endif
		//calc ans
		for(int j=0;j+1<one.size();j++){
			int lb=one[j]-(i-1),rb=min(n-(i-1),one[j+1]-(i-1)-1);
			int ones=j+1;
			lb=max(lb,ones*MAGIC);
//			cerr<<i<<" "<<lb<<" "<<rb<<" "<<ones<<endl;
			ans+=max(0,rb/ones-lb/ones+(lb%ones==0));
		}
	}
	cout<<ans<<endl;
	return 0;
}