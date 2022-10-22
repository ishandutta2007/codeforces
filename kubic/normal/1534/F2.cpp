#include <bits/stdc++.h>
using namespace std;
#define N 400005
#define pb push_back
int n,m,s,ans,tg[N],L[N],R[N],mx[N];bool vs[N],tg1[N];char a[N];
int SCC,dfn[N],low[N],st[N],bl[N];vector<int> vc[N],e[N],e1[N];
void Tarjan(int u)
{
	dfn[u]=low[u]=++dfn[0];st[++st[0]]=u;
	for(auto v:e[u]) if(!dfn[v]) Tarjan(v),low[u]=min(low[u],low[v]);
		else if(!bl[v]) low[u]=min(low[u],dfn[v]);
	if(dfn[u]==low[u])
	{bl[u]=++SCC;while(st[st[0]]!=u) bl[st[st[0]--]]=SCC;--st[0];}
}
void dfs(int u)
{
	if(vs[u]) return;vs[u]=1;
	for(auto v:e1[u]) dfs(v),L[u]=min(L[u],L[v]),R[u]=max(R[u],R[v]);
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i)
	{scanf("%s",a+1);for(int j=1;j<=m;++j) if(a[j]=='#') vc[j].pb(i);}
	for(int i=1;i<=m;++i) if(vc[i].size())
	{
		for(int j=0;j<vc[i].size()-1;++j)
		{e[s+j+1].pb(s+j+2);if(vc[i][j]+1==vc[i][j+1]) e[s+j+2].pb(s+j+1);}
		for(int j=0,t;j<vc[i].size();++j)
		{
			t=lower_bound(vc[i-1].begin(),vc[i-1].end(),vc[i][j])-vc[i-1].begin();
			if(t<vc[i-1].size()) e[s+j+1].pb(s-vc[i-1].size()+t+1);
			t=lower_bound(vc[i+1].begin(),vc[i+1].end(),vc[i][j])-vc[i+1].begin();
			if(t<vc[i+1].size()) e[s+j+1].pb(s+vc[i].size()+t+1);tg[s+j+1]=i;
		}s+=vc[i].size();
	}for(int i=1;i<=s;++i) if(!dfn[i]) Tarjan(i);for(int i=1;i<=SCC;++i) L[i]=1e9;
	for(int i=1;i<=s;++i) L[bl[i]]=min(L[bl[i]],tg[i]),R[bl[i]]=max(R[bl[i]],tg[i]);
	for(int i=1,x,s=0;i<=m;++i)
	{scanf("%d",&x);if(x) tg1[bl[s+vc[i].size()-x+1]]=1;s+=vc[i].size();}
	for(int i=1;i<=s;++i) for(auto j:e[i]) if(bl[i]!=bl[j]) e1[bl[j]].pb(bl[i]);
	for(int i=1;i<=SCC;++i) {dfs(i);if(tg1[i]) mx[R[i]]=max(mx[R[i]],L[i]);}
	for(int i=1,nw=0;i<=m;++i) {mx[i]=max(mx[i],mx[i-1]);if(nw<mx[i]) nw=i,++ans;}
	printf("%d\n",ans);return 0;
}