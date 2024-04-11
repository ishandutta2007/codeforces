#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b)
{
    a = abs(a);
    b = abs(b);
    if (a<b) swap(a,b);
    while (b)
    {
        a%=b;
        swap(a,b);
    }
    return a;
}

int main()
{
    ll d, L, v1, v2;
    cin>>d>>L>>v1>>v2;
    ll dist = L-d;
    ll v = v1+v2;
    double res = (double)dist / (double) v;
    cout.precision(10);
    cout<<res;
    return 0;
}