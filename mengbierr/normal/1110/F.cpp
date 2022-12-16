#include <cstdio>
#include <algorithm>
#include <vector>
#define lson p<<1
#define rson p<<1|1

const int N=5e5+5;
const long long INF=1LL<<60;
int n,m,tot,l[N],r[N],mx[N],lnk[N],ter[N],nxt[N],val[N];
long long seg[N<<2],tag[N<<2],dis[N],ans[N];
std::vector<int> q[N];

void pushup(int p) {
    seg[p]=std::min(seg[lson],seg[rson]);
}
void pushdown(int p) {
    if(!tag[p]) return;
    long long v=tag[p];
    seg[lson]+=v,tag[lson]+=v,seg[rson]+=v,tag[rson]+=v,tag[p]=0;
}
void modify(int x,int y,int p,int l,int r,long long v) {
    if(x<=l&&r<=y) {
        seg[p]+=v,tag[p]+=v;
        return;
    }
    pushdown(p);
    int mid=(l+r)>>1;
    if(x<=mid) modify(x,y,lson,l,mid,v);
    if(mid<y) modify(x,y,rson,mid+1,r,v);
    pushup(p);
}
long long query(int x,int y,int p,int l,int r) {
    if(x<=l&&r<=y) return seg[p];
    pushdown(p);
    int mid=(l+r)>>1;
    long long ans=INF;
    if(x<=mid) ans=std::min(ans,query(x,y,lson,l,mid));
    if(mid<y) ans=std::min(ans,query(x,y,rson,mid+1,r));
    return ans;
}
void add(int u,int v,int w) {
    ter[++tot]=v,nxt[tot]=lnk[u],lnk[u]=tot,val[tot]=w;
}
void dfs1(int u) {
    mx[u]=u;
    for(int i=lnk[u];i;i=nxt[i]) {
        int v=ter[i];
        dis[v]=dis[u]+val[i];
        dfs1(v);
        mx[u]=std::max(mx[u],mx[v]);
    }
}
void dfs2(int u) {
    for(int i:q[u]) ans[i]=query(l[i],r[i],1,1,n);
    for(int i=lnk[u];i;i=nxt[i]) {
        int v=ter[i],w=val[i];
        modify(1,n,1,1,n,w),modify(v,mx[v],1,1,n,-w-w);
        dfs2(v);
        modify(1,n,1,1,n,-w),modify(v,mx[v],1,1,n,w+w);
    }
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=2;i<=n;++i) {
        int p,w;
        scanf("%d%d",&p,&w),add(p,i,w);
    }
    dfs1(1);
    for(int i=1;i<=n;++i) {
        modify(i,i,1,1,n,i==mx[i]?dis[i]:INF);
    }
    for(int i=1;i<=m;++i) {
        int v;
        scanf("%d%d%d",&v,&l[i],&r[i]),q[v].push_back(i);
    }
    dfs2(1);
    for(int i=1;i<=m;++i) printf("%lld\n",ans[i]);
    return 0;
}