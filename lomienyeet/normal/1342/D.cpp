#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
void solve(){
    int n,k;
    cin>>n>>k;
    int arr[k+1]={},a[k+1],ps[k+5]={};
    for(int i=0,u;i<n;i++){
        cin>>u;
        arr[u]++;
    }
    for(int i=1;i<=k;i++)cin>>a[i];
    for(int i=k;i>=1;i--)ps[i]=ps[i+1]+arr[i];
    int ans=0,mengbier=0;
    for(int i=1;i<=k;i++)ans=max(ans,ps[i]/a[i]+(ps[i]%a[i]>0));
    cout<<ans<<"\n";
    vector<int> res[ans+1];
    for(int i=k;i>=1;i--){
        for(int j=1;j<=arr[i];j++){
            (mengbier%=ans)+=1;
            res[mengbier].push_back(i);
        }
    }
    for(int i=1;i<=ans;i++){
        cout<<res[i].size()<<" ";
        for(auto j:res[i])cout<<j<<" ";
        cout<<"\n";
    }
}
signed main(){
    int t=1;
    //cin>>t;
    while(t--)solve();
}