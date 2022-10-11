#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

template<typename T, typename merge_t>
struct sparse_table {
    std::vector<std::vector<T>> sparse;
    const merge_t merge;

    sparse_table(const merge_t &merge) : merge(merge) {}
    sparse_table(const std::vector<T> &a, const merge_t &merge) : merge(merge) {
        if (a.empty())
            return;

        int n = int(a.size());
        int lg = std::__lg(n);
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
        int level = std::__lg(r - l);
        return merge(sparse[level][l], sparse[level][r - (1 << level)]);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] -= x;
    }

    vector<ll> pref(n + 1);
    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i] + a[i];

    auto cmp_min = [](ll a, ll b) {
        return a < b ? a : b;
    };

    auto cmp_max = [](ll a, ll b) {
        return a > b ? a : b;
    };

    sparse_table<ll, decltype(cmp_min)> sparse_min(pref, cmp_min);
    sparse_table<ll, decltype(cmp_max)> sparse_max(pref, cmp_max);

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;

        if (pref[r] - pref[l] != 0 || sparse_max.query(l, r) > pref[l])
            cout << "-1\n";
        else
            cout << pref[l] - sparse_min.query(l, r) << '\n';
    }
}