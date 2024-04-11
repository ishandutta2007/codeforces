#include<bits/stdc++.h>
#define maxn 200002
#define maxl 18
using namespace std;
struct pos {
    long long k;
    long long cnt=0;
    int u;
};
inline bool operator >(pos x,pos y) {
    if(y.k>=maxl && x.k<maxl) return true;
    if(x.k>=maxl && y.k<maxl) return false;
    if(x.k<maxl && y.k<maxl) return (1ll<<x.k)+x.cnt<(1ll<<y.k)+y.cnt;
    return x.k<y.k || (x.k==y.k && x.cnt<y.cnt);
}
inline bool operator <(pos x,pos y) {
    return y>x;
}
long long mod=998244353;
long long step(long long x,long long y) {
    if(y==0ll) return 1ll;
    if(y&1ll) return (x*step(x,y-1))%mod;
    else return step((x*x)%mod,y>>1ll);
}
priority_queue<pos> pq;
vector<int> a[(maxl+2)*maxn];
bool vis[(maxl+2)*maxn];
int n,m;
int rn;
pos d[(maxl+2)*maxn];
void dijkstra() {
    for(int u=1;u<=n;u++) {
        for(int j=0;j<=maxl+1;j++) d[u+j*n]={n,n,u+j*n};
    }
    d[1]={0,0,1};
    pq.push(d[1]);
    pos t;
    while(!pq.empty()) {
        t=pq.top();
        pq.pop();
        int u=t.u;
        if(vis[u]) continue;
        vis[u]=true;
        int s=0,c=0;
        for(auto v:a[u]) {
            if(abs(u-v)<n) {
                s=1;
                c=0;
            }
            else {
                s=0;
                c=1;
            }
            pos pom={t.k+c,t.cnt+s,v};
            if(pom>d[v]) {
                d[v]=pom;
                pq.push(pom);
            }
        }
    }
}
int main() {
    int u,v;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++) {
        scanf("%d %d",&u,&v);
        for(int j=0;j<=maxl+1;j++) {
            if(j&1) a[v+j*n].push_back(u+j*n);
            else a[u+j*n].push_back(v+j*n);
        }
    }
    for(int u=1;u<=n;u++) {
        for(int j=0;j<=maxl;j++) a[u+j*n].push_back(u+(j+1)*n);
        a[u+(maxl+1)*n].push_back(u+maxl*n);
    }
    dijkstra();
    pos pob = d[n];
    for(int j=0;j<=(maxl+1);j++) if(d[n+j*n]>pob) pob=d[n+j*n];
    printf("%lld\n",(step(2,pob.k)+mod-1+pob.cnt)%mod);
    return 0;
}