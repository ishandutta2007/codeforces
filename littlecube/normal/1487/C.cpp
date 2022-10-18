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
        int n;
        cin >> n;
        if (n % 2)
        {
            for (int i = 1; i <= n * (n - 1) / 2; i++)
                if (i % 2)
                    cout << 1 << " ";
                else
                    cout << -1 << " ";
            cout << '\n';
        }
        else
        {
            for (int i = 1; i <= n; i++)
                for (int j = i + 1; j <= n; j++)
                    if ((i % 2) && j == i + 1)
                        cout << 0 << " ";
                    else if (i % 2)
                        if (j % 2)
                            cout << -1 << " ";
                        else
                            cout << 1 << " ";
                    else 
                        if (j % 2)
                            cout << 1 << " ";
                        else
                            cout << -1 << " ";
            cout << '\n';
        }
    }
}