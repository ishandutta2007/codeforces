#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<" :";
#define INF 1000000000
#define pii pair<long long int,long long int>
#define F first
#define S second
typedef long long ll;
using namespace std;

vector<int>arr[200001];
pii dp[200001];
int par[200001]{0};
ll n,u,v,w,k;
void dfs(int to,int from){
    dp[to] = {to,1};
    par[to] = from;
    for(auto i:arr[to]){
        if(i!=from){
            dfs(i,to);
            auto a = dp[i];
            if(a.S + 1 > dp[to].S){
                dp[to] = {i,a.S+1};
            }
        }
    }
}
priority_queue<pair<int,int>>pq;
void dfs2(int to){
    for(auto i:arr[to]){
        if(i!=par[to] && i!=dp[to].F){
            pq.push({dp[i].S,i});
        }
    }
    if(dp[to].F!=to)
        dfs2(dp[to].F);
}
// Please write the recurances once :(
void pre(){}
void solve(){
    cin>>n>>k;
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    int leaves = 0;
    for(int i=2;i<=n;i++){
        if(arr[i].size()==1){
            leaves++;
        }
    }
    ll ans = 0;
    if(k>=leaves){
        for(int i=leaves;i<=k;i++){
            ans = max(ans,(n-i)*i);
        }
        cout<<ans<<"\n";
    }else{
        dfs(1,-1);
        pq.push({dp[1].S,1});
        ll rem = n;
        for(int i=0;i<k;i++){
            auto j = pq.top();
            pq.pop();
            rem -= j.F; 
            dfs2(j.S);
        }
        ans = 1e14;
        for(int i=0;i<=rem;i++){
            ans = min(ans,(n-k-i)*(k-i));
        }
        cout<<ans<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}