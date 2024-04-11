#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n, l, r, c;
        cin >> n >> l >> r;
        vector<int> a(n + 1, 0), b(n + 1, 0);
        for (int i = 0; i < l; ++i) cin >> c, ++a[c];
        for (int i = 0; i < r; ++i) cin >> c, ++b[c];
        int ans = 0, sa = 0, sb = 0, ma = 0, mb = 0;
        for (int i = 1; i <= n; ++i) {
            int m = min(a[i], b[i]);
            a[i] -= m;
            b[i] -= m;
            sa += a[i];
            sb += b[i];
            ma += a[i] / 2;
            mb += b[i] / 2;
        }
        if (sa < sb) swap(sa, sb), swap(ma, mb);
        if (sa - ma * 2 <= sb) ans += (sa + sb) / 2;
        else ans += (sa + sb) / 2 + (sa - ma * 2 - sb) / 2;
        cout << ans << '\n';
    }
    return 0;
}