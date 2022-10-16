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
// WRITE DOWN THE RECCURANCES FFS 
// Please write the recurances once :(
void pre(){}
void solve(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<vector<int>>antipairs(n);
    vector<int>ends(n,0);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                antipairs[i].push_back(j);
                ends[j]++;
            }
        }
    }
    ll ans = 0;
    ll counter = 0;
    for(int i=0;i<n;i++){
        for(auto j:antipairs[i]){
            ends[j]--;
        }
        for(int j=i+1;j<n;j++){
            counter-=ends[j];
            if(arr[i]<arr[j])
                ans+=counter;
            counter+=antipairs[j].size();
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