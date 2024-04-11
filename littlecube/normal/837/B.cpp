#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    int n, m;
    char c[105][105], v[3], h[3];
    bool b = false;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> c[i][j];

    if (n % 3 == 0)
    {
        h[0] = c[0][0];
        h[1] = c[n / 3][0];
        h[2] = c[n / 3 * 2][0];
        bool tb = true;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (c[i][j] != h[i / (n / 3)])
                {
                    tb = false;
                    break;
                }
        if (tb && h[0] != h[1] && h[2] != h[1] && h[0] != h[2])
            b = true;
    }
    if (m % 3 == 0)
    {
        v[0] = c[0][0];
        v[1] = c[0][m / 3];
        v[2] = c[0][m / 3 * 2];
        bool tb = true;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (c[i][j] != v[j / (m / 3)])
                {
                    tb = false;
                    break;
                }
        if (tb && v[0] != v[1] && v[0] != v[2] && v[2] != v[1])
            b = true;
    }

    if (b)
        cout << "YES\n";
    else
        cout << "NO\n";
}