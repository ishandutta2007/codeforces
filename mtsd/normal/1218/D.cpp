#include <bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wsign-conversion"

#define NDEBUG
using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
using uint = unsigned int;
using usize = std::size_t;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
template<typename T> constexpr T popcount(const T u) { return u ? static_cast<T>(__builtin_popcountll(static_cast<u64>(u))) : static_cast<T>(0); }
template<typename T> constexpr T log2p1(const T u) { return u ? static_cast<T>(64 - __builtin_clzll(static_cast<u64>(u))) : static_cast<T>(0); }
template<typename T> constexpr T msbp1(const T u) { return log2p1(u); }
template<typename T> constexpr T lsbp1(const T u) { return __builtin_ffsll(u); }
template<typename T> constexpr T clog(const T u) { return u ? log2p1(u - 1) : static_cast<T>(u); }
template<typename T> constexpr bool ispow2(const T u) { return u and (static_cast<u64>(u) & static_cast<u64>(u - 1)) == 0; }
template<typename T> constexpr T ceil2(const T u) { return static_cast<T>(1) << clog(u); }
template<typename T> constexpr T floor2(const T u) { return u == 0 ? static_cast<T>(0) : static_cast<T>(1) << (log2p1(u) - 1); }
template<typename T> constexpr bool btest(const T mask, const usize ind) { return ((static_cast<u64>(mask) >> ind) & static_cast<u64>(1)); }
template<typename T> constexpr T bcut(const T mask, const usize ind) { return ind == 0 ? static_cast<T>(0) : static_cast<T>((static_cast<u64>(mask) << (64 - ind)) >> (64 - ind)); }
template<typename T> bool chmin(T& a, const T& b) { return (a > b ? a = b, true : false); }
template<typename T> bool chmax(T& a, const T& b) { return (a < b ? a = b, true : false); }
constexpr unsigned int mod                  = 1000000007;
template<typename T> constexpr T inf_v      = std::numeric_limits<T>::max() / 4;
template<typename Real> constexpr Real pi_v = Real{3.141592653589793238462643383279502884};


/**
 * http://xoshiro.di.unimi.it/xoshiro128starstar.c
 * http://xoshiro.di.unimi.it/xoshiro256starstar.c
 * http://xoshiro.di.unimi.it/splitmix64.c
 */
