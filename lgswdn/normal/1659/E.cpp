#include<bits/stdc++.h>
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

int n,m,eu[N],ev[N],ew[N],id[32][N],tag[N],s[N],tot,p[N];
vi e[32][N];

int find(int h,int i) {return i==id[h][i]?i:id[h][i]=find(h,id[h][i]);}
void unite(int h,int u,int v) {id[h][find(h,u)]=find(h,v);}

signed main() {
    n=read(), m=read();
    rep(h,0,30) rep(i,1,n) id[h][i]=i;
    rep(i,1,m) {
        int u=read(), v=read(), w=read();
        eu[i]=u, ev[i]=v, ew[i]=w;
        rep(h,0,30) if(w&(1<<h)) {
            e[h][u].emplace_back(v), e[h][v].emplace_back(u);
            unite(h,u,v);
        }
    }
    rep(h,1,30) {
        rep(i,1,n) s[i]=tag[i]=0; tot=0;
        rep(i,1,n) if(!s[i]) {
            s[i]=++tot;
            queue<int>q; q.push(i);
            while(!q.empty()) {
                int u=q.front(); q.pop(); s[u]=tot;
                for(auto v:e[h][u]) if(!s[v]) q.push(v);
            }
        }
        rep(i,1,m) {
            int u=eu[i], v=ev[i], w=ew[i];
            if(w%2==0) tag[s[u]]=1, tag[s[v]]=1;
        }
        rep(i,1,n) p[i]|=tag[s[i]];
    }
    int q=read();
    while(q--) {
        int u=read(), v=read();
        bool flag=0;
        rep(i,0,30) if(find(i,u)==find(i,v)) {flag=1; break;}
        if(flag==1) puts("0");
        else if(p[u]) puts("1");
        else puts("2");
    }
    return 0;
}