/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
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
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n,m,t,ans;
int a[10001];
int cnt[10005];
int in[11];
inline int calc(int use){
	int ret=1;
	for(int i=1;i<=use;i++){
		ret=(ll)ret*cnt[in[i]]%mod;
	}
	return ret;
}
void dfs(int use,int last,bitset<128>now){
	ans+=calc(use);if(ans>=mod)ans-=mod;
	for(int i=last+1;i<=m/2;i++){
		if(cnt[i]){
			if(now[i]||now[m-i])continue;
			bitset<128>bs=now|(now>>i)|(now<<i)|(now>>(m-i))|(now<<(m-i));
			in[use+1]=i;
			dfs(use+1,i,bs);
		}
	}
}
bitset<128>bs;
int main(){
	bs.reset();bs.set(0);
	cin>>n>>m>>t;
	for(int i=0;i<t;i++)cin>>a[i],cnt[min(m-a[i]%m,a[i]%m)]++;
	dfs(0,0,bs);
	cout<<ans<<endl;
	return 0;
}