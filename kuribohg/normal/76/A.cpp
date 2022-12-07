#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=50010;
const LL INF=9000000000000000000LL;
struct Edge
{
	int f,t;
	LL g,s;
}e[MAXN],E[MAXN];
bool cmp_g(const Edge &p,const Edge &q){return p.g<q.g;}
bool cmp_s(const Edge &p,const Edge &q){return p.s<q.s;}
int n,m,cnt;
LL G,S,g,s,ans=INF;
int fa[MAXN];
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void uni(int i,int j)
{
	fa[find(i)]=find(j);
}
int main()
{
	scanf("%d%d%I64d%I64d",&n,&m,&G,&S);
	for(int i=1;i<=m;i++) scanf("%d%d%I64d%I64d",&e[i].f,&e[i].t,&e[i].g,&e[i].s);
	sort(e+1,e+m+1,cmp_g);
	for(int i=1;i<=m;i++)
	{
		E[++cnt]=e[i];
		g=e[i].g;
		sort(E+1,E+cnt+1,cmp_s);
		int tree_edge=0;
		for(int j=1;j<=n;j++) fa[j]=j;
		for(int j=1;j<=cnt;j++)
			if(find(E[j].f)!=find(E[j].t))
				uni(E[j].f,E[j].t),s=E[j].s,E[++tree_edge]=E[j];
		if(tree_edge==n-1) ans=min(ans,G*g+S*s);
		cnt=tree_edge;
	}
	if(ans==INF) ans=-1;
	printf("%I64d\n",ans);
	return 0;
}