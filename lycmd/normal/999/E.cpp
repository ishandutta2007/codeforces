#include<bits/stdc++.h>
using namespace std;
int const N=233333;
int n,m,s,cur,cnt,top,ans,in[N],scc[N],low[N],dfn[N],stk[N];
vector<int>e[N];
void dfs(int x){
	dfn[x]=low[x]=++cur;
	stk[++top]=x;
	for(int y:e[x])
		if(!dfn[y])
			dfs(y),low[x]=min(low[x],low[y]);
		else if(!scc[y])
			low[x]=min(low[x],dfn[y]);
	if(low[x]==dfn[x]){
		scc[x]=++cnt;
		while(stk[top]!=x)
			scc[stk[top--]]=cnt;
		top--;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>s;
	while(m--){
		int x,y;cin>>x>>y;
		e[x].push_back(y);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])dfs(i);
	for(int x=1;x<=n;x++)
		for(int y:e[x])
			if(scc[x]^scc[y])
				in[scc[y]]++;
	for(int i=1;i<=cnt;i++)
		ans+=!in[i];
	ans-=!in[scc[s]];
	cout<<ans<<"\n";
}