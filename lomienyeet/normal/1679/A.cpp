#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;
    cin>>n;
    if(n&1||n==2)cout<<"-1\n";
    else cout<<(n+5)/6<<" "<<n/4<<"\n";
}
signed main(){
    int t;
    cin>>t;
    while(t--)solve();
}