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
// WRITE DOWN THE RECCURANCES FFS 
// Please write the recurances once :(
vector<set<long long>>g,rg;
vector<int>topological_sort;
vector<bool>visited;
void dfs(int i){
    if(visited[i]) return;
    visited[i] = true;
    for(auto j:g[i]) 
        dfs(j);
    topological_sort.push_back(i);
}
void pre(){}
void solve(){
    int n,m;cin>>n>>m;
    g.resize(n);
    rg.resize(n);
    visited.resize(n);
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        a--;b--;
        g[a].insert(b);
        rg[b].insert(a);    
    }
    vector<int>sg(n),srg(n);
    for(int i=0;i<n;i++){
        sg[i] = g[i].size();
        srg[i] = rg[i].size();
    }
    for(int i=0;i<n;i++){
        if(srg[i]==1 && rg[i].size()==1){
            g[*rg[i].begin()].erase(i);
            rg[i].clear();
        }
        if(sg[i]==1 && g[i].size()==1){
            rg[*g[i].begin()].erase(i);
            g[i].clear();
        }
    }
    for(int i=0;i<n;i++){
        if(!visited[i]) dfs(i);
    }
    reverse(topological_sort.begin(),topological_sort.end());
    vector<int>dp(n);
    int ans = 0;
    for(int i=n-1;i>=0;i--){
        int curr_node = topological_sort[i];
        dp[curr_node]=1;
        for(auto i:g[curr_node]){
            dp[curr_node] = max(dp[curr_node],dp[i]+1);
        }
        ans = max(ans,dp[curr_node]);
    }
    cout<<ans<<"\n";
}   
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}