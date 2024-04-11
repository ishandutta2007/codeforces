#include <bits/stdc++.h>
// created [2019/12/01] 16:38:40
// 
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wsign-conversion"

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
template<typename T> constexpr bool btest(const T mask, const usize ind) { return static_cast<bool>((static_cast<u64>(mask) >> ind) & static_cast<u64>(1)); }
template<typename T> void bset(T& mask, const usize ind) { mask |= (static_cast<T>(1) << ind); }
template<typename T> void breset(T& mask, const usize ind) { mask &= ~(static_cast<T>(1) << ind); }
template<typename T> void bflip(T& mask, const usize ind) { mask ^= (static_cast<T>(1) << ind); }
template<typename T> void bset(T& mask, const usize ind, const bool b) { (b ? bset(mask, ind) : breset(mask, ind)); }
template<typename T> constexpr T bcut(const T mask, const usize ind) { return ind == 0 ? static_cast<T>(0) : static_cast<T>((static_cast<u64>(mask) << (64 - ind)) >> (64 - ind)); }
template<typename T> bool chmin(T& a, const T& b) { return (a > b ? a = b, true : false); }
template<typename T> bool chmax(T& a, const T& b) { return (a < b ? a = b, true : false); }
constexpr unsigned int mod                  = 1000000007;
template<typename T> constexpr T inf_v      = std::numeric_limits<T>::max() / 4;
template<typename Real> constexpr Real pi_v = Real{3.141592653589793238462643383279502884};

template<typename T>
T read()
{
    T v;
    return std::cin >> v, v;
}
template<typename T, typename... Args>
auto read(const usize size, Args... args)
{
    std::vector<decltype(read<T>(args...))> ans(size);
    for (usize i = 0; i < size; i++) { ans[i] = read<T>(args...); }
    return ans;
}
template<typename... Types>
auto reads() { return std::tuple<std::decay_t<Types>...>{read<Types>()...}; }
#    define SHOW(...) static_cast<void>(0)

template<typename T>
std::vector<T> make_v(const usize size, const T v) { return std::vector<T>(size, v); }
template<typename... Args>
auto make_v(const usize size, Args... args) { return std::vector<decltype(make_v(args...))>(size, make_v(args...)); }
int main()
{
    const int T = read<int>();
    for (int t = 0; t < T; t++) {
        const int n  = read<int>();
        const auto c = read<int>(n);
        std::vector<int> num(n, 0);
        for (const int e : c) { num[e - 1]++; }
        std::set<int> ns;
        int nmax = 0;
        for (int i = 0; i < n; i++) {
            if (num[i] > 0) {
                ns.insert(num[i]);
                chmax(nmax, num[i]);
            }
        }
        SHOW(ns);
        std::set<int> ss;
        for (int i = 1; i <= nmax; i++) { ss.insert(i); }
        for (const auto& n : ns) {
            std::set<int> cand;
            for (int s = 1; (s - 1) * (s - 1) <= n; s++) {
                if (ss.find(s) == ss.end()) { continue; }
                cand.insert(s);
            }
            for (int n0 = 1; n0 * n0 <= 2 * n; n0++) {
                for (int j = 0; j <= n0; j++) {
                    const int m = n + j;
                    if (m % n0 == 0) {
                        if (ss.find(m / n0) == ss.end()) { continue; }
                        cand.insert(m / n0);
                    }
                }
            }
            std::swap(ss, cand);
        }
        SHOW(ss);
        const int s = *ss.rbegin();
        SHOW(s);
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            if (num[i] == 0) { continue; }
            ans += (num[i] + s - 1) / s;
        }
        std::cout << ans << std::endl;
    }
    return 0;
}