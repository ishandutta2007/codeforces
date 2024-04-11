#include<bits/stdc++.h>
using namespace std;
int const N=100010;
int n,m,h,p,cur,tot,a[N],dfn[N],low[N],scc[N],vis[N],sz[N],out[N];
vector<int>e[N];
stack<int>s;
void dfs(int x){
	dfn[x]=low[x]=++cur,vis[x]=1,s.push(x);
	for(int y:e[x])
		if(!dfn[y])
			dfs(y),low[x]=min(low[x],low[y]);
		else if(vis[y])
			low[x]=min(low[x],dfn[y]);
	if(dfn[x]==low[x]){
		tot++;
		while(1){
			int t=s.top();s.pop();
			vis[t]=0,scc[t]=tot,sz[tot]++;
			if(t==x)break;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>h,sz[0]=n+1;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	while(m--){
		int x,y;cin>>x>>y;
		if((a[x]+1)%h==a[y])
			e[x].push_back(y);
		if((a[y]+1)%h==a[x])
			e[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])dfs(i);
	for(int i=1;i<=n;i++)
		for(int j:e[i])
			if(scc[i]!=scc[j])
				out[scc[i]]++;
	for(int i=1;i<=tot;i++)
		if(!out[i]&&sz[i]<sz[p])
			p=i;
	cout<<sz[p]<<"\n";
	for(int i=1;i<=n;i++)
		if(scc[i]==p)
			cout<<i<<" ";
	cout<<"\n";
}