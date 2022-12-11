#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll a,b,x,y;
    cin>>a>>b>>x>>y;
    ll t=__gcd(x,y);
    x/=t,y/=t;
    cout<<min(b/y,a/x);
}