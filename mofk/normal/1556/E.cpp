#include <bits/stdc++.h>

using namespace std;

int n, q;
long long a[100005];
long long s[100005];
long long mn[100005][20];
long long mx[100005][20];

long long qmin(int l, int r) {
    int k = log2(r - l + 1);
    return min(mn[l][k], mn[r - (1<<k) + 1][k]);
}

long long qmax(int l, int r) {
    int k = log2(r - l + 1);
    return max(mx[l][k], mx[r - (1<<k) + 1][k]);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int x;
    for (int i = 1; i <= n; ++i) cin >> x, a[i] -= x;
    for (int i = 1; i <= n; ++i) s[i] = s[i-1] + a[i];

    for (int i = 1; i <= n; ++i) mn[i][0] = mx[i][0] = s[i];
    for (int j = 1; j < 18; ++j) {
        for (int i = 1; i + (1 << j) - 1 <= n; ++i) mn[i][j] = min(mn[i][j-1], mn[i+(1<<j-1)][j-1]);
        for (int i = 1; i + (1 << j) - 1 <= n; ++i) mx[i][j] = max(mx[i][j-1], mx[i+(1<<j-1)][j-1]);
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        if (s[r] != s[l-1]) {
            cout << -1 << '\n';
            continue;
        }
        if (qmax(l, r) > s[l-1]) {
            cout << -1 << '\n';
            continue;
        }
        cout << s[l-1] - qmin(l, r) << '\n';
    }
    return 0;
}