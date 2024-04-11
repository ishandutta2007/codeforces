#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxN=2e5+5;
int arr[mxN],dp[2][mxN];
bool vis[mxN];
vector<int> adj[mxN],z[mxN];
bool dfs(int u,int p){
    vis[u]=1;
    bool ans=0;
    for(auto i:adj[u]){
        if(!vis[i]){
            ans|=dfs(i,u);
            dp[0][u]+=dp[0][i];
            z[u].push_back(i);
        }
        else if(i!=p)ans=1;
    }
    for(auto i:z[u])dp[1][u]=max(dp[1][u],dp[0][u]-dp[0][i]+dp[1][i]);
    dp[1][u]+=arr[u];
    if(ans)dp[0][u]+=arr[u];
    return ans;
}
signed main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>arr[i];
    for(int i=0,u,v;i<m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int x;
    cin>>x;
    dfs(x,-1);
    cout<<dp[1][x]<<"\n";
}