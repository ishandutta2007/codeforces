#include<bits/stdc++.h>
using namespace std;
int par[700000];
vector<pair<int,int> > a[700000];
int ch[700000];
int remch[700000];
bool vis[700000];
int q;
int n,k;
long long dp[700000][2];
vector<int> top;
void dfs(int u) {
    int v,w;
    ch[u]=0;
    vis[u]=true;
    for(int i=0;i<a[u].size();i++) {
        v=a[u][i].first;
        if(!vis[v]) {
            par[v]=u;
            dfs(v);
            ch[u]++;
        }
    }
    remch[u]=ch[u];
    vis[u]=false;
}
vector<long long> kt;
void toposort() {
    int id=0,u,v,w;
    while(id<top.size()) {
        u=top[id];
        remch[par[u]]--;
        if(remch[par[u]]==0) top.push_back(par[u]);
        dp[u][0]=dp[u][1]=0;
        long long sm=0;
        kt.clear();
        for(int i=0;i<a[u].size();i++) {
            v=a[u][i].first;
            w=a[u][i].second;
            if(v!=par[u]) {
                sm+=dp[v][0];
                kt.push_back(dp[v][1]-dp[v][0]+w);
            }
        }
        dp[u][1]=dp[u][0]=sm;
        sort(kt.begin(),kt.end());
        int l=kt.size()-1;
        for(int i=0;i<k-1;i++) {
            if(l-i<0 || kt[l-i]<0) break;
            else dp[u][1]+=kt[l-i];
        }
        for(int i=0;i<k;i++) {
            if(l-i<0 || kt[l-i]<0) break;
            else dp[u][0]+=kt[l-i];
        }
        id++;
    }
}
int main() {
    scanf("%d",&q);
    while(q--) {
        scanf("%d %d",&n,&k);
        for(int i=0;i<n-1;i++) {
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            a[u].push_back({v,w});
            a[v].push_back({u,w});
        }
        dfs(1);
        top.clear();
        for(int i=1;i<=n;i++) {
            if(remch[i]==0) top.push_back(i);
        }
        toposort();
        printf("%lld\n",dp[1][0]);
        for(int i=1;i<=n;i++) a[i].clear();
    }
    return 0;
}