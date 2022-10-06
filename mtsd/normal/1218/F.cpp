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
int main()
{
    std::cin.tie(nullptr), std::ios::sync_with_stdio(false);
    const auto n = read<int>();
    auto k       = read<ll>();
    const auto x = read_vec<ll>(n);
    const auto a = read<ll>();
    const auto c = read_vec<ll>(n);
    std::priority_queue<ll, std::vector<ll>, std::greater<ll>> q;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        q.push(c[i]);
        const ll need = std::max((x[i] - k + a - 1) / a, 0LL);
        if (need > q.size()) { return std::cout << -1 << std::endl, 0; }
        k += need * a;
        for (int i = 0; i < need; i++) {
            const ll p = q.top();
            ans += p, q.pop();
        }
    }
    std::cout << ans << "\n";
    return 0;
}