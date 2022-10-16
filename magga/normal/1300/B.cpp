#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n;cin>>n;
    long long int arr[2*n];
    for(long long int i=0;i<2*n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+2*n);
    cout<<arr[n]-arr[n-1]<<"\n";
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