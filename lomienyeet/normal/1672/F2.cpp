// wow i am so fucking trash lol
// every contest, i amaze myself with how shit i can perform

#include <bits/stdc++.h>
using namespace std;
const int mxN=2e5+5;
int n,a[mxN],b[mxN],pp[mxN];
vector<int> adj[mxN];
bool dfs(int u){
    pp[u]=1;
    for(auto i:adj[u]){
        if(!pp[i]&&!dfs(i))return 0;
        else if(pp[i]==1)return 0;
    }
    pp[u]=2;
    return 1;
}
void eat(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        adj[i].clear();
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
        adj[a[i]].push_back(b[i]);
    }
    int maxi=0,ptr=0;
    for(int i=1;i<=n;i++){
        if(adj[i].size()>maxi){
            maxi=adj[i].size();
            ptr=i;
        }
        pp[i]=0;
    }
    pp[ptr]=2;
    for(int i=1;i<=n;i++){
        if(!pp[i]&&!dfs(i)){
            cout<<"WA\n";
            return;
        }
    }
    cout<<"AC\n";
}
signed main(){
    int t=1;
    cin>>t;
    while(t--)eat();
}