#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
const int mxN=3e5+5,mod=998244353;
int arr[mxN],trie[26][mxN],sz[mxN],wao[mxN];
vector<int> adj[mxN];
void eat(int a,int b,int &w){
    for(int i=0;i<26;i++){
        if(trie[i][b]){
            if(!trie[i][a]){
                w+=sz[trie[i][b]];
                trie[i][a]=trie[i][b];
            }
            else{
                sz[a]-=sz[trie[i][a]];
                eat(trie[i][a],trie[i][b],sz[trie[i][a]]);
                sz[a]+=sz[trie[i][a]];
            }
        }
    }
}
void dfs(int u,int p){
    sz[u]=1;
    for(auto i:adj[u]){
        if(i!=p){
            dfs(i,u);
            int z=wao[i];
            if(!trie[z][u]){
                sz[u]+=sz[i];
                trie[z][u]=i;
            }
            else{
                sz[u]-=sz[trie[z][u]];
                if(sz[trie[z][u]]<sz[i])swap(i,trie[z][u]);
                eat(trie[z][u],i,sz[trie[z][u]]);
                sz[u]+=sz[trie[z][u]];
            }
        }
    }
    arr[u]+=sz[u];
}
signed main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>arr[i];
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++)wao[i+1]=s[i]-'a';
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,-1);
    pair<int,int> ans={0,0};
    for(int i=1;i<=n;i++){
        if(ans.ff<arr[i])ans={arr[i],1};
        else if(ans.ff==arr[i])ans={arr[i],ans.ss+1};
    }
    cout<<ans.ff<<"\n"<<ans.ss<<"\n";
}