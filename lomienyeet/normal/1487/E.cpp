#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
// #define int long long
const int mxN=2e5+5;
int pp[5],arr[5][mxN];
vector<int> adj[mxN];
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for(int i=1;i<=4;i++)cin>>pp[i];
    for(int i=1;i<=4;i++){
        for(int j=1;j<=pp[i];j++)cin>>arr[i][j];
    }
    for(int i=1,x;i<4;i++){
        cin>>x;
        for(int j=1,u,v;j<=x;j++){
            cin>>u>>v;
            adj[v].push_back(u);
        }
        multiset<int> ms;
        for(int j=1;j<=pp[i];j++)ms.insert(arr[i][j]);
        for(int j=1;j<=pp[i+1];j++){
            for(auto k:adj[j])ms.erase(ms.find(arr[i][k]));
            if(ms.empty()||*ms.begin()==2e9)arr[i+1][j]=2e9;
            else arr[i+1][j]+=*ms.begin();
            for(auto k:adj[j])ms.insert(arr[i][k]);
        }
        for(int j=1;j<=pp[i+1];j++)adj[j].clear();
    }
    int ans=2e9;
    for(int i=1;i<=pp[4];i++)ans=min(ans,arr[4][i]);
    cout<<(ans==2e9?-1:ans)<<"\n";
}