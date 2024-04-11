#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> a[200000];
vector<pair<long long,int> > g[200000];
long long x[200000];
long long gcd(long long p,long long q) {
    if(q==0) return p;
    else return gcd(q,p%q);
}
void dfs(int u,int p,int d) {
    g[u].push_back({x[u],d});
    for(auto v:a[u]) {
        if(v!=p) {
            long long pv=-1;
            for(auto r:g[u]) {
                long long t=gcd(r.first,x[v]);
                if(t!=pv) g[v].push_back({t,r.second});
                else g[v].back().second=r.second;
                pv=t;
            }
            dfs(v,u,d+1);
        }
    }
}
int main() {
    scanf("%d",&n);
    int u,v;
    for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
    for(int i=0;i<n-1;i++) {
        scanf("%d %d",&u,&v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1,-1,1);
    long long ans=0;
    long long mod=1e9+7;
    for(int i=1;i<=n;i++) {
        ans=(ans+g[i][0].first*g[i][0].second)%mod;
        /*cout<<i<<endl;
        for(int j=0;j<g[i].size();j++) cout<<g[i][j].first<<" "<<g[i][j].second<<endl;
        cout<<endl<<endl;*/
        for(int j=1;j<g[i].size();j++) {
            ans=(ans+g[i][j].first*(g[i][j].second-g[i][j-1].second))%mod;
        }
    }
    printf("%lld",ans);
    return 0;
}