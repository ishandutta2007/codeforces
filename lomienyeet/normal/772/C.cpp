#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
const int mxN=2e5+5;
int dp[mxN],freq[mxN],todo[mxN];
vector<int> adj[mxN],go[mxN];
bool fucked[mxN];
int dfs(int u){
    if(dp[u]!=-1)return dp[u];
    dp[u]=0;
    for(auto i:adj[u]){
        if(dfs(i)>dp[u]){
            dp[u]=dfs(i);
            todo[u]=i;
        }
    }
    dp[u]+=freq[u];
    return dp[u];
}
int eat(int a,int b){
    int x=0,y=1,z=b,c=1,d=0,e=a;
    while(z){
        int wa=e/z,f=x,g=y,h=z;
        x=c-wa*x,y=d-wa*y,z=e-wa*z;
        c=f,d=g,e=h;
    }
    return c;
}
signed main(){
    int n,m;
    cin>>n>>m;
    for(int i=0,x;i<n;i++){
        cin>>x;
        fucked[x]=1;
    }
    for(int i=1;i<m;i++){
        dp[i]=-1;
        if(fucked[i])continue;
        int z=gcd(i,m);
        freq[z]++;
        go[z].push_back(i);
    }
    for(int i=1;i<m;i++){
        for(int j=i*2;j<m;j+=i)adj[i].push_back(j);
    }
    int ptr=0;
    for(int i=1;i<m;i++){
        if(dfs(i)>dp[ptr])ptr=i;
    }
    vector<int> ans;
    int ptr2=1;
    while(ptr!=0){
        for(auto i:go[ptr]){
            int u=ptr2,v=i,g=gcd(u,m),z=m/g;
            u/=g;
            v/=g;
            ans.push_back(((eat(u,z)*v)%z+z)%z);
            ptr2=i;
        }
        ptr=todo[ptr];
    }
    if(!fucked[0])ans.push_back(0);
    cout<<ans.size()<<"\n";
    for(auto i:ans)cout<<i<<" ";
}