#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[105];
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    int n, pos, l, r;
    cin >> n >> pos >> l >> r;
    if (l == 1 && r == n) {
        cout << 0;
        return 0;
    }
    int ans = 0;
    if (pos < l) {
        ans += l - pos + 1;
        if (r < n) {
            ans += r - l + 1;
        }
        cout << ans;
        return 0;
    }
    if (pos > r) {
        ans += pos - r + 1;
        if (1 < l) {
            ans += r - l + 1;
        }
        cout << ans;
        return 0;
    }
    if (l <= pos && pos <= r) {
        if (l > 1 && r < n) {
            cout << min(pos - l + 1, r - pos + 1) + (r - l + 1);
            return 0;
        }
        if (l == 1) {
            cout << r - pos + 1;
        }
        if (r == n) {
            cout << pos - l + 1;
        }
        return 0;
    }
    return 0;
}