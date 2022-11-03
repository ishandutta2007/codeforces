#include <bits/stdc++.h>
using namespace std;
#ifdef TEST
const int maxn=1005;
const int blosz=3;
#else
const int maxn=100005;
const int blosz=400;
#endif
const int maxcnt=maxn/blosz+10;
int n,cnt,he[maxn],to[maxn],ne[maxn],fa[maxn],totm,clk,dfn[maxn],sz[maxn],hson[maxn],top[maxn];
int t[maxn],tag[maxcnt],tot[maxcnt][maxn<<1],ans;
bool vis[maxn];
void dfs1(int u)
{
    int i;
    sz[u]=1,hson[u]=0;
    for(i=he[u];~i;i=ne[i])
    {
        dfs1(to[i]);
        sz[u]+=sz[to[i]];
        if(!hson[u] || sz[hson[u]]<sz[to[i]])
            hson[u]=to[i];
    }
}
void dfs2(int u,int t)
{
    dfn[u]=clk++,top[u]=t;
    if(!hson[u]) return;
    int i;
    dfs2(hson[u],t);
    for(i=he[u];~i;i=ne[i])
        if(to[i]!=hson[u])
            dfs2(to[i],to[i]);
}
inline void bf(int l,int r,int _)
{
    int i;
    for(i=l;i<=r;i++)
    {
        if(t[i]-tag[i/blosz]<0 && !vis[i]) ans--;
        if(!vis[i]) tot[i/blosz][t[i]+n]--;
        t[i]+=_;
        if(!vis[i]) tot[i/blosz][t[i]+n]++;
        if(t[i]-tag[i/blosz]<0 && !vis[i]) ans++;
    }
}
inline void update(int l,int r,int _)
{
    int i;
    if(l/blosz==r/blosz) return bf(l,r,_);
    bf(l,(l/blosz+1)*blosz-1,_),bf(r/blosz*blosz,r,_);
    for(i=l/blosz+1;i<r/blosz;i++)
        if(_==1)
        {
            ans-=tot[i][n+tag[i]-1];
            tag[i]--;
        }
        else
        {
            tag[i]++;
            ans+=tot[i][n+tag[i]-1];
        }
}
int main()
{
    int i,j,p,q,_;
    scanf("%d%d",&n,&q);
    for(i=1,totm=0;i<=n;i++) he[i]=-1,vis[i]=0;
    for(i=2,fa[1]=0;i<=n;i++) scanf("%d",&fa[i]),to[totm]=i,ne[totm]=he[fa[i]],he[fa[i]]=totm++;
    dfs1(1),clk=0,dfs2(1,1);
    for(i=1;i<=n;i++) scanf("%d",&t[dfn[i]]);
    cnt=(n-1)/blosz+1;
    for(i=0;i<cnt;i++) tag[i]=0;
    for(i=0;i<cnt;i++)
        for(j=0;j<=(n<<1);j++)
            tot[i][j]=0;
    for(i=0;i<n;i++) tot[i/blosz][n+t[i]]++;
    ans=0;
    while(q--)
    {
        scanf("%d",&p); _=(p>0)?1:-1,p=abs(p); vis[dfn[p]]^=1;
        if(t[dfn[p]]-tag[dfn[p]/blosz]<0) ans-=_;
        tot[dfn[p]/blosz][n+t[dfn[p]]]-=_;
        while(p)
        {
            update(dfn[top[p]],dfn[p],-_);
            p=fa[top[p]];
        }
        printf("%d ",ans);
    }
    printf("\n");
    return 0;
}