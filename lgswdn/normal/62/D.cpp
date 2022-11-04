#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;

inline long long read() {
    register long long x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

const int N=1e6+9;
int n,m,p[N],q[N];
bool vst[N],flag;
vp e[N];

void dfs(int u,int pos) {
    q[pos]=u;
    if(pos==m+1) {
        if(flag) {
            rep(i,1,m+1) printf("%d ",q[i]);
            puts("");
            exit(0);
        } else return;
    }
    for(auto ed:e[u]) {
        int v=ed.fi,id=ed.se;
        if(vst[id]||(v<p[pos+1]&&!flag)) continue;
        flag|=(v>p[pos+1]);
        vst[id]=1, dfs(v,pos+1), vst[id]=0;
    }
}

signed main() {
    n=read(), m=read();
    rep(i,1,m+1) {
        p[i]=read();
        if(i>1) {
            e[p[i]].emplace_back(pii(p[i-1],i));
            e[p[i-1]].emplace_back(pii(p[i],i));
        }
    }
    rep(i,1,n) sort(e[i].begin(),e[i].end());
    dfs(p[1],1); if(p[1]!=n) dfs(p[1]+1,1);
    puts("No solution");
    return 0;
}