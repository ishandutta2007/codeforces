#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
struct cell
{
    ll l, r;
};

ll sum, n, m, a[10000];
cell x[10000];
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x[i].l >> x[i].r;
        if (x[i].r >= sum)
        {
            cout << max(sum, x[i].l);
            return 0;
        }
    }
    cout << -1;
    return 0;
}