class xoshiro
{
public:
    using result_type = uint32_t;
    static constexpr result_type min() { return std::numeric_limits<result_type>::min(); }
    static constexpr result_type max() { return std::numeric_limits<result_type>::max(); }
    xoshiro() : xoshiro(std::random_device{}()) {}
    xoshiro(uint64_t seed)
    {
        uint64_t z = 0;
        for (int i = 0; i < 4; i++) { z = (seed += 0x9e3779b97f4a7c15), z = (z ^ (z >> 33)) * 0x62A9D9ED799705F5, z = (z ^ (z >> 28)) * 0xCB24D0A5C88C35B3, s[i] = static_cast<result_type>(z >> 32); }
    }
    result_type operator()()
    {
        const result_type result = rotl(s[1] * 5, 7) * 9, t = s[1] << 9;
        return s[2] ^= s[0], s[3] ^= s[1], s[1] ^= s[2], s[0] ^= s[3], s[2] ^= t, s[3] = rotl(s[3], 11), result;
    }
    void discard(const usize rep)
    {
        for (usize i = 0; i < rep; i++) { (*this)(); }
    }

private:
    result_type s[4];
    static result_type rotl(const result_type x, const int k) { return (x << k) | (x >> (32 - k)); }
};
class xoshiro_64
{
public:
    using result_type = uint64_t;
    static constexpr result_type min() { return std::numeric_limits<result_type>::min(); }
    static constexpr result_type max() { return std::numeric_limits<result_type>::max(); }
    xoshiro_64() : xoshiro_64(std::random_device{}()) {}
    xoshiro_64(uint64_t seed)
    {
        uint64_t z = 0;
        for (int i = 0; i < 4; i++) { z = (seed += 0x9e3779b97f4a7c15), z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9, z = (z ^ (z >> 27)) * 0x94d049bb133111eb, s[i] = static_cast<result_type>(z ^ (z >> 31)); }
    }
    result_type operator()()
    {
        const result_type result = rotl(s[1] * 5, 7) * 9, t = s[1] << 17;
        return s[2] ^= s[0], s[3] ^= s[1], s[1] ^= s[2], s[0] ^= s[3], s[2] ^= t, s[3] = rotl(s[3], 45), result;
    }
    void discard(const usize rep)
    {
        for (usize i = 0; i < rep; i++) { (*this)(); }
    }

private:
    result_type s[4];
    static result_type rotl(const result_type x, const int k) { return (x << k) | (x >> (64 - k)); }
};
template<typename Rng>
class rng_base
{
public:
    using rng_type    = Rng;
    using result_type = typename rng_type::result_type;
    static constexpr result_type min() { return rng_type::min(); }
    static constexpr result_type max() { return rng_type::max(); }
    rng_base() : rng_base(std::random_device{}()) {}
    rng_base(const u64 seed) : rng(seed) {}
    ~rng_base() = default;
    result_type operator()() { return rng(); }
    template<typename Int>
    Int uniform_int(const Int max)
    {
        static_assert(std::is_integral<Int>::value, "Integer type is needed.");
        if (ispow2(max + 1)) { return static_cast<Int>(rng() & max); }
        const result_type mask = static_cast<result_type>(ceil2(static_cast<u64>(max + 1))) - 1;
        while (true) {
            const Int ans = static_cast<Int>(rng() & mask);
            if (ans <= max) { return ans; }
        }
    }
    template<typename Int> Int uniform_int(const Int min, const Int max) { return min + uniform_int(static_cast<Int>(max - min)); }
    bool uniform_bool() { return uniform_int<bool>(0, 1); }
    template<typename Real>
    Real uniform_real()
    {
        static_assert(std::is_floating_point<Real>::value, "FloatingPoint type is needed.");
        return static_cast<Real>(uniformInt(~static_cast<result_type>(0)) / static_cast<Real>(~static_cast<result_type>(0)));
    }
    template<typename Real> Real uniform_real(const Real min, const Real max) { return assert(min <= max), uniform_real<Real>() * (max - min) + min; }
    template<typename Int> std::pair<Int, Int> uniform_int_pair(const Int min, const Int max) { return std::minmax(uniform_int(min, max), uniform_int(min, max)); }
    template<typename Int>
    std::vector<Int> uniform_int_vec(const std::size_t size, const Int min, const Int max)
    {
        std::vector<Int> v(size);
        for (std::size_t i = 0; i < size; i++) { v[i] = uniformInt(min, max); }
        return v;
    }
    template<typename Real>
    std::vector<Real> uniform_real_vec(const std::size_t size, const Real min, const Real max)
    {
        std::vector<Real> v(size);
        for (std::size_t i = 0; i < size; i++) { v[i] = uniformReal(min, max); }
        return v;
    }
    void discard(const usize rep) { rng.discard(rep); }

private:
    Rng rng;
};
using rng_mt        = rng_base<std::mt19937>;
using rng_mt64      = rng_base<std::mt19937_64>;
using rng_xoshiro   = rng_base<xoshiro>;
using rng_xoshiro64 = rng_base<xoshiro_64>;
rng_mt g_rng_mt;
rng_mt64 g_rng_mt64;
rng_xoshiro g_rng_xo;
rng_xoshiro64 g_rng_xo64;
template<typename T>
T read()
{
    T v;
    return std::cin >> v, v;
}
template<typename T>
std::vector<T> read_vec(const std::size_t size)
{
    std::vector<T> v(size);
    for (auto& e : v) { std::cin >> e; }
    return v;
}
#define SHOW(...) static_cast<void>(0)
template<typename T>
std::vector<T> make_v(const std::size_t size, T v) { return std::vector<T>(size, v); }
template<class... Args>
auto make_v(const std::size_t size, Args... args) { return std::vector<decltype(make_v(args...))>(size, make_v(args...)); }


