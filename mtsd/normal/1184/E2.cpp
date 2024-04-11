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
    std::vector<int> u(M), v(M);
    std::vector<ll> c(M);
    std::vector<bool> used(M, false);
    for (int i = 0; i < M; i++) { std::cin >> u[i] >> v[i] >> c[i], u[i]--, v[i]--; }
    std::vector<int> ind(M);
    std::iota(ind.begin(), ind.end(), 0);
    std::sort(ind.begin(), ind.end(), [&](const int i, const int j) { return c[i] < c[j]; });
    UnionFind uf(N);
    Graph G(2 * N - 1);
    std::vector<int> top(N);
    std::iota(top.begin(), top.end(), 0);
    std::vector<ll> cost(2 * N - 1, 0);
    int uc = 0;
    for (const int i : ind) {
        if (uf.same(u[i], v[i])) { continue; }
        used[i] = true;
        G.addEdge(N + uc, top[uf.find(u[i])], true), G.addEdge(N + uc, top[uf.find(v[i])], true);
        uf.unite(u[i], v[i]);
        cost[N + uc] = c[i], top[uf.find(u[i])] = N + uc, uc++;
    }
    LCA lca(G, 2 * N - 2);
    for (int i = 0; i < M; i++) {
        if (used[i]) { continue; }
        const int l = lca.getLCA(u[i], v[i]);
        std::cout << cost[l] << "\n";
    }
    return 0;
}