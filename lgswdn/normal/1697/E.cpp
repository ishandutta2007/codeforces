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

const int N=209,inf=0x3f3f3f3f,mod=998244353;
int n,x[N],y[N],d[N][N],e[N][N],mn[N],vst[N],f[N][N],g[N],p[N],fg[N];
vi s[N];

void upd(int &x,int y) {
    x+=y;
    if(x>=mod) x-=mod;
}

signed main() {
    n=read();
    rep(i,1,n) {p[i]=1; rep(j,0,i-1) p[i]=p[i]*(n-j)%mod;} 
    rep(i,1,n) x[i]=read(), y[i]=read();
    rep(i,1,n) rep(j,1,n) d[i][j]=abs(x[i]-x[j])+abs(y[i]-y[j]);
    rep(i,1,n) mn[i]=inf;
    rep(i,1,n) rep(j,1,n) if(i!=j) mn[i]=min(mn[i],d[i][j]); 
    rep(i,1,n) rep(j,1,n) if(d[i][j]==mn[i]) e[i][j]=1;
    rep(i,1,n) if(!fg[i]) {
        queue<int>q; q.push(i);
        rep(i,1,n) vst[i]=0;
        while(!q.empty()) {
            int x=q.front(); q.pop(); s[i].emplace_back(x); vst[x]=1;
            rep(y,1,n) if(e[x][y]&&!vst[y]) q.push(y), vst[y]=1;
        }
        g[i]=1;
        for(auto x:s[i]) for(auto y:s[i]) if(x!=y) g[i]&=(d[x][y]==mn[i]);
        if(g[i]) {
            for(auto x:s[i]) if(x!=i) fg[x]=1;
        }
    }
    f[0][0]=1;
    rep(i,0,n-1) {
        if(fg[i+1]) {
            rep(j,0,n) f[i+1][j]=f[i][j];
            continue;
        }
        rep(j,0,n) if(f[i][j]) {
            upd(f[i+1][j+1],f[i][j]);
            int sz=s[i+1].size();
            if(g[i+1]&&sz) upd(f[i+1][j+sz],f[i][j]);
        }
    }
    int ans=0;
    rep(i,1,n) upd(ans,f[n][i]*p[i]%mod);
    printf("%lld\n",ans);
    return 0;
}