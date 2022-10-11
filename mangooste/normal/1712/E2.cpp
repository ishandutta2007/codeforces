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

template<typename T>
struct binary_indexed_tree {
    std::vector<T> bit;

    binary_indexed_tree(int n = 0, T value = 0) : bit(n + 1) {
        for (int i = 1; i <= n; i++)
            bit[i] = value * (i & -i);
    }

    int size() const {
        return int(bit.size()) - 1;
    }

    void add(int pos, T delta) {
        for (pos++; pos < int(bit.size()); pos += pos & -pos)
            bit[pos] += delta;
    }

    T query(int pref) {
        T sum = 0;
        for (pref++; pref > 0; pref -= pref & -pref)
            sum += bit[pref];

        return sum;
    }

    T query(int l, int r) {
        if (r >= int(bit.size()))
            r = bit.size();

        if (l < 0)
            l = 0;

        if (r <= l)
            return 0;

        return query(r - 1) - query(l - 1);
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    auto solve = [&](int l, int r) {
        r++;
        ll ans = 0;
        auto count_mult = [&](int from, int to, int d) {
            return max(0, to / d - (from - 1) / d);
        };
        ans += count_mult(2 * l, r - 1, 6);
        ans += count_mult((5 * l + 1) / 2, r - 1, 15);

        int length = r - l;
        ll tot = 1ll * length * (length - 1) * (length - 2) / 6;
        return tot - ans;
    };

    constexpr int N = 2e5 + 2;
    struct query {
        int l, id;
    };
    vector<vector<query>> queries(N);

    int q;
    cin >> q;
    vector<ll> ans(q);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        ans[i] = solve(l, r);
        queries[r].push_back({l, i});
    }

    vector<vector<int>> divs(N);
    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) {
            divs[j].push_back(i);
        }
    }

    binary_indexed_tree<ll> bit(N);
    for (int x = 1; x < N; x++) {
        for (int i = 0; i < len(divs[x]); i++) {
            int from = i == 0 ? 0 : divs[x][i - 1] + 1;
            ll pairs = 1ll * (len(divs[x]) - i - 1) * (len(divs[x]) - i - 2) / 2;
            bit.add(from, pairs);
            bit.add(divs[x][i] + 1, -pairs);
        }
        for (auto [l, id] : queries[x]) {
            ans[id] -= bit.query(l);
        }
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << '\n';
    }
}

/*
a<b<c
L = lcm(a, b, c)
L < a+b+c =>
    1. L=c
    2. L=2c, a+b>c
L=c => a+b<c => cases do not intersect
L=2c => b=2c/3, (a=c/2 or a=2c/5)
*/