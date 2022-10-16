#include<bits/stdc++.h>
using namespace std;
long long int mod = 998244353;
void pre(){}
void solve(){
    long long int n,k;cin>>n>>k;
    long long int ans = (n-k)*k+(k*(k+1))/2;
    long long int arr[n];
    vector<long long int>v;
    for(long long int i=0;i<n;i++){
        cin>>arr[i];
        if(n-arr[i]<k){
            v.push_back(i);
        }
    }
    long long int ans1 = 1;
    long long int p= v.size();
    for(long long int i=0;i<p-1;i++){
        ans1*=(v[i+1]-v[i]);
        ans1%=mod;
    }
    cout<<ans<<" "<<ans1<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    //cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}