#include <bits/stdc++.h>

using ll                            = long long;
using uint                          = unsigned int;
using ull                           = unsigned long long;
using ld                            = long double;
template<typename T> using max_heap = std::priority_queue<T>;
template<typename T> using min_heap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
constexpr int popcount(const ull v) { return v ? __builtin_popcountll(v) : 0; }
constexpr int log2p1(const ull v) { return v ? 64 - __builtin_clzll(v) : 0; }
constexpr int lsbp1(const ull v) { return __builtin_ffsll(v); }
constexpr int clog(const ull v) { return v ? log2p1(v - 1) : 0; }
constexpr ull ceil2(const ull v) { return 1ULL << clog(v); }
constexpr ull floor2(const ull v) { return v ? (1ULL << (log2p1(v) - 1)) : 0ULL; }
constexpr bool btest(const ull mask, const int ind) { return (mask >> ind) & 1ULL; }
template<typename T> void bset(T& mask, const int ind) { mask |= ((T)1 << ind); }
template<typename T> void breset(T& mask, const int ind) { mask &= ~((T)1 << ind); }
template<typename T> void bflip(T& mask, const int ind) { mask ^= ((T)1 << ind); }
template<typename T> void bset(T& mask, const int ind, const bool b) { (b ? bset(mask, ind) : breset(mask, ind)); }
template<typename T> bool chmin(T& a, const T& b) { return (a > b ? a = b, true : false); }
template<typename T> bool chmax(T& a, const T& b) { return (a < b ? a = b, true : false); }
template<typename T> constexpr T inf_v      = std::numeric_limits<T>::max() / 4;
template<typename Real> constexpr Real pi_v = Real{3.141592653589793238462643383279502884};
template<typename T> constexpr T TEN(const int n) { return n == 0 ? T{1} : TEN<T>(n - 1) * T{10}; }
template<typename F> struct fix : F
{
    fix(F&& f) : F{std::forward<F>(f)} {}
    template<typename... Args> auto operator()(Args&&... args) const { return F::operator()(*this, std::forward<Args>(args)...); }
};
template<typename T, int n, int i = 0>
auto nd_array(int const (&szs)[n], const T x = T{})
{
    if constexpr (i == n) {
        return x;
    } else {
        return std::vector(szs[i], nd_array<T, n, i + 1>(szs, x));
    }
}
class printer
{
public:
    printer(std::ostream& os_ = std::cout) : os{os_} { os << std::fixed << std::setprecision(15); }
    template<typename T> int operator()(const T& v) { return os << v, 0; }
    template<typename T> int operator()(const std::vector<T>& vs)
    {
        for (int i = 0; i < (int)vs.size(); i++) { os << (i ? " " : ""), this->operator()(vs[i]); }
        return 0;
    }
    template<typename T> int operator()(const std::vector<std::vector<T>>& vss)
    {
        for (int i = 0; i < (int)vss.size(); i++) { os << (0 <= i or i + 1 < (int)vss.size() ? "\n" : ""), this->operator()(vss[i]); }
        return 0;
    }
    template<typename T, typename... Args> int operator()(const T& v, const Args&... args) { return this->operator()(v), os << ' ', this->operator()(args...), 0; }
    template<typename... Args> int ln(const Args&... args) { return this->operator()(args...), os << '\n', 0; }
    template<typename... Args> int el(const Args&... args) { return this->operator()(args...), os << std::endl, 0; }
    template<typename... Args> int fmt(const std::string& s, const Args&... args) { return rec(s, 0, args...); }

private:
    int rec(const std::string& s, int index) { return os << s.substr(index, s.size()), 0; }
    template<typename T, typename... Args> int rec(const std::string& s, int index, const T& v, const Args&... args) { return index == s.size() ? 0 : s[index] == '%' ? (this->operator()(v), rec(s, index + 1, args...)) : (os << s[index], rec(s, index + 1, v, args...)); }
    std::ostream& os;
};
printer out;
class scanner
{
public:
    scanner(std::istream& is_ = std::cin) : is{is_} { is.tie(nullptr), std::ios::sync_with_stdio(false); }
    template<typename T> T val()
    {
        T v;
        return is >> v, v;
    }
    template<typename T> T val(const T offset) { return val<T>() - offset; }
    template<typename T> std::vector<T> vec(const int n)
    {
        std::vector<T> vs(n);
        for (auto& v : vs) { v = val<T>(); }
        return vs;
    }
    template<typename T> std::vector<T> vec(const int n, const T offset)
    {
        std::vector<T> vs(n);
        for (auto& v : vs) { v = val<T>(offset); }
        return vs;
    }
    template<typename T> std::vector<std::vector<T>> vvec(const int n0, const int n1)
    {
        std::vector<std::vector<T>> vss(n0);
        for (auto& vs : vss) { vs = vec<T>(n1); }
        return vss;
    }
    template<typename T> std::vector<std::vector<T>> vvec(const int n0, const int n1, const T offset)
    {
        std::vector<std::vector<T>> vss(n0);
        for (auto& vs : vss) { vs = vec<T>(n1, offset); }
        return vss;
    }
    template<typename... Args> auto tup() { return std::tuple<std::decay_t<Args>...>{val<Args>()...}; }
    template<typename... Args> auto tup(const Args&... offsets) { return std::tuple<std::decay_t<Args>...>{val<Args>(offsets)...}; }

private:
    std::istream& is;
};
scanner in;
#    define SHOW(...) static_cast<void>(0)


