#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

const int N = 2e5 + 5;
const long long inf = 2e18;
const long long M = 1e9 + 7;



signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long l, r, q, x, d;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> l >> r >> d;
        if (d < l)
            cout << d << "\n";
        else {
            if (r % d == 0)
            cout << r + d << "\n";
        else
            cout << r + d - r % d << "\n";
        }
    }
    return 0;
}