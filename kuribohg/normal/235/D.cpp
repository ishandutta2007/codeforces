#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=100010;
int n;
int head[MAXN],to[MAXN],next[MAXN],cnt=1;
int dfn[MAXN],fa[MAXN],faEdge[MAXN],dfs_clock;
int Cir[MAXN],tot;
int belongn[MAXN],dis[MAXN],dep[MAXN],d[MAXN];
bool inCir[MAXN];
double ans;
inline void adde(int f,int t)
{
	cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt;
	cnt++,to[cnt]=f,next[cnt]=head[t],head[t]=cnt;
}
void getCir(int x,int father)
{
	dfn[x]=++dfs_clock;
	for(int i=head[x];i;i=next[i])
		if((i^father)!=1)
		{
			if(!dfn[to[i]]) fa[to[i]]=x,faEdge[to[i]]=i,getCir(to[i],i);
			else if(dfn[to[i]]<dfn[x])
			{
				Cir[tot=1]=to[i];
				inCir[i]=inCir[i^1]=true;
				int t=x;
				while(t!=to[i])
				{
					Cir[++tot]=t;
					inCir[faEdge[t]]=inCir[faEdge[t]^1]=true;
					t=fa[t];
				}
			}
		}
}
void FloodFill(int x,int fa,int c)
{
	belongn[x]=c;
	for(int i=head[x];i;i=next[i])
		if(to[i]!=fa&&!inCir[i])
			dis[to[i]]=dis[x]+1,FloodFill(to[i],x,c);
}
void DFS(int x,int fa)
{
	ans+=1.0/dep[x];
	for(int i=head[x];i;i=next[i])
		if(to[i]!=fa&&!inCir[i])
			dep[to[i]]=dep[x]+1,DFS(to[i],x);
}
int main()
{
	scanf("%d",&n);
	for(int i=1,x,y;i<=n;i++) scanf("%d%d",&x,&y),adde(x+1,y+1);
	getCir(1,0);
	for(int i=1;i<=tot;i++) dis[Cir[i]]=1,FloodFill(Cir[i],0,Cir[i]);
	for(int i=1;i<=n;i++) dep[i]=1,DFS(i,0);
	for(int i=1;i<=tot;i++) d[Cir[i]]=i-1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(belongn[i]!=belongn[j])
			{
				int x=(d[belongn[i]]-d[belongn[j]]+tot)%tot;
				int y=tot-x;
				int z=dis[i]+dis[j];
				x--,y--;
				ans+=1.0/(z+x)+1.0/(z+y)-1.0/(z+x+y);
			}
	printf("%.015lf\n",ans);
	return 0;
}