template<typename T, typename F>
class ds_table
{
public:
    ds_table(const std::vector<T>& vs, F merge_) : sz{(int)vs.size()}, lg{(int)log2p1(sz)}, vss(lg, vs), merge{merge_}
    {
        for (int d = 0; d < lg; d++) {
            const int width = 1 << (lg - d - 1);
            for (int i = 1; i * width < sz; i += 2) {
                int l = i * width - 1, r = i * width;
                for (int j = 1; j < width; j++) {
                    vss[d][l - j] = merge(vs[l - j], vss[d][l - j + 1]);
                    if (r + j < sz) { vss[d][r + j] = merge(vs[r + j], vss[d][r + j - 1]); }
                }
            }
        }
    }
    T fold(const int l, int r) const
    {
        assert(0 <= l and l < r and r <= sz);
        if (r - l == 1) { return vss.back()[l]; }
        r--;
        const int d = lg - log2p1(l ^ r);
        return merge(vss[d][l], vss[d][r]);
    }

private:
    const int sz, lg;
    std::vector<std::vector<T>> vss;
    F merge;
};
template<typename T, typename F = std::less<T>, typename B = ull>
class static_rmq
{
    static inline auto min_f = [](const auto& c) { return [c](const auto& x1, const auto& x2) { return std::min(x1, x2, c); }; };

public:
    static_rmq(const std::vector<T>& vs, F comp_ = F{})
        : sz{(int)vs.size()}, bn{(int)wind(sz + bs - 1)}, vals{vs}, bucket_vals([&]() {
              std::vector<T> ans(bn);
              for (int i = 0; i < sz; i++) { ans[wind(i)] = i % bs == 0 ? vals[i] : std::min(ans[wind(i)], vals[i], comp_); }
              return ans;
          }()),
          masks(sz, 0),
          st(bucket_vals, min_f(comp_)),
          comp{comp_}
    {
        for (int i = 0; i < bn; i++) {
            std::vector<int> g(bs, sz);
            std::stack<int> stack;
            for (int j = 0; j < bs and (int) ind(i, j) < sz; j++) {
                for (; not stack.empty() and not comp(vals[stack.top()], vals[ind(i, j)]); stack.pop()) {}
                g[j] = stack.empty() ? sz : stack.top(), stack.push(ind(i, j));
            }
            for (int j = 0; j < bs and (int) ind(i, j) < sz; j++) { masks[ind(i, j)] = g[j] == sz ? static_cast<B>(0) : (masks[g[j]] | static_cast<B>(1) << (g[j] - i * bs)); }
        }
    }
    T fold(const int l, const int r) const
    {
        assert(0 <= l and l < r and r <= sz);
        const int lb = (l + bs - 1) / bs, rb = r / bs;
        if (lb > rb) {
            return brmq(l, r);
        } else {
            return lb < rb
                       ? (l < bs * lb
                              ? (bs * rb < r
                                     ? std::min({st.fold(lb, rb), brmq(l, bs * lb), brmq(bs * rb, r)}, comp)
                                     : std::min(st.fold(lb, rb), brmq(l, bs * lb), comp))
                              : (bs * rb < r
                                     ? std::min(st.fold(lb, rb), brmq(bs * rb, r), comp)
                                     : st.fold(lb, rb)))
                       : (l < bs * lb
                              ? (bs * rb < r
                                     ? std::min(brmq(l, bs * lb), brmq(bs * rb, r), comp)
                                     : brmq(l, bs * lb))
                              : (bs * rb < r
                                     ? brmq(bs * rb, r)
                                     : T{}));
        }
    }

private:
    static constexpr int bs    = sizeof(B) * 8;
    static constexpr int bslog = log2p1(bs) - 1;
    static constexpr uint wind(const uint n) { return n >> (bslog); }
    static constexpr uint bind(const uint n) { return n ^ (wind(n) << bslog); }
    static constexpr uint ind(const uint w, const uint b) { return (w << bslog) | b; }
    T brmq(const int l, const int r) const
    {
        const B w = masks[r - 1] >> (l % bs);
        return w == 0 ? vals[r - 1] : vals[l + lsbp1(w) - 1];
    }

    const int sz, bn;
    std::vector<T> vals, bucket_vals;
    std::vector<B> masks;
    ds_table<T, decltype(min_f(F{}))> st;
    F comp;
};

