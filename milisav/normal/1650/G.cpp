#include<bits/stdc++.h>
#define maxn 200100
using namespace std;
int t;
int n,m;
vector<int> a[maxn];
bool vis[maxn];
int d[maxn];
long long c[maxn][2];
long long mod=1e9+7;
vector<int> q;
long long step(long long a,long long b) {
    if(b==0ll) return 1ll;
    if(b&1ll) return (a*step(a,b-1))%mod;
    else return step((a*a)%mod,b>>1ll);
}
vector<pair<int,int> > od;
void bfs(int u) {
    for(int j=1;j<=n;j++) {
        d[j]=1e9;
        c[j][0]=0;
        c[j][1]=0;
        vis[j]=false;
    }
    q.clear();
    q.push_back(u);
    vis[u]=true;
    int ind=0;
    d[u]=0;
    c[u][0]=1;
    c[u][1]=0;
    od.clear();
    while(ind<q.size()) {
        u=q[ind];
        od.push_back({d[u],u});
        for(auto v:a[u]) {
            if(d[v]+1==d[u]) {
                c[u][0]=(c[u][0]+c[v][0]);
                if(c[u][0]>=mod) c[u][0]-=mod;
            }
        }
        for(auto v:a[u]) {
            if(!vis[v]) {
                vis[v]=true;
                d[v]=d[u]+1;
                q.push_back(v);
            }
        }
        ind++;
    }
    sort(od.begin(),od.end());
    for(int i=0;i<od.size();i++) {
        int u=od[i].second;
        for(auto v:a[u]) {
            if(d[u]==d[v]+1) {
                c[u][1]=(c[u][1]+c[v][1]);
                if(c[u][1]>=mod) c[u][1]-=mod;
            }
            if(d[u]==d[v]) {
                c[u][1]=(c[u][1]+c[v][0]);
                if(c[u][1]>=mod) c[u][1]-=mod;
            }
        }
    }
}
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d",&n,&m);
        int x,y;
        scanf("%d %d",&x,&y);
        for(int i=0;i<m;i++) {
            int u,v;
            scanf("%d %d",&u,&v);
            a[u].push_back(v);
            a[v].push_back(u);
        }
        bfs(x);
        printf("%lld\n",(c[y][0]+c[y][1])%mod);
        for(int i=1;i<=n;i++) a[i].clear();
    }
    return 0;
}