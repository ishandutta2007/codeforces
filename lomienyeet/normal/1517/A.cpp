#include <bits/stdc++.h>
using namespace std;
#define int long long
void eat(){
    int x;
    cin>>x;
    if(x%2050){
        cout<<"-1\n";
        return;
    }
    x/=2050;
    int ans=0;
    while(x){
        ans+=x%10;
        x/=10;
    }
    cout<<ans<<"\n";
}
signed main(){
    int t=1;
    cin>>t;
    while(t--)eat();
}