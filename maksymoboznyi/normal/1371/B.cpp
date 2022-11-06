#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int N = 1e6 + 6;



signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, r;
        cin >> n >> r;
        if (n > r) {
            cout << r * (r + 1) / 2 << "\n";
        } else {
            int x = n * (n - 1) / 2 + 1;
            cout << x << "\n";
        }
    }
    return 0;
}