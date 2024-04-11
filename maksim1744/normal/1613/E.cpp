#include <bits/stdc++.h>
using namespace std;

// clang-format off
// template {{{
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define trav(a, x) for (auto &a : x)

#define L1(u, ...) [&](auto &&u) { return __VA_ARGS__; }
#define L2(u, v, ...) [&](auto &&u, auto &&v) { return __VA_ARGS__; }

#define sort_by(x, y) sort(all(x), [&](const auto &l, const auto &r) { return y; })

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vd = vector<double>;
using vs = vector<string>;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;

using vpii = vector<pii>;
using vpll = vector<pll>;
using vpdd = vector<pdd>;

template <typename T> void ckmin(T &a, const T &b) { a = min(a, b); }
template <typename T> void ckmax(T &a, const T &b) { a = max(a, b); }

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

namespace __input {
    template <class T1, class T2> void re(pair<T1, T2> &p);
    template <class T> void re(vector<T> &a);
    template <class T, size_t SZ> void re(array<T, SZ> &a);

    template <class T> void re(T &x) { cin >> x; }
    void re(double &x) { string t; re(t); x = stod(t); }
    template <class Arg, class... Args> void re(Arg &first, Args &...rest) { re(first); re(rest...); }

    template <class T1, class T2> void re(pair<T1, T2> &p) { re(p.first, p.second); }
    template <class T> void re(vector<T> &a) { for (auto &x : a) re(x); }
    template <class T, size_t SZ> void re(array<T, SZ> &a) { for (auto &x : a) re(x); }
}
using namespace __input;

namespace __output {
    template <typename T> struct is_outputtable { template <typename C> static constexpr decltype(declval<ostream &>() << declval<const C &>(), bool()) test(int) { return true; } template <typename C> static constexpr bool test(...) { return false; } static constexpr bool value = test<T>(int()); };
    template <class T, typename V = decltype(declval<const T &>().begin()), typename S = typename enable_if<!is_outputtable<T>::value, bool>::type> void pr(const T &x);

    template <class T, typename V = decltype(declval<ostream &>() << declval<const T &>())> void pr(const T &x) { cout << x; }
    template <class T1, class T2> void pr(const pair<T1, T2> &x);
    template <class Arg, class... Args> void pr(const Arg &first, const Args &...rest) { pr(first); pr(rest...); }

    template <class T, bool pretty = true> void prContain(const T &x) { if (pretty) pr("{"); bool fst = 1; for (const auto &a : x) pr(!fst ? pretty ? ", " : " " : "", a), fst = 0; if (pretty) pr("}"); }

    template <class T> void pc(const T &x) { prContain<T, false>(x); pr("\n"); }
    template <class T1, class T2> void pr(const pair<T1, T2> &x) { pr("{", x.first, ", ", x.second, "}"); }
    template <class T, typename V, typename S> void pr(const T &x) { prContain(x); }

    void ps() { pr("\n"); }
    template <class Arg> void ps(const Arg &first) { pr(first); ps(); }
    template <class Arg, class... Args> void ps(const Arg &first, const Args &...rest) { pr(first, " "); ps(rest...); }
}
using namespace __output;

#define __pn(x) pr(#x, " = ")
#ifdef ANAND_LOCAL
#define pd(...) pr("\033[1;31m"), __pn((__VA_ARGS__)), ps(__VA_ARGS__), pr("\033[0m"), cout << flush
#else
#define pd(...)
#endif

namespace __algorithm {
    template <typename T> void dedup(vector<T> &v) { sort(all(v)); v.erase(unique(all(v)), v.end()); }
    template <typename T> typename vector<T>::const_iterator find(const vector<T> &v, const T &x) { auto it = lower_bound(all(v), x); return it != v.end() && *it == x ? it : v.end(); }
    template <typename T> size_t index(const vector<T> &v, const T &x) { auto it = find(v, x); assert(it != v.end() && *it == x); return it - v.begin(); }
    template <typename I> struct _reversed_struct { I &v_; explicit _reversed_struct(I &v) : v_{v} {} typename I::reverse_iterator begin() const { return v_.rbegin(); } typename I::reverse_iterator end() const { return v_.rend(); } };
    template <typename I> _reversed_struct<I> reversed(I &v) { return _reversed_struct<I>(v); }
    template <typename I> struct _range_struct { const I first_, last_; explicit _range_struct(const I first, const I last) : first_{first}, last_{last} {} I begin() const { return first_; } I end() const { return last_; } };
    template <typename I> _range_struct<I> range(const I first, const I last) { return _range_struct<I>(first, last); }
}
using namespace __algorithm;

namespace __io {
    void setIO() { ios_base::sync_with_stdio(0); cin.tie(0); cout << setprecision(15); }
}
using namespace __io;
// }}}
template <class Fun> class y_combinator_result {
    Fun fun_;

  public:
    template <class T> explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}

    template <class... Args> decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

template <class Fun> decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

// clang-format on

const char X = '#', O = '.', L = 'L', P = '+';

const array<pair<int, int>, 8> dirs = {{{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}}};
struct GridIterator {
    int n, m;
    GridIterator(int n, int m) : n(n), m(m) {}

    template<size_t N>
    struct NeighbourIteratorContainer {
        int i, j, n, m;
        NeighbourIteratorContainer(int i, int j, int n, int m) : i(i), j(j), n(n), m(m) {}

        struct NeighbourIterator {
            int cur;
            int i, j, n, m;
            NeighbourIterator(int cur, int i, int j, int n, int m) : cur(cur), i(i), j(j), n(n), m(m) {
                skip_to_first_allowed();
            }

            void skip_to_first_allowed() {
                while (cur < N &&
                    (i + dirs[cur].first   < 0 ||
                     i + dirs[cur].first  >= n ||
                     j + dirs[cur].second  < 0 ||
                     j + dirs[cur].second >= m)) {
                    ++cur;
                }
            }

            NeighbourIterator& operator ++ () {
                ++cur;
                skip_to_first_allowed();
                return *this;
            }

            pair<int, int> operator * () const {
                return {i + dirs[cur].first, j + dirs[cur].second};
            }

            bool operator == (const NeighbourIterator& other) const { return cur == other.cur; }
        };

        auto begin() const { return NeighbourIterator(0, i, j, n, m); }
        auto end()   const { return NeighbourIterator(N, i, j, n, m); }
    };

    template<size_t N>
    auto iterate(int i, int j) const {
        static_assert(N == 4 || N == 8, "you can remove this, but make sure you understand what you are doing");
        return NeighbourIteratorContainer<N>(i, j, n, m);
    }
};

void solve() {
    int n, m;
    re(n, m);
    vector<string> grid(n);
    re(grid);

    GridIterator gi(n, m);

    vvi bad(n, vi(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (grid[i][j] != O)
                continue;

            for (auto [x, y] : gi.iterate<4>(i, j))
                if (grid[x][y] != X)
                    bad[i][j]++;
        }

    int lab_i, lab_j;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == L)
                lab_i = i, lab_j = j;
        }

    y_combinator([&](auto self, int i, int j) -> void {
        if (grid[i][j] == O)
            grid[i][j] = P;

        for (auto [x, y] : gi.iterate<4>(i, j))
            if (grid[x][y] == O && (--bad[x][y] <= 1))
                self(x, y);
    })(lab_i, lab_j);

    for (auto &s : grid)
        ps(s);
}

int main() {
    setIO();

    int T;
    re(T);
    for (int t = 0; t < T; t++)
        solve();

    return 0;
}