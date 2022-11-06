#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
const int N = 1e6+6;
const ll inf = 2e18;

ll n, m, q = 1;

signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        q *= 2;
        if (q > m)
        {
            cout << m;
            return 0;
        }
    }
    cout << m % q;
    return 0;
}