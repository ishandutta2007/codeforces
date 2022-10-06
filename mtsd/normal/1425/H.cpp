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
auto nd_array(int const (&szs)[n], const T x = T{}) { if constexpr (i == n) { return x; } else { return std::vector(szs[i], nd_array<T, n, i + 1>(szs, x)); } }
class printer
{
public:
    printer(std::ostream& os_ = std::cout) : m_os{os_} { m_os << std::fixed << std::setprecision(15); }
    template<typename... Args> int ln(const Args&... args) { return dump(args...), m_os << '\n', 0; }
    template<typename... Args> int el(const Args&... args) { return dump(args...), m_os << std::endl, 0; }
    template<typename... Args> int fmt(const std::string& s, const Args&... args) { return rec(s, 0, args...); }
private:
    template<typename T> int dump(const T& v) { return m_os << v, 0; }
    template<typename T> int dump(const std::vector<T>& vs) { for (int i = 0; i < (int)vs.size(); i++) { m_os << (i ? " " : ""), dump(vs[i]); } return 0; }
    template<typename T> int dump(const std::vector<std::vector<T>>& vss) { for (int i = 0; i < (int)vss.size(); i++) { m_os << (0 <= i or i + 1 < (int)vss.size() ? "\n" : ""), dump(vss[i]); } return 0; }
    template<typename T, typename... Args> int dump(const T& v, const Args&... args) { return dump(v), m_os << ' ', dump(args...), 0; }
    int rec(const std::string& s, int index) { return m_os << s.substr(index, s.size()), 0; }
    template<typename T, typename... Args> int rec(const std::string& s, int index, const T& v, const Args&... args) { return index == s.size() ? 0 : s[index] == '%' ? (tdump(v), rec(s, index + 1, args...)) : (m_os << s[index], rec(s, index + 1, v, args...)); }
    std::ostream& m_os;
};
printer out;
class scanner
{
public:
    scanner(std::istream& is_ = std::cin) : m_is{is_} { m_is.tie(nullptr), std::ios::sync_with_stdio(false); }
    template<typename T> T val() { T v; return m_is >> v, v; }
    template<typename T> T val(const T offset) { return val<T>() - offset; }
    template<typename T> std::vector<T> vec(const int n) { return make_v<T>(n, [this]() { return val<T>(); }); }
    template<typename T> std::vector<T> vec(const int n, const T offset) { return make_v<T>(n, [this, offset]() { return val<T>(offset); }); }
    template<typename T> std::vector<std::vector<T>> vvec(const int n0, const int n1) { return make_v<T>(n0, [this, n1]() { return vec<T>(n1); }); }
    template<typename T> std::vector<std::vector<T>> vvec(const int n0, const int n1, const T offset) { return make_v<T>(n0, [this, n1, offset]() { return vec<T>(n1, offset); }); }
    template<typename... Args> auto tup() { return std::tuple<std::decay_t<Args>...>{val<Args>()...}; }
    template<typename... Args> auto tup(const Args&... offsets) { return std::tuple<std::decay_t<Args>...>{val<Args>(offsets)...}; }
private:
    template<typename T, typename F>
    std::vector<T> make_v(const int n, F f)
    {
        std::vector<T> ans;
        for (int i = 0; i < n; i++) { ans.push_back(f()); }
        return ans;
    }
    std::istream& m_is;
};
scanner in;
#    define SHOW(...) static_cast<void>(0)
int main()
{
    const auto T = in.val<int>();
    for (int t = 0; t < T; t++) {
        const auto [A, B, C, D] = in.tup<ll, ll, ll, ll>();
        const bool posi         = (A + B) % 2 == 0;
        const int L = A + D, S = B + C;
        if (L == 0) {
            if (posi) {
                out.ln("Tidak", "Tidak", "Ya", "Tidak");
            } else {
                out.ln("Tidak", "Ya", "Tidak", "Tidak");
            }
        } else if (S == 0) {
            if (posi) {
                out.ln("Tidak", "Tidak", "Tidak", "Ya");
            } else {
                out.ln("Ya", "Tidak", "Tidak", "Tidak");
            }
        } else {
            if (posi) {
                out.ln("Tidak", "Tidak", "Ya", "Ya");
            } else {
                out.ln("Ya", "Ya", "Tidak", "Tidak");
            }
        }
    }
    return 0;
}