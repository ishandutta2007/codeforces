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

long long read() {
    long long res=0, w=1; char c=getchar();
    while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
    while(isdigit(c)) {res=res*10+c-48, c=getchar();}
    return res*w;
}

const int N=3e5+9;

int n,m,ans[N],b[N];

struct edge {int u,v,w,t;} e[N],t[N];
bool cmp(const edge&a, const edge &b) {return a.w<b.w;}

namespace DSU {
    int id[N],h[N],s[N],res,top;
    pair<pii,int> op[N<<5];
    int find(int x) {while(x!=id[x]) x=id[x]; return x;}
    void init() {rep(i,1,n) id[i]=i, h[i]=s[i]=1; res=n, top=0;}
    void merge(int x,int y) {
        x=find(x), y=find(y); if(x==y) return;
        if(h[x]<h[y]) swap(x,y); 
        op[++top]=make_pair(pii(x,y),h[x]==h[y]);
        id[y]=x, h[x]+=(h[x]==h[y]);
        res-=s[x]%2, res-=s[y]%2, s[x]+=s[y], res+=s[x]%2;
    }
    void undo(int bot) {
        while(top>bot) {
            auto p=op[top]; --top;
            int x=p.fi.fi, y=p.fi.se, z=p.se;
            id[y]=y, h[x]-=z;
            res-=s[x]%2, s[x]-=s[y], res+=s[y]%2, res+=s[x]%2;
        }
    }
    bool qry() {return res==0;}
}

void work(int l,int r,int x,int y) {
    if(l>r) return; int bot=DSU::top;
    int z=-1, mid=l+r>>1;
    rep(i,l,mid) if(e[i].w<x) DSU::merge(e[i].u,e[i].v);
    rep(i,x,y) {
        if(t[i].t<=mid) DSU::merge(t[i].u,t[i].v);
        if(DSU::qry()) {z=i; break;}
    }
    ans[mid]=z; DSU::undo(bot);
    if(z!=-1) {
        rep(i,x,z) if(t[i].t<l) DSU::merge(t[i].u,t[i].v);
        work(l,mid-1,z,y); DSU::undo(bot);
    }
    rep(i,l,mid) if(e[i].w<x) DSU::merge(e[i].u,e[i].v);
    work(mid+1,r,x,z==-1?y:z); DSU::undo(bot);
}

signed main() {
    n=read(), m=read();
    rep(i,1,m) {
        int u=read(), v=read(), w=read();
        e[i]=t[i]=(edge){u,v,w,i};
        b[i]=w;
    }
    sort(t+1,t+m+1,cmp); sort(b+1,b+m+1);
    rep(i,1,m) e[t[i].t].w=i;
    DSU::init();
    work(1,m,1,m);
    rep(i,1,m) {
        if(ans[i]<=0) puts("-1");
        else printf("%lld\n",t[ans[i]].w);
    }
    return 0;
}