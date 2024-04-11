#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,h[1010],g[1010][1010],cap[10100],K=1,nxt[10100],to[10100];
int q[1010],hh=0,tt=0,lvl[1010],iter[1010];
void ins(int u,int v,int c){nxt[++K]=h[u];h[u]=K;to[K]=v;cap[K]=c;}
bool bfs(int S,int T)
{
	hh=tt=0;memset(lvl,0,sizeof(lvl));
	q[tt++]=S;lvl[S]=1;
	while(hh<tt)
	{
		int u=q[hh++];
		for(int i=h[u];i;i=nxt[i])
		{
			if(cap[i]&&!lvl[to[i]])
			{
				lvl[to[i]]=lvl[u]+1;
				q[tt++]=to[i];
			}
		}
	}
	if(!lvl[T])return 0;
	return 1;
}
int dfs(int u,int f,int T)
{
	if(u==T)return f;
	int used=0,w;
	for(int &i=iter[u];i;i=nxt[i])
	{
		if(cap[i]&&lvl[to[i]]==lvl[u]+1)
		{
			w=dfs(to[i],min(f-used,cap[i]),T);
			if(w){cap[i]-=w;cap[i^1]+=w;used+=w;if(used==f)return f;}
		}
	}
	return used;
}
int dinic(int S,int T)
{
	int flow=0;
	while(bfs(S,T))
	{
		for(int i=1;i<=T;i++)iter[i]=h[i];
		flow+=dfs(S,1000000000,T);
	}
	return flow;
}
int main()
{
	int n,m;scanf("%d%d",&n,&m);
	int sum=0,S=2*n+1,T=2*n+2,sum2=0;
	for(int i=1;i<=n;i++)
	{
		int a;scanf("%d",&a);ins(S,i,a);ins(i,S,0);sum2+=a;
	}
	for(int i=1;i<=n;i++)
	{
		int a;scanf("%d",&a);sum+=a;ins(i+n,T,a);ins(T,i+n,0);
		ins(i,i+n,1000000000);ins(i+n,i,0);
	}
	if(sum!=sum2)return 0*puts("NO");
	for(int i=1;i<=m;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		ins(u,v+n,1000000000);ins(v+n,u,0);ins(v,u+n,1000000000);ins(u+n,v,0);
	}
	int ans=dinic(S,T);
	if(ans!=sum)return 0*puts("NO");
	puts("YES");
	for(int i=1;i<=n;i++)
	{
		for(int j=h[i];j;j=nxt[j])
		{
			if(n+1<=to[j]&&to[j]<=n+n)g[i][to[j]-n]=1000000000-cap[j];
		}
	}
	for(int i=1;i<=n;i++,puts(""))
	for(int j=1;j<=n;j++)printf("%d ",g[i][j]); 
	return 0;
}