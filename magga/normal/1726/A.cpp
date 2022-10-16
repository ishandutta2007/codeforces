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
    long long int n;cin>>n;
    long long int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    long long int ans = a[n-1] - a[0];
    for(int i=0;i<n;i++){
        ans = max(ans,a[i] - a[(i+1)%n]);
    }
    for(int i=1;i<n;i++)   ans = max(ans,a[i]-a[0]);
    for(int i=0;i<n-1;i++) ans = max(ans,a[n-1]-a[i]);
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