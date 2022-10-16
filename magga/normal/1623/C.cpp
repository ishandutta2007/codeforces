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
ll arr[200001];
int n;
bool check(ll m){
    vector<ll>target(n);
    for(int i=0;i<n;i++) target[i]=m;
    for(int i=n-1;i>=2;i--){
        target[i] = max(target[i],0ll);
        if(target[i]>arr[i]){
            return false;
        }else{
            target[i-1] -= (arr[i]-target[i])/3;
            target[i-2] -= 2*((arr[i]-target[i])/3);
        }
    }
    return (target[1]<=arr[1])&&(target[0]<=arr[0]);
}
void solve(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    ll start = 0,end=1e9,mid,ans=0;
    while(start<=end){
        mid = (start+end+1)/2;
        if(check(mid)){
            ans = mid;
            start = mid+1;
        }else{
            end = mid-1;
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