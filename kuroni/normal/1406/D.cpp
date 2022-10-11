#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, q, l, r, v, u = 0;
long long a[N];
long long pos = 0, neg = 0;

long long max(long long u) {
    long long mid = u / 2;
    return max(mid, u - mid);
}

void add(long long u, int coe) {
    (u >= 0 ? pos : neg) += u * coe;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; a[i] -= u; u += a[i];
        if (i > 1) {
            add(a[i], 1);
        }
    }
    cin >> q;
    cout << max(a[1] + pos) << '\n';
    while (q--) {
        cin >> l >> r >> v;
        if (l > 1) {
            add(a[l], -1);
        }
        if (r < n) {
            add(a[r + 1], -1);
        }
        a[l] += v; a[r + 1] -= v;
        if (l > 1) {
            add(a[l], 1);
        }
        if (r < n) {
            add(a[r + 1], 1);
        }
        // cout << bit.query(1) << " " << pos << '\n';
        cout << max(a[1] + pos) << '\n';
    }
}