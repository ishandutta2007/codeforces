#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int n;cin>>n;
    pair<long long int,long long int> arr[n];
    for(long long int i=0;i<n;i++){
        cin>>arr[i].first;
        arr[i].first*=-1;
        arr[i].second=i;
    }
    sort(arr,arr+n);
    long long int ans =0;
    for(long long int i=0;i<n;i++){
        ans+=arr[i].first*i*-1+1;
    }
    cout<<ans<<"\n";
    for(long long int i=0;i<n;i++){
        cout<<arr[i].second+1<<" ";
    }
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