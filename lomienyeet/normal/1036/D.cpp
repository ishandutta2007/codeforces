#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int arr[n+1],ps[n+1]={};
    for(int i=1;i<=n;i++)cin>>arr[i];
    for(int i=1;i<=n;i++)ps[i]=ps[i-1]+arr[i];
    int m;
    cin>>m;
    int arr2[m+1],ps2[m+1]={};
    map<int,bool> mp;
    for(int i=1;i<=m;i++)cin>>arr2[i];
    for(int i=1;i<=m;i++){
        ps2[i]=ps2[i-1]+arr2[i];
        mp[ps2[i]]=1;
    }
    if(ps[n]!=ps2[m]){
        cout<<"-1\n";
        return 0;
    }
    int ans=0;
    for(int i=1;i<=n;i++)ans+=mp[ps[i]];
    cout<<ans<<"\n";
}