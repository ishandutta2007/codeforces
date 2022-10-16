#include<bits/stdc++.h>
#define int long long
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
struct UFS{
	int par[100005];
	int find(int x){
		return x==par[x]?x:par[x]=find(par[x]);
	}
	void unite(int x,int y){
		int nx=find(x),ny=find(y);
		if(nx!=ny)par[nx]=ny;
	}
	void init(){
		for(int i=0;i<100005;i++)par[i]=i;
	}
}uf;
vector<int>g[111111];
signed main(){
	uf.init();ios::sync_with_stdio(0);
	int n,k;cin>>n>>k;
	for(int i=1;i<n;i++){
		int a,b,c;cin>>a>>b>>c;
		if(c==0)uf.unite(a,b);
	}
	map<int,int>mp;
	for(int i=1;i<=n;i++){
		mp[uf.find(i)]++;
	}
	int ans=modpow(n,k,mod);
	for(auto xx:mp){
		int x=xx.second;
		ans-=modpow(x,k,mod);
		ans%=mod;
	}
	ans=(ans%mod+mod)%mod;
	cout<<ans<<endl;
	return 0;
}