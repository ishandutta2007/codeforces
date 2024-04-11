#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<": ";
#define pii pair<long long int,long long int>
#define F first
#define S second
typedef long long ll;
using namespace std;


struct Graph{
    int n;
    vector<vector<pair<int,long long>>>edges;
    vector<bool>visited; 
    vector<vector<ll>>dp;
    Graph(int _n){
        n = _n;
        dp.assign(n+1,vector<ll>(n+1,1e18));
        for(int i=0;i<=n;i++) dp[i][i] = 0;
        edges.resize(n+1);
        visited.resize(n+1);
    }
    void add_edge(int u,int v,long long w = 1){
        dp[u][v] = min(dp[u][v],w);
    }
    void reset_vis(){
        for(int i=0;i<=n;i++) visited[i] = false;
    }
    void reset(int _n){
        n = _n;
        edges.resize(n+1);
        visited.resize(n+1);
        for(int i=0;i<=n;i++)
            edges[i].clear();
        reset_vis();
    }
    void dijkstra(){
        for (int k = 1; k <= n; ++k) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]); 
                }
            }       
        }
    }
};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void pre(){}

void solve(){
    int n,m;cin>>n>>m;
    Graph g(n);
    vector<pair<pii,ll>>ed;
    for(int i=0;i<m;i++){
        ll u,v,w;cin>>u>>v>>w; 
        g.add_edge(u,v);
        g.add_edge(v,u);
        ed.push_back({{v,u},w});
    }
    g.dijkstra();
    ll ans = 1e18;
    for(auto i:ed){
        ans = min(ans,i.S*(g.dp[1][i.F.F] + g.dp[n][i.F.S] + 1));
        ans = min(ans,i.S*(g.dp[1][i.F.S] + g.dp[n][i.F.F] + 1));
        for(int j=1;j<=n;j++){
            ll ma = min(g.dp[j][i.F.F],g.dp[j][i.F.S]);
            ans = min(ans,i.S*(ma + 1 + g.dp[j][1] + g.dp[j][n] + 1));
        }
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}