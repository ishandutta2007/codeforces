#include<bits/stdc++.h>
using namespace std;
long long int mod = 1000000007;
void solve(){
    long long int n,m;cin>>n>>m;
    long long int arr[n];
    for(long long int i=0;i<n;i++){
        arr[i]=1;
    }
    long long int curr = 0;
    for(long long int i = 0;i<2*m-1;i++){
        curr=0;
        for(long long int i=0;i<n;i++){
            curr+=arr[i];
            curr%=mod;
            arr[i]=curr;
        }
    }
    long long int ans=0;
    for(long long int i:arr){
        ans+=i;
        ans%=mod;
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num = 1;
    //cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}