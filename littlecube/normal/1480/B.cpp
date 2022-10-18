#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

pll a[100005];
signed main()
{

    fast;
    int t;
    cin >> t;
    while (t--)
    {
        ll A, B, n;
        cin >> A >> B >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i].first;
        for (int i = 0; i < n; i++)
            cin >> a[i].second;
        sort(a, a + n, [](pll p1, pll p2)
             { return p1.first < p2.first; });
        for (int i = 0; i < n - 1; i++)
        {
            B -= ((a[i].second + A - 1) / A) * a[i].first;
            if (B <= 0)
                break;
        }

        if (B > ((a[n - 1].second + A - 1) / A - 1) * a[n - 1].first)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}