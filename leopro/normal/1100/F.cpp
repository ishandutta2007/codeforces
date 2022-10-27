#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

#include <utility>

using namespace std;
using ll = long long;

void solve();

template<typename ...Args>
void println(Args... args) {
    apply([](auto &&... args) { ((cout << args << '\n'), ...); }, tuple(args...));
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

const int SIZE = 20;
const int N = 5e5 + 100;
template<typename T>
struct SegmentTree {
    int n;
    T neutral;
    int data[2 * N][SIZE];

    void unite(vector<int> &v, int a) {
        for (int i = 0; i < SIZE; ++i) {
            int x = data[a][i];
            if (!x) continue;
            for (int y: v) x = min(x, x ^ y);
            if (!x) continue;
            v[SIZE - 1 - __lg(x)] = x;
        }
    }

    template<typename I>
    SegmentTree(int n, I init) : n(n) {
        for (int i = 0; i < n; ++i) init(data[i + n], i);
        for (int i = n - 1; i > 0; --i) {
            memcpy(data[i], data[2 * i], sizeof(data[2 * i]));
            for (int k = 0; k < SIZE; ++k) {
                int x = data[2 * i + 1][k];
                if (!x) continue;
                for (int y: data[i]) x = min(x, x ^ y);
                if (!x) continue;
                data[i][SIZE - 1 - __lg(x)] = x;
            }
        }
    }

    T get(int l, int r) {
        T res(20);
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l & 1) unite(res, l++);
            if (r & 1) unite(res, --r);
        }
        return res;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> c(n);
    for (int &x: c) cin >> x;
    int q;
    cin >> q;
    SegmentTree<vector<int>> basis(n, [&](int *a, int i) {
        if (c[i]) a[SIZE - 1 - __lg(c[i])] = c[i];
    });
    for (int j = 0; j < q; ++j) {
        int l, r;
        cin >> l >> r;
        --l;
        auto b = basis.get(l, r);
        int x = 0;
        for (int y: b) x = max(x, x ^ y);
        cout << x << '\n';
    }
}