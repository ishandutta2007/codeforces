#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 3e5 + 5;

int n, a[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        if (a[1] == 1) {
            cout << "YES\n";
            continue;
        }
        bool can = 1;
        int gr = -1;
        for (int i = n; i > 1; i--) {
            if (a[i] < a[1]) {
                if (gr < a[i])
                    can = 0;
            }
            gr = max(gr, a[i]);
        }
        if (can)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}