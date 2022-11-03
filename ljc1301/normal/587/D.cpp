#include <bits/stdc++.h>
using namespace std;
// choose or not choose 2-sat
const int maxm=50005;
const int maxn=50005;
const int maxnode=maxm*6;
const int maxe=maxn*4+maxm*12;
int n,m,k,tote,tote_,totv,he_[maxnode],he[maxnode],ne[maxe],to[maxe],t[maxm],b[maxm],pre[maxn];
int dfn[maxnode],low[maxnode],clk,sc[maxnode],cnt,sta[maxnode],top;
bool ins[maxnode];
map<int,int> G[maxn];
bool vis[maxn];
inline void add_edge(int u,int v) { to[tote]=v,ne[tote]=he[u],he[u]=tote++; }
inline bool add_edge(int u,int c,int id)
{
    int t;
    if(G[u].count(c))
    {
        if(vis[u]) return false;
        vis[u]=1; t=G[u][c];
        add_edge(t<<1,(id<<1)|1),add_edge((id<<1)|1,t<<1);
        add_edge((t<<1)|1,id<<1),add_edge(id<<1,(t<<1)|1);
    }
    else G[u][c]=id;
    if(pre[u]==-1) pre[u]=id;
    else
    {
        t=pre[u];
        add_edge((t<<1)|1,id<<1),add_edge((id<<1)|1,t<<1);
        pre[u]=totv++,he[pre[u]<<1]=he[(pre[u]<<1)|1]=-1;
        add_edge((id<<1)|1,(pre[u]<<1)|1),add_edge(pre[u]<<1,id<<1);
        add_edge((t<<1)|1,(pre[u]<<1)|1),add_edge(pre[u]<<1,t<<1);
    }
    return true;
}
void dfs(int u)
{
    int i;
    dfn[u]=low[u]=clk++,sta[++top]=u,ins[u]=1;
    for(i=he[u];~i;i=ne[i])
        if(dfn[to[i]]==-1)
            dfs(to[i]),low[u]=min(low[u],low[to[i]]);
        else if(ins[to[i]]) low[u]=min(low[u],dfn[to[i]]);
    if(low[u]==dfn[u])
    {
        while(sta[top]!=u) sc[sta[top]]=cnt,ins[sta[top]]=0,top--;
        sc[u]=cnt,ins[u]=0,top--;
        cnt++;
    }
}
inline bool check(int k)
{
    int i;
    for(i=0,tote=tote_;i<(totv<<1);i++) he[i]=he_[i],dfn[i]=-1,ins[i]=0,sc[i]=-1;
    for(i=0;i<m;i++)
        if(t[i]>b[k])
            add_edge((i<<1)|1,i<<1);
    for(clk=cnt=0,top=-1,i=0;i<(totv<<1);i++)
        if(dfn[i]==-1)
            dfs(i);
    for(i=0;i<totv;i++)
        if(sc[i<<1]==sc[(i<<1)|1])
            return false;
    return true;
}
int main()
{
    int i,u,v,c,l,r,mid;
    scanf("%d%d",&n,&m);
    for(i=0,tote=0;i<(m<<1);i++) he[i]=-1; totv=m;
    for(i=1;i<=n;i++) G[i].clear(),vis[i]=0,pre[i]=-1;
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d%d",&u,&v,&c,&t[i]),b[i]=t[i];
        if(!add_edge(u,c,i) || !add_edge(v,c,i)) { printf("No\n"); return 0; }
    }
    for(tote_=tote,i=0;i<(totv<<1);i++) he_[i]=he[i];
    b[m]=0,sort(b,b+m+1),k=unique(b,b+m+1)-b;
    l=0,r=k;
    while(l<r)
    {
        mid=(l+r)>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    if(l==k) { printf("No\n"); return 0; }
    printf("Yes\n"),check(l);
    for(c=0,i=0;i<m;i++)
        c+=(sc[(i<<1)|1]<sc[i<<1]);
    printf("%d %d\n",b[l],c);
    for(i=0;i<m;i++)
        if(sc[(i<<1)|1]<sc[i<<1])
            printf("%d ",i+1);
    printf("\n");
    return 0;
}