template<typename Cost>
class base_graph
{
public:
    using cost_type = Cost;
    base_graph(const usize sz) : sz{sz}, edges(sz), rev_edges(sz) {}
    void add_edge(const usize from, const usize to, const Cost cost, const bool bi = false)
    {
        assert(from < sz), assert(to < sz);
        edges[from].push_back(edge{from, to, cost}), rev_edges[to].push_back(edge(to, from, cost));
        if (bi) { add_edge(to, from, cost, false); }
    }
    struct edge
    {
        edge(const usize from, const usize to, const Cost cost) : from{from}, to{to}, cost{cost} {}
        const usize from, to;
        const Cost cost;
        bool operator<(const edge& e) const { return cost != e.cost ? cost < e.cost : to < e.to; }
    };
    const std::vector<edge>& operator[](const usize i) const { return assert(i < sz), edges[i]; }
    std::vector<edge>& operator[](const usize i) { return assert(i < sz), edges[i]; }
    const std::vector<std::vector<edge>>& rev_edge() const { return rev_edges; }
    std::vector<std::vector<edge>>& rev_edge() { return rev_edges; }
    friend std::ostream& operator<<(std::ostream& os, const base_graph& g)
    {
        os << "[\n";
        for (usize i = 0; i < g.V; i++) {
            for (const auto& e : g.edges[i]) { os << i << "->" << e.to << ":" << e.cost << "\n"; }
        }
        return (os << "]\n");
    }
    static usize to(const edge& e) { return e.to; }
    usize size() const { return sz; }

private:
    const usize sz;
    std::vector<std::vector<edge>> edges, rev_edges;
};
template<>
class base_graph<void>
{
public:
    base_graph(const usize sz) : sz{sz}, edges(sz), rev_edges(sz) {}
    void add_edge(const usize from, const usize to, const bool bi = false)
    {
        assert(from < sz), assert(to < sz);
        edges[from].push_back(to), rev_edges[to].push_back(from);
        if (bi) { add_edge(to, from, false); }
    }
    const std::vector<usize>& operator[](const usize i) const { return assert(i < sz), edges[i]; }
    std::vector<usize>& operator[](const usize i) { return assert(i < sz), edges[i]; }
    const std::vector<std::vector<usize>>& rev_edge() const { return rev_edges; }
    std::vector<std::vector<usize>>& rev_edge() { return rev_edges; }
    friend std::ostream& operator<<(std::ostream& os, const base_graph& g)
    {
        os << "[\n";
        for (usize i = 0; i < g.sz; i++) {
            for (const usize to : g.edges[i]) { os << i << "->" << to << "\n"; }
        }
        return (os << "]\n");
    }
    static usize to(const usize e) { return e; }
    usize size() const { return sz; }

private:
    const usize sz;
    std::vector<std::vector<usize>> edges, rev_edges;
};
using graph = base_graph<void>;
using tree  = graph;
template<typename Cost>
using cost_graph = base_graph<Cost>;
template<typename Cost>
using cost_tree = cost_graph<Cost>;
template<typename Cost>
class lowlink
{
private:
    using P = std::pair<usize, usize>;
    const usize sz;
    std::vector<P> bs;
    std::vector<usize> ord, low, as;
    std::vector<bool> is_a;
    std::vector<std::vector<usize>> dfs_tree;

public:
    lowlink(const base_graph<Cost>& g) : sz(g.size()), ord(sz, sz), low(sz, sz), is_a(sz, false), dfs_tree(sz)
    {
        usize num = 0;
        auto dfs  = [&](auto&& self, const usize s, const usize p) -> void {
            ord[s] = low[s] = num++;
            usize back      = 0;
            for (const auto& e : g[s]) {
                const usize to = base_graph<Cost>::to(e);
                if (ord[to] == sz) {
                    dfs_tree[s].push_back(to), self(self, to, s), low[s] = std::min(low[s], low[to]);
                } else {
                    if (p == to) { back++; }
                    if (p != to or back > 1) { low[s] = std::min(low[s], ord[to]); }
                }
            }
        };
        auto dfs2 = [&](auto&& self, const usize s) -> void {
            usize max = 0;
            for (const usize to : dfs_tree[s]) {
                max = std::max(max, low[to]);
                if (is_bridge(s, to)) { bs.push_back({s, to}); }
                self(self, to);
            }
            is_a[s] = ord[s] <= max and (s != 0 or dfs_tree[s].size() > 1);
            if (is_a[s]) { as.push_back(s); }
        };
        for (usize i = 0; i < sz; i++) {
            if (ord[i] != sz) { continue; }
            dfs(dfs, i, sz), dfs2(dfs2, i);
        }
    }
    bool is_art(const usize i) const { return is_a[i]; }
    bool is_bridge(const usize i, const usize j) const { return (ord[i] < ord[j]) ? ord[i] < low[j] : ord[j] < low[i]; }
    const std::vector<P>& bridges() const { return bs; }
    const std::vector<usize>& arts() const { return as; }
};
template<typename Cost>
class bcc
{
public:
    bcc(const base_graph<Cost>& g) : sz{g.size()}, cmp(sz, sz), link{g}
    {
        auto dfs = [&](auto&& self, const usize s) -> void {
            cmp[s] = cnum;
            for (const usize to : g[s]) {
                if (cmp[to] != sz or link.is_bridge(s, to)) { continue; }
                self(self, to);
            }
        };
        for (usize i = 0; i < sz; i++) {
            if (cmp[i] != sz) { continue; }
            dfs(dfs, i), cnum++;
        }
    }
    usize operator[](const usize v) { return assert(v < sz), cmp[v]; }
    usize comp_num() const { return cnum; }

private:
    const usize sz;
    usize cnum = 0;
    std::vector<usize> cmp;
    const lowlink<Cost> link;
};


