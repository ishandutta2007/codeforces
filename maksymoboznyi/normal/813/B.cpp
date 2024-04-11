#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

vector<ll> pos;

ll x, y, l, r;
ll get(ll a, ll b)
{
    ll res = 1;
    for (int i = 0; i < b; i++)
    {
        if (res > r / a + 1)
            return -1;
        res *= a;
    }
    return res;
}

int main()
{
    cin >> x >> y >> l >> r;

    pos.pb(l-1);
    pos.pb(r+1);
    for (int a = 0; a < 1000; a++)
    {
        ll x1 = get(x, a);
        if (x1 == -1 || x1 > r)
            break;
        for (int b = 0; b < 100; b++)
        {
            ll x2 = get(y, b);
            if (x2 == -1 || x2+x1 > r)
                break;
            if (x1+x2 >= l && x1+x2 <= r)
            pos.pb(x1+x2);
        }
    }
    sort(pos.begin(), pos.end());
    ll ma = -1;
    for (int i = 0; i < int(pos.size()-1); i++)
        ma = max(pos[i+1] - pos[i] - 1, ma);
    cout << ma;
    return 0;
}