#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,h[1010];long long cap[10100];int K=1,nxt[10100],to[10100];
int q[1010],hh=0,tt=0,lvl[1010],iter[1010];
void ins(int u,int v,long long c){nxt[++K]=h[u];h[u]=K;to[K]=v;cap[K]=c;}
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
long long dfs(int u,long long f,int T)
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
int u[101000],v[101000],c[101000],x;
bool check(double a)
{
	memset(h,0,sizeof(h));K=1;
	for(int i=1;i<=m;i++)
	{
		ins(u[i],v[i],(long long)(c[i]/a));
		ins(v[i],u[i],0);
	}
	int S=1,T=n;
	int ans=dinic(S,T);
	if(ans>=x)return 1;
	return 0;
}
int main()
{
	scanf("%d%d%d",&n,&m,&x);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u[i],&v[i],&c[i]);
	}
	double l=0,r=1000000,ans=0;
	for(int i=1;i<=100;i++)
	{
		double mid=(l+r)/2;
		if(check(mid))ans=max(ans,mid),l=mid;
		else r=mid;
	}
	printf("%.10lf",ans*x);
	return 0;
}