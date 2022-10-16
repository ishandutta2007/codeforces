#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n;cin>>n;
    long long int arr[n];
    for(long long int i=0;i<n;i++) cin>>arr[i];
    long long int ans[n];
    long long int curr = 0;
    for(long long int i=0;i<n;i++){
        ans[i]=curr+arr[i];
        curr=max(curr,ans[i]);
    }
    for(long long int i:ans){
        cout<<i<<" ";
    }
    cout<<"\n";
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