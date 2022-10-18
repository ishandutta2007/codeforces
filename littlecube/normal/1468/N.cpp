#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n[3], a[5];
        cin >> n[0] >> n[1] >> n[2] >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
        n[0] -= a[0];
        n[1] -= a[1];
        n[2] -= a[2];
        a[3] = max(a[3] - n[0], 0);
        a[4] = max(a[4] - n[1], 0);
        if (a[3] + a[4] <= n[2] && n[0] >= 0 && n[1] >= 0 && n[2] >= 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}