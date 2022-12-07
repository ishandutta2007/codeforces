#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=2010;
const int MAXM=2010*2010*2;
int n,a[MAXN][MAXN];
int head[MAXN],to[MAXM],next[MAXM],cnt=1;
int dfn[MAXN],low[MAXN],belongn[MAXN],Sta[MAXN],dfs_clock,top,tot;
inline void adde(int f,int t)
{
    cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt;
}
void Tarjan(int x)
{
    dfn[x]=low[x]=++dfs_clock,Sta[++top]=x;
    for(int i=head[x];i;i=next[i])
    {
        if(!dfn[to[i]]) Tarjan(to[i]),low[x]=min(low[x],low[to[i]]);
        else if(!belongn[to[i]]) low[x]=min(low[x],dfn[to[i]]);
    }
    if(dfn[x]==low[x])
    {
        int p=-1;
        tot++;
        while(p!=x) p=Sta[top--],belongn[p]=tot;
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j]) adde(i,j);
        }
    for(int i=1;i<=n;i++) if(!dfn[i]) Tarjan(i);
    if(tot==1) puts("YES");
    else puts("NO");
    return 0;
}