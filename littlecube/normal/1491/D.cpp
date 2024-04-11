#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

signed main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        if (b < a)
        {
            puts("NO");
            continue;
        }
        vector<int> u, v;
        for (int i = 0; i <= 30; i++)
            if (a & (1LL << i))
                u.emplace_back(i);
        for (int i = 0; i <= 30; i++)
            if (b & (1LL << i))
                v.emplace_back(i);
        if (u.size() < v.size())
        {
            puts("NO");
            continue;
        }
        bool p = true;

        for (int i = 0; i < v.size(); i++)
            if (v[i] < u[i])
                p = false;
        if (p)
            puts("YES");
        else
            puts("NO");
    }
}