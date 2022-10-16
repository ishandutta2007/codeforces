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
void solve(){
    int n,m;cin>>n>>m;
    vector<ll>arr;
    pii comp[4];
    comp[0] = {0,0};
    comp[1] = {n-1,0};
    comp[2] = {0,m-1};
    comp[3] = {n-1,m-1};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ll v = 0;
            for(auto k:comp){
                v = max(v,abs(k.F-i) + abs(k.S-j));
            }
            arr.push_back(v);
        }
    }
    sort(arr.begin(),arr.end());
    for(auto i:arr){
        cout<<i<<" ";
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