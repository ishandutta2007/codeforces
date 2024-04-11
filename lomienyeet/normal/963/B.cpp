#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxN=2e5+5;
int dp[mxN];
vector<int> adj[mxN],z[mxN];
queue<int> ans;
void dfs(int u,int p){
    dp[u]=1;
    int wa=1,ch=0;
    for(auto i:adj[u]){
        if(i!=p){
            dfs(i,u);
            dp[u]+=dp[i];
            if(!dp[i])ch++;
            else wa&=(dp[i]&1);
        }
    }
    if(wa&&!((adj[u].size()-ch)&1)){
        ans.push(u);
        dp[u]=0;
    }
    else z[p].push_back(u);
}
signed main(){
    int n;
    cin>>n;
    if(!(n&1)){
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    for(int i=1,x;i<=n;i++){
        cin>>x;
        if(x){
            adj[x].push_back(i);
            adj[i].push_back(x);
        }
    }
    dfs(1,-1);
    while(ans.size()){
        auto x=ans.front();
        ans.pop();
        cout<<x<<"\n";
        for(auto i:z[x])ans.push(i);
    }
}