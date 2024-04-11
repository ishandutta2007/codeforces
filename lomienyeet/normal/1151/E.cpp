#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n,ans=0;
    cin>>n;
    int arr[n+1];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        ans+=arr[i]*(n-arr[i]+1);
    }
    for(int i=1;i<n;i++)ans-=min(arr[i],arr[i+1])*(n-max(arr[i],arr[i+1])+1);
    cout<<ans<<"\n";
}