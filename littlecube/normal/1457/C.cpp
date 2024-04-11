#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, p, k, x, y;
        ll r = _INFINITY;
        int a[100005];
        cin >> n >> p >> k;
        for (int i = 1; i <= n; i++)
        {
            char c;
            cin >> c;
            a[i] = 1 - (c - '0');
        }

        for (int i = n; i >= 0; i--)
        {
            if (i + k <= n)
                a[i] += a[i + k];
        }


        cin >> x >> y;
        for (int i = p; i <= n; i++)
            r = min(r, (i - p) * y + a[i] * x);

        cout << r << '\n';
    }
}