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
ll val[200001];
vector<int>arr[200001];
ll n,u,v,w;
int root;
pair<ll,pii> dfs(int to,int from){
    // pair<ll,pii> ret = {val[to],{val[to],val[to]}};
    pair<ll,pii> ret  = {0,{0,0}};
    pii mex = {0,0};
    for(auto i:arr[to]){
        if(i!=from){
            auto mid = dfs(i,to);
            ret.F+=mid.F;
            ret.S.F=max(ret.S.F,mid.S.F);
            ret.S.S=max(ret.S.S,mid.S.S);
            if(mid.S.S > mex.F){
                mex.S = mex.F;
                mex.F = mid.S.S;
            }else if(mid.S.S > mex.S){
                mex.S = mid.S.S;
            }
        }
    }
    // ans , max_t , max_h
    if(to!=root){
        if(val[to] > ret.S.S){
            ret.S.S  = val[to];
            ret.F += val[to] - ret.S.F;
            ret.S.F = max(ret.S.F,val[to]); 
        }
    }else{
        ret.F += 2*val[to] - mex.F - mex.S;
    }
    return ret;
}

// Please write the recurances once :(
void pre(){}
void solve(){
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>val[i];
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    root = 0;
    int mex = 0;
    for(int i=1;i<=n;i++){
        if(val[i] > mex){
            root = i;
            mex = val[i];
        }
    }
    auto ans = dfs(root,0);
    cout<<ans.F<<"\n";
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