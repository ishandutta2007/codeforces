#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int N = 2e5 + 5;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        if (n == 1) {
            cout << "0\n";
            continue;
        }
        if (n == 2) {
            cout << m << "\n";
            continue;
        }
        cout << 2 * m << "\n";
    }
    return 0;
}