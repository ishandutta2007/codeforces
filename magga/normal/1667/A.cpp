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
void solve(){
    ll n;cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    ll ans = 1e18;
    for(int i=0;i<n;i++){
        ll cans = 0;
        ll curr = 0;
        for(int j=i+1;j<n;j++){
            ll count = (curr + arr[j])/arr[j];
            cans += count;
            curr = count*arr[j];
        }
        curr = 0;
        for(int j=i-1;j>=0;j--){
            ll count = (curr + arr[j])/arr[j];
            cans += count;
            curr = count*arr[j];
        }
        ans = min(ans,cans);
    }
    cout<<ans<<"\n";
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