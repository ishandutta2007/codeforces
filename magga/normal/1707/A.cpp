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
// WRITE DOWN THE RECCURANCES FFS 
void pre(){}
void solve(){
    ll n,q;cin>>n>>q;
    long long int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<int>ans(n);
    long long int curr = 0;
    for(int i=n-1;i>=0;i--){
        if(arr[i]>curr){
            if(curr==q){
                ans[i] = 0;
            }else{
                ans[i] = 1;
                curr++;
            }
        }else{
            ans[i] = 1;
        }
    }
    for(int i=0;i<n;i++) cout<<ans[i];
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