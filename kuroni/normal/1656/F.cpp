#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        long long xa = 0, xb = 0, ans = numeric_limits<long long>::min();
        for (int i = 1; i < n; i++) {
            xa += a[0] + a[i];
            xb += 1LL * a[0] * a[i];
        }
        if (xa > 0) {
            ans = numeric_limits<long long>::max();
        }
        for (int i = 0; i < n; i++) {
            ans = max(ans, xa * (-a[i]) + xb);
            if (i > 0 && i < n - 1) {
                xa -= a[0] + a[i]; xb -= 1LL * a[0] * a[i];
                xa += a[n - 1] + a[i]; xb += 1LL * a[n - 1] * a[i];
            }
            ans = max(ans, xa * (-a[i]) + xb);
        }
        if (xa < 0) {
            ans = numeric_limits<long long>::max();
        }
        if (ans == numeric_limits<long long>::max()) {
            cout << "INF\n";
        } else {
            cout << ans << '\n';
        }
    }
}