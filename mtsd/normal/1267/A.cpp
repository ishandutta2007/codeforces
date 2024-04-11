#include <bits/stdc++.h>
// created [2019/12/01] 16:05:17
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

template<typename OpMonoid>
class dualseg
{
public:
    using operator_monoid_type = OpMonoid;
    using operator_type        = typename operator_monoid_type::operator_type;
    dualseg(const usize sz, const operator_type& initial = operator_monoid_type::id()) : sz{sz}, depth{clog(sz)}, half{static_cast<usize>(1) << depth}, op(half << 1, operator_monoid_type::id())
    {
        if (initial != operator_monoid_type::id()) { std::fill(op.begin() + half, op.end(), initial); }
    }
    template<typename InIt>
    dualseg(const InIt first, const InIt last) : sz{static_cast<usize>(std::distance(first, last))}, depth{clog(sz)}, half{static_cast<usize>(1) << depth}, op(half << 1, operator_monoid_type::id()) { std::copy(first, last, op.begin() + half); }
    operator_type get(const usize a) const
    {
        assert(a < sz);
        operator_type ans = operator_monoid_type::id();
        for (usize i = 0; i <= depth; i++) { ans = operator_monoid_type::compose(ans, op[(a + half) >> (depth - i)]); }
        return ans;
    }
    void set(usize a, const operator_type& f)
    {
        assert(a < sz);
        clean(a += half), clean(a + 1), op[a] = f;
    }
    void act(usize L, usize R, const operator_type& f)
    {
        assert(L < R), assert(R <= sz);
        clean(L += half), clean(R += half);
        for (; L < R; L >>= 1, R >>= 1) {
            if (L & 1) { update(L++, f); }
            if (R & 1) { update(--R, f); }
        }
    }
    usize size() const { return sz; }
    friend std::ostream& operator<<(std::ostream& os, const dualseg& seg)
    {
        os << "[";
        for (usize i = 0; i < seg.sz; i++) { os << seg.get(i) << (i + 1 == seg.sz ? "" : ","); }
        return (os << "]\n");
    }

private:
    void down(const usize a) { update(a << 1, op[a]), update(a << 1 | 1, op[a]), op[a] = operator_monoid_type::id(); }
    void clean(const usize a)
    {
        const usize b = (a / (a & -a)) >> 1;
        for (usize i = 0; i < depth; i++) {
            const usize v = a >> (depth - i);
            if (v > b) { break; }
            down(v);
        }
    }
    void update(const usize a, const operator_type& f) { op[a] = operator_monoid_type::compose(f, op[a]); }
    const usize sz, depth, half;
    std::vector<operator_type> op;
};
template<typename Element>
struct assign
{
    using element_type  = Element;
    using operator_type = element_type;
    static operator_type compose(const operator_type& f1, const operator_type& f2) { return f1 != id() ? f1 : f2; }
    assign() = delete;
    static constexpr operator_type id() { return inf_v<operator_type>; }
};
int main()
{
    const int n = read<int>();
    std::vector<ll> a(n), b(n), t(n);
    std::vector<ll> a_t(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i] >> b[i] >> t[i];
        a_t[i] = a[i] + t[i];
    }

    std::vector<ll> unzip;
    for (int i = 0; i < n; i++) {
        for (ll j = -1; j <= 1; j++) { unzip.push_back(a[i] + j); }
        for (ll j = -1; j <= 1; j++) { unzip.push_back(b[i] + j); }
        for (ll j = -1; j <= 1; j++) { unzip.push_back(b[i] - t[i] + j); }
    }
    std::sort(unzip.begin(), unzip.end());
    unzip.erase(std::unique(unzip.begin(), unzip.end()), unzip.end());
    std::map<ll, int> zip;
    const int s = unzip.size();
    for (int i = 0; i < s; i++) { zip[unzip[i]] = i; }

    std::vector<int> a_t_is(n);
    std::iota(a_t_is.begin(), a_t_is.end(), 0);
    std::sort(a_t_is.begin(), a_t_is.end(), [&](const int i, const int j) { return a_t[i] < a_t[j]; });

    std::vector<int> is(n);
    std::iota(is.begin(), is.end(), 0);
    std::sort(is.begin(), is.end(), [&](const int i, const int j) { return t[i] > t[j]; });
    SHOW(s);

    dualseg<assign<int>> seg(s);
    seg.act(0, s, -1);
    for (const int i : is) {
        const int az = zip[a[i]];
        const int bz = zip[b[i] - t[i] + 1];
        seg.act(az, bz, i);
    }
    SHOW(seg);
    int pi     = -1;
    ll pl      = -1LL;
    using pll  = std::pair<ll, ll>;
    using info = std::pair<pll, int>;
    std::vector<info> ints;
    for (int x = 0; x < s; x++) {
        const int i = seg.get(x);
        if (pi != i) {
            const ll r = unzip[x];
            if (pi != -1) {
                ints.push_back({{pl, r - 1}, pi});
            }
            pi = i;
            pl = r;
        }
    }
    SHOW(ints);

    int a_t_i = 0;
    int ii    = 0;
    ll pos    = 0;
    ll ans    = 0;
    for (; ii < ints.size();) {
        for (; ii < ints.size() and ints[ii].first.second < pos; ii++) {}
        if (ii == ints.size()) { break; }
        chmax(pos, ints[ii].first.first);
        const ll r   = ints[ii].first.second;
        const int id = ints[ii].second;
        const ll tim = t[id];
        const ll use = (r - pos) / tim;
        ans += use;
        pos += use * tim;
        const ll np = pos + tim;
        for (; a_t_i < n and a[a_t_is[a_t_i]] <= pos; a_t_i++) {}
        if (a_t_i == n) {
            ans++, pos = np;
        } else {
            const ll at = a_t[a_t_is[a_t_i]];
            if (at < np) {
                ans++;
                pos = at;
            } else {
                ans++;
                pos = np;
            }
        }
        SHOW(use, tim);
    }

    std::cout << ans << std::endl;

    return 0;
}