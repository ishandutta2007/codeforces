#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
const int N = 1e6+6;
const ll inf = 2e18;

ll s[N], n, l, ans, a[N];
ll g(ll x)
{
    ll r = 0, i = 1, k = 0;
    while (i*2 <= x)
        i *= 2, k++;
    while (i > 0)
    {
        r += (x/i)*a[k-1];
        x %= i;
        cout << k  << ' ' << r << endl;
        k--;
        i/=2;
    }
    return r;
}

bool is(int pos)
{
    for (int i = 0; i < pos; i++)
        if (a[i]*(s[pos]/s[i]) < a[pos])
            return 0;
    return 1;
}
signed main()
{
    ll gans = 9e18;
    ll tans=0;
    cin >> n >> l;
    s[0] = 1;
    ll tt = 1;
    for (int i = 1; i < n; i++)
        s[i] = s[i-1]*2;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = n-1; i > -1; i--)
    {
        if (i == 0 || is(i))
        {
            tans += (l/s[i])*a[i];
            l %= s[i];
        }
        gans = min(gans, tans + ((l-1)/s[i]+1)*a[i]);
    }
    cout << min(gans, tans);
    return 0;
}