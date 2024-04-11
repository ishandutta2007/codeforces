// timed lockout practice i guess?
// wtf 13 mins so slow

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
void solve() {
    int n;
    cin>>n;
    int k[n],h[n];
    pair<int,int> p[n];
    for(int i=0;i<n;i++)cin>>k[i];
    for(int i=0;i<n;i++){
        cin>>h[i];
        p[i]={k[i]-h[i],k[i]};
    }
    sort(p,p+n);
    int ans=0,l=-1,r=-1;
    for(int i=0;i<n;i++){
        if(p[i].ff>=r){
            ans+=((r-l+1)*(r-l))/2;
            l=p[i].ff;
            r=p[i].ss;
        }
        else r=max(r,p[i].ss);
    }
    ans+=((r-l+1)*(r-l))/2;
    cout<<ans<<"\n";
}
signed main(){
    int t;
    cin>>t;
    while(t--)solve();
}