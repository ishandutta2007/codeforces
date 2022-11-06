#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
using namespace std;

int xa, ya, xb, yb;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> xa >> ya >> xb >> yb;
    if (xa != xb && ya != yb) {
        cout << 2 * (abs(xa - xb) + abs(ya - yb)) + 4;
        return 0;
    }
    if (xa == xb) {
        cout << 2 * (abs(ya - yb) - 1) + 8;
        return 0;
    }

    if (ya == yb) {
        cout << 2 * (abs(xa - xb) - 1) + 8;
        return 0;
    }
    return 0;
}