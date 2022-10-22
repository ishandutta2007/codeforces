#include <bits/stdc++.h>
using namespace std;
#define N1 50005
#define N2 1000005
#define LIM 1000000
int n,m,cntP,L,R,ans,cnt,tmp[N1],rv[N1];
struct Edge {int id,u,v,w,c;}e1[N1];
vector<int> e[N2],e2[N1];
int SCC,dfn[N2],low[N2],st[N2],bl[N2];
bool cmp(Edge x,Edge y) {return x.c<y.c;}
void addE(int u,int v,bool fl)
{if(fl) e[v].push_back(u);else e[u].push_back(v);}
void Tarjan(int u)
{
	dfn[u]=low[u]=++dfn[0];st[++st[0]]=u;
	for(int i=0,v;i<e[u].size();++i)
	{
		v=e[u][i];
		if(!dfn[v]) Tarjan(v),low[u]=min(low[u],low[v]);
		else if(!bl[v]) low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u])
	{
		bl[u]=++SCC;
		while(st[st[0]]!=u) bl[st[st[0]--]]=SCC;--st[0];
	}
}
void build(bool fl,int a[])
{
	for(int i=1;i<=a[0];++i)
	{
		addE(a[i],cntP+i,fl);addE(cntP+a[0]+i,m+a[i],fl);
		if(i>1)
		{
			addE(cntP+i-1,cntP+i,fl);addE(cntP+i-1,m+a[i],fl);
			addE(cntP+a[0]+i,cntP+a[0]+i-1,fl);
			addE(a[i],cntP+a[0]+i-1,fl);
		}
	}cntP+=a[0]*2;
}
bool chk(int x)
{
	for(int i=1;i<=cntP;++i) dfn[i]=low[i]=bl[i]=0;SCC=0;
	for(int i=1;i<=m;++i) if(e1[i].w>x) addE(i,m+i,0);
	for(int i=1;i<=cntP;++i) if(!dfn[i]) Tarjan(i);
	for(int i=1;i<=m;++i) if(e1[i].w>x) e[i].pop_back();
	for(int i=1;i<=m;++i) if(bl[i]==bl[m+i]) return 0;return 1;
}
int main()
{
	scanf("%d %d",&n,&m);cntP=m*2;
	for(int i=1,u,v,w,c;i<=m;++i)
		scanf("%d %d %d %d",&u,&v,&c,&w),e1[i]=(Edge) {i,u,v,w,c};
	sort(e1+1,e1+m+1,cmp);for(int i=1;i<=m;++i) rv[e1[i].id]=i;
	for(int i=1;i<=m;++i)
		e2[e1[i].u].push_back(i),e2[e1[i].v].push_back(i); 
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<e2[i].size();++j) tmp[++tmp[0]]=e2[i][j];
		build(0,tmp);tmp[0]=0;
		for(int j=0;j<e2[i].size();++j)
		{
			tmp[++tmp[0]]=e2[i][j];
			if(j==e2[i].size()-1 || e1[e2[i][j]].c<e1[e2[i][j+1]].c)
				build(1,tmp),tmp[0]=0;
		}
	}L=0;R=1e9;ans=-1;
	while(L<=R)
	{
		int mid=(L+R)/2;
		if(chk(mid)) ans=mid,R=mid-1;else L=mid+1;
	}if(ans==-1) {puts("No");return 0;}puts("Yes");chk(ans);
	for(int i=1;i<=m;++i) if(bl[rv[i]]<bl[m+rv[i]]) ++cnt;
	printf("%d %d\n",ans,cnt);
	for(int i=1;i<=m;++i)
		if(bl[rv[i]]<bl[m+rv[i]]) printf("%d ",i);return 0;
}