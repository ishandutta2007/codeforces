#include <bits/stdc++.h>
#define pb push_back
#define ll long long

using namespace std;

const int N = 1e5 + 5;
const long long M = 1e9 + 7;
const long long inf = 2e18;

long long n, k;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    for (int o = 0; o < q; o++) {
        long long l, r;
        cin >> l >> r;
        if (l % 2 == 1)
            if (r % 2 == 1)
                cout << (r - l + 1) / 2 - r;
            else
                cout << (r - l + 1) / 2;
        else
            if (r % 2 == 1)
                cout << -(r - l + 1 ) / 2;
            else
                cout << l + (r - l + 1) / 2;
        cout << "\n";
    }
    return 0;
}