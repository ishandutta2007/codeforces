#include <bits/stdc++.h>
using namespace std;

int a[100010], l, n, b[100010], c[100010], ans[100010];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> l >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[n + 1] = l;
    int l, r, mn;
    l = 1;
    r = 1e9;
    while (l < r) {
        int m = l + r + 1 >> 1;
        int k = 0, flag = 1;
        for(int i = 1; i <= n; i++) {
            k = max(k + m, a[i]);
            if (k > a[i + 1]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            l = m;
        }
        else {
            r = m - 1;
        }
    }
    mn = l + r + 1 >> 1;
    int mx;
    l = 1;
    r = 1e9;
    while (l < r) {
        int m = l + r >> 1;
        int k = 0, flag = 1;
        for(int i = 1; i <= n; i++) {
            k = min(k + m, a[i + 1]);
            if (k < a[i]) {
                flag = 0;
                break;
            }
        }
        if (k < a[n + 1]) flag = 0;
        if (flag) {
            r = m;
        }
        else {
            l = m + 1;
        }
    }
    mx = l + r >> 1;
    for(int i = 1; i < n; i++) {
        b[i] = max(b[i - 1] + mn, a[i]);
        c[i] = min(c[i - 1] + mx, a[i + 1]);
    }
    ans[n] = a[n + 1];
    for(int i = n - 1; i >= 1; i--) {
        ans[i] = min(c[i], ans[i + 1] - mn);
    }
    for(int i = 1; i <= n; i++) {
        cout << ans[i - 1] << ' ' << ans[i] << endl;
    }
    return 0;
}