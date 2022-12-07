#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=100010;
const int MAXM=4000010;
const int INF=1000000000;
int S,T,d[MAXN],cur[MAXN];
int q[MAXN],l,r;
int head[MAXN],to[MAXM],w[MAXM],next[MAXM],cnt=1;
inline void adde(int f,int t,int ww)
{
    cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt,w[cnt]=ww;
    cnt++,to[cnt]=f,next[cnt]=head[t],head[t]=cnt,w[cnt]=0;
}
bool BFS()
{
    for(int i=1;i<=T;i++) d[i]=-1;
    q[l=r=1]=S,d[S]=0;
    while(l<=r)
    {
        int x=q[l++];
        for(int i=head[x];i;i=next[i])
            if(d[to[i]]==-1&&w[i]>0) d[to[i]]=d[x]+1,q[++r]=to[i];
    }
    return d[T]!=-1;
}
int DFS(int x,int a)
{
    if(x==T) return a;
    int flow=a,f;
    for(int i=cur[x];i;i=next[i])
        if(d[to[i]]==d[x]+1&&w[i]>0)
        {
            f=DFS(to[i],min(w[i],a));
            w[i]-=f,w[i^1]+=f,a-=f;
            if(w[i]>0) cur[x]=i;
            if(a<=0) return flow;
        }
    if(a!=0) d[x]=-1;
    return flow-a;
}
int Dinic()
{
    int flow=0,f;
    while(BFS())
    {
        for(int i=1;i<=T;i++) cur[i]=head[i];
        while((f=DFS(S,INF))!=0)
            flow+=f;
    }
    return flow;
}
int n,m,g,v[MAXN],s[MAXN],ans;
int tar[MAXN],c[MAXN],K[MAXN],a[MAXN][15],isfriend[MAXN];
int main()
{
    scanf("%d%d%d",&n,&m,&g);
    for(int i=1;i<=n;i++) scanf("%d",&s[i]);
    for(int i=1;i<=n;i++) scanf("%d",&v[i]);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&tar[i],&c[i],&K[i]);
        ans+=c[i];
        for(int j=1;j<=K[i];j++) scanf("%d",&a[i][j]);
        scanf("%d",&isfriend[i]);
        if(isfriend[i]) c[i]+=g;
    }
    S=n+m+1,T=S+1;
    for(int i=1;i<=n;i++)
        if(s[i]==0) adde(S,i,v[i]);
        else adde(i,T,v[i]);
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=K[i];j++)
            if(tar[i]==0) adde(n+i,a[i][j],INF);
            else adde(a[i][j],n+i,INF);
        if(tar[i]==0) adde(S,n+i,c[i]);
        else adde(n+i,T,c[i]);
    }
    ans-=Dinic();
    printf("%d\n",ans);
    return 0;
}