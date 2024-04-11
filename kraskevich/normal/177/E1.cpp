#include <iostream>
using namespace std;

#define ll long long

int n;
ll a[10000], b[10000];
ll c;

ll check(ll val)
{
     ll res = 0;
     for(int i = 0; i < n; ++i)
             res += (a[i] * val) / b[i] + 1;
     return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    cin >> n >> c;
    for(int i = 0; i < n; ++i)
            cin >> a[i] >> b[i];
    
    ll l = 1, r = 1e9;
    
    while(l < r)
    {
            int m = (l + r) / 2 + (l + r) % 2;
            if(check(m) > c)
                        r = m - 1;
            else
                l = m;
    }
    int u = l;
    l = 1, r = 1e9;
    while(l < r)
    {
            int m = (l + r) / 2;
            if(check(m) < c)
                        l = m + 1;
            else
                r = m;
    }
    int d = l;
    if(check(u) != c || check(d) != c)
                 cout << 0;
    else
        cout <<  u - d + 1;
    
    cin >> n;
    
    return 0;
}