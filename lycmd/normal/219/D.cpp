#include<bits/stdc++.h>
using namespace std;
int const N=200010;
int n,res,sz[N],f[N];
vector<pair<int,int> >e[N];
void dfs(int x,int fa){
	for(auto i:e[x]){
		int y=i.first,w=i.second;
		if(y==fa)
			continue;
		sz[x]+=w,dfs(y,x),sz[x]+=sz[y];
	}
}
void solve(int x,int fa){
	for(auto i:e[x]){
		int y=i.first,w=i.second;
		if(y==fa)
			continue;
		f[y]=f[x]-w+!w,solve(y,x);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n,res=n;
	for(int i=1,x,y;i<n;i++)
		cin>>x>>y,e[x].push_back({y,0}),e[y].push_back({x,1});
	dfs(1,0),f[1]=sz[1],solve(1,0);
	for(int i=1;i<=n;i++)
		res=min(res,f[i]);
	cout<<res<<"\n";
	for(int i=1;i<=n;i++)
		if(f[i]==res)
			cout<<i<<" ";
}