//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
#define int long long
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=998244353;
typedef long long ll;
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int dp[200005];
int n,fact[200005],inv[200005];
vector<int>g[200005];
int ans=0;
inline int C(int n,int m){
	return fact[n]*inv[m]%mod*inv[n-m]%mod;
}
void dfs(int x,int par=0){
	for(auto to:g[x])if(to!=par)dfs(to,x);
	if(x==1){
		(ans*=fact[g[x].size()])%=mod;
		return;
	}
	int sz=g[x].size();
	int tmp=0;
	for(int i=0;i<sz;i++){
		tmp+=(1ll*fact[i]%mod*fact[sz-i-1]%mod*C(sz-1,i)%mod);
		tmp%=mod;
	}
	(ans*=tmp)%=mod;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	fact[0]=1;for(int i=1;i<=200000;i++)fact[i]=fact[i-1]*i%mod;
	for(int i=0;i<=200000;i++)inv[i]=modpow(fact[i],mod-2,mod);
	for(int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	ans=n;
	dfs(1);
	cout<<ans<<endl;
	return 0;
}