//  thinking: ~20min
// a+b>=k  #(a>=i, b>=k-i)-#(a>=i, b>=k-i-1) (a=i)
//   writing: 34min + 45min
// debugging: 58min(wa,ub) + 4min
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn0=150005;
const int maxn=maxn0<<1;
const int maxm=150005;
const int maxlog=19;
struct node
{
    int u,v,h;
    node() { }
    node(int u,int v,int h):u(u),v(v),h(h) { }
    inline bool operator <(const node &p) const { return h>p.h; }
}qs[2][maxm];
int n,m,k,he_[maxn0],ne_[maxn0<<1],to_[maxn0<<1],tot;
int he[maxn],ne[maxn<<1],to[maxn<<1],val[maxn<<1],sz[maxn],rt/*,rt_*/,hsz;
int dep[maxn],dep0[maxn],f[maxn],fa[maxlog][maxn],logn,dfn[maxn],clk;
int s[maxm],t[maxm],s_[maxm],t_[maxm],did[maxm],F[2][maxm],pos[maxm];
vector<int> id[2][maxm];
ll ans;
map<pii,int> cnt;
bool vis[maxn],col[maxn];
inline void add_edge(int u,int v) { to_[tot]=v,ne_[tot]=he_[u],he_[u]=tot++; }
inline void add_edge(int u,int v,int c)
{
    to[tot]=v,ne[tot]=he[u],val[tot]=c,he[u]=tot++;
#ifdef DEBUG
    if(tot&1) printf("%d-%d %d\n",u,v,c);
#endif
}
void prework(int u,int fa)
{
    int i,x=-1,y=-1,xc=0,yc=0;
#ifdef DEBUG
    // printf("%d\n",u);
#endif
    for(i=he_[u];~i;i=ne_[i])
        if(to_[i]!=fa)
        {
            prework(to_[i],u);
#ifdef DEBUG
            // printf("%d %d\n",u,to_[i]);
#endif
            if(x==-1) x=to_[i],xc=1;
            else if(y==-1) y=to_[i],yc=1;
            else
            {
                he[++n]=-1,
                add_edge(n,x,xc),add_edge(x,n,xc),
                add_edge(n,y,yc),add_edge(y,n,yc),
                x=n,xc=0,y=to_[i],yc=1;
            }
        }
    if(x!=-1) add_edge(u,x,xc),add_edge(x,u,xc);
    if(y!=-1) add_edge(u,y,yc),add_edge(y,u,yc);
}
void findrt(int u,int /*fa*/pre)
{
    int i;
    sz[u]=1;
    for(i=he[u];~i;i=ne[i])
        if(!vis[i>>1] && /*to[i]!=fa*/(i^pre)!=1)
            findrt(to[i],/*u*/i),sz[u]+=sz[to[i]];
    if(hsz>max(sz[u],tot-sz[u])) hsz=max(sz[u],tot-sz[u]),/*rt=u,rt_=fa*/rt=pre;
}
void dfs(int u,bool c)
{
    int i;
    col[u]=c,f[u]=0,dfn[u]=clk++;
    for(i=1;i<=logn;i++)
        fa[i][u]=(fa[i-1][u]==-1)?-1:fa[i-1][fa[i-1][u]];
    for(i=he[u];~i;i=ne[i])
        if(to[i]!=fa[0][u] && !vis[i>>1])
            fa[0][to[i]]=u,dep[to[i]]=dep[u]+val[i],dep0[to[i]]=dep0[/*i*/u]+1,
            dfs(to[i],c);
}
inline int lca(int u,int v)
{
    int i;
#ifdef DEBUG
    // printf("query lca %d %d\n",u,v);
#endif
    if(dep0[u]<dep0[v]) swap(u,v);
    for(i=logn;i>=0;i--)
        if(dep0[u]-(1<<i)>=dep0[v])
            u=fa[i][u];
    if(u==v) return u;
    for(i=logn;i>=0;i--)
        if(fa[i][u]!=fa[i][v])
            u=fa[i][u],v=fa[i][v];
    return fa[0][u];
}
inline void ins(int u,int v)
{
    if(dep[v]-dep[u]<k) return;
    int i;
    swap(u,v);
    for(i=logn;i>=0;i--)
        if(fa[i][u]!=-1 && dep[fa[i][u]]-dep[v]>=k)
            u=fa[i][u];
    f[u]++;
}
void dfs(int u)
{
    int i;
    for(i=he[u];~i;i=ne[i])
        if(to[i]!=fa[0][u] && !vis[i>>1])
            f[to[i]]+=f[u],dfs(to[i]);
}
// template<int *dfn>
// inline bool cmp(int a,int b) { return dfn[a]<dfn[b]; }
template<int *u>
inline bool cmp(int a,int b) { return dfn[u[a]]<dfn[u[b]]; }
void solve(/*int u,int v*/int e,int l,int r)
{
    if(/*l>=r*/r-l<=1 || /*v*/e==-1) return;
    int u=to[e],v=to[e^1],i,j,p,q,x,y,w;
    vector<int>::iterator it;
    vis[e>>1]=1;
    for(logn=0;(2<<logn)<=tot;logn++);
    dep[u]=dep0[u]=0,fa[0][u]=-1,clk=0,dfs(u,0),
    dep[v]=dep0[v]=0,fa[0][v]=-1,clk=0,dfs(v,1);
#ifdef DEBUG
    printf("solve %d-%d(%d):\n",u,v,val[e]);
#endif
    for(p=l,i=l;i<r;i++)
        if(col[s[i]] && col[t[i]])
            x=lca(s[i],t[i]),ins(x,s[i]),ins(x,t[i]),s_[p]=s[i],t_[p++]=t[i];
    for(q=p,i=l;i<r;i++)
        if(!col[s[i]] && !col[t[i]])
            x=lca(s[i],t[i]),ins(x,s[i]),ins(x,t[i]),s_[/*p*/q]=s[i],t_[q++]=t[i];
    dfs(u),dfs(v);
    for(x=q,i=l;i<r;i++)
        if(col[s[i]]^col[t[i]])
        {
            if(col[s[i]]) swap(s[i],t[i]);
            did[x]=x,s_[x]=s[i],t_[x++]=t[i],
            ans+=f[s[i]]+f[t[i]];
        }
#ifdef DEBUG
    printf("   middle: %lld\n",ans);
#endif
    assert(x==r);
    if(x-q<=1) goto ttt;
    sort(did+q,did+r,cmp<s_>);
    for(x=0,i=q+1;i<r;i++)
        // qs[0][x++]=node(s_[did[i-1]],s_[did[i]],dep[lca(s_[did[i-1]],s_[did[i]])]);
        qs[0][x++]=node(did[i-1],did[i],dep[lca(s_[did[i-1]],s_[did[i]])]);
    sort(did+q,did+r,cmp<t_>);
    for(x=0,i=q+1;i<r;i++)
        // qs[1][x++]=node(t_[did[i-1]],t_[did[i]],dep[lca(t_[did[i-1]],t_[did[i]])]);
        qs[1][x++]=node(did[i-1],did[i],dep[lca(t_[did[i-1]],t_[did[i]])]);
#ifdef DEBUG
    for(i=q;i<r;i++) printf("%d: %d-%d; ",i,s_[i],t_[i]); printf("\n");
    for(i=0;i<x;i++) printf("%d-%d(%d-%d) %d; ",qs[0][i].u,qs[0][i].v,
        s_[qs[0][i].u],s_[qs[0][i].v],qs[0][i].h);
    printf("\n");
    for(i=0;i<x;i++) printf("%d-%d(%d-%d) %d; ",qs[1][i].u,qs[1][i].v,
        t_[qs[1][i].u],t_[qs[1][i].v],qs[1][i].h);
    printf("\n");
#endif
    sort(qs[0],qs[0]+x),sort(qs[1],qs[1]+x);
    for(i=q;i<r;i++) id[0][i].clear(),F[0][i]=F[1][i]=i,id[0][i].push_back(i);
    for(i=0;i<x;i++)
    {
#define u qs[0][i].u
#define v qs[0][i].v
        u=F[0][u],v=F[0][v];
        if(id[0][u].size()<id[0][v].size()) swap(u,v);
        /*u=F[0][u],v=F[0][v],*/pos[i]=(int)id[0][u].size();
        for(it=id[0][v].begin();it!=id[0][v].end();++it)
            F[0][*it]=u,id[0][u].push_back(*it);
        id[0][v].clear(),id[0][v].shrink_to_fit();
#undef u
#undef v
    }
    for(cnt.clear(),i=q;i<r;i++)
        cnt[make_pair(F[0][i],F[1][i])]+=1,id[1][i].clear(),id[1][i].push_back(i);
#ifdef DEBUG
    for(i=q;i<r;i++) printf("%d: %d,%d; ",i,F[0][i],F[1][i]); printf("\n");
#endif
    for(i=0,j=x;i<x;i++)
    {
        for(;j && qs[0][j-1].h+qs[1][i].h+val[e]/*>k*/<k;)
        {
            id[0][qs[0][/*j*/--j].v].clear();
            for(/*j--,*/y=pos[j];y<(int)id[0][qs[0][j].u].size();y++)
            {
                w=id[0][qs[0][j].u][/*j*/y];
                if(!(cnt[make_pair(F[0][w],F[1][w])]-=1))
                    cnt.erase(make_pair(F[0][w],F[1][w]));
                F[0][w]=qs[0][j].v,cnt[make_pair(F[0][w],F[1][w])]+=1,
                id[0][qs[0][j].v].push_back(w);
            }
            while((int)id[0][qs[0][j].u].size()>pos[j]) id[0][qs[0][j].u].pop_back();
        }
#define u qs[1][i].u
#define v qs[1][i].v
        u=F[1][u],v=F[1][v];
        if(id[1][u].size()<id[1][v].size()) swap(u,v);
        // u=F[1][u],v=F[1][v];
        for(it=id[1][v].begin();it!=id[1][v].end();++it)
            // ans+=cnt[make_pair(u,F[1][*it])],F[1][*it]=u,id[1][u].push_back(*it);
            ans+=cnt[make_pair(F[0][*it],/*v*/u)],F[1][*it]=u,id[1][u].push_back(*it);
        for(it=id[1][v].begin();it!=id[1][v].end();++it)
            // cnt.erase(make_pair(v,F[1][*it])),cnt[make_pair(u,F[1][*it])]+=1;
            cnt.erase(make_pair(F[0][*it],v)),cnt[make_pair(F[0][*it],u)]+=1;
        id[1][v].clear(),id[1][v].shrink_to_fit();
#ifdef DEBUG
        for(w=q;w<r;w++) printf("%d: %d,%d; ",w,F[0][w],F[1][w]);
        printf("ans = %lld\n",ans);
#endif
#undef u
#undef v
    }
ttt:
#ifdef DEBUG
    printf("    final: %lld\n",ans);
#endif
    for(i=l;i<q;i++) s[i]=s_[i],t[i]=t_[i];
    tot-=sz[u],hsz=tot+1,rt=-1,findrt(v,-1),solve(rt,l,p),
    tot=sz[u],hsz=tot+1,rt=-1,findrt(u,-1),solve(rt,p,q);
}
int main()
{
    int i,u,v;
    scanf("%d%d%d",&n,&m,&k);
    for(tot=0,i=1;i<=n;i++) he_[i]=he[i]=-1;
    for(i=1;i<n;i++) scanf("%d%d",&u,&v),add_edge(u,v),add_edge(v,u);
    tot=0/*,prework(u,1)*/,prework(1,-1);
    for(i=0;i<m;i++) scanf("%d%d",&s[i],&t[i]);
    for(i=0;i<tot;i+=2) vis[i>>1]=0;
    ans=0,tot=n,hsz=n+1,rt=/*rt_=*/-1,findrt(1,-1),solve(rt/*,rt_*/,0,m),printf("%lld\n",ans);
    return 0;
}