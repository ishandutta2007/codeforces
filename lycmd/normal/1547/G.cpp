#include<bits/stdc++.h>
using namespace std;
int const N=400010;
int t,n,m,cur,tot,ans[N],ord[N],dfn[N],low[N],vis[N],slp[N],con[N];
vector<int>e[N],g[N];
stack<int>s;
void tarjan(int x){
	dfn[x]=low[x]=++cur,vis[x]=1,s.push(x);
	for(int y:e[x])
		if(!dfn[y])
			tarjan(y),low[x]=min(low[x],low[y]);
		else if(vis[y])
			low[x]=min(low[x],dfn[y]);
	if(low[x]==dfn[x]){
		tot++;
		int cnt=0,flg=0;
		while(1){
			int t=s.top();
			ord[t]=tot,cnt++,flg|=slp[t];
			vis[t]=0;s.pop();
			if(x==t)break;
		}
		if(cnt>1||flg)ans[tot]=-1;
	}
}
void dfs(int x,int cur){
	if(!~ans[x])cur=-1,vis[x]=1;
	else if(~cur&&ans[x])cur=2,vis[x]=1;
	if(con[x]&&ans[x]==cur)return;
	ans[x]=cur,con[x]=1;
	for(int y:g[x])
		if(!vis[y]||(!~cur&&ans[y]==2))
			dfs(y,cur);
}
int main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cur=tot=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			e[i].clear(),g[i].clear(),
			ord[i]=dfn[i]=low[i]=vis[i]=slp[i]=ans[i]=0;
		while(m--){
			int x,y;cin>>x>>y;
			if(x==y)slp[x]=1;
			else e[x].push_back(y);
		}
		for(int i=1;i<=n;i++)
			if(!dfn[i])
				tarjan(i);
		for(int x=1;x<=n;x++)
			for(int y:e[x])
				if(ord[x]^ord[y])
					g[ord[x]].push_back(ord[y]);
		for(int i=1;i<=n;i++)
			vis[i]=con[i]=0;
		dfs(ord[1],1);
		for(int i=1;i<=n;i++)
			cout<<(con[ord[i]]?ans[ord[i]]:0)<<" ";
		cout<<"\n";
	}
}