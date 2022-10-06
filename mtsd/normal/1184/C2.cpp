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
//!===================================!//
//!   888888ba  dP                    !//
//!   88    '8b 88                    !//
//!  a88aaaa8P' 88 dP    dP .d8888b.  !//
//!   88        88 88    88 Y8ooooo.  !//
//!   88        88 88.  .88       88  !//
//!   dP        dP '88888P' '88888P'  !//
//!===================================!//
template <typename ElemType>
struct Plus
{
    using OpType = ElemType;
    OpType operator()(const OpType& a, const OpType& b) const { return a + b; }
    static constexpr OpType id() { return OpType{}; }
};
//!=====================================================================!//
//!  8888ba.88ba  oo                    888888ba  dP                    !//
//!  88  '8b  '8b                       88    '8b 88                    !//
//!  88   88   88 dP 88d888b.          a88aaaa8P' 88 dP    dP .d8888b.  !//
//!  88   88   88 88 88'  '88 88888888  88        88 88    88 Y8ooooo.  !//
//!  88   88   88 88 88    88           88        88 88.  .88       88  !//
//!  dP   dP   dP dP dP    dP           dP        dP '88888P' '88888P'  !//
//!=====================================================================!//
template <typename ValElemType, typename OpElemType>
struct Min_Plus
{
    using ValMonoid = Min<ValElemType>;
    using OpMonoid = Plus<OpElemType>;
    using ValType = typename ValMonoid::ValType;
    using OpType = typename OpMonoid::OpType;
    template <typename Ind>
    ValType operator()(const OpType& f, const ValType& x, const Ind) const { return x == ValMonoid::id() ? x : static_cast<ValType>(f) + x; }
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
    int N, R;
    std::cin >> N >> R;
    std::vector<int> x(N), y(N);
    for (int i = 0; i < N; i++) { std::cin >> x[i] >> y[i], std::tie(x[i], y[i]) = std::pair<int, int>{x[i] + y[i], x[i] - y[i]}; }
    using P = std::pair<bool, int>;
    constexpr int L = 3000000;
    std::vector<std::vector<P>> op(2 * L + 10);
    for (int i = 0; i < N; i++) { op[y[i] - R + L].push_back({true, x[i] - R + L}), op[y[i] + R + 1 + L].push_back({false, x[i] - R + L}); }
    LazySeg<Min_Plus<int, int>> seg((std::size_t)2 * L + 10, 0);
    int ans = 0;
    for (int y = 0; y < 2 * L + 10; y++) {
        if (op[y].empty()) { continue; }
        for (const auto& o : op[y]) {
            const bool in = o.first;
            const int xl = o.second;
            const int xr = o.second + 2 * R + 1;
            seg.act(xl, xr, in ? -1 : 1);
        }
        chmin(ans, seg.fold(0, 2 * L + 10));
    }
    std::cout << -ans << "\n";
    return 0;
}