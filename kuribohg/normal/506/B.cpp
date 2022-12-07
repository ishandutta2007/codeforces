#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000010;
int n,m,X[MAXN],Y[MAXN],K;
int head[MAXN],to[MAXN],next[MAXN],cnt;
bool used[MAXN];
inline void adde(int f,int t)
{
    cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt;
}
inline void add2(int f,int t)
{
    adde(f,t),adde(t,f);
}
int size[MAXN],belongn[MAXN],dfn[MAXN],low[MAXN],dfs_clock,tot;
int Sta[MAXN],top;
void Tarjan(int x)
{
    dfn[x]=low[x]=++dfs_clock;
    Sta[++top]=x;
    for(int i=head[x];i;i=next[i])
    {
        if(!dfn[to[i]]) Tarjan(to[i]),low[x]=min(low[to[i]],low[x]);
        else if(!belongn[to[i]]) low[x]=min(dfn[to[i]],low[x]);
    }
    if(low[x]==dfn[x])
    {
        int p=-1;
        tot++;
        while(p!=x) p=Sta[top--],belongn[p]=tot,size[tot]++;
    }
}
bool DFS(int x)
{
    used[x]=true;
    bool con=false;
    for(int i=head[x];i;i=next[i])
        if(!used[to[i]]) con|=DFS(to[i]);
    if(size[x]>1) con=true;
    return con;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) scanf("%d%d",&X[i],&Y[i]),adde(X[i],Y[i]);
    for(int i=1;i<=n;i++) if(!dfn[i]) Tarjan(i);
    cnt=0;
    for(int i=1;i<=n;i++) head[i]=0;
    for(int i=1;i<=m;i++)
        if(belongn[X[i]]!=belongn[Y[i]]) add2(belongn[X[i]],belongn[Y[i]]);
    for(int i=1;i<=tot;i++)
        if(!used[i])
        {
            n--;
            if(DFS(i)) n++;
        }
    printf("%d\n",n);
    return 0;
}