#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n,m;cin>>n>>m;
    long long int arr[n];
    long long int ma[m];
    for(long long int i=0;i<m;i++)ma[i]=0;
    for(long long int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(n>m){
        cout<<0<<"\n";
        return;
    }
    long long int ans = 1;
    for(long long int i=0;i<n;i++){
        for(long long int j=i+1;j<n;j++){
            ans*=abs(arr[i]-arr[j]);
            ans%=m;
        }
    }
    cout<<ans<<"\n";
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