#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
const ll maxn = 1e18;
ll res;
ll x;
bool y;
int main()
{
    ll a ,b,c=1;
    cin >> a >> b;
    while (c < a)
    {
        y=true;
        c=(c<<1);
    }
    if(y && c>1)
        c/=2;
    while(c < b*2)
    {
        c=(c<<1);
        x=1;
        while (x < c/2 )
        {
            ll d=(c-1)-x;
            if(d>=a && d<=b && d!=0)
                {
                    res++;
                }
            x=(x<<1);
        }
    }
    cout << res;
}