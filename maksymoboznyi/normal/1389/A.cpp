#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define all(x) (x).begin(), (x).end()
using namespace std;

const int N = 1e5 + 5;



signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        if (2 * l <= r)
            cout << l << ' ' << 2 * l << "\n";
        else
            cout << "-1 -1\n";
    }
    return 0;
}