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

int T,n,f[N],deg[N];
vi e[N];

void dfs(int u,int fa) {
    int cnt=0;
    for(auto v:e[u]) if(v!=fa) {
        dfs(v,u);
        cnt+=(f[v]>0), f[u]+=f[v];
    }
    if(cnt<deg[u]-2) f[u]+=deg[u]-2-cnt;
}

signed main() {
    T=read();
    while(T--) {
        n=read();
        rep(i,1,n) deg[i]=0, e[i].clear(), e[i].shrink_to_fit(), f[i]=0;
        rep(i,2,n) {
            int u=read(), v=read();
            deg[u]++, deg[v]++;
            e[u].emplace_back(v), e[v].emplace_back(u);
        }
        int r=0;
        rep(i,1,n) if(deg[i]>deg[r]) r=i;
        if(n==1) puts("0");
        else if(deg[r]<3) puts("1");
        else deg[r]++, dfs(r,0), printf("%lld\n",f[r]);
    }
    return 0;
}