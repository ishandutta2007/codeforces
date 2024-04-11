#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;
void solve()
{
    int n, k, h[200000], hmax, hmin;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> h[i];
    hmin = h[0];
    hmax = h[0];
    for (int i = 1; i < n; i++)
    {
        hmin = max(hmin - k + 1, h[i]);
        hmax = min(hmax + k - 1, h[i] + k - 1);
        if (hmin > hmax)
        {
            cout << "NO\n";
            return;
        }
    }
    if (hmin <= h[n - 1] && h[n - 1] <= hmax)
        cout << "YES\n";
    else
        cout << "NO\n";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}