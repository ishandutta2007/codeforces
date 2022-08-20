/*
    25.03.2019 18:14:31
*/

#include <bits/stdc++.h>

using namespace std;

#ifdef HOME
#define TAG_LENGTH 45
#define LR_LEFT left
#define LR_RIGHT right
#define LR_VALUE value
#define LR_SECOND_VALUE mn
#include "C:/C++ libs/print.cpp"
#define showl cout << endl;
#define shows cout << string(5, ' ') + string(TAG_LENGTH, '-') << endl;
#else
#define show(...) 42;
#define showt(...) 42;
#define showl 42;
#define shows 42;
#define print(...) 42;
#define printTree(...) 42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#endif

const long long mod = 998244353;

using T = int;

struct segtree {
    vector< T > tree;
    int n;

    segtree(int size) : n(size), tree(size * 4, T()) {}
    segtree(vector< T >& v) : n(v.size()), tree(v.size() * 4) {
        build(v, 0, 0, n - 1);
    }

    void build(vector< T >& v, int i, int l, int r) {
        if (l == r) {
            tree[i] = v[l];
            return;
        }
        int m = (l + r) / 2;
        build(v, i * 2 + 1, l, m);
        build(v, i * 2 + 2, m + 1, r);
        tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
    }

    void set(int ind, T k, int i, int l, int r) {
        while (l < r) {
            int m = (l + r) / 2;
            if (ind <= m) {
                r = m;
                i = 2 * i + 1;
            } else {
                l = m + 1;
                i = 2 * i + 2;
            }
        }
        tree[i] = k;
        while (i != 0) {
            i = (i - 1) / 2;
            tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
        }
    }

    void set(int ind, T k) {
        set(ind, k, 0, 0, n - 1);
    }

    T ask(int l, int r, int i, int vl, int vr) {
        if (l == vl && r == vr) {
            return tree[i];
        }
        int m = (vl + vr) / 2;
        if (r <= m) {
            return ask(l, r, 2 * i + 1, vl, m);
        }
        if (l > m) {
            return ask(l, r, 2 * i + 2, m + 1, vr);
        }
        return ask(l, m, 2 * i + 1, vl, m) + ask(m + 1, r, 2 * i + 2, m + 1, vr);
    }

    T ask(int l, int r) {
        if (l > r) return 0;
        return ask(l, r, 0, 0, n - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    vector<vector<long long>> m(n, vector<long long>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> m[i][j];
        }
    }
    vector<long long> fact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = fact[i - 1] * i % mod;
    }
    vector<long long> f(n + 1);
    f[0] = 1;
    for (int i = 1; i <= n; ++i) {
        long long sign = i % 2 ? -1 : 1;
        long long p = 1;
        f[i] = 0;
        for (int j = i; j >= 0; --j) {
            f[i] += p * sign;
            p = p * j % mod;
            sign *= -1;
        }
        f[i] %= mod;
    }
    vector<long long> fp(n + 1);
    fp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fp[i] = fp[i - 1] * f[n] % mod;
    }
    // vector<vector<long long>> c(n + 1, vector<long long>(n + 1));
    // for (int i = 0; i < n + 1; ++i) {
    //     c[0][i] = 0;
    //     c[i][0] = 1;
    // }
    // for (int i = 1; i <= n; ++i) {
    //     for (int j = 1; j <= n; ++j) {
    //         c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
    //     }
    // }
    vector<vector<long long>> g(n + 1, vector<long long>(n + 1, 0));
    for (int i = 1; i < n + 1; ++i) {
        g[0][i] = 0;
    }
    g[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        g[i][0] = fact[i];
        for (int k = 1; k <= i; ++k) {
            if (k >= 2) {
                g[i][k] += g[i - 1][k - 2] * (k - 1);
            }
            g[i][k] += g[i - 1][k - 1] * (i - k);
            g[i][k] %= mod;
        }
    }
    // printMatrix(g);
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        segtree t(n + 1);
        segtree t2(n + 1);
        for (int j = 1; j <= n; ++j) {
            t.set(j, 1);
            t2.set(j, 1);
        }
        for (int j = 0; j < n; ++j) {
            // shows;
            // show(i, j);
            if (i == 0) {
                ans = (ans + (long long)t.ask(1, m[i][j] - 1) * fact[n - j - 1] % mod * fp[n - i - 1]) % mod;
                t.set(m[i][j], 0);
            } else {
                t.set(m[i - 1][j], 0);
                long long cnt0 = t.ask(1, m[i][j] - 1);
                long long cnt1 = t.ask(1, n);
                long long cnt2 = t2.ask(1, m[i][j] - 1);
                if (m[i - 1][j] < m[i][j])
                    cnt2 -= t2.ask(m[i - 1][j], m[i - 1][j]);
                // show(cnt0, cnt1, cnt2);
                if (cnt1 > 0)
                    ans = (ans + cnt0 * g[n - j - 1][cnt1 - 1] % mod * fp[n - i - 1]) % mod;
                // show(ans);
                ans = (ans + (cnt2 - cnt0) * g[n - j - 1][cnt1] % mod * fp[n - i - 1]) % mod;
                // show(ans);
                t.set(m[i][j], 0);
                t2.set(m[i][j], 0);
            }
            // show(ans);
        }
    }
    cout << ans << '\n';
    return 0;
}