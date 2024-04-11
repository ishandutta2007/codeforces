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
    int n;cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int last = n-1;
    while(last>0 && arr[last]==0) last--;
    if(last==-1){
        cout<<"Yes"<<"\n";
        return;
    }
    n = last+1;    
    for(int i=1;i<n;i++){
        arr[i]+=arr[i-1];
    }
    for(int i=0;i<n-1;i++){
        if(arr[i]<=0){
            cout<<"No"<<"\n";
            return;
        }
    }
    if(arr[n-1]==0) cout<<"Yes"<<"\n";
    else cout<<"No"<<"\n";
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