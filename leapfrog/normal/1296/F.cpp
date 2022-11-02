//xtwakioi! xtwddYnoi()!
#include <bits/stdc++.h>
#define ri register
//#define int long long
#define E (n+1)
using namespace std; const int N=5010;
inline int read()
{
    int s=0, w=1; ri char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar();
    return s*w;
}
int n,m,dis[N],flg,f[N],q[N],cnt,book[N][N];
int head[N],maxE; struct Edge { int nxt,to; }e[N<<1];
struct Node { int u,v,w; }g[N<<1];
struct TE { int u,v; }T[N<<1];
inline bool cp(Node x,Node y) { return x.w>y.w; }
inline void Add(int u,int v) { e[++maxE].nxt=head[u]; head[u]=maxE; e[maxE].to=v; }
void DFS(int x,int fa,int gl)
{
    if(flg) { return; } 
    for(int i=head[x];i;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v==gl)
        {
            q[++cnt]=v;
            flg=1;
            return;
        }
        if(v==fa) continue;
        cnt++;
        q[cnt]=v;
        DFS(v,x,gl);
        if(flg) { return; }
        cnt--;
    }
}
signed main()
{
    n=read();
    for(ri int i=1;i<n;i++)
    {
        int x,y;
        x=read(), y=read();
        Add(x,y), Add(y,x);
        T[i].u=x, T[i].v=y;
    }
    m=read();
    for(ri int i=1;i<=m;i++) g[i].u=read(), g[i].v=read(), g[i].w=read();
    sort(g+1,g+1+m,cp);
    for(ri int i=1;i<=m;i++)
    {
        flg=cnt=0;
        DFS(g[i].u,0,g[i].v);
        q[0]=g[i].u;
        flg=0;
        for(ri int j=1;j<=cnt;j++)
        {
            if(book[q[j-1]][q[j]]>g[i].w) continue;
            flg=1; book[q[j-1]][q[j]]=book[q[j]][q[j-1]]=g[i].w;
        }
        if(!flg) { puts("-1"); return 0; }
    }
    for(ri int i=1;i<n;i++) printf("%d ",max(book[T[i].u][T[i].v],1));
    puts("");
    return 0;
}