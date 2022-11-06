#include<bits/stdc++.h>
#define re register
#define minp(a,b) (dep[a]<dep[b]?a:b)
struct eg{int to;eg*nx;}e[2000100],*la[200100],*la1[200100],*cnt=e;
int eul[20][400100],lg[400100],tot,dfn[200100],dep[200100];
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
void dfs(re int a,re int fa)
{
	eul[0][++tot]=a;dfn[a]=tot;
	for(re eg*i=la[a];i;i=i->nx)if(i->to!=fa)
	{
		dep[i->to]=dep[a]+1;
		dfs(i->to,a);eul[0][++tot]=a;
	}
}
int LCA(re int a,re int b)
{
	a=dfn[a];b=dfn[b];
	if(a>b)std::swap(a,b);
	re int c=lg[b-a+1];
	return minp(eul[c][a],eul[c][b-(1<<c)+1]);
}
int v1[200100],ss[200100],s1[200100],q1[400100],tt,sta[400100],ta;
bool vis[200100];
bool cmp(re int a,re int b){return dfn[a]<dfn[b];}
#define mk(a,b) std::make_pair(a,b)
std::pair<int,int>dw[200100];
long long dq[200100];
void dfs1(re int a,re int fa)
{
	std::pair<int,int> x;
	for(re eg*i=la1[a];i;i=i->nx)if(i->to!=fa)
	{
		dfs1(i->to,a);
		x=dw[i->to];
		if(!x.second)continue;
		re int ds=dep[i->to]-dep[a],y=0;
		if(ds>dq[i->to])
		{
			y=(ds-dq[i->to]-1)/ss[x.second]+1;
			x.first+=y;
		}else y=0;
		if(x<dw[a])
		{
			dw[a]=x;
			dq[a]=dq[i->to]+1ll*y*ss[x.second]-ds;
		}
	}
}
void dfs2(re int a,re int fa)
{
	std::pair<int,int> x;
	for(re eg*i=la1[a];i;i=i->nx)if(i->to!=fa)
	{
		x=dw[a];
		re int ds=dep[i->to]-dep[a],y=0;
		if(ds>dq[a])
		{
			y=(ds-dq[a]-1)/ss[x.second]+1;
			x.first+=y;
		}else y=0;
		if(x<dw[i->to])
		{
			dw[i->to]=x;
			dq[i->to]=dq[a]+1ll*y*ss[x.second]-ds;
		}
		dfs2(i->to,a);
	}
}
int main()
{
	re int n,q,x,y;
	scanf("%d",&n);
	for(re int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		addE(x,y);
	}
	dep[1]=1;
	dfs(1,0);
	for(re int i=2;i<=tot;i++)lg[i]=lg[i/2]+1;
	for(re int i=1;(1<<i)<=tot;i++)
	{
		for(re int j=1;j+(1<<i)<=tot+1;j++)
		{
			eul[i][j]=minp(eul[i-1][j],eul[i-1][j+(1<<i-1)]);
		}
	}
	scanf("%d",&q);
	eg*cntt=cnt;
	for(re int i=1;i<=n;i++)dw[i]=mk(1<<30,0);
	for(;q--;)
	{
		re int k,m,tp;
		cnt=cntt;tt=0;ta=0;
		scanf("%d%d",&k,&m);
		for(re int i=1;i<=k;i++)
		{
			scanf("%d%d",&v1[i],&ss[i]);dw[v1[i]]=mk(0,i);
			if(!vis[v1[i]])q1[++tt]=v1[i],vis[v1[i]]=1;
		}
		for(re int i=1;i<=m;i++)
		{
			scanf("%d",&s1[i]);
			if(!vis[s1[i]])q1[++tt]=s1[i],vis[s1[i]]=1;
		}
		tp=tt;
		std::sort(q1+1,q1+tt+1,cmp);
		for(re int i=1;i<=tt;i++)
		{
			if(ta)
			{
				re int x2=LCA(q1[i],sta[ta]);
				for(;ta>1&&dfn[sta[ta-1]]>=dfn[x2];ta--)
				{
					addE1(sta[ta-1],sta[ta]);
				}
				if(sta[ta]!=x2)q1[++tp]=x2,addE1(x2,sta[ta]),sta[ta]=x2;
				sta[++ta]=q1[i];
			}else sta[++ta]=q1[i];
		}
		for(;ta>1;ta--)
		{
			addE1(sta[ta-1],sta[ta]);
		}
		dfs1(sta[1],0);
		dfs2(sta[1],0);
		for(re int i=1;i<=m;i++)printf("%d ",dw[s1[i]].second);puts("");
		for(re int i=1;i<=tp;i++)la1[q1[i]]=0,dw[q1[i]]=mk(1<<30,0),dq[q1[i]]=0;
		for(re int i=1;i<=k;i++)vis[v1[i]]=0;
		for(re int i=1;i<=m;i++)vis[s1[i]]=0;
	}
}