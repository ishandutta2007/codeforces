#pragma GCC optimize("Ofast")

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
    #define dprint(...)
#endif // LOCAL

template<typename Fun>
struct y_combinator {
    const Fun fun;

    explicit y_combinator(const Fun&& fun) : fun(std::forward<const Fun>(fun)) {}

    template<typename... Args>
    auto operator()(Args&&... args) const {
        return fun(std::ref(*this), std::forward<Args>(args)...);
    }
};

void solve(int test_num) {
    int n;
    cin >> n;
    vector<int> d1(n), d2(n);
    for (auto &x : d1) cin >> x;
    for (auto &x : d2) cin >> x;
    sort(all(d1));
    sort(all(d2));

    if (d1 == d2) {
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            cout << d1[i] << " \n"[i == n - 1];
        }
        cout << "0 0\n";
        return;
    }

    auto solve = [&](int length) {
        assert(length >= 0);
        if (length == 0) return false;

        unordered_map<int, int> freq1, freq2;
        freq1.rehash(n);
        freq2.rehash(n);
        for (int i = 0; i < n; i++) {
            freq1[d1[i]]++;
            freq2[d2[i]]++;
        }

        auto remove = [](unordered_map<int, int> &mp, int val) {
            mp[val]--;
            assert(mp[val] >= 0);
            if (mp[val] == 0) mp.erase(val);
        };

        vector<int> houses;
        houses.reserve(n);
        for (int i = 0; i < n; i++) {
            int opt1 = d1[i] + length;
            int opt2 = abs(d1[i] - length);
            if (opt1 == opt2) {
                assert(d1[i] == 0 && opt1 == length);
                if (!freq2[opt1]) return false;
                houses.push_back(0);
                remove(freq2, opt1);
                remove(freq1, 0);
            }
        }

        for (int i = 0; i < n; i++) {
            int opt1 = d2[i] + length;
            int opt2 = abs(d2[i] - length);
            if (opt1 == opt2) {
                assert(d2[i] == 0 && opt1 == length);
                if (!freq1[opt1]) return false;
                houses.push_back(length);
                remove(freq1, opt1);
                remove(freq2, 0);
            }
        }

        struct edge {
            int to, cnt, val;
        };
        unordered_map<int, vector<edge>> g;
        g.rehash(2 * len(freq1));
        for (auto [x, cnt] : freq1) {
            int opt1 = x + length;
            int opt2 = abs(x - length);
            if (opt1 == opt2) continue;
            for (int rot = 0; rot < 2; rot++, swap(opt1, opt2)) {
                g[opt1].emplace_back(opt2, cnt, x);
            }
        }

        auto add_house = [&](int val, int ver) {
            assert(val > 0 && ver > 0);
            if (ver == val + length) {
                houses.push_back(-val);
            } else if (ver == length - val) {
                houses.push_back(val);
            } else {
                assert(ver == val - length);
                houses.push_back(val);
            }
        };

        vector<int> ord;
        ord.reserve(len(g));
        for (int deg : {1, 2}) {
            for (auto &[v, adj] : g) {
                assert(1 <= len(adj) && len(adj) <= 2);
                if (len(adj) == deg) ord.push_back(v);
            }
        }

        unordered_set<int> used;
        used.rehash(len(ord));
        vector<int> vers, init, vals, edges;
        vector<ll> in(n), out(n);
        for (auto v : ord) {
            if (used.count(v)) continue;
            auto adj = g[v];

            vers.clear();
            init.clear();
            vals.clear();
            edges.clear();

            y_combinator([&](auto dfs, int v) -> void {
                used.insert(v);
                vers.push_back(v);
                vals.push_back(freq2[v]);
                for (auto [u, w, val] : g[v]) {
                    if (!used.count(u)) {
                        edges.push_back(w);
                        init.push_back(val);
                        dfs(u);
                    }
                }
            })(v);

            if (len(adj) == 2) {
                assert(adj[1].to == vers.back());
                edges.push_back(adj[1].cnt);
                init.push_back(adj[1].val);
            } else {
                edges.push_back(0);
                init.push_back(-1);
            }
            assert(len(edges) == len(vals));
            assert(len(edges) != 1);

            if (accumulate(all(edges), 0ll) != accumulate(all(vals), 0ll)) {
                return false;
            }

            const int n = len(edges);
            in.resize(n);
            out.resize(n);
            out[0] = edges[0];
            for (int i = 1; i < n; i++) {
                in[i] = vals[i] - out[i - 1];
                out[i] = edges[i] - in[i];
            }
            assert(out[n - 1] == vals[0]);

            ll from = -*min_element(all(in));
            from = max(from, 0ll);
            ll to = *min_element(all(out));
            if (from > to) return false;

            ll x = from;
            for (int i = 0; i < n; i++) {
                assert(in[i] + x >= 0);
                for (int it = 0; it < in[i] + x; it++) {
                    add_house(init[i], vers[i]);
                }
                assert(out[i] - x >= 0);
                for (int it = 0; it < out[i] - x; it++) {
                    add_house(init[i], vers[(i + 1) % n]);
                }
            }
        }
        assert(len(houses) == n);

        int delta = -min(0, *min_element(all(houses)));
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            cout << houses[i] + delta << " \n"[i == n - 1];
        }
        cout << delta << ' ' << length + delta << '\n';
        return true;
    };

    for (int i = 0; i < n; i++) {
        if (solve(d1[0] + d2[i])) return;
        if (solve(abs(d1[0] - d2[i]))) return;
    }
    cout << "NO\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}