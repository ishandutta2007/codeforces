#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
const int maxm=100005;
const int maxv=10*maxn;
const int maxe=4*maxm+(maxn<<5);
int n,L,R,l[maxn],r[maxn],b[maxn<<1],k,he[maxv],ne[maxe],to[maxe],tot;
int cnt,sta[maxv],top,clk,dfn[maxv],low[maxv],sc[maxv];
bool ins[maxv];
inline void add_edge(int u,int v) { to[tot]=v,ne[tot]=he[u],he[u]=tot++; }
inline void add_2edge(int u,int v) { add_edge(u,v),add_edge(v^1,u^1); }
void dfs(int u)
{
    int i;
    dfn[u]=low[u]=clk++,sta[++top]=u,ins[u]=1;
    for(i=he[u];~i;i=ne[i])
        if(dfn[to[i]]==-1) dfs(to[i]),low[u]=min(low[u],low[to[i]]);
        else if(ins[to[i]]) low[u]=min(low[u],dfn[to[i]]);
    if(dfn[u]==low[u])
    {
        while(sta[top]!=u) sc[sta[top]]=cnt,ins[sta[top]]=0,top--;
        sc[u]=cnt++,ins[u]=0,top--;
    }
}
int main()
{
    int m,i,u,v;
    scanf("%d%d%d%d",&L,&R,&n,&m);
    for(k=1,tot=0,i=0;i<n;i++) scanf("%d%d",&l[i],&r[i]),r[i]=min(r[i],R),b[k++]=l[i]-1,b[k++]=r[i],he[i<<1]=he[(i<<1)|1]=-1;
    while(m--) scanf("%d%d",&u,&v),u--,v--,add_2edge(u<<1,(v<<1)|1),add_2edge((u<<1)|1,v<<1);
    b[k++]=-1,b[k++]=R,sort(b,b+k),k=unique(b,b+k)-b;
    for(i=0;i<k;i++) // n+i: |S_1|<=b[i]?; n+i+k: |S_2|<=b[i]?
        he[(i+n)<<1]=he[((i+n)<<1)|1]=he[(i+n+k)<<1]=he[((i+n+k)<<1)|1]=-1;
    for(i=0;i<k;i++)
    {
        // >=L; |S1|<=b[i] => |S2|>=L-b[i] => |S2|>L-b[i]-1
        if(L>b[i])
        {
            u=upper_bound(b,b+k,L-b[i]-1)-b-1;
            add_2edge(((i+n)<<1)|1,(u+n+k)<<1),add_2edge(((i+n+k)<<1)|1,(u+n)<<1);
        }
        // <=R; |S1|>b[i] => |S2|<=R-b[i]-1
        u=lower_bound(b,b+k,R-b[i]-1)-b;
        add_2edge((i+n)<<1,((u+n+k)<<1)|1),add_2edge((u+n)<<1,((i+n+k)<<1)|1);
    }
    add_edge((n<<1)|1,n<<1),add_edge(((n+k)<<1)|1,(n+k)<<1);
    add_edge((n+k-1)<<1,((n+k-1)<<1)|1),add_edge((n+(k<<1)-1)<<1,((n+(k<<1)-1)<<1)|1);
    for(i=1;i<k;i++)
        add_2edge(((i-1+n)<<1)|1,((i+n)<<1)|1),add_2edge(((i-1+n+k)<<1)|1,((i+n+k)<<1)|1);
    for(i=0;i<n;i++)
    {
        u=lower_bound(b,b+k,l[i]-1)-b;
        add_2edge(i<<1,(u+n)<<1),add_2edge((i<<1)|1,(u+n+k)<<1);
        u=lower_bound(b,b+k,r[i])-b;
        add_2edge(i<<1,((u+n)<<1)|1),add_2edge((i<<1)|1,((u+n+k)<<1)|1);
    }
    for(i=0;i<(n<<1)+(k<<2);i++) dfn[i]=-1,ins[i]=0;
    for(i=0,cnt=clk=0;i<(n<<1)+(k<<2);i++)
        if(dfn[i]==-1)
            top=-1,dfs(i);
    // for(i=0;i<(n<<1)+(k<<2);i++) printf("%d ",sc[i]); printf("\n");
    for(i=0;i<n+(k<<1);i++)
        if(sc[i<<1]==sc[(i<<1)|1])
        {
            printf("IMPOSSIBLE\n");
            return 0;
        }
    printf("POSSIBLE\n");
    // for(i=0;i<k;i++) printf("%d ",b[i]); printf("\n");
    // for(i=0;i<n;i++) printf("%d",(sc[i<<1]<sc[(i<<1)|1])?1:2); printf("\n");
    // for(i=0;i<k;i++) printf("%c","<>"[sc[((i+n)<<1)|1]<sc[(i+n)<<1]]); printf("\n");
    // for(i=0;i<k;i++) printf("%c","<>"[sc[((i+n+k)<<1)|1]<sc[(i+n+k)<<1]]); printf("\n");
    for(u=0;u<k;u++)
        if(sc[(u+n)<<1]>sc[((u+n)<<1)|1])
            break;
    for(v=0;v<k;v++)
        if(sc[(v+n+k)<<1]>sc[((v+n+k)<<1)|1])
            break;
    if(L<=b[u-1]+1+b[v] && b[u-1]+1+b[v]<=R)
        printf("%d %d\n",b[u-1]+1,b[v]);
    else if(b[u-1]+1+b[v]<L)
        printf("%d %d\n",L-b[v],b[v]);
    else printf("%d %d\n",b[u-1]+1,R-b[u-1]-1);
    for(i=0;i<n;i++) printf("%d",(sc[i<<1]<sc[(i<<1)|1])?1:2);
    printf("\n");
    return 0;
}