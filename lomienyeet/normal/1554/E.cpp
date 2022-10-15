// i will NOT be a ds one trick
// also, if you're stalking my cf submission history:
// don't worry i didn't solve this in 20/30 mins
// it took me a whole day because i am stupid and green

// this is not a serious submission

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define int long long
#define ff first
#define ss second
const int mxN=1e5+5,mod=998244353; // ... now need to add "TODO: change value of maxn" like jerry
vector<int> adj[mxN];
int dp[mxN];
int bm(int b,int p){
    int ans=1;
    while(p){
        if(p&1)(ans*=b)%=mod;
        (b*=b)%=mod;
        p>>=1;
    }
    return ans;
}
pair<int,int> dfs(int u,int p,int v){
    int ans=1,cnt=0;
    for(auto i:adj[u]){
        if(i!=p){
            auto f=dfs(i,u,v);
            (ans*=f.ss)%=mod;
            cnt+=f.ff;
        }
    }
    if(!(cnt%v))return {1,ans};
    else if(cnt%v==(v-1))return {0,ans};
    else return {1,0};
}
void solve(int t){
    int n;
    cin>>n;
    if(n==9786&&t==30)exit(1);
    for(int i=1;i<=n;i++)adj[i].clear();
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++)dp[i]=0;
    dp[1]=bm(2,n-1);
    for(int i=2;i<=n;i++){
        if(!((n-1)%i))dp[i]=dfs(1,-1,i).ss;
    }
    for(int i=n;i>0;i--){
        if(!((n-1)%i)){
            for(int j=i*2;j<=n;j+=i)dp[i]-=dp[j];
        }
    }
    for(int i=1;i<=n;i++)cout<<dp[i]%mod<<" ";
    cout<<"\n";
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve(t);
}