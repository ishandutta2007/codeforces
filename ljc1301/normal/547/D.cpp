#include <bits/stdc++.h>
using namespace std;
// row/col make pairs and add edge
// must be some even rings(-|-|...) and chains => binary graph
const int maxn=200005;
const int maxx=200005;
const int maxm=maxn<<1;
int n,he[maxn],ne[maxm],to[maxm],tot,prex[maxx],prey[maxx],col[maxn];
inline void add_edge(int u,int v) { to[tot]=v,ne[tot]=he[u],he[u]=tot++; }
void dfs(int u)
{
    int i;
    for(i=he[u];~i;i=ne[i])
        if(col[to[i]]==-1)
            col[to[i]]=col[u]^1,dfs(to[i]);
}
int main()
{
    int i,x,y;
    scanf("%d",&n);
    for(i=0;i<maxx;i++) prex[i]=prey[i]=-1;
    for(tot=0,i=1;i<=n;i++)
    {
        scanf("%d%d",&x,&y);
        he[i]=-1,col[i]=-1;
        if(prex[x]==-1) prex[x]=i;
        else add_edge(prex[x],i),add_edge(i,prex[x]),prex[x]=-1;
        if(prey[y]==-1) prey[y]=i;
        else add_edge(prey[y],i),add_edge(i,prey[y]),prey[y]=-1;
    }
    for(i=1;i<=n;i++)
        if(col[i]==-1)
            col[i]=0,dfs(i);
    for(i=1;i<=n;i++) printf("%c",col[i]?'b':'r');
    printf("\n");
    return 0;
}