#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=200010;
int n,f[N];
vector<int>e[N];
void dfs1(int x,int fa){
	for(int y:e[x]){
		if(y==fa)continue;
		dfs1(y,x),f[x]+=max(f[y],0ll);
	}
}
void dfs2(int x,int fa){
	for(int y:e[x]){
		if(y==fa)continue;
		f[y]=max(f[y],f[x]+min(f[y],0ll)),dfs2(y,x);
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>f[i],f[i]=f[i]*2-1;
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs1(1,0),dfs2(1,0);
	for(int i=1;i<=n;i++)
		cout<<f[i]<<" ";
	cout<<"\n";
}