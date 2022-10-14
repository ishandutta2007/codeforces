#include<bits/stdc++.h>
using namespace std;
int const N=233333;
int n,cnt,f[N],g[N];
vector<int>e[N];
void dfs(int x){
	if(e[x].empty()){
		cnt+=f[x]=g[x]=1;
		return;
	}
	f[x]=n;
	for(int y:e[x])
		dfs(y),f[x]=min(f[x],g[y]),g[x]+=f[y];
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		e[x].push_back(y);
	}
	dfs(1),cout<<cnt+1-f[1]<<" "<<g[1]<<"\n";
}