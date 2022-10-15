// 
//  ds 

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxN=2e5+5;
int arr[mxN],ans=0;
vector<int> adj[mxN];
int dfs(int u,int p){
    int maxi=0,sec=0;
    for(auto i:adj[u]){
        if(i!=p){
            int go=dfs(i,u);
            if(go>maxi){
                sec=maxi;
                maxi=go;
            }
            else if(go>sec)sec=go;
        }
    }
    ans+=max(0ll,arr[u]-maxi);
    if(p==-1)ans+=max(0ll,arr[u]-sec);
    else maxi=max(maxi,arr[u]);
    return maxi;
}
signed main(){
    int n;
    cin>>n;
    int x=-1,y=-1e18;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        if(arr[i]>y){
            y=arr[i];
            x=i;
        }
    }
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(x,-1);
    cout<<ans<<"\n";
}