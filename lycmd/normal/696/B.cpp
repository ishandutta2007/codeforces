#include<bits/stdc++.h>
using namespace std;
int const N=100010;
int n,fa[N],sz[N];
double f[N];
vector<int>e[N];
void dfs(int x){
	sz[x]=1;
	for(int y:e[x])
		dfs(y),sz[x]+=sz[y];
}
void solve(int x){
	f[x]=f[fa[x]]+1.0+max(0,sz[fa[x]]-sz[x]-1)/2.0;
	for(int y:e[x])
		solve(y);
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=2;i<=n;i++)
		cin>>fa[i],e[fa[i]].push_back(i);
	dfs(1),solve(1);
	for(int i=1;i<=n;i++)
		cout<<fixed<<setprecision(1)<<f[i]<<" ";
	cout<<"\n";
}