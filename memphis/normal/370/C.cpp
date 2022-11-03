#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#define inf 0x7f7f7f7f
using namespace std;

int HOH[500000],next[500000],ed[500000],flow[500000];
int a,b,u,v,c;
int d[50000];
bool s[50000];
int n,m,i,j,k,tot,S,T;
int ans;

inline void add(int u,int v,int f)
{
	next[++tot]=HOH[u];HOH[u]=tot;ed[tot]=v;flow[tot]=f;
	next[++tot]=HOH[v];HOH[v]=tot;ed[tot]=u;flow[tot]=0;
}

int find(int now,int Flow)
{
	if (now==T)	return Flow;
	int tmp,w=0,w0,i;
	for(i=HOH[now];i&&w<Flow;i=next[i])
	if((flow[i])&&(d[now]+1==d[ed[i]])&&(w0=min(Flow-w,flow[i]))&&(tmp=find(ed[i],w0)))
	flow[i]-=tmp,flow[i^1]+=tmp,w+=tmp;
	if(!w)d[now]=inf;
	return w;
}

inline void dinic(int S,int T)
{
	int queue[50000],t1,t2,tmp,i;
	while(true)
	{
		memset(s,true,sizeof(s));
		queue[1]=S;t1=0;t2=1;s[S]^=1;
		while(t1<t2&&s[T])
		for(i=HOH[queue[++t1]];i;i=next[i])
		if(flow[i]&&s[ed[i]])
		queue[++t2]=tmp=ed[i],d[tmp]=d[queue[t1]]+1,s[tmp]^=1;
		if(s[T])break;
		while(true)if(tmp=find(S,inf))ans+=tmp;else break;
	}
}

int num[1000];
int link[105][105];

int main()
{
    scanf("%d%d",&n,&m);
    S=0;T=m*2+1;tot=1;
	for(i=1;i<=n;++i)
	{
		scanf("%d",&j);
		++num[j];
	}
	for(i=1;i<=m;++i)add(S,i,num[i]);
	for(i=1;i<=m;++i)add(i+m,T,num[i]);
	for(i=1;i<=m;++i)
	for(j=1;j<=m;++j)
	if(i!=j)
	{
		add(i,j+m,inf);
		link[i][j]=tot-1;
	}
	dinic(S,T);
	printf("%d\n",ans);
	for(i=1;i<=m;++i)
	{
		for(j=1;j<=m;++j)
		if(i!=j)
		{
			for(k=1;k<=inf-flow[link[i][j]];++k)
			printf("%d %d\n",i,j);
			num[i]-=inf-flow[link[i][j]];
		}
		for(k=1;k<=num[i];++k)printf("%d %d\n",i,i);
	}
	return 0;
}