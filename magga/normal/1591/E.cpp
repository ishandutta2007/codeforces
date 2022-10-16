#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
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
int a[1000001];
vector<int>arr[1000001];
vector<pair<int,pii>> q[1000001];
int ans[1000001];
ll n,u,v,w;
void dfs(int i,pair<vector<int>,ordered_set>&ds){
    ds.S.erase({ds.F[a[i]],a[i]});
    ds.F[a[i]]++;
    ds.S.insert({ds.F[a[i]],a[i]});
    for(auto p:q[i]){
        auto pal = ds.S.order_of_key({p.S.F,0});
        auto val = ds.S.find_by_order(pal + p.S.S-1);
        if(val==end(ds.S) || ((*val).F<p.S.F)){
            ans[p.F] = -1;
        }else{
            ans[p.F] = (*val).S;
        }
    }
    for(auto to:arr[i]){
        dfs(to,ds);
    }
    ds.S.erase({ds.F[a[i]],a[i]});
    ds.F[a[i]]--;
    ds.S.insert({ds.F[a[i]],a[i]});
}

// Please write the recurances once :(
void pre(){}
void solve(){
    int n,q1,d,v,l,k;cin>>n>>q1;
    for(int i=1;i<=n;i++){ 
        cin>>a[i];
        arr[i].clear();
        q[i].clear();
    }
    for(int i=2;i<=n;i++){
        cin>>d;
        arr[d].push_back(i);
    }
    for(int i=0;i<q1;i++){
        cin>>v>>l>>k;
        q[v].push_back({i,{l,k}});
    }
    pair<vector<int>,ordered_set>ds;
    ds.F.resize(n+1);
    dfs(1,ds);
    for(int i=0;i<q1;i++) cout<<ans[i]<<" ";
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