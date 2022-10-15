/*
no one likes to fail
but one always needs to learn how to try again after failing
at least i still have next year
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxN=2e5+5;
int n,k,a,b,ans,oo,arr[mxN];
vector<int> adj[mxN];
void dfs(int u,int p,int d){
    if(u==b)oo=d;
    for(auto i:adj[u]){
        if(i!=p){
            dfs(i,u,d+1);
            arr[u]=max(arr[u],arr[i]);
        }
    }
    ans+=arr[u];
}
void eat(){
    cin>>n>>k>>a>>b;
    ans=0;
    for(int i=1;i<=n;i++){
        arr[i]=0;
        adj[i].clear();
    }
    arr[b]=1;
    for(int i=1,x;i<=k;i++){
        cin>>x;
        arr[x]=1;
    }
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(a,0,0);
    cout<<ans*2-oo-2<<"\n";
}
signed main(){
    int t;
    cin>>t;
    while(t--)eat();
}

//  iol & noi 2023 