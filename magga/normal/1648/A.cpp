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
// Please write the recurances once :(
void pre(){}
ll counter(vector<vector<int>> &v){
    int n = v.size();
    int m = v[0].size();
    vector<int>f(100001);
    for(auto &i:v){
        for(auto j:i){
            f[j]++;
        }
    }
    vector<ll>count(100001);
    ll ret = 0;
    ll curr = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            curr -= count[v[i][j]]*f[v[i][j]];
            count[v[i][j]]++;
            f[v[i][j]]--;
            curr += count[v[i][j]]*f[v[i][j]];
        }
        ret += curr;
    }
    return ret;
}
void solve(){
    ll n,m;cin>>n>>m;
    vector<vector<int>>v(n,vector<int>(m));
    vector<vector<int>>v_(m,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
            v_[j][i] = v[i][j];
        }
    }
    cout<<counter(v)+counter(v_)<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    //cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}