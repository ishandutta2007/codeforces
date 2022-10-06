#include <bits/stdc++.h>
#pragma region Header
using i32 = int;
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
using u128 = __uint128_t;
using f64 = double;
using f80 = long double;
using f128 = __float128;
constexpr i32 operator"" _i32(u64 v)
{
    return v;
}
constexpr i32 operator"" _u32(u64 v)
{
    return v;
}
constexpr i64 operator"" _i64(u64 v)
{
    return v;
}
constexpr u64 operator"" _u64(u64 v)
{
    return v;
}
constexpr f64 operator"" _f64(f80 v)
{
    return v;
}
constexpr f80 operator"" _f80(f80 v)
{
    return v;
}
using Istream = std::istream;
using Ostream = std::ostream;
using Str = std::string;
template<typename T>
using Lt = std::less<T>;
template<typename T>
using Gt = std::greater<T>;
template<typename T>
using IList = std::initializer_list<T>;
template<int n>
using BSet = std::bitset<n>;
template<typename T1, typename T2>
using Pair = std::pair<T1, T2>;
template<typename... Ts>
using Tup = std::tuple<Ts...>;
template<typename T, int N>
using Arr = std::array<T, N>;
template<typename... Ts>
using Deq = std::deque<Ts...>;
template<typename... Ts>
using Set = std::set<Ts...>;
template<typename... Ts>
using MSet = std::multiset<Ts...>;
template<typename... Ts>
using USet = std::unordered_set<Ts...>;
template<typename... Ts>
using UMSet = std::unordered_multiset<Ts...>;
template<typename... Ts>
using Map = std::map<Ts...>;
template<typename... Ts>
using MMap = std::multimap<Ts...>;
template<typename... Ts>
using UMap = std::unordered_map<Ts...>;
template<typename... Ts>
using UMMap = std::unordered_multimap<Ts...>;
template<typename... Ts>
using Vec = std::vector<Ts...>;
template<typename... Ts>
using Stack = std::stack<Ts...>;
template<typename... Ts>
using Queue = std::queue<Ts...>;
template<typename T>
using MaxHeap = std::priority_queue<T>;
template<typename T>
using MinHeap = std::priority_queue<T, Vec<T>, Gt<T>>;
using NSec = std::chrono::nanoseconds;
using USec = std::chrono::microseconds;
using MSec = std::chrono::milliseconds;
using Sec = std::chrono::seconds;
template<typename T>
constexpr T LIMMIN = std::numeric_limits<T>::min();
template<typename T>
constexpr T LIMMAX = std::numeric_limits<T>::max();
template<typename T>
constexpr T INF = (LIMMAX<T> - 1) / 2;
template<typename T>
constexpr T PI = T{3.141592653589793238462643383279502884};
template<typename T = u64>
constexpr T TEN(const int n)
{
    return n == 0 ? T{1} : TEN<T>(n - 1) * T{10};
}
Ostream& operator<<(Ostream& os, i128 v)
{
    bool minus = false;
    if (v < 0) { minus = true, v = -v; }
    Str ans;
    if (v == 0) { ans = "0"; }
    while (v) {
        ans.push_back('0' + v % 10), v /= 10;
    }
    std::reverse(ans.begin(), ans.end());
    return os << (minus ? "-" : "") << ans;
}
Ostream& operator<<(Ostream& os, u128 v)
{
    Str ans;
    if (v == 0) { ans = "0"; }
    while (v) {
        ans.push_back('0' + v % 10), v /= 10;
    }
    std::reverse(ans.begin(), ans.end());
    return os << ans;
}
template<typename T>
bool chmin(T& a, const T& b)
{
    if (a > b) {
        a = b;
        return true;
    } else {
        return false;
    }
}
template<typename T>
bool chmax(T& a, const T& b)
{
    if (a < b) {
        a = b;
        return true;
    } else {
        return false;
    }
}
template<typename T>
constexpr T floorDiv(T x, T y)
{
    if (y < T{}) { x = -x, y = -y; }
    return x >= T{} ? x / y : (x - y + 1) / y;
}
template<typename T>
constexpr T ceilDiv(T x, T y)
{
    if (y < T{}) { x = -x, y = -y; }
    return x >= T{} ? (x + y - 1) / y : x / y;
}
template<typename T, typename I>
constexpr T modPower(T v, I n, T mod)
{
    T ans = 1 % mod;
    for (; n > 0; n >>= 1, (v *= v) %= mod) {
        if (n % 2 == 1) { (ans *= v) %= mod; }
    }
    return ans;
}
template<typename T, typename I>
constexpr T power(T v, I n)
{
    T ans = 1;
    for (; n > 0; n >>= 1, v *= v) {
        if (n % 2 == 1) { ans *= v; }
    }
    return ans;
}
template<typename T, typename I>
constexpr T power(T v, I n, const T& e)
{
    T ans = e;
    for (; n > 0; n >>= 1, v *= v) {
        if (n % 2 == 1) { ans *= v; }
    }
    return ans;
}
template<typename T>
Vec<T> operator+=(Vec<T>& vs1, const Vec<T>& vs2)
{
    vs1.insert(vs1.end(), vs2.begin(), vs2.end());
    return vs1;
}
template<typename T>
Vec<T> operator+(const Vec<T>& vs1, const Vec<T>& vs2)
{
    auto vs = vs1;
    vs += vs2;
    return vs;
}
template<typename Vs, typename V>
void fillAll(Vs& arr, const V& v)
{
    if constexpr (std::is_convertible<V, Vs>::value) {
        arr = v;
    } else {
        for (auto& subarr : arr) {
            fillAll(subarr, v);
        }
    }
}
template<typename Vs>
void sortAll(Vs& vs)
{
    std::sort(std::begin(vs), std::end(vs));
}
template<typename Vs, typename C>
void sortAll(Vs& vs, C comp)
{
    std::sort(std::begin(vs), std::end(vs), comp);
}
template<typename Vs>
void reverseAll(Vs& vs)
{
    std::reverse(std::begin(vs), std::end(vs));
}
template<typename V, typename Vs>
V sumAll(const Vs& vs)
{
    if constexpr (std::is_convertible<Vs, V>::value) {
        return static_cast<V>(vs);
    } else {
        V ans = 0;
        for (const auto& v : vs) {
            ans += sumAll<V>(v);
        }
        return ans;
    }
}
template<typename Vs>
int minInd(const Vs& vs)
{
    return std::min_element(std::begin(vs), std::end(vs)) - std::begin(vs);
}
template<typename Vs>
int maxInd(const Vs& vs)
{
    return std::max_element(std::begin(vs), std::end(vs)) - std::begin(vs);
}
template<typename Vs, typename V>
int lbInd(const Vs& vs, const V& v)
{
    return std::lower_bound(std::begin(vs), std::end(vs), v) - std::begin(vs);
}
template<typename Vs, typename V>
int ubInd(const Vs& vs, const V& v)
{
    return std::upper_bound(std::begin(vs), std::end(vs), v) - std::begin(vs);
}
template<typename T, typename F>
Vec<T> genVec(int n, F gen)
{
    Vec<T> ans;
    std::generate_n(std::back_insert_iterator(ans), n, gen);
    return ans;
}
Vec<int> iotaVec(int n, int offset = 0)
{
    Vec<int> ans(n);
    std::iota(ans.begin(), ans.end(), offset);
    return ans;
}
constexpr int popcount(const u64 v)
{
    return v ? __builtin_popcountll(v) : 0;
}
constexpr int log2p1(const u64 v)
{
    return v ? 64 - __builtin_clzll(v) : 0;
}
constexpr int lsbp1(const u64 v)
{
    return __builtin_ffsll(v);
}
constexpr int clog(const u64 v)
{
    return v ? log2p1(v - 1) : 0;
}
constexpr u64 ceil2(const u64 v)
{
    const int l = clog(v);
    return (l == 64) ? 0_u64 : (1_u64 << l);
}
constexpr u64 floor2(const u64 v)
{
    return v ? (1_u64 << (log2p1(v) - 1)) : 0_u64;
}
constexpr bool ispow2(const u64 v)
{
    return (v > 0) and ((v & (v - 1)) == 0);
}
constexpr bool btest(const u64 mask, const int ind)
{
    return (mask >> ind) & 1_u64;
}
template<typename F>
struct Fix : F
{
    Fix(F&& f) : F{std::forward<F>(f)} {}
    template<typename... Args>
    auto operator()(Args&&... args) const
    {
        return F::operator()(*this, std::forward<Args>(args)...);
    }
};
class irange
{
private:
    struct itr
    {
        itr(i64 start = 0, i64 step = 1) : m_cnt{start}, m_step{step} {}
        bool operator!=(const itr& it) const
        {
            return m_cnt != it.m_cnt;
        }
        int operator*()
        {
            return m_cnt;
        }
        itr& operator++()
        {
            m_cnt += m_step;
            return *this;
        }
        i64 m_cnt, m_step;
    };
    i64 m_start, m_end, m_step;
public:
    irange(i64 start, i64 end, i64 step = 1)
    {
        assert(step != 0);
        const i64 d = std::abs(step);
        const i64 l = (step > 0 ? start : end);
        const i64 r = (step > 0 ? end : start);
        int n = (r - l) / d + ((r - l) % d ? 1 : 0);
        if (l >= r) { n = 0; }
        m_start = start;
        m_end = start + step * n;
        m_step = step;
    }
    itr begin() const
    {
        return itr{m_start, m_step};
    }
    itr end() const
    {
        return itr{m_end, m_step};
    }
};
irange rep(int end)
{
    return irange(0, end, 1);
}
irange per(int rend)
{
    return irange(rend - 1, -1, -1);
}
#pragma COMMENT("[REFS] Xoshiro: https://prng.di.unimi.it")
namespace xoshiro_impl {
u64 x;
u64 next()
{
    uint64_t z = (x += 0x9e3779b97f4a7c15);
    z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9;
    z = (z ^ (z >> 27)) * 0x94d049bb133111eb;
    return z ^ (z >> 31);
}
}
class Xoshiro32
{
public:
    using result_type = u32;
    using T = result_type;
    Xoshiro32(T seed = 0)
    {
        xoshiro_impl::x = seed;
        s[0] = xoshiro_impl::next();
        s[1] = xoshiro_impl::next();
        s[2] = xoshiro_impl::next();
        s[3] = xoshiro_impl::next();
    }
    static constexpr T min()
    {
        return LIMMIN<T>;
    }
    static constexpr T max()
    {
        return LIMMAX<T>;
    }
    T operator()()
    {
        return next();
    }
private:
    static constexpr T rotl(const T x, int k)
    {
        return (x << k) | (x >> (32 - k));
    }
    T next()
    {
        const T ans = rotl(s[1] * 5, 7) * 9;
        const T t = s[1] << 9;
        s[2] ^= s[0];
        s[3] ^= s[1];
        s[1] ^= s[2];
        s[0] ^= s[3];
        s[2] ^= t;
        s[3] = rotl(s[3], 11);
        return ans;
    }
    T s[4];
};
class Xoshiro64
{
public:
    using result_type = u64;
    using T = result_type;
    Xoshiro64(T seed = 0)
    {
        xoshiro_impl::x = seed;
        s[0] = xoshiro_impl::next();
        s[1] = xoshiro_impl::next();
        s[2] = xoshiro_impl::next();
        s[3] = xoshiro_impl::next();
    }
    static constexpr T min()
    {
        return LIMMIN<T>;
    }
    static constexpr T max()
    {
        return LIMMAX<T>;
    }
    T operator()()
    {
        return next();
    }
private:
    static constexpr T rotl(const T x, int k)
    {
        return (x << k) | (x >> (64 - k));
    }
    T next()
    {
        const T ans = rotl(s[1] * 5, 7) * 9;
        const T t = s[1] << 17;
        s[2] ^= s[0];
        s[3] ^= s[1];
        s[1] ^= s[2];
        s[0] ^= s[3];
        s[2] ^= t;
        s[3] = rotl(s[3], 45);
        return ans;
    }
    T s[4];
};
template<typename Rng>
class RNG
{
public:
    using result_type = typename Rng::result_type;
    using T = result_type;
    static constexpr T min()
    {
        return Rng::min();
    }
    static constexpr T max()
    {
        return Rng::max();
    }
    RNG() : RNG(std::random_device{}()) {}
    RNG(T seed) : m_rng(seed) {}
    T operator()()
    {
        return m_rng();
    }
    template<typename T>
    T val(T min, T max)
    {
        return std::uniform_int_distribution<T>(min, max)(m_rng);
    }
    template<typename T>
    Pair<T, T> pair(T min, T max)
    {
        return std::minmax({val<T>(min, max), val<T>(min, max)});
    }
    template<typename T>
    Vec<T> vec(int n, T min, T max)
    {
        return genVec<T>(n, [&]() { return val<T>(min, max); });
    }
    template<typename T>
    Vec<Vec<T>> vvec(int n, int m, T min, T max)
    {
        return genVec<Vec<T>>(n, [&]() { return vec(m, min, max); });
    }
private:
    Rng m_rng;
};
RNG<std::mt19937> rng;
RNG<std::mt19937_64> rng64;
RNG<Xoshiro32> rng_xo;
RNG<Xoshiro64> rng_xo64;
class Scanner
{
public:
    Scanner(Istream& is = std::cin) : m_is{is}
    {
        m_is.tie(nullptr)->sync_with_stdio(false);
    }
    template<typename T>
    T val()
    {
        T v;
        return m_is >> v, v;
    }
    template<typename T>
    T val(T offset)
    {
        return val<T>() - offset;
    }
    template<typename T>
    Vec<T> vec(int n)
    {
        return genVec<T>(n, [&]() { return val<T>(); });
    }
    template<typename T>
    Vec<T> vec(int n, T offset)
    {
        return genVec<T>(n, [&]() { return val<T>(offset); });
    }
    template<typename T>
    Vec<Vec<T>> vvec(int n, int m)
    {
        return genVec<Vec<T>>(n, [&]() { return vec<T>(m); });
    }
    template<typename T>
    Vec<Vec<T>> vvec(int n, int m, const T offset)
    {
        return genVec<Vec<T>>(n, [&]() { return vec<T>(m, offset); });
    }
    template<typename... Args>
    auto tup()
    {
        return Tup<Args...>{val<Args>()...};
    }
    template<typename... Args>
    auto tup(const Args&... offsets)
    {
        return Tup<Args...>{val<Args>(offsets)...};
    }
private:
    Istream& m_is;
};
Scanner in;
class Printer
{
public:
    Printer(Ostream& os = std::cout) : m_os{os}
    {
        m_os << std::fixed << std::setprecision(15);
    }
    template<typename... Args>
    int operator()(const Args&... args)
    {
        dump(args...);
        return 0;
    }
    template<typename... Args>
    int ln(const Args&... args)
    {
        dump(args...), m_os << '\n';
        return 0;
    }
    template<typename... Args>
    int el(const Args&... args)
    {
        dump(args...), m_os << std::endl;
        return 0;
    }
private:
    template<typename T>
    void dump(const T& v)
    {
        m_os << v;
    }
    template<typename T>
    void dump(const Vec<T>& vs)
    {
        for (const int i : rep(vs.size())) {
            m_os << (i ? " " : ""), dump(vs[i]);
        }
    }
    template<typename T>
    void dump(const Vec<Vec<T>>& vss)
    {
        for (const int i : rep(vss.size())) {
            m_os << (i ? "\n" : ""), dump(vss[i]);
        }
    }
    template<typename T, typename... Ts>
    int dump(const T& v, const Ts&... args)
    {
        dump(v), m_os << ' ', dump(args...);
        return 0;
    }
    Ostream& m_os;
};
Printer out;
template<typename T, int n, int i = 0>
auto ndVec(int const (&szs)[n], const T x = T{})
{
    if constexpr (i == n) {
        return x;
    } else {
        return std::vector(szs[i], ndVec<T, n, i + 1>(szs, x));
    }
}
template<typename T, typename F>
T binSearch(T ng, T ok, F check)
{
    while (std::abs(ok - ng) > 1) {
        const T mid = (ok + ng) / 2;
        (check(mid) ? ok : ng) = mid;
    }
    return ok;
}
template<u32 mod_, u32 root_, u32 max2p_>
class modint
{
    template<typename U = u32&>
    static U modRef()
    {
        static u32 s_mod = 0;
        return s_mod;
    }
    template<typename U = u32&>
    static U rootRef()
    {
        static u32 s_root = 0;
        return s_root;
    }
    template<typename U = u32&>
    static U max2pRef()
    {
        static u32 s_max2p = 0;
        return s_max2p;
    }
public:
    template<typename U = const u32>
    static constexpr std::enable_if_t<mod_ != 0, U> mod()
    {
        return mod_;
    }
    template<typename U = const u32>
    static std::enable_if_t<mod_ == 0, U> mod()
    {
        return modRef();
    }
    template<typename U = const u32>
    static constexpr std::enable_if_t<mod_ != 0, U> root()
    {
        return root_;
    }
    template<typename U = const u32>
    static std::enable_if_t<mod_ == 0, U> root()
    {
        return rootRef();
    }
    template<typename U = const u32>
    static constexpr std::enable_if_t<mod_ != 0, U> max2p()
    {
        return max2p_;
    }
    template<typename U = const u32>
    static std::enable_if_t<mod_ == 0, U> max2p()
    {
        return max2pRef();
    }
    template<typename U = u32>
    static void setMod(std::enable_if_t<mod_ == 0, U> m)
    {
        modRef() = m;
    }
    template<typename U = u32>
    static void setRoot(std::enable_if_t<mod_ == 0, U> r)
    {
        rootRef() = r;
    }
    template<typename U = u32>
    static void setMax2p(std::enable_if_t<mod_ == 0, U> m)
    {
        max2pRef() = m;
    }
    constexpr modint() : m_val{0} {}
    constexpr modint(i64 v) : m_val{normll(v)} {}
    constexpr void setRaw(u32 v)
    {
        m_val = v;
    }
    constexpr modint operator-() const
    {
        return modint{0} - (*this);
    }
    constexpr modint& operator+=(const modint& m)
    {
        m_val = norm(m_val + m.val());
        return *this;
    }
    constexpr modint& operator-=(const modint& m)
    {
        m_val = norm(m_val + mod() - m.val());
        return *this;
    }
    constexpr modint& operator*=(const modint& m)
    {
        m_val = normll((i64)m_val * (i64)m.val() % (i64)mod());
        return *this;
    }
    constexpr modint& operator/=(const modint& m)
    {
        return *this *= m.inv();
    }
    constexpr modint operator+(const modint& m) const
    {
        auto v = *this;
        return v += m;
    }
    constexpr modint operator-(const modint& m) const
    {
        auto v = *this;
        return v -= m;
    }
    constexpr modint operator*(const modint& m) const
    {
        auto v = *this;
        return v *= m;
    }
    constexpr modint operator/(const modint& m) const
    {
        auto v = *this;
        return v /= m;
    }
    constexpr bool operator==(const modint& m) const
    {
        return m_val == m.val();
    }
    constexpr bool operator!=(const modint& m) const
    {
        return not(*this == m);
    }
    friend Istream& operator>>(Istream& is, modint& m)
    {
        i64 v;
        return is >> v, m = v, is;
    }
    friend Ostream& operator<<(Ostream& os, const modint& m)
    {
        return os << m.val();
    }
    constexpr u32 val() const
    {
        return m_val;
    }
    template<typename I>
    constexpr modint pow(I n) const
    {
        return power(*this, n);
    }
    constexpr modint inv() const
    {
        return pow(mod() - 2);
    }
    static modint sinv(u32 n)
    {
        static Vec<modint> is{1, 1};
        for (u32 i = (u32)is.size(); i <= n; i++) {
            is.push_back(-is[mod() % i] * (mod() / i));
        }
        return is[n];
    }
    static modint fact(u32 n)
    {
        static Vec<modint> fs{1, 1};
        for (u32 i = (u32)fs.size(); i <= n; i++) {
            fs.push_back(fs.back() * i);
        }
        return fs[n];
    }
    static modint ifact(u32 n)
    {
        static Vec<modint> ifs{1, 1};
        for (u32 i = (u32)ifs.size(); i <= n; i++) {
            ifs.push_back(ifs.back() * sinv(i));
        }
        return ifs[n];
    }
    static modint comb(int n, int k)
    {
        return k > n or k < 0 ? modint{0} : fact(n) * ifact(n - k) * ifact(k);
    }
private:
    static constexpr u32 norm(u32 x)
    {
        return x < mod() ? x : x - mod();
    }
    static constexpr u32 normll(i64 x)
    {
        return norm(u32(x % (i64)mod() + (i64)mod()));
    }
    u32 m_val;
};
using modint_1000000007 = modint<1000000007, 5, 1>;
using modint_998244353 = modint<998244353, 3, 23>;
template<int id>
using modint_dynamic = modint<0, 0, id>;
template<typename T = int>
class Graph
{
    struct Edge
    {
        Edge() = default;
        Edge(int i, int t, T c) : id{i}, to{t}, cost{c} {}
        int id;
        int to;
        T cost;
        operator int() const
        {
            return to;
        }
    };
public:
    Graph(int n) : m_v{n}, m_edges(n) {}
    void addEdge(int u, int v, bool bi = false)
    {
        assert(0 <= u and u < m_v);
        assert(0 <= v and v < m_v);
        m_edges[u].emplace_back(m_e, v, 1);
        if (bi) { m_edges[v].emplace_back(m_e, u, 1); }
        m_e++;
    }
    void addEdge(int u, int v, const T& c, bool bi = false)
    {
        assert(0 <= u and u < m_v);
        assert(0 <= v and v < m_v);
        m_edges[u].emplace_back(m_e, v, c);
        if (bi) { m_edges[v].emplace_back(m_e, u, c); }
        m_e++;
    }
    const Vec<Edge>& operator[](const int u) const
    {
        assert(0 <= u and u < m_v);
        return m_edges[u];
    }
    Vec<Edge>& operator[](const int u)
    {
        assert(0 <= u and u < m_v);
        return m_edges[u];
    }
    int v() const
    {
        return m_v;
    }
    int e() const
    {
        return m_e;
    }
    friend Ostream& operator<<(Ostream& os, const Graph& g)
    {
        for (int u : rep(g.v())) {
            for (const auto& [id, v, c] : g[u]) {
                os << "[" << id << "]: ";
                os << u << "->" << v << "(" << c << ")\n";
            }
        }
        return os;
    }
    Vec<T> sizes(int root = 0) const
    {
        const int N = v();
        assert(0 <= root and root < N);
        Vec<T> ss(N, 1);
        Fix([&](auto dfs, int u, int p) -> void {
            for (const auto& [id, v, c] : m_edges[u]) {
                static_cast<void>(id);
                if (v == p) { continue; }
                dfs(v, u);
                ss[u] += ss[v];
            }
        })(root, -1);
        return ss;
    }
    Vec<T> depths(int root = 0) const
    {
        const int N = v();
        assert(0 <= root and root < N);
        Vec<T> ds(N, 0);
        Fix([&](auto dfs, int u, int p) -> void {
            for (const auto& [id, v, c] : m_edges[u]) {
                static_cast<void>(id);
                if (v == p) { continue; }
                ds[v] = ds[u] + c;
                dfs(v, u);
            }
        })(root, -1);
        return ds;
    }
    Vec<int> parents(int root = 0) const
    {
        const int N = v();
        assert(0 <= root and root < N);
        Vec<int> ps(N, -1);
        Fix([&](auto dfs, int u, int p) -> void {
            for (const auto& [id, v, c] : m_edges[u]) {
                static_cast<void>(id);
                if (v == p) { continue; }
                ps[v] = u;
                dfs(v, u);
            }
        })(root, -1);
        return ps;
    }
private:
    int m_v;
    int m_e = 0;
    Vec<Vec<Edge>> m_edges;
};
class ndRep
{
private:
    struct itr
    {
        itr(const Vec<int>& ns) : m_ns{ns}, m_cs(ns.size(), 0), m_end{false} {}
        bool operator!=(const itr&) const
        {
            return not m_end;
        }
        const Vec<int>& operator*()
        {
            return m_cs;
        }
        itr& operator++()
        {
            for (const int i : per(m_ns.size())) {
                m_cs[i]++;
                if (m_cs[i] < m_ns[i]) {
                    break;
                } else {
                    if (i == 0) { m_end = true; }
                    m_cs[i] = 0;
                }
            }
            return *this;
        }
        Vec<int> m_ns, m_cs;
        bool m_end;
    };
    Vec<int> m_ns;
public:
    ndRep(const Vec<int>& ns) : m_ns{ns} {}
    itr begin() const
    {
        return itr{m_ns};
    }
    itr end() const
    {
        return itr{m_ns};
    }
};
#pragma endregion
int main()
{
    const auto N = in.val<int>();
    const auto Bs = in.vec<i64>(N);
    Map<i64, int> mp;
    for (i64 B : Bs) {
        mp[B]++;
    }
    Vec<i64> Es, Os;
    for (i64 B : Bs) {
        if (B % 2 == 0) {
            Es.push_back(B);
        } else {
            Os.push_back(B);
        }
    }
    const int K = mp.size();
    auto makeAns = [&](Vec<i64>& ans) {
        sortAll(ans);
        ans.erase(std::unique(ans.begin(), ans.end()), ans.end());
        while (ans.size() < N) {
            ans.push_back(0);
        }
    };
    if (K != N) {
        auto ans = Bs;
        ans.push_back(0);
        makeAns(ans);
        out.ln("YES");
        out.ln(ans);
        return 0;
    }
    if (N == 2) {
        return out.ln("NO");
    } else if (N == 3) {
        const i64 x2 = Bs[0] - Bs[1] + Bs[2];
        if (x2 % 2 == 1) {
            return out.ln("NO");
        } else {
            const i64 x = x2 / 2;
            Vec<i64> ans{x, Bs[0] - x, Bs[2] - x};
            makeAns(ans);
            out.ln("YES");
            out.ln(ans);
        }
    } else {
        if (Es.size() >= 3) {
            const i64 x = (Es[0] - Es[1] + Es[2]) / 2;
            Vec<i64> ans{x, Es[0] - x, Es[2] - x};
            for (i64 B : Bs) {
                if (B != Es[1]) { ans.push_back(B - x); }
            }
            makeAns(ans);
            out.ln("YES");
            out.ln(ans);
        } else if (Es.size() >= 1) {
            const i64 x = (Os[0] - Es[0] + Os[1]) / 2;
            Vec<i64> ans{x, Os[0] - x, Os[1] - x};
            for (i64 B : Bs) {
                if (B != Es[0]) { ans.push_back(B - x); }
            }
            makeAns(ans);
            out.ln("YES");
            out.ln(ans);
        } else {
            if (N >= 27) {
                constexpr int MAXB = 1000000;
                constexpr int L = 13;
                Vec<int> is_(L, 0);
                Map<int, Vec<int>> dp;
                Fix([&](auto dfs, int i) -> void {
                    if (i == L) {
                        i64 S = 0;
                        for (int i : is_) {
                            S += Bs[i];
                        }
                        if (dp.count(S) == 0) {
                            dp[S] = is_;
                        } else {
                            Vec<int> is, pis;
                            for (int i : is_) {
                                const int j = lbInd(dp[S], i);
                                if (j == L or dp[S][j] != i) {
                                    is.push_back(i);
                                }
                            }
                            for (int pi : dp[S]) {
                                const int j = lbInd(is_, pi);
                                if (j == L or is_[j] != pi) {
                                    pis.push_back(pi);
                                }
                            }
                            assert(is.size() == pis.size());
                            const int L = is.size();
                            if (L == 0) { return; }
                            Vec<i64> As;
                            for (int i : rep(L)) {
                                As.push_back(Bs[is[i]]);
                                As.push_back(Bs[pis[i]]);
                            }
                            Vec<i64> ans{0};
                            for (int i : rep(2 * L - 1)) {
                                ans.push_back(As[i] - ans.back());
                            }
                            for (i64 B : Bs) {
                                bool ok = true;
                                for (i64 A : As) {
                                    if (A == B) { ok = false; }
                                }
                                if (ok) { ans.push_back(B); }
                            }
                            makeAns(ans);
                            out.ln("YES");
                            out.ln(ans);
                            exit(0);
                        }
                    } else {
                        int min = (i == 0 ? 0 : is_[i - 1] + 1);
                        for (is_[i] = min; is_[i] < N; is_[i]++) {
                            dfs(i + 1);
                        }
                    }
                })(0);
                return out.ln("NO");
            } else {
                const int N1 = N / 2;
                const int N2 = N - N1;
                auto dp = ndVec<Vec<Pair<i64, Vec<int>>>>({N1 * 2 + 1});
                for (auto cs : ndRep(Vec<int>(N1, 3))) {
                    for (auto& c : cs) {
                        c--;
                    }
                    i64 S = 0;
                    int p = 0;
                    for (int i : rep(N1)) {
                        p += cs[i];
                        S += Bs[i] * (i64)cs[i];
                    }
                    dp[p + N1].push_back({S, cs});
                }
                for (int i : rep(N1 * 2 + 1)) {
                    sortAll(dp[i]);
                }
                for (auto cs : ndRep(Vec<int>(N2, 3))) {
                    for (auto& c : cs) {
                        c--;
                    }
                    i64 S = 0;
                    int p = 0;
                    for (int i : rep(N2)) {
                        p += cs[i];
                        S += Bs[i + N1] * (i64)cs[i];
                    }
                    const int np = N1 + (-p);
                    if (np < 0 or dp.size() <= np) { continue; }
                    const int ni
                        = lbInd(dp[np], Pair<i64, Vec<int>>{-S, Vec<int>{}});
                    if (ni < dp[np].size() and dp[np][ni].first == -S) {
                        const auto& ncs = dp[np][ni].second;
                        Vec<int> is, pis;
                        for (int i : rep(N1)) {
                            if (ncs[i] == -1) {
                                is.push_back(i);
                            } else if (ncs[i] == 1) {
                                pis.push_back(i);
                            }
                        }
                        for (int i : rep(N2)) {
                            if (cs[i] == -1) {
                                is.push_back(i + N1);
                            } else if (cs[i] == 1) {
                                pis.push_back(i + N1);
                            }
                        }
                        assert(is.size() == pis.size());
                        const int L = is.size();
                        if (L == 0) { continue; }
                        Vec<i64> As;
                        for (int i : rep(L)) {
                            As.push_back(Bs[is[i]]);
                            As.push_back(Bs[pis[i]]);
                        }
                        Vec<i64> ans{0};
                        for (int i : rep(2 * L - 1)) {
                            ans.push_back(As[i] - ans.back());
                        }
                        for (i64 B : Bs) {
                            bool ok = true;
                            for (i64 A : As) {
                                if (A == B) { ok = false; }
                            }
                            if (ok) { ans.push_back(B); }
                        }
                        makeAns(ans);
                        out.ln("YES");
                        return out.ln(ans);
                    }
                }
                return out.ln("NO");
            }
        }
    }
    return 0;
}