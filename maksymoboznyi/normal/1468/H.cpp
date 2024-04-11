#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k, m;
        cin >> n >> k >> m;
        vector<bool> rem(n, true);
        for (int i = 0; i < m; ++i) {
            int bb;
            cin >> bb;
            rem[bb - 1] = false;
        }
        int sumA = 0, p = (k - 1) / 2;
        if ((n - m) % (k - 1) != 0) {
            cout << "NO\n";
            continue;
        }
        bool isYes = false;
        for (int i = 0; i < n; ++i) {
            if (rem[i]) {
                ++sumA;
            } else if (sumA >= p && (n - m) - sumA >= p) {
                isYes = true;
                break;
            }
        }
        if (isYes) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}