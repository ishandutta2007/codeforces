#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        vector<int> s(m);
        for (int& ss : s) cin >> ss;
        sort(begin(s), end(s));
        int fc = 0, t = 0;
        if (a < b) {
            t = b - 1;
            fc = b - a - 1;
        } else if (a > b) {
            t = n - b;
            fc = a - b - 1;
        }
        fc = min(fc, m);
        int lo = 0;
        int hi = fc;
        int res = 0;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            bool canDo = true;
            for (int i = 0; i < mid; ++i) {
                if (s[mid - i - 1] + i + 1 > t) {
                    canDo = false;
                    break;
                }
            }
            if (canDo) {
                lo = mid + 1;
                res = mid;
            } else {
                hi = mid - 1;
            }
        }
        cout << res << '\n';
    }
}