#include <cassert>
#include <cstdio>
#include <algorithm>

/** Fast allocation */

#define FAST_ALLOCATOR_MEMORY 2e8
#ifdef FAST_ALLOCATOR_MEMORY
int allocator_pos = 0;
        char allocator_memory[(int)FAST_ALLOCATOR_MEMORY];
        inline void * operator new ( size_t n ) {
                char *res = allocator_memory + allocator_pos;
                allocator_pos += n;
                if (allocator_pos % 8 != 0) { allocator_pos += 8 - (allocator_pos % 8); }
                assert(allocator_pos <= (int)FAST_ALLOCATOR_MEMORY);
                return (void *)res;
        }
        inline void operator delete ( void * ) noexcept { }
        inline void operator delete(void *, size_t) noexcept {}
        //inline void * operator new [] ( size_t ) { assert(0); }
        //inline void operator delete [] ( void * ) { assert(0); }
#endif

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define pb push_back
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forrn(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
#define PYMOD(a, m) ((((a) % (m)) + (m)) % (m))
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define mp make_pair
#define ff first
#define ss second

template <typename T> struct printer {
    static bool print(const T &value) {
        cout << value << ' ';
        return false;
    }
};
template <typename T> struct printer<vector<T>> {
    static bool print(const vector<T> &v) {
        for (const auto &element : v) {
            cout << element << ' ';
        }
        return false;
    }
};
template <typename... Args> void print(const Args &...args) {
    if (!(printer<Args>::print(args), ...)) {
        cout << '\n';
    }
}
[[noreturn]] void TODO(const std::string &what = "") {
    if (what.empty()) {
        throw std::runtime_error{"TODO"};
    }
    throw std::runtime_error{"TODO: " + what};
}

using output = ll;
// struct output {
//     void do_print() const {
//         TODO("output::do_print");
//     }

//     bool operator==([[maybe_unused]] const output &other) const {
//         TODO("output::operator==");
//     }
// };
// template <> struct printer<output> {
//     static bool print(const output &v) {
//         v.do_print();
//         return true;
//     }
// };

struct pair_hash {
    size_t operator()(const pair<int, int>& p) const {
        return 1ll * p.first * 100'001 + p.second;
    }
};

struct input {
    int n;
    vector<vector<pair<int, ll>>> tree;

    void read() {
        cin >> n;
        tree.resize(n);
        forn(i, n - 1) {
            int u, v, w;
            cin >> u >> v >> w;
            u--; v--;
            tree[u].emplace_back(v, w);
            tree[v].emplace_back(u, w);
        }
    }

    void do_print() const {
        TODO("input::do_print");
    }

    void gen() {
        // Use static rnd gen.
        TODO("input::gen");
    }

    output fast() {
        if (n == 1) {
            return 0;
        }

        unordered_map<pair<int, int>, ll, pair_hash> sum_edges;
        unordered_map<pair<int, int>, ll, pair_hash> diameter;
        unordered_map<pair<int, int>, ll, pair_hash> height;
        vector<int> unknown_ans(n);
        queue<pair<int, int>> q;
        forn(i, n) {
            unknown_ans[i] = tree[i].size();
            if (tree[i].size() == 1) {
                q.emplace(tree[i][0].first, i);
            }
        }
        auto enqueue = [&](int p) {
            unknown_ans[p]--;
            if (unknown_ans[p] == 0) {
                q.emplace(-1, p);
            } else if (unknown_ans[p] == 1) {
                for (auto [v, w] : tree[p]) {
                    if (!sum_edges.count({p, v})) {
                        q.emplace(v, p);
                    }
                }
            }
        };
        while (!q.empty()) {
            auto [p, u] = q.front();
            q.pop();
            if (p == -1) {
                ll swe = 0;
                vector<ll> hgs;
                vector<ll> ds;
                for (auto [v, w] : tree[u]) {
                    swe += w + sum_edges[{u, v}];
                    hgs.push_back(height[{u, v}] + w);
                    ds.push_back(diameter[{u, v}]);
                }
                vector<ll> p_fmx(hgs.size() + 1), p_smx(hgs.size() + 1);
                for (int i = 0; i < (int)hgs.size(); i++) {
                    if (hgs[i] >= p_fmx[i]) {
                        p_fmx[i + 1] = hgs[i];
                        p_smx[i + 1] = p_fmx[i];
                    } else if (hgs[i] >= p_smx[i]) {
                        p_fmx[i + 1] = p_fmx[i];
                        p_smx[i + 1] = hgs[i];
                    } else {
                        p_fmx[i + 1] = p_fmx[i];
                        p_smx[i + 1] = p_smx[i];
                    }
                }
                vector<ll> s_fmx(hgs.size() + 1), s_smx(hgs.size() + 1);
                for (int i = hgs.size() - 1; i >= 0; i--) {
                    if (hgs[i] >= s_fmx[i + 1]) {
                        s_fmx[i] = hgs[i];
                        s_smx[i] = s_fmx[i + 1];
                    } else if (hgs[i] >= s_smx[i + 1]) {
                        s_fmx[i] = s_fmx[i + 1];
                        s_smx[i] = hgs[i];
                    } else {
                        s_fmx[i] = s_fmx[i + 1];
                        s_smx[i] = s_smx[i + 1];
                    }
                }
                vector<ll> d_pmx(hgs.size() + 1);
                for (int i = 0; i < (int)hgs.size(); i++) {
                    d_pmx[i + 1] = max(d_pmx[i], ds[i]);
                }
                vector<ll> d_smx(hgs.size() + 1);
                for (int i = (int)hgs.size() - 1; i >= 0; i--) {
                    d_smx[i] = max(d_smx[i + 1], ds[i]);
                }
                int i = 0;
                for (auto [v, w] : tree[u]) {
                    ll& se = sum_edges[{v, u}];
                    ll& h = height[{v, u}];
                    ll& d = diameter[{v, u}];

                    se = swe - w - sum_edges[{u, v}];

                    h = max(p_fmx[i], s_fmx[i + 1]);

                    d = h;
                    d = max(d, max(d_pmx[i], d_smx[i + 1]));
                    d = max(d, p_fmx[i] + p_smx[i]);
                    d = max(d, p_fmx[i] + s_fmx[i + 1]);
                    d = max(d, s_fmx[i + 1] + s_smx[i + 1]);
                    i++;
                }
                for (auto [v, _] : tree[u]) {
                    enqueue(v);
                }
            } else {
                ll& se = sum_edges[{p, u}];
                ll& h = height[{p, u}];
                ll& d = diameter[{p, u}];
                ll fmx = 0, smx = 0;
                for (auto [v, w] : tree[u]) {
                    if (v == p) {
                        continue;
                    }
                    se += w + sum_edges[{u, v}];
                    ll ch = height[{u, v}] + w;
                    h = max(h, ch);
                    if (ch >= fmx) {
                        smx = fmx;
                        fmx = ch;
                    } else if (ch >= smx) {
                        smx = ch;
                    }
                    d = max(d, diameter[{u, v}]);
                }
                d = max(d, fmx + smx);
                // print(p, u, se, h, d);
                enqueue(p);
            }
        }

        auto get_val = [&](int u, int v) -> ll {
            return 2 * sum_edges[{u, v}] - diameter[{u, v}];
        };

        ll ans = numeric_limits<ll>::max();
        forn(u, n) {
            for (auto [v, _] : tree[u]) {
                ans = min(ans, get_val(u, v) + get_val(v, u));
            }
        }
        ll se = 0;
        forn(i, n) {
            for (auto [u, w] : tree[i]) {
                se += w;
            }
        }
        forn(i, n) {
            if (tree[i].size() < 4) {
                continue;
            }
            sort(all(tree[i]), [&](auto p, auto q) { return height[{i, p.first}] + p.second > height[{i, q.first}] + q.second; });
            auto a0 = height[{i, tree[i][0].first}] + tree[i][0].second;
            auto a1 = height[{i, tree[i][1].first}] + tree[i][1].second;
            auto a2 = height[{i, tree[i][2].first}] + tree[i][2].second;
            auto a3 = height[{i, tree[i][3].first}] + tree[i][3].second;
            ans = min(ans, se - a0 - a1 - a2 - a3);
        }

        return ans;
    }

    output slow() {
        TODO("input::slow");
    }
};
template <> struct printer<input> {
    static bool print(const input &v) {
        v.do_print();
        return true;
    }
};

void test() {
    input in;
    in.read();
    output out = in.fast();
    print(out);
}

void multitest() {
    int tests;
    cin >> tests;
    for (int t = 0; t < tests; t++) {
        test();
    }
}

void stress() {
    int TESTS = 10'000;
    for (int test = 1; test <= TESTS; test++) {
        input in;
        in.gen();
        input in_fast = in, in_slow = in;
        output ja = in_slow.slow();
        output ca = in_fast.fast();
        if (!(ja == ca)) {
            print("WA test", test);
            print(in);
            print("Expected:", ja);
            print("Found:", ca);
            return;
        }
    }
    print("OK");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // Code here:

    test();
    // multitest();
    // stress();

    return 0;
}