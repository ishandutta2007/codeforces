#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll a,b,c,d,k;
    cin>>a>>b>>c>>d>>k;
    ll j=min(b,d);
    ll i=max(a,c);
    ll x=0;
    if(k<=j && k>=i)
        x=j-i;
    else
        x=j-i+1;
    if(x<0)
        cout<<0;
    else
        cout<<x;
}