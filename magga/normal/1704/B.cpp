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
    long long int n,x;cin>>n>>x;
    long long int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    pii curr = {-1e17,1e17};
    long long int ans = 0;
    for(int i=0;i<n;i++){
        pii next = {arr[i]-x,arr[i]+x};
        curr.F = max(curr.F,next.F);
        curr.S = min(curr.S,next.S);
        if(curr.S<curr.F){
            ans++;
            curr = next;
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