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

template<typename InIt>
std::vector<int> manacher(const InIt first, const InIt last)
{
    const int sz = std::distance(first, last);
    std::vector<int> ans(sz);
    for (int i = 0, k = 1, j = 0; i < sz; i += k, j -= k, k = 1) {
        while (i >= j and i + j < sz and *std::next(first, i - j) == *std::next(first, i + j)) { ++j; }
        ans[i] = j;
        while (i >= k and i + k < sz and k + ans[i - k] < j) { ans[i + k] = ans[i - k], ++k; }
    }
    return ans;
}
int main()
{
    const auto [N, M] = in.tup<int, ll>();
    const auto as     = in.vec<ll>(N);
    std::vector<ll> bs;
    for (int i = 0; i + 1 < N; i++) {
        bs.push_back(-1LL);
        bs.push_back(as[i + 1] - as[i]);
    }
    bs.push_back(-1);
    const auto rs = manacher(bs.begin(), bs.end());
    SHOW(bs);
    SHOW(rs);
    std::vector<ll> ans;
    for (int i = 0; i <= N; i++) {  // 
        int S = 0, M_S = 0;
        if (i != 0) { S = as[0] + as[i - 1]; }
        if (i != N) { M_S = as[i] + as[N - 1]; }
        if (i != 0 and i != N and M_S != S + M) { continue; }
        if (i == 0) { S = M_S - M; }
        if (S >= M or S < 0) { continue; }
        if (i != 0 and as[i - 1] > S) { continue; }
        if (i != N and as[i] <= S) { continue; }
        SHOW(i, S);
        if (i != 0 and rs[i - 1] != i) { continue; }
        if (i != N and rs[N + i - 1] != N - i) { continue; }
        SHOW(i, S);
        ans.push_back(S);
    }
    out.ln(ans.size());
    out.ln(ans);
    return 0;
}