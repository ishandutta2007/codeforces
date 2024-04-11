#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

signed main()
{
    fast;
    int t, n, a, b, c, d;
    cin >> t;
    while (t--)
    {
        cin >> n >> a >> b >> c >> d;

        for (int i = 0; i <= 15; i++)
        {
            bool p = true;
            if (i & 1 && i & 2)
            {
                if (a < 2)
                    p = false;
            }
            else if (i & 1 || i & 2)
            {
                if (a < 1 || a == n)
                    p = false;
            }
            else
            {
                if (a >= n - 1)
                    p = false;
            }

            if (i & 2 && i & 4)
            {
                if (b < 2)
                    p = false;
            }
            else if (i & 2 || i & 4)
            {
                if (b < 1 || b == n)
                    p = false;
            }
            else
            {
                if (b >= n - 1)
                    p = false;
            }

            if (i & 4 && i & 8)
            {
                if (c < 2)
                    p = false;
            }
            else if (i & 4 || i & 8)
            {
                if (c < 1 || c == n)
                    p = false;
            }
            else
            {
                if (c >= n - 1)
                    p = false;
            }

            if (i & 1 && i & 8)
            {
                if (d < 2)
                    p = false;
            }
            else if (i & 1 || i & 8)
            {
                if (d < 1 || d == n)
                    p = false;
            }
            else
            {
                if (d >= n - 1)
                    p = false;
            }

            if (p)
            {
                cout << "YES\n";
                break;
            }
            if (!p && i == 15)
                cout << "NO\n";
        }
    }
}