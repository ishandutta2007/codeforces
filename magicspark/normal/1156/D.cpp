#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n;
struct UFS{
	int par[400002],sz[400002];
	void init(){
		for(int i=2;i<=n+n+1;i++)par[i]=i;
	}
	void unite(int x,int y){
		int nx=find(x),ny=find(y);
		par[nx]=ny;
	}
	int find(int x){
		return x==par[x]?x:par[x]=find(par[x]);
	}
	void calc(){
		for(int i=2;i<=n+n+1;i++)sz[find(i)]++;
	}
}uf;
ll ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;uf.init();
	for(int i=1;i<n;i++){
		int x,y,c;
		cin>>x>>y>>c;
		uf.unite(x*2+c,y*2+c);
	}
	uf.calc();
	for(int i=1;i<=n;i++){
		if(uf.par[i+i]==i+i)ans+=(ll)uf.sz[i+i]*(uf.sz[i+i]-1);
		if(uf.par[i+i+1]==i+i+1)ans+=(ll)uf.sz[i+i+1]*(uf.sz[i+i+1]-1);
		ans+=1ll*(uf.sz[uf.find(i+i)]-1)*(uf.sz[uf.find(i+i+1)]-1);
	}
	cout<<ans<<endl;
	return 0;
}