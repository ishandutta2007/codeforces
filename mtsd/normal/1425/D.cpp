#include <bits/stdc++.h>

using ll                            = long long;
using uint                          = unsigned int;
using ull                           = unsigned long long;
using ld                            = long double;
template<typename T> using max_heap = std::priority_queue<T>;
template<typename T> using min_heap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

template<typename T>
constexpr std::pair<T, T> extgcd(const T a, const T b)
{
    if (b == 0) { return std::pair<T, T>{1, 0}; }
    const auto g = std::gcd(a, b), da = std::abs(b) / g;
    const auto p = extgcd(b, a % b);
    const auto x = (da + p.second % da) % da, y = (g - a * x) / b;
    return {x, y};
}
template<typename T> constexpr T inverse(const T a, const T mod) { return extgcd(a, mod).first; }
template<uint mod_value, bool dynamic = false>
class modint_base
{
public:
    template<typename UInt = uint>
    static std::enable_if_t<dynamic, const UInt> mod() { return mod_ref(); }
    template<typename UInt = uint>
    static constexpr std::enable_if_t<not dynamic, const UInt> mod() { return mod_value; }
    template<typename UInt = uint>
    static void set_mod(const std::enable_if_t<dynamic, const UInt> mod) { mod_ref() = mod, inv_ref() = {1, 1}; }
    modint_base() : v{0} {}
    modint_base(const ll val) : v{norm(static_cast<uint>(val % static_cast<ll>(mod()) + static_cast<ll>(mod())))} {}
    modint_base(const modint_base& n) : v{n()} {}
    explicit operator bool() const { return v != 0; }
    explicit operator int() const { return v; }
    explicit operator uint() const { return v; }
    explicit operator ll() const { return v; }
    explicit operator ull() const { return v; }
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
    static modint_base fact(const int n)
    {
        auto& fact_ = fact_ref();
        if (n < (int)fact_.size()) { return fact_[n]; }
        for (int i = (int)fact_.size(); i <= n; i++) { fact_.push_back(fact_.back() * i); }
        return fact_.back();
    }
    static modint_base inv_fact(const int n)
    {
        auto& inv_fact_ = inv_fact_ref();
        if (n < (int)inv_fact_.size()) { return inv_fact_[n]; }
        for (int i = inv_fact_.size(); i <= n; i++) { inv_fact_.push_back(inv_fact_.back() * modint_base::small_inv(i)); }
        return inv_fact_.back();
    }
    static modint_base perm(const int n, const int k) { return k > n ? modint_base{0} : fact(n) * inv_fact(n - k); }
    static modint_base comb(const int n, const int k) { return k > n ? modint_base{0} : fact(n) * inv_fact(n - k) * inv_fact(k); }
    std::pair<ll, ll> quad() const
    {
        const auto ans = quad_r(v, mod());
        ll x = std::get<0>(ans), y = std::get<1>(ans);
        if (y < 0) { x = -x, y = -y; }
        return {x, y};
    }

private:
    static std::tuple<ll, ll, ll> quad_r(const ll r, const ll p)  // r = x/y (mod p), (x,y,z) s.t. x=yr+pz
    {
        if (std::abs(r) <= 1000) { return {r, 1, 0}; }
        ll nr = p % r, q = p / r;
        if (nr * 2LL >= r) { nr -= r, q++; }
        if (nr * 2LL <= -r) { nr += r, q--; }
        const auto sub = quad_r(nr, r);
        const ll x = std::get<0>(sub), z = std::get<1>(sub), y = std::get<2>(sub);
        return {x, y - q * z, z};
    }

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
    static modint_base small_inv(const int n)
    {
        auto& inv_ = inv_ref();
        if (n < (int)inv_.size()) { return inv_[n]; }
        for (int i = inv_.size(); i <= n; i++) { inv_.push_back(-inv_[modint_base::mod() % i] * (modint_base::mod() / i)); }
        return inv_.back();
    }
    static modint_base inv(const ll v) { return v <= 2000000 ? small_inv(static_cast<int>(v)) : modint_base{inverse(v, static_cast<ll>(mod()))}; }
    static std::vector<modint_base>& inv_ref()
    {
        static std::vector<modint_base> inv_{1, 1};
        return inv_;
    }
    static std::vector<modint_base>& fact_ref()
    {
        static std::vector<modint_base> fact_{1, 1};
        return fact_;
    }
    static std::vector<modint_base>& inv_fact_ref()
    {
        static std::vector<modint_base> inv_fact_{1, 1};
        return inv_fact_;
    }

    uint v;
};
template<uint mod>
using modint = modint_base<mod, false>;
template<uint id>
using dynamic_modint = modint_base<id, true>;
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
    constexpr uint mod   = 1000000007;
    using mint           = modint<mod>;
    const auto [N, M, R] = in.tup<int, int, int>();
    std::vector<int> xs(N), ys(N);
    std::vector<mint> bs(N);
    for (int i = 0; i < N; i++) { std::tie(ys[i], xs[i], bs[i]) = in.tup<int, int, mint>(); }
    constexpr int X = 1000;
    auto imos       = nd_array<int>({X + 1, X + 1}, 0);
    for (int i = 0; i < N; i++) { imos[ys[i]][xs[i]]++; }
    for (int y = 0; y <= X; y++) {
        for (int x = 1; x <= X; x++) { imos[y][x] += imos[y][x - 1]; }
    }
    for (int y = 1; y <= X; y++) {
        for (int x = 0; x <= X; x++) { imos[y][x] += imos[y - 1][x]; }
    }
    auto count = [&](int yl, int yu, int xl, int xu) {
        if (yl > yu or xl > xu) { return 0; }
        return imos[yu][xu] - imos[yu][xl - 1] - imos[yl - 1][xu] + imos[yl - 1][xl - 1];
    };
    mint ans = 0;
    for (int i = 0; i < N; i++) {
        const int yli = std::max(1, ys[i] - R);
        const int yui = std::min(X, ys[i] + R);
        const int xli = std::max(1, xs[i] - R);
        const int xui = std::min(X, xs[i] + R);
        for (int j = 0; j < N; j++) {
            const int ylj = std::max(1, ys[j] - R);
            const int yuj = std::min(X, ys[j] + R);
            const int xlj = std::max(1, xs[j] - R);
            const int xuj = std::min(X, xs[j] + R);

            const int yl = std::max(yli, ylj);
            const int yu = std::min(yui, yuj);
            const int xl = std::max(xli, xlj);
            const int xu = std::min(xui, xuj);
            SHOW(i, j, yl, yu, xl, xu);

            mint way      = mint::comb(N, M);
            const int ai  = count(yli, yui, xli, xui);
            const int aj  = count(ylj, yuj, xlj, xuj);
            const int aij = count(yl, yu, xl, xu);

            way -= mint::comb(N - ai, M);
            way -= mint::comb(N - aj, M);
            way += mint::comb(N - ai - aj + aij, M);
            SHOW(i, j, ai, aj, aij, way);
            ans += way * bs[i] * bs[j];
        }
    }
    out.ln(ans);
    return 0;
}