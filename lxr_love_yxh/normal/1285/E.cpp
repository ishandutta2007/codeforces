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
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int T,n;
map<int,int>mp;
int l[200005],r[200005];
int f[800005],pre[800005];
signed main(){
	cin>>T;
	while(T--){
		cin>>n;
//		n=10;
		for(int i=1;i<=n;i++){
			cin>>l[i]>>r[i];l[i]*=2;r[i]*=2;
//			l[i]=rand();r[i]=max(rand(),l[i]);
		}
		mp.clear();
		for(int i=1;i<=n;i++){
			mp[l[i]];mp[r[i]];mp[l[i]-1];mp[r[i]+1];
		}
		int now=0;
		for(auto &p:mp)p.second=++now;
		for(int i=1;i<=n;i++){
			l[i]=mp[l[i]];
			r[i]=mp[r[i]];
		}
		for(int i=0;i<=now;i++)f[i]=0;
		for(int i=1;i<=n;i++){
			f[l[i]]++;f[r[i]+1]--;
		}
		for(int i=1;i<=now;i++)f[i]+=f[i-1];
		int ans=0;
		for(int i=1;i<=now;i++){
			int r=i;
			while(r<=now&&f[r]==f[i])r++;
			r--;
			ans+=(f[i]==0);
			for(int j=i;j<=r;j++){
				pre[j]=pre[i-1]+(f[i]==1);
			}
//			cerr<<i<<" "<<r<<" "<<f[i]<<endl;
			i=r;
		}
		int res=-1;
		for(int i=1;i<=n;i++){
			int tmp=pre[r[i]]-pre[l[i]-1];
			if(f[l[i]-1]==0&&f[l[i]]==1)tmp--;
			if(f[r[i]]==1&&f[r[i]+1]==0)tmp--;
//			cerr<<i<<" "<<tmp<<endl;
			res=max(res,ans+tmp);
		}
		cout<<res-1<<endl;
	}
	return 0;
}