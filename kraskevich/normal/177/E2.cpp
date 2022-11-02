#include <iostream>
#include <cmath>
using namespace std;

#define ll long long

const ll inf = 2e18;

int n;
ll a[10000], b[10000];
ll c;

ll check(ll val)
{
     ll res = 0;
     for(int i = 0; i < n; ++i)
     {
             if((double)a[i] * val / b[i] > inf)
                     return inf;
             res += (ll)((double)a[i] * val / b[i]) + 1;
             res = min(res, inf);
     }
     return res;        
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    cin >> n >> c;
    
    bool any = false;
    for(int i = 0; i < n; ++i)
    {
            cin >> a[i] >> b[i];
            if(a[i] != 0)
                    any = true;
    }
    
    if(!any)
    {
            cout << (c == n ? -1 : 0);
            return 0;
    }
    
    ll l = 1, r = inf;
    while(l < r)
    {
            ll m = (l + r) / 2 + (l + r) % 2;
            if(check(m) > c)
                        r = m - 1;
            else
                l = m;
    }
    ll u = l;
    l = 1, r = inf;
    while(l < r)
    {
            ll m = (l + r) / 2;
            if(check(m) < c)
                        l = m + 1;
            else
                r = m;
    }
    ll d = l;
    if(check(u) != c || check(d) != c)
                 cout << 0;
    else
        cout <<  u - d + 1;
    
    cin >> n;
    
    return 0;
}