#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, r, ans = 1, a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> r;
    r--;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int cur = 0;
    for (int i = 1; i <= r + 1; i++) {
        if (a[i] == 1) {
            cur = max(cur, i);
        }
    }
    if (cur == 0) {
        return cout << -1, 0;
    }
    while (cur < n - r) {
        int nxt = 0;
        for (int i = cur + 1; i <= n && i <= cur + 2 * r + 1; i++) {
            if (a[i] == 1) {
                nxt = max(nxt, i);
            }
        }
        if (nxt == 0) {
            return cout << -1, 0;
        }
        cur = nxt;
        ans++;
    }
    cout << ans;
}