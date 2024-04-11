#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    int ans=0;
    for(int i=1,x;i<=n;i++){
        cin>>x;
        ans=max(ans,x-i);
    }
    cout<<ans<<"\n";
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
}