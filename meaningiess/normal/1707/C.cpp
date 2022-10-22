#include<bits/stdc++.h>
#define ll long long
#define N 200010
using namespace std;
int dfn[N],fa[N],l[N],r[N],dep[N],tot,siz[N],st[20][N],ans[N];vector<int> e[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void dfs(int x,int f)
{
	dep[x]=dep[f]+1;dfn[x]=++tot;siz[x]=1;st[0][x]=f;
	for (auto p:e[x]) if (p!=f) {dfs(p,x);siz[x]+=siz[p];}
	//cout<<x<<' '<<dfn[x]<<' '<<siz[x]<<endl;
}
int main()
{
	int n,m,i,cnt=0;cin>>n>>m;
	for (i=1;i<=n;i++) fa[i]=i;
	for (i=1;i<=m;i++)
	{
		int u,v;cin>>u>>v;
		int t1=find(u),t2=find(v);
		if (t1==t2)
		{
			l[++cnt]=u,r[cnt]=v;
			continue;
		}
		fa[t1]=t2;
		e[u].push_back(v),e[v].push_back(u);
	}
	dfs(1,0);
	for (int j=1;j<19;j++) for (i=1;i<=n;i++) st[j][i]=st[j-1][st[j-1][i]];
	for (i=1;i<=cnt;i++)
	{
		if (dep[l[i]]>dep[r[i]]) swap(l[i],r[i]);
		//cout<<l[i]<<' '<<r[i]<<endl;
		ans[dfn[r[i]]]++;ans[dfn[r[i]]+siz[r[i]]]--;
		if (dfn[l[i]]<=dfn[r[i]] && dfn[r[i]]<dfn[l[i]]+siz[l[i]])
		{
			int t=dep[r[i]]-dep[l[i]]-1;
			for (int j=18;j>=0;j--) if ((t>>j)&1) r[i]=st[j][r[i]];
			ans[1]++;ans[dfn[r[i]]]--;ans[dfn[r[i]]+siz[r[i]]]++;
		}
		else
		{
			ans[dfn[l[i]]]++;ans[dfn[l[i]]+siz[l[i]]]--;
		}
	}
	for (i=1;i<=n;i++) ans[i]+=ans[i-1];
	for (i=1;i<=n;i++) if (ans[dfn[i]]==cnt) putchar('1');else putchar('0');
}