#include <bits/stdc++.h>
using namespace std;
void solve(){
    long long a,b,c;
    cin>>a>>b>>c;
    long long ans=(a+b+c)/2;
    ans=min(ans,a+b);
    ans=min(ans,b+c);
    ans=min(ans,c+a);
    cout<<ans<<"\n";
    return;
}
int main(){
    int T;
    cin>>T;
    while(T--)solve();
    return 0;
}