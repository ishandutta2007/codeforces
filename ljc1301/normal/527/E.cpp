#include <bits/stdc++.h>
using namespace std;
// 2|d[u], 2|E
const int maxn=100005;
const int maxm=200005+maxn;
int n,m,he[maxn],ne[maxm<<1],to[maxm<<1],tot,d[maxn],sta[maxm];
bool vis[maxm<<1];
inline void add_edge(int u,int v) { to[tot]=v,ne[tot]=he[u],he[u]=tot++; }
void dfs(int u)
{
    for(int &i=he[u];~i;i=(~i)?ne[i]:i)
        if(!vis[i])
            vis[i]=vis[i^1]=1,dfs(to[i]);
    sta[tot++]=u;
}
int main()
{
    int i,u,v;
    scanf("%d%d",&n,&m);
    for(tot=0,i=1;i<=n;i++) he[i]=-1,d[i]=0;
    for(i=0;i<m;i++) scanf("%d%d",&u,&v),d[u]++,d[v]++,add_edge(u,v),add_edge(v,u);
    for(i=1,u=0;i<=n;i++)
        if(d[i]&1)
        {
            if(u) add_edge(u,i),add_edge(i,u),m++,u=0;
            else u=i;
        }
    if(m&1) m++,add_edge(1,1),add_edge(1,1);
    printf("%d\n",m);
    for(i=0;i<(m<<1);i++) vis[i]=0;
    tot=0,dfs(1);
    for(i=0;i<m;i+=2)
        printf("%d %d\n",sta[i],sta[i+1]),printf("%d %d\n",sta[i+2],sta[i+1]);
    return 0;
}