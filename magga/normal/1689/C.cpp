#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<": ";
#define INF 1000000000
#define pii pair<long long int,long long int>
#define F first
#define S second
typedef long long ll;
using namespace std;
struct Graph{
    int n;
    vector<vector<pair<int,long long>>>edges;
    vector<bool>visited;
    
    Graph(int _n){
        n = _n;
        edges.resize(n+1);
        visited.resize(n+1);
    }

    void add_edge(int u,int v,long long w = 1){
        edges[u].push_back({v,w});
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

    pii dfs(int i,int from){
        vector<pii>v;
        for(auto k:edges[i]){
            int to = k.F;
            if(to!=from){
                v.push_back(dfs(to,i));
            }
        }
        if(v.size()==0){
            return {0,1};
        }else if(v.size()==1){
            return {v[0].S-1,v[0].S+1};
        }else{
            return {max(v[0].F+v[1].S-1,v[1].F+v[0].S-1),v[0].S+v[1].S+1};
        }
    }
};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void pre(){}
void solve(){
    int n,u,v;cin>>n;
    Graph g(n);
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        u--;v--;
        g.add_edge(u,v);
        g.add_edge(v,u);
    }
    cout<<g.dfs(0,-1).F<<"\n";
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