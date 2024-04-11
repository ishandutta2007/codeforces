#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n,d,k;cin>>n>>d;
    long long int arr[n];
    for(long long int i=0;i<n;i++){
        cin>>arr[i];
    }
    long long int ans = arr[0];
    for(long long int i=1;i<n;i++){
        ans+=min(arr[i],d/i);
        k=min(arr[i],d/i);
        d-=k*i;
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