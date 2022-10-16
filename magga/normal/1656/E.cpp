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

vector<int>arr[100001];
ll ans[100001];
ll n,u,v,w;
void dfs(int to,int from,int depth){
    ans[to] = 1 ;
    if(depth&1) ans[to]*=-1;
    ans[to] *= arr[to].size();
    for(auto i:arr[to]){
        if(i!=from){
            dfs(i,to,depth+1);
        }
    }
   
}

// Please write the recurances once :(
void pre(){}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        ans[i] = 0;
        arr[i].clear();
    }
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    dfs(1,-1,0);
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
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