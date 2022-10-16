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
    long long int n,k;cin>>n>>k;
    long long int arr[n];
    long long int curr = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        curr+=arr[i];
    }
    curr-=n*k;
    long long int ans = curr;
    for(int i=0;i<n;i++){
        curr+=k;
        for(int j=n-1-i;j<min(n,n-1-i+32);j++){
            curr -= arr[j];
            arr[j]/=2;
            curr += arr[j];
        }
        ans = max(ans,curr);
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