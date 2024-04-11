#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define INF 1000000000
#define pii pair<long long int,long long int>
#define pb(a) push_back(a)
#define F first
#define S second
typedef long long ll;
using namespace std;
void pre(){}
void solve(){
    ll n;cin>>n;
    ll arr[n];
    map<int,vector<int>>m;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        m[arr[i]].push_back(i);
    }
    ll ans = 0;
    for(auto i:m){
        ll start = 0;
        for(auto j:i.S){
            start += n - j;
        }
        for(auto j:i.S){
            start -= n - j;
            ans += start*(j+1);
        }
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