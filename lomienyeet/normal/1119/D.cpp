#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=1;i<=n;i++)cin>>arr[i];
    sort(arr+1,arr+n+1);
    int d[n];
    for(int i=1;i<n;i++)d[i]=arr[i+1]-arr[i];
    sort(d+1,d+n);
    int ps[n]={};
    for(int i=1;i<n;i++)ps[i]=ps[i-1]+d[i];
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        int x=lower_bound(d+1,d+n,r-l+1)-d-1;
        cout<<(n-x)*(r-l+1)+ps[x]<<" ";
    }
    cout<<"\n";
}