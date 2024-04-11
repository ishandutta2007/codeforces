#include<bits/stdc++.h>
using namespace std;
int const N=200010;
int n,m,vis[N],pre[N];
vector<int>e[N];
vector<array<int,3> >ans;
void dfs(int x){
	vis[x]=1;
	for(int y:e[x]){
		if(!y)continue;
		for(int&t:e[y])t=t^x?t:0;
		if(!vis[y])dfs(y);
		if(pre[y])
			ans.push_back({x,y,pre[y]}),pre[y]=0;
		else if(pre[x])
			ans.push_back({pre[x],x,y}),pre[x]=0;
		else pre[x]=y;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	while(m--){
		int x,y;cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])dfs(i);
	cout<<ans.size()<<"\n";
	for(auto i:ans)
		cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<"\n";
}