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

void solve(int test_num) {
    int n;
    cin >> n;
    array<vector<int>, 2> a;
    a.fill(vector<int>(n));
    for (int i : {0, 1}) {
        for (auto &x : a[i]) cin >> x;
    }
    a[0][0] = -1;

    vector<int> ord1, ord2;
    ord1.reserve(2 * n);
    ord2.reserve(2 * n);
    for (int i = 0; i < n; i++) {
        ord1.push_back(a[0][i]);
        ord2.push_back(a[1][i]);
    }
    for (int i = n - 1; i >= 0; i--) {
        ord1.push_back(a[1][i]);
        ord2.push_back(a[0][i]);
    }

    for (int i = 0; i < 2 * n; i++) {
        ord1[i] -= i;
        ord2[i] -= i;
    }

    auto merge_max = [&](const int x, const int y) {
        return x > y ? x : y;
    };
    sparse_table<int, decltype(merge_max)> sparse1(ord1, merge_max), sparse2(ord2, merge_max);

    array<int, 2> dp, ndp;
    dp = {-2, int(2e9)};

    int ans = 2e9;
    for (int col = 0; col < n; col++) {
        if (col % 2 == 0) {
            int from = col;
            int to = 2 * n - col;
            int res = dp[0] + to - from;
            res = max(res, sparse1.query(from, to) + to);
            ans = min(ans, res);
        } else {
            int from = col;
            int to = 2 * n - col;
            int res = dp[1] + to - from;
            res = max(res, sparse2.query(from, to) + to);
            ans = min(ans, res);
        }
        for (int i : {0, 1}) {
            ndp[i ^ 1] = max(max(dp[i], a[i][col]) + 1, a[i ^ 1][col]) + 1;
            ndp[i ^ 1] = min<int>(ndp[i ^ 1], 2e9);
        }
        swap(dp, ndp);
    }

    ans = min(ans, dp[0]);
    ans = min(ans, dp[1]);
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}