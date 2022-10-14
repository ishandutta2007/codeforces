#include<bits/stdc++.h>
#define int long long
using namespace std;
#define maxn 1010010
#define inf 333333333333333ll
int n,m,nume=1,dis[maxn],s,t,ans;
int head[maxn],to[maxn<<2],val[maxn<<2],nxt[maxn<<2];
void add(int a,int b,int c)
{
    nxt[++nume]=head[a];
    val[nume]=c;
    to[nume]=b;
    head[a]=nume;
}
bool bfs()
{
    queue<int>q;
    memset(dis,-1,sizeof(dis));
    q.push(s);
    dis[s]=0;
    while(!q.empty())
    {
        int p=q.front();
        q.pop();
        for(int i=head[p];i;i=nxt[i])
            if(val[i]>0&&dis[to[i]]==-1)
            {
                dis[to[i]]=dis[p]+1;
                q.push(to[i]);
                if(to[i]==t) return 1;
            }
    }
    return 0;
}
int dfs(int p,int flow)
{
    int now,gjy=flow;
    if(p==t)
        return flow;
    for(int i=head[p];i;i=nxt[i])
    {
        if(val[i]>0&&dis[to[i]]==dis[p]+1)
        {
            now=dfs(to[i],min(val[i],gjy));
            if(!now)dis[to[i]]=-1;
            gjy-=now;;val[i]-=now;
            val[i^1]+=now;
            if(!gjy) break;
        }
    }
    return flow-gjy;
}
void dinic()
{
    while(bfs()) ans-=dfs(s,inf);
}
signed main()
{
    scanf("%lld%lld",&n,&m);
    s=n+m+1;
    t=n+m+2;
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%lld",&a);
        add(i,t,a);
        add(t,i,0);
    }
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        ans+=c;
        add(s,i+n,c),add(i+n,s,0);
        add(i+n,b,inf),add(b,i+n,0);
        add(i+n,a,inf),add(a,i+n,0);
    }
    dinic();
    cout<<ans;
}