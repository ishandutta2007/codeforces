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

const int N=2009;
int n,mod,f[N][N],s[N][N],d[N][N],ans[N],c[N][N],deg[N],pre[N][N],suf[N][N];
vi e[N];

int ksm(int x,int y,int r=1) {
    for(;y;x=x*x%mod,y>>=1) if(y%2==1) r=r*x%mod;
    return r;
}

void dfs(int u,int fa) {
    rep(i,1,n) d[u][i]=1;
    vi son(0); int sons=0;
    for(auto v:e[u]) if(v!=fa) {
        dfs(v,u);
        son.emplace_back(v); sons++;
        rep(i,1,n) d[u][i]=d[u][i]*s[v][i]%mod;
    }
    rep(j,0,sons-1) {
        int v=son[j];
        rep(i,1,n) pre[j][i]=(j?pre[j-1][i]:1)*s[v][i]%mod;
    }
    per(j,sons-1,0) {
        int v=son[j];
        rep(i,1,n) suf[j][i]=(j!=sons-1?suf[j+1][i]:1)*s[v][i]%mod;
    }
    rep(j,0,sons-1) {
        int v=son[j], sum=0;
        rep(i,1,n) {
            f[u][i]=(f[u][i]+sum*f[v][i])%mod;
            sum=(sum+(j?pre[j-1][i]:1)*(j!=sons-1?suf[j+1][i]:1))%mod;
        }
    }
    rep(i,1,n) f[u][i]=((u!=1)*f[u][i]+d[u][i])%mod;
    rep(i,1,n) s[u][i]=(s[u][i-1]+f[u][i])%mod;
}

signed main() {
    n=read(), mod=read();
    rep(i,2,n) {
        int u=read(), v=read();
        e[u].emplace_back(v), e[v].emplace_back(u);
        deg[u]++, deg[v]++;
    }
    dfs(1,0);
    c[0][0]=1;
    rep(i,1,n) rep(j,0,i) c[i][j]=(c[i-1][j]+(j?c[i-1][j-1]:0))%mod;
    rep(i,1,n) {
        ans[i]=f[1][i];
        rep(j,1,i-1) ans[i]=(ans[i]-c[i][j]*ans[j])%mod;
    }
    rep(i,1,n-1) printf("%lld ",(ans[i]+mod)%mod); puts("");
    return 0;  
}