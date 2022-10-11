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

struct disjoin_set_union {
    int components;
    std::vector<int> parent, rank;

    disjoin_set_union(int n = 0) : components(n), parent(n), rank(n, 1) {
        std::iota(parent.begin(), parent.end(), 0);
    }

    int size() const {
        return rank.size();
    }

    void set_default() {
        components = size();
        std::fill(rank.begin(), rank.end(), 1);
        std::iota(parent.begin(), parent.end(), 0);
    }

    int root(int v) {
        return (v ^ parent[v]) == 0 ? v : parent[v] = root(parent[v]);
    }

    bool unite(int v, int u) {
        v = root(v), u = root(u);
        if (v == u)
            return false;

        if (rank[v] < rank[u])
            std::swap(v, u);

        rank[v] += rank[u];
        parent[u] = v;
        components--;
        return true;
    }

    bool connected(int v, int u) {
        return root(v) == root(u);
    }
};

void solve(int test_num) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    int zeroes = 0;
    for (auto &x : a) {
        if (x == 0) {
            x++;
            zeroes++;
        }
    }

    auto check = [&]() {
        if (count(all(a), 0)) return false;

        constexpr int LG = 30;
        disjoin_set_union dsu(LG);
        int tot_or = 0;
        for (int i = 0; i < n; i++) {
            tot_or |= a[i];
            for (int j = 0; j < LG; j++) {
                if (a[i] >> j & 1) dsu.unite(j, __lg(a[i]));
            }
        }

        for (int i = 0; i < LG; i++) {
            if ((tot_or >> i & 1) && !dsu.connected(i, __lg(tot_or))) {
                return false;
            }
        }
        return true;
    };

    if (check()) {
        cout << zeroes << '\n';
        for (int i = 0; i < n; i++) {
            cout << a[i] << " \n"[i == n - 1];
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int d : {-1, 1}) {
            a[i] += d;
            if (check()) {
                cout << zeroes + 1 << '\n';
                for (int i = 0; i < n; i++) {
                    cout << a[i] << " \n"[i == n - 1];
                }
                return;
            }
            a[i] -= d;
        }
    }

    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        b[i] = __builtin_ctz(a[i]);
    }
    const int mx = *max_element(all(b));
    assert(count(all(b), mx) > 1);

    int first = find(all(b), mx) - b.begin();
    int second = find(first + 1 + all(b), mx) - b.begin();
    a[first]--;
    a[second]++;

    cout << zeroes + 2 << '\n';
    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}