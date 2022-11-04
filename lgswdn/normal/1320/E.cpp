#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;
typedef unsigned long long ull;
typedef bitset<509> bset;
typedef pair<bset,bset> v2;

long long read() {
    long long res=0, w=1; char c=getchar();
    while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
    while(isdigit(c)) {res=res*10+c-48, c=getchar();}
    return res*w;
}

const int N=2e5+9;
int n,q,fa[N][29],dep[N],dfn[N],tick,b[N],k,m,s[N],st[N],top,vst[N];
vi e[N],use;
vp t[N],a;

int lca(int u,int v) {
    if(dep[u]<dep[v]) swap(u,v);
    per(h,20,0) if(dep[fa[u][h]]>=dep[v]) u=fa[u][h];
    per(h,20,0) if(fa[u][h]!=fa[v][h]) u=fa[u][h], v=fa[v][h];
    return u==v?u:fa[u][0];
}
void dfs0(int u,int faa) {
    fa[u][0]=faa, dep[u]=dep[faa]+1, dfn[u]=++tick;;
    rep(h,1,20) fa[u][h]=fa[fa[u][h-1]][h-1];
    for(auto v:e[u]) if(v!=faa) {
        dfs0(v,u);
    }
}
void add(int u,int v) {
    int w=dep[v]-dep[u];
    t[u].emplace_back(pii(v,w));
    t[v].emplace_back(pii(u,w));
    //cout<<"ADDE "<<u<<" "<<v<<endl;
}
void ins(int x) {
    st[++top]=x; use.emplace_back(x);
}
void build() {
    top=1; st[1]=1; use.emplace_back(1);
    vp aa=a; sort(aa.begin(),aa.end());
    for(auto p:aa) {
        int x=p.se; if(x==1) continue;
        int y=lca(x,st[top]);
        if(y==st[top]) ins(x);
        else {
            while(top>1&&dep[st[top-1]]>dep[y]) add(st[top-1],st[top]), top--;
            add(y,st[top]), top--;
            if(st[top]!=y) ins(y); ins(x);
        }
    }
    while(top>1) add(st[top-1],st[top]), top--;
}
struct node {
    int t,d,f;
    node(int _t=0,int _d=0,int _f=0) {t=_t, d=_d, f=_f;}
} d[N];
node operator + (node a,int w) {
    if(a.d+w<=s[a.f]) return node(a.t,a.d+w,a.f);
    else return node(a.t+(a.d+w-1)/s[a.f],a.d+w-(a.d+w-1)/s[a.f]*s[a.f],a.f);
}
bool operator < (node a,node b) {
    if(a.t!=b.t) return a.t>b.t;
    else if(a.f!=b.f) return a.f>b.f;
    else return a.d>b.d;
}
void work() {
    priority_queue<pair<node,int> >q;
    rep(i,0,k-1) q.push(make_pair(d[a[i].se]=node(0,s[i+1],i+1),a[i].se));
    while(!q.empty()) {
        auto pp=q.top(); q.pop(); int u=pp.se;
        //cout<<"UPD "<<u<<" "<<d[u].t<<" "<<d[u].f<<" "<<d[u].d<<" "<<s[u]<<endl;
        if(vst[u]) continue; vst[u]=1;
        for(auto ed:t[u]) {
            int v=ed.fi, w=ed.se;
            if(d[v]<d[u]+w) d[v]=d[u]+w, q.push(make_pair(d[v],v));
        }
    }
    rep(i,k,k+m-1) printf("%lld ",d[a[i].se].f); puts("");
}

signed main() {
    n=read();
    rep(i,2,n) {
        int u=read(), v=read();
        e[u].emplace_back(v), e[v].emplace_back(u);
    }
    dfs0(1,0);
    q=read();
    rep(i,1,n) d[i]=node(n+1,0,0);
    while(q--) {
        k=read(), m=read();
        a.resize(k+m);
        rep(i,0,k-1) {
            a[i].se=read(), s[i+1]=read(), a[i].fi=dfn[a[i].se];
            b[a[i].se]=1;
        }

        rep(i,k,k+m-1) {
            a[i].se=read(), a[i].fi=dfn[a[i].se];
            b[a[i].se]=2;
        }
        build();
        work();
        for(auto x:use) {
            t[x].clear(), t[x].shrink_to_fit();
            b[x]=vst[x]=0;
            d[x]=node(n+1,n+1,0);
        }
        use.clear(); use.shrink_to_fit();
    }
    return 0;
}