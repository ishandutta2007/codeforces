#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b)
{
    a = abs(a);
    b = abs(b);
    while (b)
    {
        a%=b;
        swap(a,b);
    }
    return a;
}
int main()
{
    ll n, a, b,x,r=0;
    ll m[1000];
    cin>>x;
    r=x/5;
    x%=5;
    r+=x/4;
    x%=4;
    r+=x/3;
    x%=3;
    r+=x/2;
    x%=2;
    r+=x;
    cout<<r;
    return 0;
}