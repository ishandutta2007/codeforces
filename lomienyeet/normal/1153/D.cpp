#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxN=3e5+5;
int arr[mxN],dp[mxN],child;
vector<int> adj[mxN];
void dfs(int u){
    if(adj[u].empty()){
        dp[u]=1;
        child++;
        return;
    }
    if(!arr[u]){
        dp[u]=0;
        for(auto i:adj[u]){
            dfs(i);
            dp[u]+=dp[i];
        }
    }
    else{
        dp[u]=1e18;
        for(auto i:adj[u]){
            dfs(i);
            dp[u]=min(dp[u],dp[i]);
        }
    }
}
signed main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>arr[i];
    for(int i=2,x;i<=n;i++){
        cin>>x;
        adj[x].push_back(i);
    }
    dfs(1);
    cout<<child-dp[1]+1<<"\n";
}