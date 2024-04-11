#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=200010,MOD=1000000007;
int n,f[N],ans[N];
vector<int>e[N];
int qpow(int x,int y){
	return y?qpow(x*x%MOD,y>>1)*(y&1?x:1)%MOD:1;
}
void dfs(int x,int fa){
	f[x]=1;
	for(int y:e[x])
		if(y^fa)
			dfs(y,x),f[x]=f[x]*(f[y]+1)%MOD;
}
void solve(int x,int fa,int s){
	vector<int>v1,v2;
	ans[x]=f[x]*s%MOD;
	v1.push_back(1);
	for(int y:e[x])
		if(y^fa)
			v1.push_back(f[y]+1),v2.push_back(f[y]+1);
		else
			v1.push_back(1),v2.push_back(1);
	v2.push_back(1);
	for(int i=1;i<v1.size();i++)
		v1[i]=v1[i]*v1[i-1]%MOD;
	for(int i=v2.size()-2;~i;i--)
		v2[i]=v2[i]*v2[i+1]%MOD;
	for(int i=0;i<e[x].size();i++){
		int y=e[x][i];
		if(y==fa)continue;
		solve(y,x,s*v1[i]%MOD*v2[i+1]%MOD+1);
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=2,x;i<=n;i++)
		cin>>x,e[i].push_back(x),e[x].push_back(i);
	dfs(1,0),solve(1,0,1);
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
}