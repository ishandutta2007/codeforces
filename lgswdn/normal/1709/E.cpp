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
int n,a[N],b[N],d[N],sz[N],f[N];
vi e[N];
set<int>s[N];

void dfs1(int u,int fa) {
    sz[u]=1, d[u]=d[fa]=1, b[u]=b[fa]^a[u];
    for(auto v:e[u]) if(v!=fa) {
        dfs1(v,u);
        sz[u]+=sz[v];
    }
}
void dfs2(int u,int fa) {
    s[u].insert(b[u]);
    for(auto v:e[u]) if(v!=fa) {
        dfs2(v,u);
        if(s[u].size()<s[v].size()) swap(s[u],s[v]);
        for(auto x:s[v]) f[u]|=s[u].count(x^a[u]);
        for(auto x:s[v]) s[u].insert(x);
        s[v].clear();
    }
    if(f[u]) s[u].clear();
}

signed main() {
    n=read();
    rep(i,1,n) a[i]=read();
    rep(i,2,n) {
        int x=read(), y=read();
        e[x].emplace_back(y), e[y].emplace_back(x);
    }
    dfs1(1,0);
    dfs2(1,0);
    int ans=0;
    rep(i,1,n) ans+=f[i];
    printf("%lld\n",ans);
    return 0;
}