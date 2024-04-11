#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
signed main(){
    int n,m,k;
    cin>>n>>m>>k;
    k++;
    set<pair<int,int> > s;
    for(int i=0,x;i<n;i++){
        cin>>x;
        s.insert({x,i});
    }
    int ans[n]={},ptr=1;
    while(s.size()){
        auto e=*s.begin();
        ans[e.ss]=ptr++;
        s.erase(s.begin());
        auto x=s.lower_bound({e.ff+k,-1e18});
        while(x!=s.end()){
            auto ee=*x;
            ans[ee.ss]=ans[e.ss];
            s.erase(x);
            x=s.lower_bound({ee.ff+k,-1e18});
        }
    }
    cout<<ptr-1<<"\n";
    for(int i=0;i<n;i++)cout<<ans[i]<<" ";
}