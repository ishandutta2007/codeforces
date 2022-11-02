//xtwakioi! xtwddYnoi()!
#include <bits/stdc++.h>
#define ri register
//#define int long long
#define mk make_pair
#define E (n+1)
using namespace std; const int N=400010;
inline int read()
{
    int s=0, w=1; ri char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar();
    return s*w;
}
int n,m,deg[N],mx,root,book[N],g[N],f[N],cnt;
struct Node { int u,v; }e[N];
vector<pair<int,int> > Q[N];
void DFS(int x,int fa)
{
    for(ri int i=0;i<(int)Q[x].size();i++)
    {
        int v=Q[x][i].first, gg=Q[x][i].second;
        if(book[gg] || g[v] || v==fa) continue;
        book[gg]=g[v]=1;
        DFS(v,x);
    }
}
signed main()
{
    n=read(), m=read();
    for(ri int i=1;i<=m;i++)
    {
        e[i].u=read(), e[i].v=read();
        Q[e[i].u].push_back(mk(e[i].v,i));
        Q[e[i].v].push_back(mk(e[i].u,i));
        deg[e[i].u]++, deg[e[i].v]++;
    }
    for(ri int i=1;i<=n;i++)
    {
        if(deg[i]>mx) root=i, mx=deg[i];
    }
    g[root]=1;
    for(ri int i=1;i<=m;i++)
    {
        if(e[i].u==root || e[i].v==root)
        {
            g[e[i].u]=g[e[i].v]=1;
            book[i]=1;
        }
    }
    for(ri int i=1;i<=n;i++) if(g[i]) f[++cnt]=i;
    for(ri int i=1;i<=cnt;i++)
    {
        DFS(f[i],root);
    }
    for(ri int i=1;i<=m;i++) if(book[i]) printf("%d %d\n",e[i].u,e[i].v);
    return 0;
}