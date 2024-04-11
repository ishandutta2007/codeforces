#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        long long k; cin >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        if (accumulate(a.begin(), a.end(), 0LL) <= k) {
            cout << "0\n";
        } else {
            long long ans = numeric_limits<long long>::max(), cur = k;
            for (int i = 0; i < n; i++) {
                if (i > 0) {
                    cur -= a[i];
                }
                long long x = cur / (n - i);
                if (x * (n - i) > cur) {
                    x--;
                }
                ans = min(ans, n - 1 - i + max(a[0] - x, 0LL));
            }
            cout << ans << '\n';
        }
    }
}