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

const int N=1e5+9;
int n,m,d[N],s[N],f[N],ss[N],r[N],ans,de[N],vst[N];
vi t[N],vans,eans;
vp e[N];
vector<pair<pii,int> > ed;

void dfs1(int u,int fa) {
    d[u]=d[fa]+1; vst[u]=1;
    for(auto ee:e[u]) if(ee.fi!=fa) {
        int v=ee.fi;
        if(d[v]) {
            ed.emplace_back(pii(v,u),ee.se);
        } else {
            dfs1(v,u);
            de[v]=ee.se;
            t[u].emplace_back(v);
        }
    }
}
void dfs2(int u) {
    vst[u]=1;
    for(auto v:t[u]) {
        dfs2(v);
        s[u]+=s[v];
    }
}
void dfs3(int u) {
    vst[u]=1;
    for(auto v:t[u]) {
        ss[v]=ss[u]+s[v];
        dfs3(v);
    }
}
void dfs4(int u) {
    vst[u]=1;
    for(auto v:t[u]) {
        dfs4(v);
        r[u]+=r[v];
    }
    if(s[u]==1&&r[u]==1) ans++, vans.emplace_back(u);
}

signed main() {
    n=read(), m=read();
    rep(i,1,m) {
        int u=read(), v=read();
        e[u].emplace_back(pii(v,i)), e[v].emplace_back(pii(u,i));
    }
    rep(i,1,n) vst[i]=0;
    rep(i,1,n) if(!vst[i]) dfs1(i,0);
    for(auto pp:ed) {
        int u=pp.fi.fi, v=pp.fi.se;
        if(d[u]>d[v]) continue;
        s[u]--, s[v]++;
    } 
    rep(i,1,n) vst[i]=0;
    rep(i,1,n) if(!vst[i]) dfs2(i);
    rep(i,1,n) vst[i]=0;
    rep(i,1,n) if(!vst[i]) dfs3(i);
    for(int i=0;i<ed.size();i++) {
        pii pp=ed[i].fi; int u=pp.fi, v=pp.se;
        if(d[u]<d[v]) continue;
        //cout<<u<<" "<<v<<" "<<ss[u]<<" "<<s[u]<<" "<<ss[v]<<" "<<s[v]<<" "<<d[u]-d[v]<<endl;
        if(ss[u]-ss[v]==d[u]-d[v]) f[i]=1;
        else f[i]=0;
        if(f[i]==1) {
            ans++, eans.emplace_back(ed[i].se);
            r[u]++, r[v]--;
        }
    }
    rep(i,1,n) vst[i]=0;
    rep(i,1,n) if(!vst[i]) dfs4(i);
    printf("%lld\n",ans);
    vi rans;
    for(auto x:vans) rans.emplace_back(de[x]);
    for(auto x:eans) rans.emplace_back(x);
    sort(rans.begin(),rans.end());
    for(auto x:rans) printf("%lld ",x);
    if(ans!=0) puts("");
    return 0;
}