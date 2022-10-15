#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
#define int long long
#define ff first
#define ss second
signed main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    tree<pair<int,int>,null_type,less<pair<int,int> >,rb_tree_tag,tree_order_statistics_node_update> ost;
    for(int i=0;i<n;i++)ost.insert({arr[i],i});
    int ans;
    if(ost.size()==1)ans=ost.begin()->ff;
    else ans=ost.find_by_order((ost.size()-1)/2)->ff;
    int l=ans+1,r=n;
    while(l<=r){
        int m=(l+r)>>1,ps[n+1]={},mn[n+1]={};
        for(int i=1;i<=n;i++){
            ps[i]=ps[i-1]-1;
            if(arr[i-1]>=m)ps[i]+=2;
        }
        for(int i=0;i<=n;i++){
            mn[i]=ps[i];
            if(i>1)mn[i]=min(mn[i],mn[i-2]);
        }
        bool add=0;
        for(int i=k;i<=n;i++){
            for(int j=i-k;j>=max(0ll,i-k-3);j--){
                if((!((i+j)&1)&&ps[i]>=mn[j]+2)||((i+j)&1&&ps[i]>=mn[j]+1)){
                    add=1;
                    goto die;
                }
            }
        }
        die:;
        if(add){
            ans=m;
            l=m+1;
        }
        else r=m-1;
    }
    cout<<ans<<"\n";
}