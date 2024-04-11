#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=100010;
const int MAXM=1000010;
const int INF=1000000000;
int S,T,N,d[MAXN];
int q[MAXN],l,r;
int head[MAXN],to[MAXM],next[MAXM],w[MAXM],cnt=1;
inline void add2(int f,int t,int ww)
{
    cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt,w[cnt]=ww;
    cnt++,to[cnt]=f,next[cnt]=head[t],head[t]=cnt,w[cnt]=ww;
}
bool BFS()
{
    for(int i=1;i<=N;i++) d[i]=-1;
    q[l=r=1]=S,d[S]=1;
    while(l<=r)
    {
        int x=q[l++];
        for(int i=head[x];i;i=next[i])
            if(w[i]>0&&d[to[i]]==-1) d[to[i]]=d[x]+1,q[++r]=to[i];
    }
    return d[T]!=-1;
}
int DFS(int x,int a)
{
    if(x==T) return a;
    int flow=a,f;
    for(int i=head[x];i;i=next[i])
        if(w[i]>0&&d[to[i]]==d[x]+1)
        {
            f=DFS(to[i],min(w[i],a));
            w[i]-=f,w[i^1]+=f,a-=f;
            if(a<=0) return flow;
        }
    if(a!=0) d[x]=-1;
    return flow-a;
}
int Dinic()
{
    int flow=0,f;
    while(BFS())
        while((f=DFS(S,INF))!=0)
            flow+=f;
    return flow;
}
int n,m,x,y,z,ans,now;
int fa[MAXN],fw[MAXN];
void dfs(int x,int fa)
{
    for(int i=head[x];i;i=next[i])
        if(to[i]!=fa&&w[i]!=INF)
        {
            if(now==0||w[i]<w[now]) now=i;
            dfs(to[i],x);
        }
}
void Solve(int x)
{
    now=0;
    dfs(x,0);
    if(!now) {printf("%d ",x);return;}
    w[now]=w[now^1]=INF;
    int p=now;
    Solve(to[p]);
    Solve(to[p^1]);
}
int X[MAXM],Y[MAXM],Z[MAXM];
int main()
{
    scanf("%d%d",&n,&m);
    N=n;
    for(int i=1;i<=m;i++) scanf("%d%d%d",&X[i],&Y[i],&Z[i]);
    for(int i=1;i<=n;i++) fa[i]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=n;j++) head[j]=0;
        cnt=1;
        for(int j=1;j<=m;j++) add2(X[j],Y[j],Z[j]);
        S=i,T=fa[i];
        fw[i]=Dinic();
        BFS();
        for(int j=i+1;j<=n;j++)
            if(d[j]!=-1&&fa[j]==fa[i]) fa[j]=i;
    }
    for(int i=1;i<=n;i++) head[i]=0;
    cnt=1;
    for(int i=2;i<=n;i++) add2(i,fa[i],fw[i]),ans+=fw[i];
    printf("%d\n",ans);
    Solve(1);
    return 0;
}