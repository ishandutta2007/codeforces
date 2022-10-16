#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<": ";
#define INF 1000000000
#define pii pair<long long int,long long int>
#define F first
#define S second
typedef long long ll;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void pre(){}
ll coeff[200001]{0};
vector<ll>g[200001];
void solve(){
    int n,m,u,v;cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        u--;v--;
        coeff[u]++;
        g[v].push_back(u);
    }
    vector<ll>dp(n+1,-1);
    set<pii>s;
    s.insert({0,n-1});
    while(s.size()>0){
        auto curr = *s.begin();
        s.erase(curr); 
        if(dp[curr.S]!=-1) continue;
        dp[curr.S] = curr.F;
        for(auto to:g[curr.S]){
            coeff[to]--;
            s.insert({curr.F+coeff[to]+1,to});
        }
    }
    cout<<dp[0]<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    solve();   
}