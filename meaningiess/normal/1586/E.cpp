#include<bits/stdc++.h>
#define ll long long
#define N 300005
using namespace std;
vector<int> e[N],ans1[N],ans2[N],o[N];
int fa[N],w[N],dep[N],tp[N],d[N],vis[N];
void dfs(int x,int f)
{
	dep[x]=dep[f]+1;fa[x]=w[x]=f;
	for (auto p:e[x]) if (p!=f)
	{
		dfs(p,x);
	}
}
void gt(int x,int y,int i)
{
	while (dep[x]>dep[y]) tp[x]^=1,ans1[i].push_back(x),x=fa[x];
	while (dep[x]<dep[y]) tp[y]^=1,ans2[i].push_back(y),y=fa[y];
	while (x!=y)
	{
		tp[x]^=1,tp[y]^=1,ans1[i].push_back(x),x=fa[x],ans2[i].push_back(y),y=fa[y];
	}
	ans1[i].push_back(x);
}
int ans=0;
void dfs2(int x,int tg)
{
	int cnt=0;vis[x]=1;
	for (auto p:o[x]) if (!vis[p])
	{
		dfs2(p,0);cnt++;
	}
	if (!cnt) return;
	if (!tg)
	{
		ans+=cnt/2;
	}
	else ans+=(cnt+1)/2;
}
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int main()
{
	int n,m,i,u,v;cin>>n>>m;
	for (i=1;i<=n;i++) fa[i]=i;
	for (i=1;i<=m;i++)
	{
		cin>>u>>v;
		int t1=find(u),t2=find(v);
		if (t1!=t2) fa[t1]=t2,e[u].push_back(v),e[v].push_back(u);
	}
	dfs(1,0);int q;cin>>q;
	for (i=1;i<=q;i++)
	{
		cin>>u>>v;
		gt(u,v,i);
	}
	int cnt=n;
	for (i=1;i<=n;i++) if (tp[i])
	{o[i].push_back(w[i]);o[w[i]].push_back(i);
	}
	for (i=1;i<=n;i++) if (!vis[i]) dfs2(i,1);
	if (!ans)
	{
		puts("YES");
		for (i=1;i<=q;i++)
		{
			printf("%d\n",ans1[i].size()+ans2[i].size());
			for (u=0;u<ans1[i].size();u++) printf("%d ",ans1[i][u]);
			for (u=ans2[i].size()-1;u>=0;u--) printf("%d ",ans2[i][u]);puts("");
		}
	}
	else
	{
		printf("NO\n%d",ans);
	}
}