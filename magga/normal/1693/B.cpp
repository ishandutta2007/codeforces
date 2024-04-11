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
// WRITE DOWN THE RECCURANCES FFS 
void pre(){}
int n,d;
vector<int>g[200001];
pii arr[200001];
ll dfs(int i){
    ll ret = 0;
    ll t = 0;
    for(auto to:g[i]){
        ret+=dfs(to);
        t += arr[to].S;
    }
    if(t<arr[i].F){
        ret++;
    }else{
        arr[i].S = min(t,arr[i].S);
    }
    return ret;
}
void solve(){
    cin>>n;
    for(int i=0;i<=n;i++){
        g[i].clear();
    }
    for(int i=0;i<n-1;i++){
        cin>>d;
        g[d-1].push_back(i+1);
    }
    for(int i=0;i<n;i++){
        cin>>arr[i].F>>arr[i].S;
    }
    cout<<dfs(0)<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}