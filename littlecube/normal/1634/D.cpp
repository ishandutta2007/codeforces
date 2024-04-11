#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int t, a[1003], b[1003], n;

signed main()
{
    // fast;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 3; i <= n; i++)
        {
            cout << "? 1 2 " << i << endl;
            cin >> a[i];
        }
        int mx = 3, mx2 = 2;
        for (int i = 3; i <= n; i++)
            if (a[i] > a[mx])
                mx = i;
        for (int i = 2; i <= n; i++)
            if (i != mx)
            {
                cout << "? 1 " << mx << " " << i << endl;
                cin >> b[i];
            }
        for (int i = 2; i <= n; i++)
            if (i != mx)
                if (b[i] > b[mx2])
                    mx2 = i;
        // Case 1: (1, 2) is min, max => mx2 = 2
        // Case 2: 1 is min/max => mx2 = 2
        // Case 3: 2 is min/max => mx2 = 2
        // Case 4: otherwise => mx2 != 2
        if (mx2 != 2)
            cout << "! " << mx << " " << mx2 << endl;
        else
        {
            bool same = 1;
            for (int i = 4; i <= n; i++)
                if (a[i] != a[i - 1])
                    same = 0;
            if (same)
                cout << "! 1 2" << endl;
            else
            {
                same = 1;
                for (int i = 3; i <= n; i++)
                    if (i != mx)
                        if (b[i] != b[2])
                            same = 0;
                if (same)
                    cout << "! 1 " << mx << endl;
                else
                    cout << "! 2 " << mx << endl;
            }
        }
    }
}