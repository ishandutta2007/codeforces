#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b)
{
    a = abs(a);
    b = abs(b);
    if (a<b) swap (a,b);
    while (b)
    {
        a%=b;
        swap(a,b);
    }
    return a;
}

int main()
{
    ll n;
    cin>>n;
    if (n<6 || n%2==1) {cout<<0; return 0;}
    else
    {
        n/=2;
        if (n%2==0) cout<<n/2-1;
        else cout<<n/2;
    }
    return 0;
}