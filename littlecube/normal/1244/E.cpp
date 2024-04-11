#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define ll long long
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

ll n, k, x;
map<ll, ll> mp;

signed main()
{
    fast;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        mp[x]++;
    }
    while (k > 0 && mp.size() > 1)
    {
        if (k < min(mp.begin()->second, mp.rbegin()->second))
            break;
        if (mp.begin()->second < mp.rbegin()->second)
        {
            if (((++mp.begin())->first - mp.begin()->first) * mp.begin()->second > k)
                {
                    k = k / mp.begin()->second;
                    mp[mp.begin()->first + k] += mp.begin()->second;
                    mp.erase(mp.begin());
                    break;
                }
            else
            {
                k -= ((++mp.begin())->first - mp.begin()->first) * mp.begin()->second;
                mp[(++mp.begin())->first] += mp.begin()->second;
                mp.erase(mp.begin());
            }
        }
        else
        {
            if ((mp.rbegin()->first - (++mp.rbegin())->first) * mp.rbegin()->second > k)
            {
                k = k / mp.rbegin()->second;
                mp[mp.rbegin()->first - k] += mp.rbegin()->second;
                mp.erase((++mp.rbegin()).base());
                break;
            }
            else
            {
                k -= (mp.rbegin()->first - (++mp.rbegin())->first) * mp.rbegin()->second;
                mp[(--(++mp.rbegin()).base())->first] += mp.rbegin()->second;
                mp.erase((++mp.rbegin()).base());
            }
        }
    }
    cout << mp.rbegin()->first - mp.begin()->first << '\n';
}