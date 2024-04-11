#include <bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wsign-conversion"
#define NDEBUG
#define SHOW(...) static_cast<void>(0)
//!===========================================================!//
//!  dP     dP                          dP                    !//
//!  88     88                          88                    !//
//!  88aaaaa88a .d8888b. .d8888b. .d888b88 .d8888b. 88d888b.  !//
//!  88     88  88ooood8 88'  '88 88'  '88 88ooood8 88'  '88  !//
//!  88     88  88.  ... 88.  .88 88.  .88 88.  ... 88        !//
//!  dP     dP  '88888P' '88888P8 '88888P8 '88888P' dP        !//
//!===========================================================!//
template <typename T>
T read()
{
    T v;
    return std::cin >> v, v;
}
template <typename T>
std::vector<T> readVec(const std::size_t l)
{
    std::vector<T> v(l);
    for (auto& e : v) { std::cin >> e; }
    return v;
}
using ld = long double;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr unsigned int MOD = 1000000007;
template <typename T>
constexpr T INF = std::numeric_limits<T>::max() / 4;
template <typename F>
constexpr F PI = static_cast<F>(3.1415926535897932385);
std::mt19937 mt{std::random_device{}()};
template <typename T>
bool chmin(T& a, const T& b) { return (a > b ? a = b, true : false); }
template <typename T>
bool chmax(T& a, const T& b) { return (a < b ? a = b, true : false); }
template <typename T>
std::vector<T> Vec(const std::size_t n, T v) { return std::vector<T>(n, v); }
template <class... Args>
auto Vec(const std::size_t n, Args... args) { return std::vector<decltype(Vec(args...))>(n, Vec(args...)); }
template <typename T>
constexpr T popCount(const T u)
{
#ifdef __has_builtin
    return u == 0 ? T(0) : (T)__builtin_popcountll(u);
#else
    unsigned long long v = static_cast<unsigned long long>(u);
    return v = (v & 0x5555555555555555ULL) + (v >> 1 & 0x5555555555555555ULL), v = (v & 0x3333333333333333ULL) + (v >> 2 & 0x3333333333333333ULL), v = (v + (v >> 4)) & 0x0F0F0F0F0F0F0F0FULL, static_cast<T>(v * 0x0101010101010101ULL >> 56 & 0x7f);
#endif
}
template <typename T>
constexpr T log2p1(const T u)
{
#ifdef __has_builtin
    return u == 0 ? T(0) : T(64 - __builtin_clzll(u));
#else
    unsigned long long v = static_cast<unsigned long long>(u);
    return v = static_cast<unsigned long long>(v), v |= (v >> 1), v |= (v >> 2), v |= (v >> 4), v |= (v >> 8), v |= (v >> 16), v |= (v >> 32), popCount(v);
#endif
}
template <typename T>
constexpr T clog(const T v) { return v == 0 ? T(0) : log2p1(v - 1); }
template <typename T>
constexpr T msbp1(const T v) { return log2p1(v); }
template <typename T>
constexpr T lsbp1(const T v)
{
#ifdef __has_builtin
    return __builtin_ffsll(v);
#else
    return v == 0 ? T(0) : popCount((v & (-v)) - T(1)) + T(1);
#endif
}
template <typename T>
constexpr bool ispow2(const T v) { return popCount(v) == 1; }
template <typename T>
constexpr T ceil2(const T v) { return v == 0 ? T(1) : T(1) << log2p1(v - 1); }
template <typename T>
constexpr T floor2(const T v) { return v == 0 ? T(0) : T(1) << (log2p1(v) - 1); }
//!==============================================================================!//
//!  dP     dP          oo                       88888888b oo                dP  !//
//!  88     88                                   88                          88  !//
//!  88     88 88d888b. dP .d8888b. 88d888b.    a88aaaa    dP 88d888b. .d888b88  !//
//!  88     88 88'  '88 88 88'  '88 88'  '88     88        88 88'  '88 88'  '88  !//
//!  Y8.   .8P 88    88 88 88.  .88 88    88     88        88 88    88 88.  .88  !//
//!  'Y88888P' dP    dP dP '88888P' dP    dP     dP        dP dP    dP '88888P8  !//
//!==============================================================================!//
class UnionFind
{
public:
    UnionFind(const std::size_t v) : V(v), parent(v), size(v, 1) { std::iota(parent.begin(), parent.end(), 0); }
    std::size_t find(const std::size_t a) { return assert(a < V), parent[a] == a ? a : parent[a] = find(parent[a]); }
    bool same(const std::size_t a, const std::size_t b)
    {
        assert(a < V), assert(b < V);
        return find(a) == find(b);
    }
    void unite(std::size_t a, std::size_t b)
    {
        assert(a < V), assert(b < V);
        a = find(a), b = find(b);
        if (a == b) { return; }
        if (size[a] < size[b]) { std::swap(a, b); }
        size[a] += size[b], parent[b] = a;
    }
    std::size_t getSize(const std::size_t a) { return assert(a < V), size[find(a)]; }
    friend std::ostream& operator<<(std::ostream& os, const UnionFind& uf)
    {
        os << "[";
        for (std::size_t i = 0; i < uf.parent.size(); i++) { os << uf.parent[i] << (i + 1 == uf.parent.size() ? "" : ","); }
        return (os << "]\n");
    }

private:
    const std::size_t V;
    std::vector<std::size_t> parent, size;
};
//!=======================================================================!//
//!  dP                                      .d88888b                     !//
//!  88                                      88.    "'                    !//
//!  88        .d8888b. d888888b dP    dP    'Y88888b. .d8888b. .d8888b.  !//
//!  88        88'  '88    .d8P' 88    88          '8b 88ooood8 88'  '88  !//
//!  88        88.  .88  .Y8P    88.  .88    d8'   .8P 88.  ... 88.  .88  !//
//!  88888888P '88888P8 d888888P '8888P88     Y88888P  '88888P' '8888P88  !//
//!                                   .88                            .88  !//
//!                               d8888P                         d8888P   !//
//!=======================================================================!//
template <typename MAct>
class LazySeg
{
public:
    using ValMonoid = typename MAct::ValMonoid;
    using OpMonoid = typename MAct::OpMonoid;
    using ValType = typename ValMonoid::ValType;
    using OpType = typename OpMonoid::OpType;
    LazySeg(const std::size_t N, const ValType initial = ValMonoid::id()) : size(N), depth(clog(size)), half(1 << depth), val(half << 1, ValMonoid::id()), op(half << 1, OpMonoid::id())
    {
        if (initial != ValMonoid::id()) {
            std::fill(val.begin() + half, val.end(), initial);
            for (std::size_t i = half - 1; i >= 1; i--) { up(i); }
        }
    }
    template <typename InIt>
    LazySeg(const InIt first, const InIt last) : size(std::distance(first, last)), depth(clog(size)), half(1 << depth), val(half << 1, ValMonoid::id()), op(half << 1, OpMonoid::id())
    {
        std::copy(first, last, val.begin() + half);
        for (std::size_t i = half - 1; i >= 1; i--) { up(i); }
    }
    ValType get(const std::size_t a) { return assert(a < size), fold(a, a + 1); }
    void set(std::size_t a, const ValType& v)
    {
        assert(a < size);
        topDown(a += half), op[a] = OpMonoid::id(), val[a] = v;
        while (a >>= 1) { up(a); }
    }
    ValType fold(std::size_t L, std::size_t R)
    {
        assert(L < R);
        assert(R <= size);
        topDown(L += half), topDown(R += half);
        ValType accl = ValMonoid::id(), accr = ValMonoid::id();
        for (; L < R; L >>= 1, R >>= 1) {
            if (L & 1) { accl = acc(accl, val[L++]); }
            if (R & 1) { accr = acc(val[--R], accr); }
        }
        return acc(accl, accr);
    }
    void act(std::size_t L, std::size_t R, const OpType& f)
    {
        assert(L < R), assert(R <= size);
        const std::size_t l = L + half, r = R + half;
        topDown(L += half), topDown(R += half);
        for (std::size_t ls = 1, rs = 1; L < R; L >>= 1, R >>= 1, ls <<= 1, rs <<= 1) {
            if (L & 1) { update(L++, f, ls); }
            if (R & 1) { update(--R, f, rs); }
        }
        bottomUp(l), bottomUp(r);
    }
    friend std::ostream& operator<<(std::ostream& os, LazySeg& lseg)
    {
        os << "[";
        for (std::size_t i = 0; i < lseg.size; i++) { os << lseg.get(i) << (i + 1 == lseg.size ? "" : ","); }
        return (os << "]\n");
    }

private:
    void up(const std::size_t i) { val[i] = acc(val[i << 1], val[i << 1 | 1]); }
    void update(const std::size_t a, const OpType& f, const std::size_t l) { op[a] = compose(f, op[a]), val[a] = eval(f, val[a], l); }
    void down(const std::size_t a, const std::size_t l) { update(a << 1, op[a], l >> 1), update(a << 1 | 1, op[a], l >> 1), op[a] = OpMonoid::id(); }
    void topDown(const std::size_t a)
    {
        const std::size_t b = (a / (a & -a)) >> 1;
        for (std::size_t i = 0, l = half; i < depth; i++, l >>= 1) {
            const std::size_t v = a >> (depth - i);
            if (v > b) { break; }
            down(v, l);
        }
    }
    void bottomUp(std::size_t a)
    {
        a = (a / (a & -a)) >> 1;
        for (; a >= 1; a >>= 1) { up(a); }
    }
    const std::size_t size, depth, half;
    std::vector<ValType> val;
    std::vector<OpType> op;
    const ValMonoid acc{};
    const OpMonoid compose{};
    const MAct eval{};
};
//!======================================================================================!//
//!   a88888b.          .d88888b                    d888888P                             !//
//!  d8'   '88          88.    "'                      88                                !//
//!  88        .d8888b. 'Y88888b. .d8888b. .d8888b.    88    88d888b. .d8888b. .d8888b.  !//
//!  88        88'  '88       '8b 88ooood8 88'  '88    88    88'  '88 88ooood8 88ooood8  !//
//!  Y8.   .88 88.  .88 d8'   .8P 88.  ... 88.  .88    88    88       88.  ... 88.  ...  !//
//!   Y88888P' '88888P'  Y88888P  '88888P' '8888P88    dP    dP       '88888P' '88888P'  !//
//!                                             .88                                      !//
//!                                         d8888P                                       !//
//!======================================================================================!//
template <typename OpMonoid>
class CoSegTree
{
public:
    using OpType = typename OpMonoid::OpType;
    CoSegTree(const std::size_t N, const OpType& initial = OpMonoid::id()) : size(N), depth(clog(size)), half(1 << depth), op(half << 1, OpMonoid::id())
    {
        if (initial != OpMonoid::id()) { std::fill(op.begin() + half, op.end(), initial); }
    }
    template <typename InIt>
    CoSegTree(const InIt first, const InIt last) : size(std::distance(first, last)), depth(clog(size)), half(ceil2(size)), op(half << 1, OpMonoid::id()) { std::copy(first, last, op.begin() + half); }
    OpType get(const std::size_t a) const
    {
        assert(a < size);
        OpType ans = OpMonoid::id();
        for (std::size_t i = 0; i <= depth; i++) { ans = compose(ans, op[(a + half) >> (depth - i)]); }
        return ans;
    }
    void act(std::size_t L, std::size_t R, const OpType& f)
    {
        assert(L < R), assert(R <= size);
        cleanup(L += half), cleanup(R += half);
        for (; L < R; L >>= 1, R >>= 1) {
            if (L & 1) { update(L++, f); }
            if (R & 1) { update(--R, f); }
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const CoSegTree& seg)
    {
        os << "[";
        for (std::size_t i = 0; i < seg.size; i++) { os << seg.get(i) << (i + 1 == seg.size ? "" : ","); }
        return (os << "]\n");
    }

private:
    void down(const std::size_t a) { update(a << 1, op[a]), update(a << 1 | 1, op[a]), op[a] = OpMonoid::id(); }
    void cleanup(const std::size_t a)
    {
        for (std::size_t i = 0; i < depth; i++) { down(a >> (depth - i)); }
    }
    void update(const std::size_t a, const OpType& f) { op[a] = compose(f, op[a]); }
    const std::size_t size, depth, half;
    std::vector<OpType> op;
    const OpMonoid compose{};
};
//!=============================!//
//!  .d88888b             dP    !//
//!  88.    "'            88    !//
//!  'Y88888b. .d8888b. d8888P  !//
//!        '8b 88ooood8   88    !//
//!  d8'   .8P 88.  ...   88    !//
//!   Y88888P  '88888P'   dP    !//
//!=============================!//
template <typename ElemType>
struct Set
{
    using OpType = ElemType;
    OpType operator()(const OpType& f1, const OpType& f2) const { return f1 != std::numeric_limits<OpType>::max() ? f1 : f2; }
    static constexpr OpType id() { return std::numeric_limits<OpType>::max(); }
};
//!============================!//
//!  8888ba.88ba  oo           !//
//!  88  '8b  '8b              !//
//!  88   88   88 dP 88d888b.  !//
//!  88   88   88 88 88'  '88  !//
//!  88   88   88 88 88    88  !//
//!  dP   dP   dP dP dP    dP  !//
//!============================!//
template <typename Elemtype>
struct Min
{
    using ValType = Elemtype;
    ValType operator()(const ValType& a, const ValType& b) const { return std::min(a, b); }
    static constexpr ValType id() { return std::numeric_limits<ValType>::max(); }
};
//!===============================================================!//
//!  8888ba.88ba  oo                   .d88888b             dP    !//
//!  88  '8b  '8b                      88.    "'            88    !//
//!  88   88   88 dP 88d888b.          'Y88888b. .d8888b. d8888P  !//
//!  88   88   88 88 88'  '88 88888888       '8b 88ooood8   88    !//
//!  88   88   88 88 88    88          d8'   .8P 88.  ...   88    !//
//!  dP   dP   dP dP dP    dP           Y88888P  '88888P'   dP    !//
//!===============================================================!//
template <typename ValElemType, typename OpElemType>
struct Min_Set
{
    using ValMonoid = Min<ValElemType>;
    using OpMonoid = Set<OpElemType>;
    using ValType = typename ValMonoid::ValType;
    using OpType = typename OpMonoid::OpType;
    template <typename Ind>
    ValType operator()(const OpType& f, const ValType& x, const Ind) const { return f != OpMonoid::id() ? static_cast<ValType>(f) : x; }
};
//!=================================================!//
//!   .88888.                             dP        !//
//!  d8'   '88                            88        !//
//!  88        88d888b. .d8888b. 88d888b. 88d888b.  !//
//!  88   YP88 88'  '88 88'  '88 88'  '88 88'  '88  !//
//!  Y8.   .88 88       88.  .88 88.  .88 88    88  !//
//!   '88888'  dP       '88888P8 88Y888P' dP    dP  !//
//!                              88                 !//
//!                              dP                 !//
//!=================================================!//
struct Graph
{
    Graph(const std::size_t v) : V{v}, edge(v), rev_edge(v) {}
    void addEdge(const std::size_t from, const std::size_t to, const bool bi = false)
    {
        assert(from < V), assert(to < V);
        edge[from].push_back(to), rev_edge[to].push_back(from);
        if (bi) { addEdge(to, from, false); }
    }
    const std::vector<std::size_t>& operator[](const std::size_t i) const { return assert(i < V), edge[i]; }
    friend std::ostream& operator<<(std::ostream& os, const Graph& g)
    {
        os << "[\n";
        for (std::size_t i = 0; i < g.V; i++) {
            for (const std::size_t to : g.edge[i]) { os << i << "->" << to << "\n"; }
        }
        return (os << "]\n");
    }
    std::size_t V;
    std::vector<std::vector<std::size_t>> edge, rev_edge;
};
using Tree = Graph;
//!==================================!//
//!  dP     dP  dP        888888ba   !//
//!  88     88  88        88    '8b  !//
//!  88aaaaa88a 88        88     88  !//
//!  88     88  88        88     88  !//
//!  88     88  88        88    .8P  !//
//!  dP     dP  88888888P 8888888P   !//
//!==================================!//
class HLD
{
public:
    HLD(Tree& tree, const std::size_t r = 0) : par(tree.V, tree.V), top(tree.V, tree.V), in(tree.V, tree.V), out(tree.V, tree.V)
    {
        const std::size_t N = tree.V;
        std::vector<std::size_t> sz(N, 1);
        auto dfs1 = [&](auto&& self, const std::size_t s, const std::size_t p) -> std::size_t {
            par[s] = p;
            for (std::size_t& to : tree.edge[s]) {
                if (p == to) { continue; }
                sz[s] += self(self, to, s);
                if (sz[to] > sz[tree.edge[s][0]]) { std::swap(to, tree.edge[s][0]); }
            }
            return sz[s];
        };
        dfs1(dfs1, r, N);
        top[r] = r;
        auto dfs2 = [&](auto&& self, const std::size_t s, const std::size_t p, std::size_t& ind) -> void {
            in[s] = ind++;
            for (const std::size_t to : tree.edge[s]) {
                if (to == p) { continue; }
                top[to] = (to == tree.edge[s][0] ? top[s] : to);
                self(self, to, s, ind);
            }
            out[s] = ind;
        };
        std::size_t ind = 0;
        dfs2(dfs2, r, N, ind);
    }
    std::size_t at(const std::size_t v) const { return in[v]; }
    std::pair<std::size_t, std::size_t> sub(const std::size_t v) const { return {in[v], out[v]}; }
    std::vector<std::pair<std::size_t, std::size_t>> path(std::size_t u, std::size_t v, const bool edgeWeight = false) const
    {
        using P = std::pair<std::size_t, std::size_t>;
        std::vector<P> head, tail;
        for (std::size_t pu = top[u], pv = top[v]; pu != pv;) {
            if (in[pu] < in[pv]) {
                tail.push_back({in[pv], in[v]});
                v = par[pv], pv = top[v];
            } else {
                tail.push_back({in[u], in[pu]});
                u = par[pu], pu = top[u];
            }
        }
        if (edgeWeight) {
            if (std::abs((int)in[u] - (int)in[v]) >= 1) { head.push_back(in[u] < in[v] ? P{in[u] + 1, in[v]} : P{in[u], in[v] + 1}); }
        } else {
            head.push_back({in[u], in[v]});
        }
        std::reverse(tail.begin(), tail.end());
        for (const auto& p : tail) { head.push_back(p); }
        return head;
    }

private:
    std::vector<std::size_t> par, top, in, out;
};
//!====================================================================================================!//
//!  .d88888b                                                  d888888P          dP       dP           !//
//!  88.    "'                                                    88             88       88           !//
//!  'Y88888b. 88d888b. .d8888b. 88d888b. .d8888b. .d8888b.       88    .d8888b. 88d888b. 88 .d8888b.  !//
//!        '8b 88'  '88 88'  '88 88'  '88 Y8ooooo. 88ooood8       88    88'  '88 88'  '88 88 88ooood8  !//
//!  d8'   .8P 88.  .88 88.  .88 88             88 88.  ...       88    88.  .88 88.  .88 88 88.  ...  !//
//!   Y88888P  88Y888P' '88888P8 dP       '88888P' '88888P'       dP    '88888P8 88Y8888' dP '88888P'  !//
//!            88                                                                                      !//
//!            dP                                                                                      !//
//!====================================================================================================!//
template <typename SemiGroup>
class SparseTable
{
public:
    using ValType = typename SemiGroup::ValType;
    template <typename InIt>
    SparseTable(const InIt first, const InIt last) : D(clog(std::size_t(std::distance(first, last)) + 1)), table(D, std::vector<ValType>(1 << D))
    {
        const std::size_t N = 1 << D;
        for (std::size_t d = 0, B = 1; d < D; d++, B <<= 1) {
            std::copy(first, last, table[d].begin());
            for (std::size_t b = 0; b < N / B; b++) {
                if (b % 2 == 1) {
                    for (std::size_t i = 1; i < B; i++) { table[d][b * B + i] = op(table[d][b * B + i - 1], table[d][b * B + i]); }
                } else {
                    for (std::size_t i = 1; i < B; i++) { table[d][(b + 1) * B - i - 1] = op(table[d][(b + 1) * B - i - 1], table[d][(b + 1) * B - i]); }
                }
            }
        }
    }
    ValType fold(const std::size_t l, const std::size_t r) const
    {
        assert(l < r);
        if (r - l == 1) { return table[0][l]; }
        const std::size_t d = msbp1(r ^ l) - 1;
        return op(table[d][l], table[d][r - 1]);
    }

private:
    const std::size_t D;
    std::vector<std::vector<ValType>> table;
    const SemiGroup op{};
};
//!==========================================================================================!//
//!  dP        oo                                         888888ba  8888ba.88ba   .88888.    !//
//!  88                                                   88    '8b 88  '8b  '8b d8'   '8b   !//
//!  88        dP 88d888b. .d8888b. .d8888b. 88d888b.    a88aaaa8P' 88   88   88 88     88   !//
//!  88        88 88'  '88 88ooood8 88'  '88 88'  '88     88   '8b. 88   88   88 88  db 88   !//
//!  88        88 88    88 88.  ... 88.  .88 88           88     88 88   88   88 Y8.  Y88P   !//
//!  88888888P dP dP    dP '88888P' '88888P8 dP           dP     dP dP   dP   dP  '8888PY8b  !//
//!==========================================================================================!//
template <typename Type, typename Comp = std::less<Type>, typename B = uint64_t>
class LinearRMQ
{
    static constexpr std::size_t L = 1;

public:
    template <typename InIt>
    LinearRMQ(const InIt first, const InIt last) : N{std::size_t(std::distance(first, last))}, M{(N + L - 1) / L}, v{first, last}, blocks([&]() {
                                                       std::vector<Type> ans(M);
                                                       for (std::size_t i = 0; i < N; i++) { ans[i / L] = i % L == 0 ? v[i] : std::min(ans[i / L], v[i], Comp{}); }
                                                       return ans;
                                                   }()),
                                                   masks(N, 0),
                                                   stable(blocks.begin(), blocks.end())
    {
        for (std::size_t i = 0; i < M; i++) {
            std::vector<std::size_t> g(L, N);
            std::stack<std::size_t> stack;
            for (std::size_t j = 0; j < L and i * L + j < N; j++) {
                for (; not stack.empty() and not Comp{}(v[stack.top()], v[i * L + j]); stack.pop()) {}
                g[j] = stack.empty() ? N : stack.top(), stack.push(i * L + j);
            }
            for (std::size_t j = 0; j < L and i * L + j < N; j++) { masks[i * L + j] = g[j] == N ? B(0) : (masks[g[j]] | B(1) << (g[j] - i * L)); }
        }
    }
    Type fold(const std::size_t l, const std::size_t r) const
    {
        assert(l < r);
        const std::size_t LB = (l + L - 1) / L, RB = r / L;
        if (LB > RB) {
            return internal(l, r);
        } else {
            return LB < RB
                       ? (l < L * LB
                              ? (L * RB < r
                                     ? std::min({stable.fold(LB, RB), internal(l, L * LB), internal(L * RB, r)}, Comp{})
                                     : std::min(stable.fold(LB, RB), internal(l, L * LB), Comp{}))
                              : (L * RB < r
                                     ? std::min(stable.fold(LB, RB), internal(L * RB, r), Comp{})
                                     : stable.fold(LB, RB)))
                       : (l < L * LB
                              ? (L * RB < r
                                     ? std::min(internal(l, L * LB), internal(L * RB, r), Comp{})
                                     : internal(l, L * LB))
                              : (L * RB < r
                                     ? internal(L * RB, r)
                                     : Type{}));
        }
    }

private:
    Type internal(const std::size_t l, std::size_t r) const
    {
        r--;
        const B w = masks[r] >> (l % L);
        return w == 0 ? v[r] : v[l + lsbp1(w) - 1];
    }
    const std::size_t N, M;
    std::vector<Type> v, blocks;
    std::vector<B> masks;
    struct SMin
    {
        using ValType = Type;
        ValType operator()(const ValType& a, const ValType& b) const { return std::min(a, b, Comp{}); }
    };
    SparseTable<SMin> stable;
};
//!==================================!//
//!  dP         a88888b.  .d888888   !//
//!  88        d8'   '88 d8'    88   !//
//!  88        88        88aaaaa88a  !//
//!  88        88        88     88   !//
//!  88        Y8.   .88 88     88   !//
//!  88888888P  Y88888P' 88     88   !//
//!==================================!//
class LCA
{
public:
    LCA(const Tree& tree, const std::size_t root = 0) : left(tree.V, 0),
                                                        depth([&]() {
                                                            std::vector<std::pair<std::size_t, std::size_t>> ans;
                                                            std::vector<bool> used(tree.V, false);
                                                            auto dfs = [&](auto&& self, const std::pair<std::size_t, std::size_t>& s) -> void {
                                                                const std::size_t pos = s.second;
                                                                used[pos] = true, left[pos] = depth.size(), ans.push_back(s);
                                                                for (const std::size_t to : tree.edge[pos]) {
                                                                    if (used[to]) { continue; }
                                                                    self(self, {s.first + 1, to}), ans.push_back(s);
                                                                }
                                                            };
                                                            dfs(dfs, {0, root});
                                                            return ans;
                                                        }()),
                                                        stable(depth.begin(), depth.end()) {}
    std::size_t getLCA(const std::size_t u, const std::size_t v) const
    {
        const std::size_t ul = left[u], vl = left[v];
        return stable.fold(std::min(ul, vl), std::max(ul, vl) + 1).second;
    }

private:
    std::vector<std::size_t> left;
    std::vector<std::pair<std::size_t, std::size_t>> depth;
    LinearRMQ<std::pair<std::size_t, std::size_t>> stable;
};
//!=====================================!//
//!  8888ba.88ba           oo           !//
//!  88  '8b  '8b                       !//
//!  88   88   88 .d8888b. dP 88d888b.  !//
//!  88   88   88 88'  '88 88 88'  '88  !//
//!  88   88   88 88.  .88 88 88    88  !//
//!  dP   dP   dP '88888P8 dP dP    dP  !//
//!=====================================!//
int main()
{
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    const int N = read<int>(), M = read<int>();
    std::vector<int> u(M), v(M), c(M);
    std::vector<bool> used(M, false);
    for (int i = 0; i < M; i++) { std::cin >> u[i] >> v[i] >> c[i], u[i]--, v[i]--; }
    std::vector<int> ind(M);
    std::iota(ind.begin(), ind.end(), 0);
    std::sort(ind.begin(), ind.end(), [&](const int i, const int j) { return c[i] < c[j]; });
    UnionFind uf(N);
    Graph G(2 * N - 1);
    std::vector<int> top(N);
    std::iota(top.begin(), top.end(), 0);
    std::vector<int> cost(2 * N - 1, 0);
    int uc = 0;
    Tree T(N);
    for (const int i : ind) {
        if (uf.same(u[i], v[i])) { continue; }
        used[i] = true;
        T.addEdge(u[i], v[i], true);
        G.addEdge(N + uc, top[uf.find(u[i])], true), G.addEdge(N + uc, top[uf.find(v[i])], true);
        uf.unite(u[i], v[i]), cost[N + uc] = c[i], top[uf.find(u[i])] = N + uc, uc++;
    }
    HLD hld(T);
    std::vector<int> in(N);
    for (int i = 0; i < N; i++) { in[i] = hld.at(i); }
    auto rev = ind;
    std::reverse(rev.begin(), rev.end());
    LazySeg<Min_Set<int, int>> seg(N);
    //CoSegTree<Set<int>> seg(N);
    seg.act(0, N, 1000000000);
    for (const int i : rev) {
        if (used[i]) { continue; }
        const auto pathes = hld.path(u[i], v[i], true);
        for (const auto& p : pathes) {
            const std::size_t l = std::min(p.first, p.second), r = std::max(p.first, p.second) + 1;
            seg.act(l, r, c[i]);
        }
    }
    LCA lca(G, 2 * N - 2);
    using P = std::pair<int, int>;
    std::map<P, int> e;
    for (int i = 0; i < N; i++) {
        for (const int to : T[i]) {
            if (in[i] > in[to]) { continue; }
            e[std::minmax(i, to)] = seg.get(in[to]);
        }
    }
    for (int i = 0; i < M; i++) {
        if (used[i]) {
            std::cout << e[std::minmax(u[i], v[i])] << "\n";
        } else {
            const int l = lca.getLCA(u[i], v[i]);
            std::cout << cost[l] << "\n";
        }
    }
    return 0;
}