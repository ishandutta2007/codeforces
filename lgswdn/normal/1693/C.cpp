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
int n,m,f[N],c[N],vst[N];
vi e[N];

signed main() {
    n=read(), m=read();
    rep(i,1,m) {
        int u=read(), v=read();
        e[v].emplace_back(u);
        c[u]++;
    }
    priority_queue<pii>q; q.push(pii(0,n));
    rep(i,1,n-1) f[i]=0x3f3f3f3f;
    while(!q.empty()) {
        int u=q.top().se; q.pop();
        if(vst[u]) continue; vst[u]=1; 
        for(auto v:e[u]) if(!vst[v]) {
            c[v]--;
            f[v]=min(f[v],f[u]+1+c[v]);
            q.push(pii(-f[v],v));
        }
    }
    printf("%lld\n",f[1]);
    return 0;
}