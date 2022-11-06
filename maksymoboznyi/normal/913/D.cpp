#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
const int N = 1e6+6;
const ll inf = 2e18;

ll n, a[N], t[N], T;

bool check(ll x)
{
    vector<ll> p;
    for (int i = 1; i <= n; i++)
        if (a[i] >= x)
            p.pb(t[i]);
    sort(p.begin(), p.end());
    ll sum = 0, k = 0;
    for (int i = 0; i < int(p.size()); i++)
        if (sum + p[i] > T)
            break;
        else
        {
            k++;
            sum += p[i];
        }
    if (k >= x)
        return 1;
    else
        return 0;
}

signed main()
{
    cin >> n >> T;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> t[i];
    int l = 0, r = n+1;
    while (l < r-1)
    {
        int m = (l+r)/2;
        if (check(m))
            l = m;
        else
            r = m;
    }
    cout << l <<endl << l << endl;
    vector<pair<ll, int> > p;
    for (int i = 1; i <= n; i++)
        if (a[i] >= l)
            p.pb({t[i], i});
    sort(p.begin(), p.end());
    for (int i = 0; i < l; i++)
        cout << p[i].second << ' ';
    return 0;
}