template<typename T> T gcd(const T& a, const T& b) { return (a > b ? gcd(b, a) : a == 0 ? b : gcd(b % a, a)); }
template<typename T> T lcm(const T& a, const T& b) { return a / gcd(a, b) * b; }
template<typename T>
constexpr std::pair<T, T> extgcd(const T a, const T b)
{
    if (b == 0) { return std::pair<T, T>{1, 0}; }
    const auto g = gcd(a, b), da = std::abs(b) / g;
    const auto p = extgcd(b, a % b);
    const auto x = (da + p.second % da) % da, y = (g - a * x) / b;
    return {x, y};
}
template<typename T>
constexpr T inverse(const T a, const T mod) { return extgcd(a, mod).first; }
template<uint mod_value, bool dynamic = false>
class modint_base
{
public:
    template<typename UInt = uint>
    static std::enable_if_t<dynamic, const UInt> mod() { return mod_ref(); }
    template<typename UInt = uint>
    static constexpr std::enable_if_t<not dynamic, const UInt> mod() { return mod_value; }
    template<typename UInt = uint>
    static void set_mod(const std::enable_if_t<dynamic, const UInt> mod) { mod_ref() = mod; }
    modint_base() : v{0} {}
    modint_base(const ll val) : v{norm(static_cast<uint>(val % static_cast<ll>(mod()) + static_cast<ll>(mod())))} {}
    modint_base(const modint_base& n) : v{n()} {}
    explicit operator bool() const { return v != 0; }
    bool operator!() const { return not static_cast<bool>(*this); }
    modint_base& operator=(const modint_base& m) { return v = m(), (*this); }
    modint_base& operator=(const ll val) { return v = norm(uint(val % static_cast<ll>(mod()) + static_cast<ll>(mod()))), (*this); }
    friend modint_base operator+(const modint_base& m) { return m; }
    friend modint_base operator-(const modint_base& m) { return make(norm(mod() - m.v)); }
    friend modint_base operator+(const modint_base& m1, const modint_base& m2) { return make(norm(m1.v + m2.v)); }
    friend modint_base operator-(const modint_base& m1, const modint_base& m2) { return make(norm(m1.v + mod() - m2.v)); }
    friend modint_base operator*(const modint_base& m1, const modint_base& m2) { return make(static_cast<uint>(static_cast<ll>(m1.v) * static_cast<ll>(m2.v) % static_cast<ll>(mod()))); }
    friend modint_base operator/(const modint_base& m1, const modint_base& m2) { return m1 * inv(m2.v); }
    friend modint_base operator+(const modint_base& m, const ll val) { return modint_base{static_cast<ll>(m.v) + val}; }
    friend modint_base operator-(const modint_base& m, const ll val) { return modint_base{static_cast<ll>(m.v) - val}; }
    friend modint_base operator*(const modint_base& m, const ll val) { return modint_base{static_cast<ll>(m.v) * (val % static_cast<ll>(mod()))}; }
    friend modint_base operator/(const modint_base& m, const ll val) { return modint_base{static_cast<ll>(m.v) * inv(val)}; }
    friend modint_base operator+(const ll val, const modint_base& m) { return modint_base{static_cast<ll>(m.v) + val}; }
    friend modint_base operator-(const ll val, const modint_base& m) { return modint_base{-static_cast<ll>(m.v) + val}; }
    friend modint_base operator*(const ll val, const modint_base& m) { return modint_base{static_cast<ll>(m.v) * (val % static_cast<ll>(mod()))}; }
    friend modint_base operator/(const ll val, const modint_base& m) { return modint_base{val * inv(static_cast<ll>(m.v))}; }
    friend modint_base& operator+=(modint_base& m1, const modint_base& m2) { return m1 = m1 + m2; }
    friend modint_base& operator-=(modint_base& m1, const modint_base& m2) { return m1 = m1 - m2; }
    friend modint_base& operator*=(modint_base& m1, const modint_base& m2) { return m1 = m1 * m2; }
    friend modint_base& operator/=(modint_base& m1, const modint_base& m2) { return m1 = m1 / m2; }
    friend modint_base& operator+=(modint_base& m, const ll val) { return m = m + val; }
    friend modint_base& operator-=(modint_base& m, const ll val) { return m = m - val; }
    friend modint_base& operator*=(modint_base& m, const ll val) { return m = m * val; }
    friend modint_base& operator/=(modint_base& m, const ll val) { return m = m / val; }
    friend modint_base operator^(const modint_base& m, const ll n) { return power(m.v, n); }
    friend modint_base& operator^=(modint_base& m, const ll n) { return m = m ^ n; }
    friend bool operator==(const modint_base& m1, const modint_base& m2) { return m1.v == m2.v; }
    friend bool operator!=(const modint_base& m1, const modint_base& m2) { return not(m1 == m2); }
    friend bool operator==(const modint_base& m, const ll val) { return m.v == norm(static_cast<uint>(static_cast<ll>(mod()) + val % static_cast<ll>(mod()))); }
    friend bool operator!=(const modint_base& m, const ll val) { return not(m == val); }
    friend bool operator==(const ll val, const modint_base& m) { return m.v == norm(static_cast<uint>(static_cast<ll>(mod()) + val % static_cast<ll>(mod()))); }
    friend bool operator!=(const ll val, const modint_base& m) { return not(m == val); }
    friend std::istream& operator>>(std::istream& is, modint_base& m)
    {
        ll v;
        return is >> v, m = v, is;
    }
    friend std::ostream& operator<<(std::ostream& os, const modint_base& m) { return os << m(); }
    uint operator()() const { return v; }

private:
    template<typename UInt = uint>
    static std::enable_if_t<dynamic, UInt&> mod_ref()
    {
        static UInt mod = 0;
        return mod;
    }
    static uint norm(const uint x) { return x < mod() ? x : x - mod(); }
    static modint_base make(const uint x)
    {
        modint_base m;
        return m.v = x, m;
    }
    static modint_base power(modint_base x, ull n)
    {
        modint_base ans = 1;
        for (; n; n >>= 1, x *= x) {
            if (n & 1) { ans *= x; }
        }
        return ans;
    }
    static modint_base inv(const modint_base& x) { return modint_base{inverse(static_cast<ll>(x.v), static_cast<ll>(mod()))}; }

