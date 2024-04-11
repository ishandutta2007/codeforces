#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mxN=3e5+5,lg=19;
int dep[mxN],dp[2][mxN],pp[mxN],st[lg][mxN];
vector<int> adj[mxN],weeee[mxN];
void dfs(int u,int p){
    dep[u]=dep[p]+1;
    dp[0][u]=dp[1][u]=pp[u]=0;
    for(auto i:adj[u]){
        if(i!=p){
            st[0][i]=u;
            dfs(i,u);
            dp[1][u]=max(dp[1][u],dp[0][u]+dp[0][i]);
            dp[0][u]=max(dp[0][u],dp[0][i]);
            pp[u]=max(pp[u],pp[i]);
        }
    }
    dp[0][u]++;
    dp[1][u]++;
    pp[u]=max(pp[u],dp[1][u]);
}
int lca(int a,int b){
    if(dep[a]<dep[b])swap(a,b);
    for(int i=lg-1;i>=0;i--){
        if(dep[st[i][a]]>=dep[b])a=st[i][a];
    }
    for(int i=lg-1;i>=0;i--){
        if(st[i][a]!=st[i][b]){
            a=st[i][a];
            b=st[i][b];
        }
    }
    if(a!=b)return st[0][a];
    else return a;
}
void eat(){
    int n;
    cin>>n;
    for(int i=0;i<=n;i++){
        adj[i].clear();
        weeee[i].clear();
    }
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    for(int i=1;i<lg;i++){
        for(int j=1;j<=n;j++)st[i][j]=st[i-1][st[i-1][j]];
    }
    int ans[n+1]={},wa=0;
    for(int i=2;i<=n;i++){
        weeee[dep[i]-1].push_back(i);
        wa=max(wa,dep[i]-1);
    }
    for(int i=wa;i>0;i--){
        int z=weeee[i][0];
        for(auto j:weeee[i])z=lca(z,j);
        if(i-pp[z]/2<2)break;
        ans[i-pp[z]/2-1]=i-1;
    }
    for(int i=n;i>0;i--){
        if(ans[i])wa=ans[i];
        else ans[i]=wa;
    }
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
    cout<<"\n";
}
signed main(){
    int t;
    cin>>t;
    while(t--)eat();
}