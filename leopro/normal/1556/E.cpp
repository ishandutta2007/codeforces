#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define int long long
using ll = long long;
using ull = unsigned long long;
using namespace std;

void solve();

signed main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}

void merge(int &b, int &mnb, int &mxb, int b1, int mnb1, int mxb1, int b2, int mnb2, int mxb2) {
    b = b1 + b2;
    mnb = min(mnb1, b1 + mnb2);
    mxb = max(mxb1, b1 + mxb2);
}

tuple<int, int, int> merge(int a, int b, int c, int d, int e, int f) {
    merge(a, b, c, a, b, c, d, e, f);
    return {a, b, c};
}

struct BalanceTree {
    int n;
    vector<int> balance;
    vector<int> maxBalance, minBalance;

    BalanceTree(vector<int> c) : n(c.size()), balance(2 * n), minBalance(2 * n), maxBalance(2 * n) {
        for (int i = 0; i < c.size(); ++i) balance[i + n] = c[i];
        for (int i = 0; i < c.size(); ++i) maxBalance[i + n] = c[i];
        for (int i = 0; i < c.size(); ++i) minBalance[i + n] = c[i];
        for (int i = n - 1; i > 0; --i) update(i);
    }


    void update(int i) {
        merge(balance[i], minBalance[i], maxBalance[i],
              balance[2 * i], minBalance[2 * i], maxBalance[2 * i],
              balance[2 * i + 1], minBalance[2 * i + 1], maxBalance[2 * i + 1]);
    }

    void mergeL(int &a, int &b, int &c, int i) {
        merge(a, b, c, a, b, c, balance[i], minBalance[i], maxBalance[i]);
    }

    void mergeR(int i, int &a, int &b, int &c) {
        merge(a, b, c, balance[i], minBalance[i], maxBalance[i], a, b, c);
    }

    tuple<int, int, int> get(int l, int r) {
        int lb = 0, lmnb = 0, lmxb = 0;
        int rb = 0, rmnb = 0, rmxb = 0;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l & 1) mergeL(lb, lmnb, lmxb, l++);
            if (r & 1) mergeR(--r, rb, rmnb, rmxb);
        }
        return merge(lb, lmnb, lmxb, rb, rmnb, rmxb);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(n);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;
    vector<int> c(n), d(n);
    for (int i = 0; i < n; ++i) c[i] = b[i] - a[i];
    BalanceTree balance(c);
    for (int j = 0; j < q; ++j) {
        int l, r;
        cin >> l >> r;
        --l;
        auto[b, mnb, mxb] = balance.get(l, r);
        if (b == 0 && mnb == 0) cout << mxb; else cout << -1;
        cout << endl;
    }
}