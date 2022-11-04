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

const int N=1<<18;
int T,n,p,d[N],eu[N],ev[N],w[N];
vi e[N];

void dfs(int u,int fa) {
    if(d[u]%2==0) w[u]+=n;
    for(auto v:e[u]) if(v!=fa) d[v]=d[u]+1, dfs(v,u);
}

signed main() {
    T=read();
    while(T--) {
        p=read(); n=1<<p; 
        rep(i,1,n) e[i].clear(), e[i].shrink_to_fit(), w[i]=i%n;
        rep(i,2,n) {
            int u=read(), v=read();
            eu[i]=u, ev[i]=v, e[u].emplace_back(v), e[v].emplace_back(u);
        }
        d[n]=0; dfs(n,0);
        printf("%lld\n",n);
        rep(i,1,n) printf("%lld ",w[i]); puts("");
        rep(i,2,n) {
            if(d[eu[i]]>d[ev[i]]) printf("%lld ",w[eu[i]]^n);
            else printf("%lld ",w[ev[i]]^n);
        } puts("");
    }
    return 0;
}