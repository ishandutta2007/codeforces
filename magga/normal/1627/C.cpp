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
int ans[200001];
vector<pii>arr[200001];
ll n,u,v,w;
void dfs(int to,int from,int p){
    for(auto i:arr[to]){
        if(i.F!=from){
            if(p) ans[i.S] = 2;
            else ans[i.S] = 3;
            dfs(i.F,to,1-p);
        }
    }
}

// Please write the recurances once :(
void pre(){}
void solve(){
    int n;cin>>n;
    for(int i=0;i<=n;i++) arr[i].clear();
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        arr[u].push_back({v,i+1});
        arr[v].push_back({u,i+1});
    }
    int root = -1;
    for(int i=1;i<=n;i++){
        if(arr[i].size()==1){
            root = i;
        }
        if(arr[i].size()>2){
            cout<<-1<<"\n";
            return;
        }
    }
    dfs(root,-1,0);
    for(int i=1;i<n;i++){
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