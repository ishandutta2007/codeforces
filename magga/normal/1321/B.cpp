#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n;cin>>n;
    long long int arr[n];
    long long int b[n];
    map<long long int,long long int>m;
    for(long long int i=0;i<n;i++){
        cin>>arr[i];
        b[i]=arr[i];
        arr[i]-=i;
        m[arr[i]]+=b[i];
    }
    long long int ans = -1;
    for(auto i:m){
        ans=max(ans,i.second);
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