#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ull unsigned long long
using namespace std;
const int N = 2e5;

struct cell
{
    ll mi, ma;
};
cell pref[N], suff[N];
ll a[N], n, p, q, rr, x = -5000000000000000000;

int main()
{
    cin >> n >> p >> q >> rr;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    pref[1] = {a[1], a[1]};
    for (int i = 2; i <= n; i++)
    {
        pref[i].mi = min(pref[i-1].mi, a[i]);
        pref[i].ma = max(pref[i-1].ma, a[i]);
    }
    suff[n].mi = a[n];
    suff[n].ma = a[n];
    for (int i = n-1; i > 0; i--)
    {
        suff[i].mi = min(suff[i+1].mi, a[i]);
        suff[i].ma = max(suff[i+1].ma, a[i]);
    }
    ll x0 = 0;
    for (int i = 1; i <= n; i++)
    {
        x0 = q*a[i];
        if (p <= 0)
            x0 += pref[i].mi*p;
        else
            x0 += pref[i].ma*p;
        if (rr <= 0)
            x0 += suff[i].mi*rr;
        else
            x0 +=suff[i].ma*rr;
        x = max(x, x0);
    }

    cout << x << endl;
    return 0;
}