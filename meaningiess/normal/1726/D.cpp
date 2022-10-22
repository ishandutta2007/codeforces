#include<bits/stdc++.h>
#define ll long long
#define fi first
#define sc second
using namespace std;
int u[200010],v[200010],fa[200010],dep[200010],ans[200010],cnt[200010],vis[200010];
vector<pair<int,int> >e[200010];
void dfs(int x)
{
	vis[x]=1;
	for (auto p:e[x]) if (!vis[p.fi])
	{
		dep[p.fi]=dep[x]+1;fa[p.fi]=p.sc;ans[p.sc]=1;
		dfs(p.fi);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;cin>>T;
	while (T--)
	{
		int n,m,i;cin>>n>>m;
		for (i=1;i<=n;i++) cnt[i]=vis[i]=0;
		for (i=1;i<=m;i++) ans[i]=0;
		for (i=1;i<=n;i++) e[i].clear();
		for (i=1;i<=m;i++)
		{
			cin>>u[i]>>v[i];
			e[u[i]].push_back({v[i],i});
			e[v[i]].push_back({u[i],i});
		}
		dfs(1);
		int res=0;
		for (i=1;i<=m;i++) if (!ans[i])
		{
			cnt[u[i]]++;cnt[v[i]]++;
			if (cnt[u[i]]==2) res++;
			if (cnt[v[i]]==2) res++;
		}
		if (res==3)
		{
			for (i=1;i<=m;i++) if (!ans[i])
			{
				int tp=u[i];
				if (dep[v[i]]>dep[u[i]]) tp=v[i];
				if (i==fa[tp]) continue;
				assert(ans[i]==0);
				assert(ans[fa[tp]]==1);
				ans[i]=1;
				ans[fa[tp]]=0;
				break;
			}
		}
		for (i=1;i<=m;i++) cout<<ans[i];cout<<endl;
	}
}