#include <bits/stdc++.h>
using namespace std;

const int N = 300005;

int t, n, m, a[N], c[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= m; i++) {
            cin >> c[i];
        }
        sort(a + 1, a + n + 1);
        int mx = 1;
        for (int i = 1; i <= n; i++) {
            mx = max(mx, i - a[i] + 1);
        }
        int en = n - mx + 1;
        long long ans = accumulate(c + 1, c + en + 1, 0LL);
        for (int i = 1; i < mx; i++) {
            ans += c[a[i]];
        }
        for (int i = mx; i <= n; i++, en--) {
            if (a[i] < en) {
                ans += c[a[i]] - c[en];
            }
        }
        cout << ans << '\n';
    }
}