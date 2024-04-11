#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

signed main()
{

    fast;
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        if (n % 2)
            if (k % (n - 1) > n / 2)
                cout << ((k - 1) % (n - 1) + 1 + ((k) / (n - 1))) % n + 1 << '\n';
            else
                cout << ((k - 1) % (n - 1) + ((k) / (n - 1))) % n + 1 << '\n';
        else
            cout << (k - 1) % n + 1 << '\n';
    }
}