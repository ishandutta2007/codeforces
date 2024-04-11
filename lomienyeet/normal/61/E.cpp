// "proactive student!!!"
// - description of xenxation, 2022

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
//#define int long long
#define ost tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
signed main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    ost l,r;
    l.insert(arr[0]);
    for(int i=2;i<n;i++)r.insert(arr[i]);
    long long ans=0;
    for(int i=1;i<n-1;i++){
        ans+=(1ll*l.size()-l.order_of_key(arr[i]))*(1ll*r.order_of_key(arr[i]));
        l.insert(arr[i]);
        r.erase(arr[i+1]);
    }
    cout<<ans<<"\n";
}