#include <bits/stdc++.h>
using namespace std;
const int maxn=155;
const int maxm=155;
const int maxlog=35;
int n,m,k,u[maxm],v[maxm],c[maxm],b[maxm],he[maxn],ne[maxm],to[maxm],tot,dis[maxn];
// bitset<maxn> ma[maxn],maT[maxn],cur,temp[maxn];
int ma[maxlog][maxn][maxn];
bool vis[2][maxn]; int cur;
inline void add_edge(int u,int v) { to[tot]=v,ne[tot]=he[u],he[u]=tot++; }
inline void bfs()
{
    queue<int> que;
    int u,i;
    for(i=1;i<=n;i++) dis[i]=0x7fffffff;
    while(!que.empty()) que.pop();
    dis[n]=0,que.push(n);
    while(!que.empty())
    {
        u=que.front(),que.pop();
        for(i=he[u];~i;i=ne[i])
            if(dis[to[i]]==0x7fffffff)
                dis[to[i]]=dis[u]+1,que.push(to[i]);
    }
}
int main()
{
    int i,j,t,l,minn;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++) scanf("%d%d%d",&u[i],&v[i],&c[i]),b[i]=c[i];
    for(tot=0,cur=0,i=1;i<=n;i++) he[i]=-1,vis[cur][i]=(i==1);
    sort(b,b+m),k=unique(b,b+m)-b,b[k]=b[k-1]+n+1;
    if(b[0]!=0) { printf("Impossible\n"); return 0; }
    // cur.reset(),cur.set(1);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            ma[0][i][j]=b[k];
    for(i=0;i<m;i++) ma[0][u[i]][v[i]]=min(ma[0][u[i]][v[i]],c[i]);
    for(t=1;(1ll<<t)<=b[k];t++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                for(ma[t][i][j]=b[k],l=1;l<=n;l++)
                    ma[t][i][j]=min(ma[t][i][j],max(ma[t-1][i][l],ma[t-1][l][j]));
    for(i=0;i<k;i++)
    {
        for(j=0;j<m;j++)
            if(c[j]==b[i])
                add_edge(v[j],u[j]);
        bfs(),minn=b[i+1]-b[i]+1;
        for(j=1;j<=n;j++)
            if(/*cur[j]*/vis[cur][j])
                minn=min(minn,dis[j]);
        if(minn<=b[i+1]-b[i]) { printf("%d\n",b[i]+minn); return 0; }
        // for(j=1;j<=n;j++) ma[j].reset();
        // for(j=0;j<m;j++)
        //     if(c[j]<=b[i])
        //         ma[v[j]][u[j]]=1;
        // for(t=b[i+1]-b[i];t;)
        // {
        //     if(t&1)
        //     {
        //         temp[0].reset();
        //         for(j=1;j<=n;j++)
        //             temp[0][j]=(ma[j]&cur).any();
        //         cur=temp[0];
        //     }
        //     if(t>>=1)
        //     {
        //         for(j=1;j<=n;j++) maT[j].reset();
        //         for(j=1;j<=n;j++)
        //             for(l=1;l<=n;l++)
        //                 maT[j][l]=ma[l][j];
        //         for(j=1;j<=n;j++)
        //             for(l=1;l<=n;l++)
        //                 temp[j][l]=(maT[l]&ma[j]).any();
        //         for(j=1;j<=n;j++) ma[j]=temp[j];
        //     }
        // }
        for(t=0;(1ll<<t)<=b[i+1]-b[i];t++)
            if(((b[i+1]-b[i])>>t)&1)
                for(cur^=1,j=1;j<=n;j++)
                    for(vis[cur][j]=0,l=1;l<=n;l++)
                        vis[cur][j]|=vis[cur^1][l]&&(ma[t][l][j]<=b[i]);
    }
    printf("Impossible\n");
    return 0;
}