#include <bits/stdc++.h>
using namespace std;

const int N = 3E5 + 5;

int n, q, mx = 0, cnt = 0, a[N], le[N], ri[N];

void solve() {
    for (int i = 1; i <= n; i++) {
        le[a[i]] = ri[a[i]] = 0;
    }
    mx = cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (le[a[i]] == 0) {
            le[a[i]] = i;
            ++cnt;
        }
        ri[a[i]] = i;
    }
    int pt = 1;
    while (pt <= n) {
        int cur = 0, r = 0;
        while (pt <= n) {
            if (le[pt] == 0) {
                pt++;
                continue;
            }
            if (le[pt] <= r) {
                break;
            }
            cur++;
            r = ri[pt++];
        }
        mx = max(mx, cur);
    }
    cout << cnt - mx << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> q;
    while (q--) {
        solve();
    }
}