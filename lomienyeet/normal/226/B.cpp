#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
void solve(){
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=1;i<=n;i++)cin>>arr[i];
    sort(arr+1,arr+n+1,greater<int>());
    for(int i=2;i<=n;i++)arr[i]+=arr[i-1];
    int q;
    cin>>q;
    map<int,int> mp;
    while(q--){
        int y;
        cin>>y;
        if(mp.find(y)!=mp.end())cout<<mp[y]<<" ";
        else{
            int nig=1,lg=0,ans=0,cur=1;
            while(cur<n){
                lg++;
                nig*=y;
                ans+=lg*(arr[min(cur+nig,n)]-arr[cur]);
                cur+=nig;
            }
            mp[y]=ans;
            cout<<mp[y]<<" ";
        }
    }
}
signed main(){
    int t=1;
    //cin>>t;
    while(t--)solve();
}