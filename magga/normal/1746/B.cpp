#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<": ";
#define pii pair<long long int,long long int>
#define F first
#define S second
typedef long long ll;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void pre(){}
void solve(){
    int n;cin>>n;
    int arr[n];
    int s = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        s+=arr[i];
    }
    int ans = n;
    int ones  = 0;
    int zeros = n - s;
    for(int i=0;i<=n;i++){
        ans = min(ans,max(zeros,ones));
        if(i!=n){
            if(arr[i]){
                ones++;
            }else{
                zeros--;
            }
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