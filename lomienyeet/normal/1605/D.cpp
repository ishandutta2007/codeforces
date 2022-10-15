#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,inline,unroll-loops")
using namespace std;
#define int long long
const int mxN=3e5+5;
vector<int> adj[mxN];
int col[mxN],pos[mxN];
int calc(int x){
    if(x<1)return -1;
    int ans=0;
    while(x){
        ans++;
        x>>=1;
    }
    return ans-1;
}
void dfs(int u,int p){
    col[u]=1-col[p];
    for(auto i:adj[u]){
        if(i!=p)dfs(i,u);
    }
}
void eat(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        adj[i].clear();
        col[i]=0;
        pos[i]=-1;
    }
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    int z=0;
    for(int i=1;i<=n;i++)z+=col[i];
    int zz=n-z;
    if(z<zz){
        for(int i=1;i<=n;i++)col[i]^=1;
        swap(z,zz);
    }
    vector<int> e[18],wa;
    for(int i=1;i<=n;i++)e[calc(i)].push_back(i);
    for(int i=0;i<18;i++){
        if(zz&(1<<i))wa.push_back(i);
    }
    for(int i=1;i<=n;i++){
        if(!col[i]){
            pos[i]=e[wa.back()].back();
            e[wa.back()].pop_back();
            if(e[wa.back()].empty())wa.pop_back();
        }
    }
    set<int> s;
    for(int i=1;i<=n;i++)s.insert(i);
    for(int i=1;i<=n;i++)s.erase(pos[i]);
    for(int i=1;i<=n;i++){
        if(pos[i]==-1){
            pos[i]=*s.begin();
            s.erase(s.begin());
        }
    }
    for(int i=1;i<=n;i++)cout<<pos[i]<<" ";
    cout<<"\n";
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)eat();
}