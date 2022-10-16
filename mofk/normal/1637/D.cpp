#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        int s = 0;
        for (int i = 0; i < n; ++i) cin >> a[i], s += a[i];
        for (int i = 0; i < n; ++i) cin >> b[i], s += b[i];
        vector<vector<int>> f(n, vector<int>(s + 1, -1));
        f[0][a[0]] = a[0];
        f[0][b[0]] = b[0];
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j + a[i] <= s; ++j) if (~f[i-1][j]) f[i][j + a[i]] = a[i];
            for (int j = 0; j + b[i] <= s; ++j) if (~f[i-1][j]) f[i][j + b[i]] = b[i];
        }
        for (int k = s / 2; k >= 0; --k) if (~f[n-1][k]) {
            int cur = k;
            for (int i = n - 1; i >= 0; --i) {
                if (f[i][cur] == b[i]) swap(a[i], b[i]);
                cur -= a[i];
            }
            assert(cur == 0);
            break;
        }
        long long ans = 0;
        for (int i = 0; i < n; ++i) for (int j = 0; j < i; ++j) ans += (a[i] + a[j]) * (a[i] + a[j]);
        for (int i = 0; i < n; ++i) for (int j = 0; j < i; ++j) ans += (b[i] + b[j]) * (b[i] + b[j]);
        cout << ans << '\n';
    }
    return 0;
}