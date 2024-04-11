#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<int> a(n);
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            ans += abs(a[i]);
        }
        int k = 0;
        while (m--) {
            int u; cin >> u;
            k = __gcd(u, k);
        }
        vector<int> mi(k, numeric_limits<int>::max());
        vector<bool> xo(k);
        for (int i = 0; i < n; i++) {
            int ind = i % k;
            if (a[i] < 0) {
                xo[ind] = !xo[ind];
            }
            mi[ind] = min(mi[ind], abs(a[i]));
        }
        long long mre = numeric_limits<long long>::max();
        for (int j = 0; j < 2; j++) {
            long long cur = 0;
            for (int i = 0; i < k; i++) {
                if (xo[i] ^ j) {
                    cur += mi[i];
                }
            }
            mre = min(mre, cur);
        }
        cout << ans - 2 * mre << '\n';
    }
}