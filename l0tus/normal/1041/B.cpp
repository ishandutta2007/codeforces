#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll x, ll y)
{
    if(x<y) swap(x,y);
    if(x%y==0) return y;
    gcd(x%y,y);
}

int main()
{
    ll a,b,x,y;
    cin >> a >> b >> x >> y;
    ll k = x/gcd(x,y), j = y/gcd(x,y);
    cout << min(a/k,b/j);
}