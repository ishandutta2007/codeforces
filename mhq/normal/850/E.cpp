#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = (int)1e9 + 7;

int mult(int a, int b) {
    return (1LL * a * b) % mod;
}

int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}

int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}

int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int n;
void go(int n, vector < int >& a, bool invert) {
    for (int bit = 0; bit < n; bit++) {
        for (int mask = 0; mask < (1 << n); mask++) {
            if (mask & (1 << bit)) {
                int u = a[mask];
                int v = a[mask ^ (1 << bit)];
                a[mask ^ (1 << bit)] = sum(v, u);
                a[mask] = sub(v, u);
            }
        }
    }
    if (invert) {
        int p = pw(1 << n, mod - 2);
        for (int i = 0; i < (1 << n); i++) a[i] = mult(a[i], p);
    }
}
int pw3[21];
int pw2[21];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    pw2[0] = 1;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        pw2[i] = mult(2, pw2[i - 1]);
    }
    vector < int > c0(1 << n), c1(1 << n);
    for (int i = 0; i < (1 << n); i++) {
        char c;
        cin >> c;
        if (c == '0') {
            c0[i] = 1;
            c1[i] = 0;
        }
        else {
            c0[i] = 0;
            c1[i] = 1;
        }
    }
    go(n, c0, false);
    go(n, c1, false);
    for (int i = 0; i < c0.size(); i++) c0[i] = mult(c0[i], c1[i]);
    go(n, c0, true);
    int ans = 0;
    for (int i = 0; i < c0.size(); i++) {
        int ways = mult(c0[i], pw2[__builtin_popcount(i)]);
        ans = sum(ans, ways);
    }
    ans = mult(ans, 3);
    cout << ans;
    return 0;
}