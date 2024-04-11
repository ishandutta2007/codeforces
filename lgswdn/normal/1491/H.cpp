#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;

long long read() {
    long long res=0, w=1; char c=getchar();
    while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
    while(isdigit(c)) {res=res*10+c-48, c=getchar();}
    return res*w;
}

const int N=4e5+9;
int n,m,bs,tot,b[N],l[N],r[N],f[N],fa[N],tag[N],af[N],last;

int getfa(int x) {
    if(af[b[x]]) return max(1,fa[x]-tag[b[x]]);
    else return fa[x];
}
int getf(int x) {
    if(af[b[x]]) return max(1,fa[x]-tag[b[x]]);
    else return f[x];
}
void build(int p) {
    af[p]=1;
    rep(i,l[p],r[p]) {
        if(fa[i]<l[p]) f[i]=fa[i];
        else f[i]=f[fa[i]];
        af[p]&=(fa[i]<l[p]);
    }
}
void mdfb(int p,int x) {
    if(af[p]) tag[p]=min(n,tag[p]+x);
    else {
        rep(i,l[p],r[p]) fa[i]=max(1,fa[i]-x);
        build(p);
    }
}
void mdf(int x,int y,int s) {
    if(b[x]==b[y]) {
        rep(i,x,y) fa[i]=max(1,fa[i]-s);
        if(!af[b[x]]) build(b[x]);
    } else {
        rep(i,x,r[b[x]]) fa[i]=max(1,fa[i]-s);
        rep(i,l[b[y]],y) fa[i]=max(1,fa[i]-s);
        rep(i,b[x]+1,b[y]-1) mdfb(i,s);
        if(!af[b[x]]) build(b[x]);
        if(!af[b[y]]) build(b[y]);
    }
}
int lca(int x,int y) {
    if(x==y) return x; int fx=getf(x), fy=getf(y);
    if(b[fx]!=b[fy]) return b[fx]<b[fy]?lca(x,fy):lca(fx,y);
    else if(fx!=fy) return fx<fy?lca(x,fy):lca(fx,y);
    else return x<y?lca(x,getfa(y)):lca(getfa(x),y);
}

int main() {
    n=read(), bs=sqrt(n), m=read();
    rep(i,2,n) fa[i]=read(); fa[1]=f[1]=1;
    for(int i=1;i<=n;i+=bs) {
        l[++tot]=i, r[tot]=min(n,i+bs-1);
        rep(j,l[tot],r[tot]) b[j]=tot;
        build(tot);
    }
    rep(i,1,m) {
        int op=read(), x=read(), y=read();
        if(op==1) mdf(x,y,read());
        else printf("%d\n",last=lca(x,y));
    }
    return 0;
}