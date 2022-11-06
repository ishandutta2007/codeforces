#include<iostream>
#include<cstdio>
#include<cstring>
#define INF 1000000000
using namespace std;
int h[510000],nxt[500100],to[500100],cap[500100],cost[500100],K=1;
int q[1010000],hh=0,tt=0,d[1010000],lst[1010000];bool inq[101000];
void ins(int u,int v,int c1,int c2){nxt[++K]=h[u];h[u]=K;to[K]=v;cap[K]=c1;cost[K]=c2;}
void insw(int u,int v,int c1,int c2){ins(u,v,c1,c2);ins(v,u,0,-c2);}
bool spfa(int S,int T)
{
    hh=0,tt=0;q[tt++]=S;
    memset(d,127/2,sizeof(d));
    memset(inq,0,sizeof(inq));
    d[S]=0;inq[S]=1;
    while(hh<tt)
    {
        int u=q[hh++];inq[u]=0;
        for(int i=h[u];i;i=nxt[i])
        {
            int v=to[i];
            if(cap[i]&&d[v]>d[u]+cost[i])
            {
                d[v]=d[u]+cost[i];lst[v]=i;
                if(!inq[v])q[tt++]=v,inq[v]=1;
            }
        }
    }
    if(d[T]>=INF)return false;return true;
}
int ans1=0,ans2=0;
void mcf(int S,int T)
{
    int Min=INF;
    for(int i=T;i!=S;i=to[lst[i]^1])Min=min(Min,cap[lst[i]]);
    ans1+=Min;
    for(int i=T;i!=S;i=to[lst[i]^1])
    {
        cap[lst[i]]-=Min;cap[lst[i]^1]+=Min;ans2+=cost[lst[i]]*Min;
    }
}
int a[1010][1010]; int n,m;
int get(int i,int j){return (i-1)*m+j;}
int main()
{
    scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		if((i+j)&1)
		{
			if(i!=1)insw(get(i,j),get(i-1,j),1,(a[i-1][j]==a[i][j])^1);
			if(i!=n)insw(get(i,j),get(i+1,j),1,(a[i+1][j]==a[i][j])^1);
			if(j!=1)insw(get(i,j),get(i,j-1),1,(a[i][j-1]==a[i][j])^1);
			if(j!=m)insw(get(i,j),get(i,j+1),1,(a[i][j+1]==a[i][j])^1);
		}
	}
	int S=n*m+1,T=n*m+2;
    for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		if((i+j)&1)
		{
			insw(S,get(i,j),1,0);
		}
		else
		{
			insw(get(i,j),T,1,0);
		}
	}
    while(spfa(S,T))mcf(S,T);
    cout<<ans2;
    return 0;
}