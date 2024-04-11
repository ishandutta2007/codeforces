#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        long long ans = numeric_limits<long long>::max();
        vector<int> le(3), ri(3);
        le[0] = abs(a[0] - b[0]); le[1] = abs(a[0] - b[n - 1]); le[2] = numeric_limits<int>::max();
        ri[0] = abs(a[n - 1] - b[0]); ri[1] = abs(a[n - 1] - b[n - 1]); ri[2] = numeric_limits<int>::max();
        int ul = numeric_limits<int>::max(), ur = numeric_limits<int>::max();
        for (int i = 1; i < n - 1; i++) {
            le[2] = min(le[2], abs(a[0] - b[i]));
            ri[2] = min(ri[2], abs(a[n - 1] - b[i]));
        }
        for (int i = 0; i < n; i++) {
            ul = min(ul, abs(b[0] - a[i]));
            ur = min(ur, abs(b[n - 1] - a[i]));
        }
        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++) {
                long long cur = le[x] + ri[y];
                if (x != 0 && y != 0) {
                    cur += ul;
                }
                if (x != 1 && y != 1) {
                    cur += ur;
                }
                ans = min(ans, cur);
            }
        }
        cout << ans << '\n';
    }
}