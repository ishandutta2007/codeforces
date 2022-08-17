#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;

ll gcd (ll a, ll b)
{
    a = abs(a);
    b = abs(b);
    if (a<b) swap (a,b);
    while (b)
    {
        a%=b;
        if (a<b) swap (a,b);
    }
    return a;
}

int main()
{
    ll r=0, n, s, t, f;
    ll m[1001]={0};
    cin>>n>>s;
    for (int i=0; i<n; i++)
    {
        cin>>f>>t;
        m[f]=max(m[f], t);
    }

    for (int i=s; i>0; i--)
    {
        r = max(r, m[i]);
        r++;
    }
    cout<<r;
    return 0;
}