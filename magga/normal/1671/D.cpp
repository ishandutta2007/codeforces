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
// Please write the recurances once :(
void pre(){}
ll evaluate(ll a,ll mid,ll b){
    return abs(a-mid) + abs(b-mid) - abs(a - b);
}
void solve(){
    ll n,x;cin>>n>>x;
    ll ma = -1e18;
    ll mi = 1e18;
    ll arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        ma = max(ma,arr[i]);
        mi = min(mi,arr[i]);
    }
    ll cans = 0;
    for(int i=0;i<n-1;i++) cans += abs(arr[i]-arr[i+1]);
    ll lend = 1,hend = x;
    ll maans = min(abs(hend-arr[0]),abs(hend - arr[n-1]));
    ll mians = min(abs(lend-arr[0]),abs(lend - arr[n-1]));
    for(int i=0;i<n-1;i++){
        maans = min(maans,evaluate(arr[i],hend,arr[i+1]));
        mians = min(mians,evaluate(arr[i],lend,arr[i+1]));
    }
    if(mi > x){
        maans = 0;
    }else if(mi!=1){
        if(ma >= x) maans = 0;
    }else{
        mians = 0;
        if(ma >= x) {
            maans = 0;
        }
    }
    cout<<cans + maans + mians<<"\n";
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