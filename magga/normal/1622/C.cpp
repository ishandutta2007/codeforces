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
    ll n,k;cin>>n>>k;
    ll arr[n];
    ll sum = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum += arr[i];
    }
    sort(arr,arr+n);
    ll ans = max(0ll,sum-k);
    ll j = 1;
    for(int i=n-1;i>=1;i--){
        j++;
        sum -= arr[i] - arr[0];
        ans = min(ans,j - 1 + max((sum - k + j - 1)/ j,0ll));
    }
    cout<<ans<<"\n";
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