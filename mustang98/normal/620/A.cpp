#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b)
{
    a=abs(a);
    b=abs(b);
    if (a<b) swap(a,b);
    while (b)
    {
        a = a%b;
        swap(a,b);
    }
    return a;
}

int main()
{
    ll n, x,y,x1,y1;
    cin>>x>>y>>x1>>y1;
    ll a = abs(x1-x);
    ll b = abs(y1-y);
    ll r = min(a,b)+abs(a-b);
    cout<<r;

    return 0;
}