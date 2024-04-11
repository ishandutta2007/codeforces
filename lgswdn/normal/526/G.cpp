// LUOGU_RID: 91325144
#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define eb emplace_back
#define y1 yylyylyylyyl
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

const int N=1e5+9;
int n,m,s[2][N],t[2][N],p[2][N],son[2][N],id[2][N],rk[2][N],g[2][N],cnt[2],rt1,rt2,f[2][N][29],sum[2][N],ff[2][N],last;
vp e[N];

bool cmp0(const int &x,const int &y) {return g[0][x]>g[0][y];}
bool cmp1(const int &x,const int &y) {return g[1][x]>g[1][y];}

void dfs1(int u,int fa,int k=0) {
    p[k][u]=u; ff[k][u]=fa; son[k][u]=0; g[k][u]=0;
    for(auto ed:e[u]) {
        int v=ed.fi, w=ed.se;
        if(v==fa) continue;
        s[k][v]=s[k][u]+w; dfs1(v,u,k);
        g[k][v]+=w;
        if(g[k][v]>g[k][u]) son[k][u]=v, p[k][u]=p[k][v], g[k][u]=g[k][v];
    }
}
void dfs2(int u,int fa,int top,int k=0) {
    t[k][u]=top;
    if(top==u) {
        if(fa) {
            f[k][u][0]=t[k][fa];
            rep(h,1,20) f[k][u][h]=f[k][f[k][u][h-1]][h-1];
        }
        id[k][++cnt[k]]=u;
    }
    for(auto ed:e[u]) {
        int v=ed.fi, w=ed.se;
        if(v==fa) continue;
        if(v==son[k][u]) dfs2(v,u,top,k);
        else dfs2(v,u,v,k);
    }
    //cout<<u<<" "<<s[u]<<" "<<t[u]<<" "<<p[u]<<" "<<g[u]<<endl;
}
int find(int x,int z,int k) {
    per(h,20,0) if(rk[k][f[k][x][h]]>z) x=f[k][x][h];
    return x;
}
int work1(int x,int z,int k) {
    int y=find(t[k][x],z,k);
    return s[k][p[k][x]]-s[k][ff[k][y]]-g[k][id[k][z]];
}
int work2(int x,int z,int k) {
    int y=find(t[k][x],z,k);
    return s[k][p[k][x]]-s[k][p[k][ff[k][y]]];
}
int work(int x,int k,int tp) {
    if(2*k-1>=cnt[tp]) return sum[tp][cnt[tp]];
    else if(rk[tp][t[tp][x]]<=2*k-1) return sum[tp][2*k-1];
    else return sum[tp][2*k-1]+max(work1(x,2*k-1,tp),work2(x,2*k-1,tp));
}

signed main() {
    n=read(), m=read();
    rep(i,2,n) {
        int u=read(), v=read(), w=read();
        e[u].eb(pii(v,w)), e[v].eb(pii(u,w));
    }
    dfs1(1,0);
    rt1=p[0][1];
    s[0][rt1]=0; dfs1(rt1,0,0), dfs2(rt1,0,rt1,0);
    rt2=p[0][rt1]; dfs1(rt2,0,1), dfs2(rt2,0,rt2,1);
    rep(k,0,1) {
        if(k==0) sort(id[k]+1,id[k]+cnt[k]+1,cmp0);
        else sort(id[k]+1,id[k]+cnt[k]+1,cmp1);
        rep(i,1,cnt[k]) sum[k][i]=sum[k][i-1]+g[k][id[k][i]];
        rep(i,1,cnt[k]) rk[k][id[k][i]]=i;
    }
    rep(i,1,m) {
        int x=read(), k=read();
        x=(x+last-1)%n+1, k=(k+last-1)%n+1;
        //cout<<x<<" "<<k<<endl;
        printf("%lld\n",last=max(work(x,k,0),work(x,k,1)));
    }
    return 0;
}