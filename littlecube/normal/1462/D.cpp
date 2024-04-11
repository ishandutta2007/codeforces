#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

void solve()
{
    int n, a[3000], total = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        total += a[i];
    }
    for (int r = 0; r <= n - 1; r++)
    {
        if (total % (n - r))
            continue;
        int sum = 0, tagert = total / (n - r);
        bool p = true;
        for (int i = 0; i < n; i++)
        {
            sum += a[i];
            if (sum > tagert)
            {
                p = 0;
                break;
            }
            else if (sum == tagert)
                sum = 0;
        }
        if (p)
        {
            cout << r << '\n';
            break;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}