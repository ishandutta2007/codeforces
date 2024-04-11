#include <bits/stdc++.h>

using namespace std;

const long long inf = 9e18;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        long long l, r;
        unsigned n, x, y, z;
        cin >> n >> l >> r >> x >> y >> z;
        vector<unsigned> a(n);
        cin >> a[0] >> a[1];
        for (int i = 2; i < n; ++i) a[i] = (x * a[i-2] + y * a[i-1] + z);
        vector<long long> b(n);
        for (int i = 0; i < n; ++i) b[i] = (a[i] % (r - l + 1) + l);
        
        long long ans = inf, mn = inf;
        for (int i = 0; i < n; ++i) {
            if (b[i] > mn) ans = min(ans, b[i] * mn);
            else mn = b[i];
        }
        long long mx = -inf;
        for (int i = n - 1; i >= 0; --i) {
            if (b[i] < mx) ans = min(ans, b[i] * mx);
            else mx = b[i];
        }
        if (ans == inf) cout << "IMPOSSIBLE" << endl;
        else cout << ans << endl;
    }
    return 0;
}