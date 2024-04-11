#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

void solve()
{
    int n, x, a[50], b[50];
    cin >> n >> x;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
        if (a[i] + b[n - i - 1] > x)
        {
            cout << "No\n";
            return;
        }
    cout << "Yes\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}