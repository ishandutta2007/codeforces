#include <bits/stdc++.h>
using namespace std;
const int maxn=800005;
const int maxm=2000005;
int n,p,M,m,nodes,he[maxn<<1],ne[maxm<<1],to[maxm<<1],tote;
int clk,dfn[maxn<<1],low[maxn<<1],sc[maxn<<1],cnt;
int sta[maxn<<1],top;
bool ins[maxn<<1];
inline void add_edge(int u,int v)
{
    assert(u<(nodes<<1)),assert(v<(nodes<<1));
    // printf("%d %d\n",u,v);
    ne[tote]=he[u];
    to[tote]=v;
    he[u]=tote++;
}
void dfs(int u)
{
    int i;
    dfn[u]=low[u]=clk++,sta[++top]=u,ins[u]=1;
    for(i=he[u];i!=-1;i=ne[i])
        if(dfn[to[i]]==-1)
            dfs(to[i]),low[u]=min(low[u],low[to[i]]);
        else if(ins[to[i]])
            low[u]=min(low[u],dfn[to[i]]);
    if(low[u]==dfn[u])
    {
        do
        {
            sc[sta[top]]=cnt;
            ins[sta[top]]=0;
            top--;
        }while(sta[top+1]!=u);
        cnt++;
    }
}
int main()
{
    int i,u,v,ans=0,l,r;
    scanf("%d%d%d%d",&n,&p,&M,&m),M+=2,nodes=p+M;
    for(i=0,tote=0;i<(nodes<<1);i++) he[i]=-1,dfn[i]=-1,ins[i]=0;
    for(i=p+1;i<p+M;i++)
    {
        add_edge((i-1)<<1,i<<1);
        add_edge((i<<1)|1,((i-1)<<1)|1);
    }
    while(n--)
    {
        scanf("%d%d",&u,&v),u--,v--;
        add_edge(u<<1,(v<<1)|1);
        add_edge(v<<1,(u<<1)|1);
    }
    for(i=0;i<p;i++)
    {
        scanf("%d%d",&l,&r);
        add_edge((i<<1)|1,((p+l-1)<<1)|1);
        add_edge((p+l-1)<<1,i<<1);
        add_edge((i<<1)|1,(r+p)<<1);
        add_edge(((r+p)<<1)|1,i<<1);
    }
    while(m--)
    {
        scanf("%d%d",&u,&v),u--,v--;
        add_edge((u<<1)|1,v<<1);
        add_edge((v<<1)|1,u<<1);
    }
    for(i=0,cnt=0,clk=0,top=-1;i<(nodes<<1);i++)
        if(dfn[i]==-1)
            dfs(i);
    for(u=0;u<(nodes<<1);u++)
        for(i=he[u];~i;i=ne[i])
            assert(sc[u]>=sc[to[i]]);
    for(i=0;i<(nodes<<1);i+=2)
        if(sc[i]==sc[i|1])
        {
            printf("-1\n");
            return 0;
        }
    for(i=0;i<(p<<1);i+=2)
        ans+=sc[i|1]<sc[i];
    // for(i=(p<<1);i<(nodes<<1);i+=2)
    //     printf("%s%d ",(sc[i|1]<sc[i])?">":"",i/2-p);
    // printf("\n");
    for(i=(nodes<<1)-2;i>=(p<<1);i-=2)
        if(sc[i|1]<sc[i])
            break;
    printf("%d %d\n",ans,i/2-p+1);
    for(i=0;i<(p<<1);i+=2)
        if(sc[i|1]<sc[i])
            printf("%d ",i/2+1);
    printf("\n");
    return 0;
}