template<typename T = int>
struct edge
{
    using cost_type = T;
    int v;
    T c;
    edge(const int v_) : v{v_}, c{1} {}
    edge(const int v_, const T& c_) : v{v_}, c{c_} {}
    operator int() const { return v; }
    int to() const { return v; }
    T cost() const { return c; }
    friend std::ostream& operator<<(std::ostream& os, const edge& e) { return os << e.u << "->" << e.v << ":" << e.c; }
};
template<typename Edge>
class base_graph
{
public:
    base_graph(const int n) : sz{n}, es(n)  // , res(n)
    {}
    void add_edge(const int u, const int v, const bool bi = false)
    {
        es[u].emplace_back(v);
        //res[v].emplace_back(u);
        if (bi) {
            es[v].emplace_back(u);
            //res[u].emplace_back(v);
        }
    }
    template<typename Cost>
    void add_edge(const int u, const int v, const Cost& c, const bool bi = false)
    {
        es[u].emplace_back(v, c);
        //res[v].emplace_back(u, c);
        if (bi) {
            es[v].emplace_back(u, c);
            //res[u].emplace_back(v, c);
        }
    }
    std::vector<Edge>& operator[](const int u) { return es[u]; }
    const std::vector<Edge>& operator[](const int u) const { return es[u]; }
    std::vector<Edge>& from(const int u) { return es[u]; }
    const std::vector<Edge>& from(const int u) const { return es[u]; }
    // std::vector<Edge>& to(const int v) { return res[v]; }
    // const std::vector<Edge>& to(const int v) const { return res[v]; }
    int size() const { return sz; }
    friend std::ostream& operator<<(std::ostream& os, const base_graph& g)
    {
        for (int i = 0; i < g.sz; i++) {
            for (const auto& e : g.es[i]) { os << e << '\n'; }
        }
        return os;
    }

private:
    int sz;
    std::vector<std::vector<Edge>> es  // , res
        ;
};
using graph = base_graph<edge<>>;
template<typename Cost>
using cost_graph = base_graph<edge<Cost>>;
template<typename Edge = edge<>>
class lca_manager
{
public:
    lca_manager(const base_graph<Edge>& tree, const std::size_t root = 0) : ins(tree.size(), 0),
                                                                            ds([&]() {
                                                                                std::vector<std::pair<std::size_t, std::size_t>> ans;
                                                                                std::vector<bool> used(tree.size(), false);
                                                                                auto dfs = [&](auto self, const std::pair<std::size_t, std::size_t>& s) -> void {
                                                                                    const std::size_t pos = s.second;
                                                                                    used[pos] = true, ins[pos] = ans.size(), ans.push_back(s);
                                                                                    for (const auto& e : tree[pos]) {
                                                                                        const std::size_t to = e.to();
                                                                                        if (used[to]) { continue; }
                                                                                        self(self, {s.first + 1, to}), ans.push_back(s);
                                                                                    }
                                                                                };
                                                                                dfs(dfs, {0, root});
                                                                                return ans;
                                                                            }()),
                                                                            rmq(ds) {}
    std::size_t operator()(const std::size_t u, const std::size_t v) const
    {
        const std::size_t ul = ins[u], vl = ins[v];
        return rmq.fold(std::min(ul, vl), std::max(ul, vl) + 1).second;
    }

private:
    std::vector<std::size_t> ins;
    std::vector<std::pair<std::size_t, std::size_t>> ds;
    static_rmq<std::pair<std::size_t, std::size_t>> rmq;
};

int main()
{
    const auto [N, M, Q] = in.tup<int, int, int>();
    std::vector<int> ps(N, -1);
    graph g(N);
    graph tree(2 * N);
    for (int i = 0; i < M; i++) {
        const auto [u, v] = in.tup<int, int>(1, 1);
        g.add_edge(u, v, true);
    }
    std::vector<int> ds(N, -1);
    ds[0]     = 0;
    int dummy = N;
    fix([&](auto dfs, const int s) -> void {
        int min = N, minp = -1;
        int son = 0;
        for (const int to : g[s]) {
            if (ds[to] != -1) {
                if (ds[to] < ds[s]) {
                    if (chmin(min, ds[to])) { minp = to; }
                }
            } else {
                ds[to] = ds[s] + 1, ps[to] = s;
                dfs(to);
                son++;
            }
        }
        if (ps[s] != -1) {
            int v = s;
            tree.add_edge(dummy, v, true);
            while (v != minp) {
                if (ps[v] == -1) { break; }
                const int p = ps[v];
                ps[v] = -1, v = p;
                tree.add_edge(dummy, v, true);
            }
            dummy++;
        }
    })(0);
    while (dummy < 2 * N) {
        tree.add_edge(0, dummy, true);
        dummy++;
    }
    const auto lca = lca_manager(tree, 0);
    std::vector<int> ds2(2 * N, 0);
    fix([&](auto& dfs, const int s, const int p) -> void {
        for (const int to : tree[s]) {
            if (to == p) { continue; }
            ds2[to] = ds2[s] + 1;
            dfs(to, s);
        }
    })(0, -1);
    for (int q = 0; q < Q; q++) {
        const auto [u, v] = in.tup<int, int>(1, 1);
        const int l       = lca(u, v);
        const int ans     = ds2[u] + ds2[v] - 2 * ds2[l];
        out.ln(ans / 2);
    }
    return 0;
}