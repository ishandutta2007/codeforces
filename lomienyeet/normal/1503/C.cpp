#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
signed main(){
    int n,ans=0;
    cin>>n;
    vector<pair<int,int> > v;
    for(int i=1,a,b;i<=n;i++){
        cin>>a>>b;
        v.push_back({a,a+b});
        ans+=b;
    }
    sort(v.begin(),v.end());
    int e=v[0].ff;
    for(int i=0;i<n;i++){
        ans+=max(0ll,v[i].ff-e);
        e=max(e,v[i].ss);
    }
    cout<<ans<<"\n";
}