#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

void solve() {
    ll n,m;
    cin>>n>>m;
    ll arr[2*n];
    long double one=1.0;
    for(int i=0; i<2*n; i++) cin>>arr[i];
    sort(arr,arr+(2*n));
    long double maxig=arr[0],maxib=arr[n];
    long double maxi=min(maxig*2,maxib);
    maxi=(maxi+(maxi/2))*n;
    maxi=min(maxi,m*one);
    cout<<fixed<<setprecision(6)<<maxi<<endl;
}

int main() {
    int t=1;
    // cin>>t;
    while(t--) {
        solve();
    }
}

/*
Lasted longer than expected, def not winning this round tho


zyxyz

xyzyz
yyxzz
*/