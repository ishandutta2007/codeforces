#include <bits/stdc++.h>

void openFile() {
    freopen("train.in", "r", stdin);
    freopen("train.out", "w", stdout);
}

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 205;

int n, m, k, a[N], b[N], c[N];
long long ans, d[N], f[N];

bool check() {
    for (int i = 0; i < n; i++) {
        f[i] = a[i];
    }
    for (int i = 0; i < m; i++) {
        long long p = k * d[i], e;
        for (int j = 0; j < n; j++) {
            e = std::min(f[j], p);
            f[j] -= e; p -= e;
            f[j] += b[j];
            if (f[j] > c[j]) { return false; }
        }
    }
    return true;
}

int main() {
    // openFile();
    n = read(); m = read(); k = read();
    for (int i = 0; i < n; i++) {
        a[i] = read(); b[i] = read(); c[i] = read();
    }
    for (int i = 0; i < m; i++) {
        d[i] = 3e18 / k;
    }
    for (int i = m - 1; i >= 0; i--) {
        long long res = 0;
        for (long long l = 0, r = d[i], mid; l <= r; ) {
            mid = l + r >> 1; d[i] = mid;
            if (check()) {
                r = mid - 1; res = mid;
            } else {
                l = mid + 1;
            }
        }
        d[i] = res;
        ans += d[i];
    }
    printf("%lld\n", ans);
    return 0;
}