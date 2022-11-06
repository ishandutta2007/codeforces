#include<bits/stdc++.h>
#define re register
#define minp(a,b) (dep[a]<dep[b]?(a):(b))
struct eg{int to;eg*nx;}e[800100],*la[200100],*la1[200100],*cnt=e;
inline void addE(re int a,re int b)
{
	*++cnt=(eg){b,la[a]};la[a]=cnt;
	*++cnt=(eg){a,la[b]};la[b]=cnt;
}
inline void addE1(re int a,re int b)
{
	*++cnt=(eg){b,la1[a]};la1[a]=cnt;
	*++cnt=(eg){a,la1[b]};la1[b]=cnt;
}
int dfn[200100],eul[20][400100],low[200100],sta[200100],in[200100],bs[200100];
int x[200100],y[200100],lg[400100],dep[200100],tt,ta,tot;
bool vis[200100];
void dfs(re int a,re int fa)
{
	low[a]=dfn[a]=++tot;sta[++ta]=a;
	for(re eg*i=la[a];i;i=i->nx)if(!dfn[i->to])
	{
		bs[i->to]=bs[a];
		dfs(i->to,a);low[a]=std::min(low[a],low[i->to]);
	}else if(i->to==fa)fa=0;
	else low[a]=std::min(low[a],dfn[i->to]);
	if(low[a]==dfn[a])
	{
		tt++;
		do
		{
			in[sta[ta]]=tt;
		}while(sta[ta--]!=a);
	}
}
void dfs1(re int a)
{
	dfn[a]=++tot;eul[0][tot]=a;
	for(re eg*i=la1[a];i;i=i->nx)if(!dep[i->to])
	{
		dep[i->to]=dep[a]+1;
		dfs1(i->to);eul[0][++tot]=a;
	}
}
int ff[200100],ff1[200100];
void dfs2(re int a)
{
	vis[a]=1;
	for(re eg*i=la1[a];i;i=i->nx)if(!vis[i->to])
	{
		dfs2(i->to);ff[a]+=ff[i->to];ff1[a]+=ff1[i->to];
	}
	if(ff[a]>0&&ff1[a]>0){puts("No");exit(0);}
}
int LCA(re int x,re int y)
{
	x=dfn[x];y=dfn[y];
	if(x>y)std::swap(x,y);
	re int c=lg[y-x+1];
	return minp(eul[c][x],eul[c][y-(1<<c)+1]);
}
int main()
{
	re int n,m,q,x1,y1,z1;
	scanf("%d%d%d",&n,&m,&q);
	for(re int i=1;i<=m;i++)scanf("%d%d",&x[i],&y[i]),addE(x[i],y[i]);
	for(re int i=1;i<=n;i++)if(!dfn[i])
	{
		bs[i]=i;dfs(i,0);
	}
	for(re int i=1;i<=m;i++)if(in[x[i]]!=in[y[i]])addE1(in[x[i]],in[y[i]]);
	tot=0;lg[0]=-1;
	for(re int i=1;i<=n;i++)
	{
		lg[i]=lg[i/2]+1;
		if(!dep[i])dep[i]=1,dfs1(i);
	}
	for(re int i=1;i<=tot;i++)
		lg[i]=lg[i/2]+1;
	for(re int i=1;(1<<i)<=tot;i++)
		for(re int j=1;j+(1<<i)<=tot+1;j++)eul[i][j]=minp(eul[i-1][j],eul[i-1][j+(1<<i-1)]);
	for(;q--;)
	{
		scanf("%d%d",&x1,&y1);
		if(bs[x1]!=bs[y1]){puts("No");return 0;}
		x1=in[x1];y1=in[y1];z1=LCA(x1,y1);
		if(x1==y1)continue;
		ff[x1]++;ff1[y1]++;ff[z1]--;ff1[z1]--;
	}
	for(re int i=1;i<=n;i++)
	if(!vis[i]){
		dfs2(i);
	}
	puts("Yes");
	return 0;
}