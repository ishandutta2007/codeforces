#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n;cin>>n;
    pair<long long int,long long int>arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].first>>arr[(i+1)%n].second;
    }
    long long int ans = 0;
    for(int i=0;i<n;i++){
        ans+=max(arr[i].first-arr[i].second,(long long int)0);
    }
    long long int base = ans;
    ans+=min(arr[0].second,arr[0].first);
    for(int i=0;i<n;i++){
        if(base+min(arr[i].second,arr[i].first)<ans){
            ans=base+min(arr[i].second,arr[i].first);
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