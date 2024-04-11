#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n;cin>>n;
    long long int arr[n];
    for(long long int i=0;i<n;i++)cin>>arr[i];
    sort(arr,arr+n,greater<>());
    for(long long int i=0;i<n;i++)cout<<arr[i]<<" ";
    cout<<"\n";
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