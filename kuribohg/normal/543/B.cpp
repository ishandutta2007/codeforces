#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=100010;
const int INF=1000000000;
int n,m,x,y,dis[3010][3010];
int S1,T1,L1,S2,T2,L2,ans=INF;
int head[MAXN],to[MAXN],next[MAXN],cnt=1;
inline void adde(int f,int t)
{
    cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt;
    cnt++,to[cnt]=f,next[cnt]=head[t],head[t]=cnt;
}
void BFS(int S,int dis[])
{
    static int q[3010],l,r;
    for(int i=1;i<=n;i++) dis[i]=INF;
    q[l=r=1]=S,dis[S]=0;
    while(l<=r)
    {
        int x=q[l++];
        for(int i=head[x];i;i=next[i])
            if(dis[to[i]]==INF) dis[to[i]]=dis[x]+1,q[++r]=to[i];
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) scanf("%d%d",&x,&y),adde(x,y);
    scanf("%d%d%d%d%d%d",&S1,&T1,&L1,&S2,&T2,&L2);
    for(int i=1;i<=n;i++) BFS(i,dis[i]);
    if(dis[S1][T1]<=L1&&dis[S2][T2]<=L2) ans=min(ans,dis[S1][T1]+dis[S2][T2]);
    else {puts("-1");return 0;}
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(dis[S1][i]+dis[i][j]+dis[j][T1]<=L1&&dis[S2][i]+dis[i][j]+dis[j][T2]<=L2)
                ans=min(ans,dis[S1][i]+dis[S2][i]+dis[i][j]+dis[j][T1]+dis[j][T2]);
            if(dis[S1][j]+dis[j][i]+dis[i][T1]<=L1&&dis[S2][i]+dis[i][j]+dis[j][T2]<=L2)
                ans=min(ans,dis[S1][j]+dis[S2][i]+dis[i][j]+dis[i][T1]+dis[j][T2]);
        }
    printf("%d\n",m-ans);
    return 0;
}