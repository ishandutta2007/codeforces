#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define F first
#define S second

bool cmp(pll a, pll b)
{
     return a.S < b.S;
}
       
int main()
{
    ios_base::sync_with_stdio(0);
    
    int n;
    
    cin >> n;
    
    pll k[n];
    
    for(int i = 0; i < n; ++i)
            cin >> k[i].F >> k[i].S;
    
    sort(k, k + n, cmp);
    
    int t;
    
    cin >> t;
    
    ll p[t];
    
    for(int i = 0; i < t; ++i)
            cin >> p[i];
    
    ll mult = 0, res = 0, all = 0;
    
    for(int i = 0; i < n; ++i)
    {
            while(mult < t && p[mult] - all <= k[i].F && all <= p[mult])
            {
                       res += k[i].S * (mult + 1) * (p[mult] - all);
                       k[i].F -= (p[mult] - all);
                       all += p[mult] - all;
                       ++mult;
            }
            res += (mult + 1) * k[i].S * k[i].F;
            all += k[i].F;
    }
    
    cout << res;
    
    cin >> n;
    
    return 0;
}