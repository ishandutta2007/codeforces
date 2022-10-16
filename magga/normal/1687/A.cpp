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
void solve(){
    ll n,k;cin>>n>>k;
    ll arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    ll tans = 0;
    if(k>n){
        tans = (n*(n-1))/2 + (k-n)*n;
        k = n;
    }else{
        tans = (k*(k-1))/2;
    }
    ll ans = 0;
    ll curr = 0;
    for(int i=0;i<k-1;i++){
        curr+=arr[i];
    }
    for(int i=k-1;i<n;i++){
        curr+=arr[i];
        ans = max(ans,curr);
        curr-=arr[i-k+1];
    }
    cout<<ans+tans<<"\n";
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