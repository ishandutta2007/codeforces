#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a;i<=b;++i)
typedef long long ll;
using namespace std;
const int maxn=3e5+10;

struct Segment_Tree
{
    #define mid ((l+r)>>1)
    #define lc (rt<<1)
    #define rc (rt<<1|1)
    #define lson lc,l,mid
    #define rson rc,mid+1,r
    ll sum[maxn<<2],tag[maxn<<2];
    inline void pushdown(int rt,int l,int r){
        sum[lc]+=tag[rt]*(mid-l+1);tag[lc]+=tag[rt];
        sum[rc]+=tag[rt]*(r-mid);  tag[rc]+=tag[rt];
        tag[rt]=0;
    }
    void update(int rt,int l,int r,int L,int R,ll x){
        if(L<=l && r<=R){
            sum[rt]+=(r-l+1)*x;
            tag[rt]+=x;
            return;
        }
        if(tag[rt])pushdown(rt,l,r);
        if(L<=mid)update(lson,L,R,x);
        if(R>=mid+1)update(rson,L,R,x);
        sum[rt]=sum[lc]+sum[rc];
    }
    ll query(int rt,int l,int r,int L,int R){
        if(L<=l && r<=R)return sum[rt];
        ll ret=0ll;
        if(tag[rt])pushdown(rt,l,r);
        if(L<=mid)ret+=query(lson,L,R);
        if(R>=mid+1)ret+=query(rson,L,R);
        return ret;
    }
}T;

int n,q,root,w[maxn],cnt;
int to[maxn<<1],last[maxn<<1],beg[maxn],cnte;
int fa[maxn],son[maxn],top[maxn],siz[maxn],dep[maxn],cnt_dfn,dfn[maxn];

void add(int u,int v){
    last[++cnte]=beg[u];
    beg[u]=cnte;
    to[cnte]=v;
}

void dfs1(int u,int f){
    fa[u]=f;
    siz[u]=1;
    dep[u]=dep[f]+1;
    for(int i=beg[u];i;i=last[i]){
        if(to[i]==f)continue;
        dfs1(to[i],u);
        siz[u]+=siz[to[i]];
        if(siz[to[i]]>siz[son[u]])
            son[u]=to[i];
    }
}

void dfs2(int u,int t){
    dfn[u]=++cnt_dfn;
    top[u]=t;
    if(son[u])dfs2(son[u],t);
    for(int i=beg[u];i;i=last[i]){
        if(to[i]==fa[u] || to[i]==son[u])continue;
        dfs2(to[i],to[i]);
    }
}

inline int find(int u,int v){
    while(top[u]!=top[v]){
        ++cnt;
        if(dep[top[u]]<dep[top[v]])swap(u,v);
        u=fa[top[u]];
    }
    return dep[u]<dep[v] ? u : v;
}

int change(int u){
    int v=root;
    while(top[v]!=top[u]){
        if(fa[top[v]]==u)return top[v];
        v=fa[top[v]];
    }
    return son[u];
}

void init(){
    scanf("%d%d",&n,&q);
    root=1;
    REP(i,1,n) scanf("%d",&w[i]);
    REP(i,1,n-1){
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);
        add(v,u);
    }
    dfs1(1,0);
    dfs2(1,1);
    REP(i,1,n)T.update(1,1,n,dfn[i],dfn[i],w[i]);
}

int main()
{
    init();
    REP(i,1,q)
    {
        int ty,u,v;
        ll x;
        scanf("%d",&ty);
        if(ty==1){
            scanf("%d",&u);
            root=u;
        }
        else if(ty==2){
            scanf("%d%d%I64d",&u,&v,&x);
            int lca=find(u,v),tmp;
            if(dep[tmp=find(u,root)]>dep[lca])lca=tmp;
            if(dep[tmp=find(v,root)]>dep[lca])lca=tmp;
            if(lca==root)T.update(1,1,n,1,n,x);
            else if(dfn[root]<dfn[lca] || dfn[root]>dfn[lca]+siz[lca]-1)
                T.update(1,1,n,dfn[lca],dfn[lca]+siz[lca]-1,x);
            else{
                lca=change(lca);
                T.update(1,1,n,1,n,x);
                T.update(1,1,n,dfn[lca],dfn[lca]+siz[lca]-1,-x);
            }
        }
        else{
            ll sum=0;
            scanf("%d",&u);
            if(u==root)sum=T.query(1,1,n,1,n);
            else if(dfn[root]<dfn[u] || dfn[root]>dfn[u]+siz[u]-1)
                sum=T.query(1,1,n,dfn[u],dfn[u]+siz[u]-1);
            else{
                u=change(u);
                sum+=T.query(1,1,n,1,n);
                sum-=T.query(1,1,n,dfn[u],dfn[u]+siz[u]-1);
            }
            printf("%I64d\n",sum);
        }
    }
    return 0;
}