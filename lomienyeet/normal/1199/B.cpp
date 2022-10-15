#include <bits/stdc++.h>
using namespace std;
void solve(){
    double h,l,ans=0.0;
    cin>>h>>l;
    ans=(l*l-h*h)/(2.0*h);
    cout<<fixed<<setprecision(10)<<ans<<"\n";
}
int main(){
    int T;
    T=1;
    while(T--)solve();
    return 0;
}