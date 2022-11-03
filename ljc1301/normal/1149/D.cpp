#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=0x3fffffffffffffffll;
const int maxn=75;
const int maxm=205;
const int maxcnt=17;
struct node
{
    ll dis; int s,u;
    node(ll d=0,int s=0,int u=0):dis(d),s(s),u(u) { }
    inline bool operator <(const node &p) const { return dis>p.dis; }
}temp;
int n,fa[maxn],id[maxn],re[maxcnt],he[maxn],ne[maxm<<1],to[maxm<<1],tot,cnt[maxn];
ll a,b/*,G[maxn][maxn]*/,/*dis[maxn],*/f[(1<<maxcnt)|1][maxn],val[maxm<<1];
bool vis[maxn];
priority_queue<node> que;
int father(int x) { return (fa[x]==x)?x:(fa[x]=father(fa[x])); }
inline void add_edge(int u,int v,ll c) { to[tot]=v,val[tot]=c,ne[tot]=he[u],he[u]=tot++; }
int main()
{
    int m,u,v,i,j,k;
    ll c;
    scanf("%d%d%lld%lld",&n,&m,&a,&b);
    // for(i=1;i<=n;i++)
    //     for(j=1;j<=n;j++)
    //         G[i][j]=inf;
    for(i=1,tot=0;i<=n;i++) fa[i]=i,vis[i]=0/*,dis[i]=(i==1)?0:inf*/,he[i]=-1,cnt[i]=0;
    while(m--)
    {
        scanf("%d%d%lld",&u,&v,&c);
        if(c==a) fa[father(u)]=father(v);
        // G[u][v]=G[v][u]=min(G[u][v],c);
        add_edge(u,v,c),add_edge(v,u,c);
    }
    for(i=1;i<=n;i++) father(i),cnt[fa[i]]++;
    for(i=1,tot=0;i<=n;i++)
        if(fa[i]==i)
        {
            if(cnt[i]>=4) re[tot]=i,id[i]=tot++;
            else id[i]=-1;
        }
    for(i=1;i<=n;i++)
        if(fa[i]!=i)
            id[i]=id[fa[i]];
    for(i=1;i<=n;i++)
        if(id[i]==-1) id[i]=0;
        else id[i]=1<<id[i];
    // for(i=1;i<=n;i++)
    //     for(j=1;j<=n;j++)
    //         if(father(i)==father(j) && G[i][j]==b)
    //             G[i][j]=inf;
    // for(i=1;i<=n;i++)
    // {
    //     k=-1;
    //     for(j=1;j<=n;j++)
    //         if(!vis[j] && (k==-1 || dis[k]>dis[j]))
    //             k=j;
    //     vis[k]=1;
    //     for(j=1;j<=n;j++)
    //         dis[j]=min(dis[j],dis[k]+G[k][j]);
    // }
    // for(i=1;i<=n;i++) printf("%lld ",dis[i]);
    // printf("\n");
    while(!que.empty()) que.pop();
    for(i=1;i<=n;i++)
        for(j=0;j<(1<<tot);j++)
            f[j][i]=inf;
    que.push(node(f[/*(id[1]==-1)?0:1<<id[1]*/id[1]][1]=0,/*(id[1]==-1)?0:1<<id[1]*/id[1],1));
    while(!que.empty())
    {
        temp=que.top(),que.pop();
        if(temp.dis!=f[temp.s][temp.u]) continue;
        // printf("%lld %d %d\n",temp.dis,temp.s,temp.u);
        for(i=he[temp.u];~i;i=ne[i])
        {
            if(/*id[to[i]]!=-1 && ((temp.s>>id[to[i]])&1)*/(id[to[i]]&temp.s) && val[i]==b) continue;
            if(val[i]==b && fa[temp.u]==fa[to[i]]) continue;
            if(temp.dis+val[i]<f[temp.s|id[to[i]]][to[i]])
                que.push(node(f[temp.s|id[to[i]]][to[i]]=temp.dis+val[i],temp.s|id[to[i]],to[i]));
        }
    }
    for(i=1;i<=n;i++)
    {
        for(c=inf,j=0;j<(1<<tot);j++)
            c=min(c,f[j][i]);
        printf("%lld ",c);
    }
    printf("\n");
    return 0;
}