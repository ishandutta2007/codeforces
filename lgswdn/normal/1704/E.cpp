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

const int N=1009,mod=998244353;

int T,n,m,a[N],f[N],deg[N],ot[N],g[N];
vi e[N];

signed main() {
    T=read();
    while(T--) {
        n=read(), m=read();
        rep(i,1,n) deg[i]=f[i]=g[i]=0, e[i].clear(), e[i].shrink_to_fit(), ot[i]=0;
        rep(i,1,n) a[i]=read();
        rep(i,1,m) {
            int x=read(), y=read();
            e[x].emplace_back(y); deg[y]++; ot[x]++;
        }
        queue<int>q; rep(i,1,n) if(deg[i]==0) q.push(i);
        rep(i,1,n) f[i]=a[i];
        int flag=0;
        while(!q.empty()) {
            int u=q.front(); q.pop();
            for(auto v:e[u]) {
                f[v]+=f[u], deg[v]--; if(f[v]>=mod) flag=1, f[v]%=mod;
                if(deg[v]==0) q.push(v);
            }
        }
        int t=0;
        rep(i,1,n) if(ot[i]==0) t=i;
        int ans=f[t], r=0;
        rep(i,1,n) f[i]=a[i];
        int ttt=0;
        rep(i,1,2*n) if(r<ans||flag) {
            rep(i,1,n) g[i]=f[i];
            rep(u,1,n) if(f[u]) {
                g[u]--; if(u==t) r++;
                for(auto v:e[u]) if(f[u]) g[v]++;
            }
            rep(u,1,n) f[u]=g[u];
            ttt=i;
        }
        ans=(ans+ttt-r)%mod;
        printf("%lld\n",ans);
    }
    return 0;
}