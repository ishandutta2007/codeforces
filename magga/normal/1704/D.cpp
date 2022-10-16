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
    long long int n,m;cin>>n>>m;
    pii arr[n];
    long long int a[m];
    for(int i=0;i<n;i++){
        for(int i=0;i<m;i++) cin>>a[i];
        for(int i=1;i<m;i++) a[i]+=a[i-1];
        arr[i].F = 0;
        for(int j=0;j<m;j++) arr[i].F += a[j];
        arr[i].S = i+1;
    }
    sort(arr,arr+n);
    cout<<arr[0].S<<" "<<arr[1].F - arr[0].F<<"\n";
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