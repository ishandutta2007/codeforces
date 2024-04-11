#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define pb push_back
int n,tp,rt,ans,z[N],ps[N],pr[N],sf[N],dp1[N],dp2[N];
vector<int> e[N];struct Node {int x,w;}st[N];
bool cmp(Node x,Node y) {return x.w>y.w;}
bool cmp1(int x,int y) {return dp1[x]>dp1[y];}
int qry(int u)
{
	int res;printf("? %d\n",u);fflush(stdout);
	scanf("%d",&res);return res;
}
void dfs1(int u,int f)
{
	for(auto v:e[u]) if(v!=f) dfs1(v,u);
	tp=dp1[u]=0;st[++tp]=(Node) {0,0};
	for(auto v:e[u]) if(v!=f) st[++tp]=(Node) {v,dp1[v]};
	sort(st+1,st+tp+1,cmp);
	for(int i=1;i<=tp;++i) dp1[u]=max(dp1[u],st[i].w+i-1);
}
void dfs2(int u,int f)
{
	tp=0;st[++tp]=(Node) {0,0};
	if(u!=1) st[++tp]=(Node) {0,dp2[u]};
	for(auto v:e[u]) if(v!=f) st[++tp]=(Node) {v,dp1[v]};
	ans=max(ans,tp-1);sf[tp+1]=0;sort(st+1,st+tp+1,cmp);
	for(int i=2;i<=tp;++i) ans=max(ans,st[1].w+st[i].w+i-2);
	for(int i=1;i<=tp;++i) ps[st[i].x]=i;
	for(int i=1;i<=tp;++i) pr[i]=max(pr[i-1],st[i].w+i-1);
	for(int i=tp;i;--i) sf[i]=max(sf[i+1],st[i].w+i-1);
	for(auto v:e[u]) if(v!=f)
		dp2[v]=max(pr[ps[v]-1],sf[ps[v]+1]-1);
	for(auto v:e[u]) if(v!=f) dfs2(v,u);
}
int dfs3(int u,int f)
{
	int t;sort(e[u].begin(),e[u].end(),cmp1);
	for(auto v:e[u]) if(v!=f)
	{t=dfs3(v,u);if(t!=u) return t;}if(z[0]>1) return rt;
	if(u!=rt && e[u].size()<2) {t=qry(u);if(t!=u) return t;}
	z[++z[0]]=u;return rt;
}
int main()
{
	scanf("%d",&n);
	for(int i=1,u,v;i<n;++i)
		scanf("%d %d",&u,&v),e[u].pb(v),e[v].pb(u);
	dfs1(1,0);dfs2(1,0);printf("%d\n",ans);fflush(stdout);
	scanf("%d",&rt);dfs1(rt,0);dfs3(rt,0);
	if(z[0]<2) z[1]=z[2]=rt;
	printf("! %d %d\n",z[1],z[2]);fflush(stdout);return 0;
}