    uint v;
};
template<uint mod>
using modint = modint_base<mod, false>;
template<uint id>
using dynamic_modint = modint_base<id, true>;
template<uint mod>
struct bfft
{
    static constexpr uint i2 = (mod + 1) / 2;
    using Value              = modint<mod>;
    using value_type         = Value;
    bfft()                   = delete;
    static void fzt(std::vector<value_type>& a, const bool upper)
    {
        const usize sz = a.size();
        assert(ispow2(sz));
        for (usize i = 1; i < sz; i <<= 1) {
            for (usize j = 0; j < sz; j++) {
                if ((j & i) == 0) { (upper ? a[j] : a[j | i]) += (upper ? a[j | i] : a[j]); }
            }
        }
    }
    static void fmt(std::vector<value_type>& a, const bool upper)
    {
        const usize sz = a.size();
        assert(ispow2(sz));
        for (usize i = 1; i < sz; i <<= 1) {
            for (usize j = 0; j < sz; j++) {
                if ((j & i) == 0) { (upper ? a[j] : a[j | i]) -= (upper ? a[j | i] : a[j]); }
            }
        }
    }
    static void fwt(std::vector<value_type>& a, const bool rev)
    {
        const usize sz = a.size();
        assert(ispow2(sz));
        for (usize i = 1; i < sz; i <<= 1) {
            for (usize j = 0; j < sz; j++) {
                if ((j & i) == 0) {
                    const value_type x = a[j], y = a[j | i];
                    a[j] = (rev ? (x + y) * i2 : x + y), a[j | i] = (rev ? (x - y) * i2 : x - y);
                }
            }
        }
    }
    static std::vector<value_type> and_convolute(const std::vector<value_type>& a, const std::vector<value_type>& b)
    {
        const usize sz = ispow2(std::max(a.size(), b.size())) ? a.size() : ceil2(std::max(a.size(), b.size()));
        std::vector<value_type> A(sz), B(sz);
        for (usize i = 0; i < a.size(); i++) { A[i] = a[i]; }
        for (usize i = 0; i < b.size(); i++) { B[i] = b[i]; }
        fzt(A, true), fzt(B, true);
        for (usize i = 0; i < sz; i++) { A[i] *= B[i]; }
        return fmt(A, true), A;
    }
    static std::vector<value_type> or_convolute(const std::vector<value_type>& a, const std::vector<value_type>& b)
    {
        const usize sz = ispow2(std::max(a.size(), b.size())) ? a.size() : ceil2(std::max(a.size(), b.size()));
        std::vector<value_type> A(sz), B(sz);
        for (usize i = 0; i < a.size(); i++) { A[i] = a[i]; }
        for (usize i = 0; i < b.size(); i++) { B[i] = b[i]; }
        fzt(A, false), fzt(B, false);
        for (usize i = 0; i < sz; i++) { A[i] *= B[i]; }
        return fmt(A, false), A;
    }
    static std::vector<value_type> xor_convolute(const std::vector<value_type>& a, const std::vector<value_type>& b)
    {
        const usize sz = ispow2(std::max(a.size(), b.size())) ? a.size() : ceil2(std::max(a.size(), b.size()));
        std::vector<value_type> A(sz), B(sz);
        for (usize i = 0; i < a.size(); i++) { A[i] = a[i]; }
        for (usize i = 0; i < b.size(); i++) { B[i] = b[i]; }
        fwt(A, false), fwt(B, false);
        for (usize i = 0; i < sz; i++) { A[i] *= B[i]; }
        return fwt(A, true), A;
    }
};
int main()
{
    std::cin.tie(nullptr), std::ios::sync_with_stdio(false);
    constexpr uint mod1 = 1000000007, mod2 = 1000000009;
    using mint1  = modint<mod1>;
    using mint2  = modint<mod2>;
    const auto n = read<int>(), m = read<int>();
    graph g(n);
    int x = 0;
    std::vector<int> u(m), v(m), w(m);
    for (int i = 0; i < m; i++) {
        std::cin >> u[i] >> v[i] >> w[i], u[i]--, v[i]--;
        g.add_edge(u[i], v[i], true), x ^= w[i];
    }
    bcc b(g);
    std::vector<int> num(n, 0);
    for (int i = 0; i < n; i++) { num[b[i]]++; }
    std::vector<bool> isc(n);
    for (int i = 0; i < n; i++) { isc[i] = (num[i] >= 2); }
    std::vector<std::vector<int>> c(n);
    for (int i = 0; i < m; i++) {
        if (b[u[i]] == b[v[i]] and isc[b[u[i]]]) { c[b[u[i]]].push_back(w[i]); }
    }
    constexpr int max = 1 << 17;
    std::vector<mint1> dp1(max, 0);
    std::vector<mint2> dp2(max, 0);
    dp1[0] = 1, dp2[0] = 1;
    std::vector<mint1> v1(max, 0);
    std::vector<mint2> v2(max, 0);
    for (int i = 0; i < n; i++) {
        if (c[i].empty()) { continue; }
        std::fill(v1.begin(), v1.end(), 0), std::fill(v2.begin(), v2.end(), 0);
        for (const int w : c[i]) { v1[w] += 1, v2[w] += 1; }
        dp1 = bfft<mod1>::xor_convolute(dp1, v1), dp2 = bfft<mod2>::xor_convolute(dp2, v2);
    }
    for (int i = 0; i < max; i++) {
        if (dp1[i ^ x] == 0 and dp2[x ^ i] == 0) { continue; }
        std::cout << i << " " << dp1[x ^ i] << "\n";
        break;
    }
    return 0;
}