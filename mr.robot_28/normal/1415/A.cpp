
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int n, m, r, c;
        cin >> n >> m >> r >> c;
        int a1 = abs(r - 1) + abs(c - 1);
        int a2 = abs(n - r) + abs(c - 1);
        int a3 = abs(n - r) + abs(m - c);
        int a4 = abs(r - 1) + abs(m - c);
        cout << max(max(a1, a2), max(a3, a4)) << "\n";
    }
    return 0;
}