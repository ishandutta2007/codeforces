#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

#ifdef LOCAL
    #include "debug.h"
#else
    #define dbg(...)
#endif // LOCAL

template<typename T, typename merge_t>
struct sparse_table {
    std::vector<std::vector<T>> sparse;
    const merge_t merge;

    sparse_table(const merge_t &merge) : merge(merge) {}

    sparse_table(const std::vector<T> &a, const merge_t &merge) : merge(merge) {
        if (a.empty())
            return;

        const int n = int(a.size()), lg = std::__lg(n);
        sparse.reserve(lg + 1);
        sparse.push_back(a);

        for (int level = 1; level <= lg; level++) {
            sparse.push_back(std::vector<T>(n - (1 << level) + 1));
            for (int i = 0; i < int(sparse[level].size()); i++)
                sparse[level][i] = merge(sparse[level - 1][i], sparse[level - 1][i + (1 << (level - 1))]);
        }
    }

    T query(int l, int r) const {
        assert(l < r);
        const int level = std::__lg(r - l);
        return merge(sparse[level][l], sparse[level][r - (1 << level)]);
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (auto &x : a) cin >> x;

    auto merge_max = [&](const int x, const int y) {
        return max(x, y);
    };
    sparse_table<int, decltype(merge_max)> sparse(a, merge_max);

    int q;
    cin >> q;
    while (q--) {
        int sx, sy, fx, fy, k;
        cin >> sx >> sy >> fx >> fy >> k;
        sx--, sy--, fx--, fy--;
        if (abs(sx - fx) % k || abs(sy - fy) % k) {
            cout << "NO\n";
            continue;
        }
        if (sy == fy) {
            cout << "YES\n";
            continue;
        }

        int l = min(sy, fy), r = max(sy, fy);
        int rem = sx % k;
        int max_possib = rem + (n - 1 - rem) / k * k;
        cout << (sparse.query(l, r + 1) > max_possib ? "NO" : "YES") << '\n';
    }
}