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
    int n;cin>>n;
    ll arr[2*n][2*n];
    for(int i=0;i<2*n;i++){
        for(int j=0;j<2*n;j++){
            cin>>arr[i][j];
        }
    }
    ll ans = 0;
    for(int i=n;i<2*n;i++){
        for(int j=n;j<2*n;j++){
            ans+=arr[i][j];
        }
    }
    vector<pii>v{{0,0},{0,n-1},{n-1,0},{n-1,n-1}};
    ll m = 1e10;
    int a = n,b = 0;
    for(auto i:v){
        m = min(m,arr[i.F+a][i.S+b]);
    }  
    a = 0,b = n;
    for(auto i:v){
        m = min(m,arr[i.F+a][i.S+b]);
    }  
    cout<<ans+m<<"\n";
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