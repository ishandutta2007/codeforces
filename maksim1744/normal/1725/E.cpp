/*
    author:  Maksim1744
    created: 04.09.2022 18:29:59
*/

#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;

#define mp   make_pair
#define pb   push_back
#define eb   emplace_back

#define sum(a)     ( accumulate ((a).begin(), (a).end(), 0ll))
#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

template<typename T>             vector<T>& operator--            (vector<T> &v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T> &v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>  v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U> &p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>  p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define SHOW_COLORS
#include "/mnt/c/Libs/tools/print.cpp"
#else
#define show(...) void(0)
#define debugf(fun)   fun
#define debugv(var)   var
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#define OSTREAM(...)    ;
#define OSTREAM0(...)   ;
#endif

struct Sieve {
    struct PrimeIterator {
        int prime;
        int count;
        int num;
        const Sieve& sieve;

        PrimeIterator(int num, const Sieve& sieve) : num(num), sieve(sieve) {
            step();
        }

        void step() {
            prime = sieve.mn[num];
            count = 0;
            while (num != 1 && sieve.mn[num] == prime) {
                num /= sieve.mn[num];
                ++count;
            }
        }

        bool operator == (const PrimeIterator& other) const {
            return tie(prime, count, num) == tie(other.prime, other.count, other.num);
        }
        bool operator != (const PrimeIterator& other) const {
            return !(*this == other);
        }

        PrimeIterator& operator ++ () {
            step();
            return *this;
        }

        pair<int, int> operator * () const {
            return {prime, count};
        }
    };

    struct PrimeIteratorContainer {
        int num;
        const Sieve& sieve;
        using iterator = PrimeIterator;

        PrimeIteratorContainer(int num, const Sieve& sieve) : num(num), sieve(sieve) {}

        PrimeIterator begin() const {
            return PrimeIterator(num, sieve);
        }

        PrimeIterator end() const {
            return PrimeIterator(1, sieve);
        }

        vector<pair<int, int>> collect() const {
            vector<pair<int, int>> result;
            for (auto p : *this)
                result.push_back(p);
            return result;
        }
    };

    template<typename U, typename V>
    struct DoubleIterator {
        U u;
        V v;
        U::iterator uit;
        V::iterator vit;
        int prime;
        int count;

        DoubleIterator(const U& u, const V& v, U::iterator uit, V::iterator vit) : u(u), v(v), uit(uit), vit(vit) {
            tie(prime, count) = this->operator*();
        }

        DoubleIterator& operator ++ () {
            if (uit == u.end()) {
                ++vit;
            } else if (vit == v.end()) {
                ++uit;
            } else if ((*uit).first < (*vit).first) {
                ++uit;
            } else if ((*uit).first > (*vit).first) {
                ++vit;
            } else {
                ++uit;
                ++vit;
            }
            return *this;
        }

        bool operator == (const DoubleIterator& other) const {
            return tie(uit, vit) == tie(other.uit, other.vit);
        }
        bool operator != (const DoubleIterator& other) const {
            return !(*this == other);
        }

        pair<int, int> operator * () const {
            if (uit == u.end()) return *vit;
            if (vit == v.end()) return *uit;
            if ((*uit).first < (*vit).first) return *uit;
            if ((*uit).first > (*vit).first) return *vit;
            return {(*uit).first, (*uit).second + (*vit).second};
        }
    };

    template<typename U, typename V>
    struct DoubleIteratorContainer {
        using iterator = DoubleIterator<U, V>;
        U u;
        V v;

        DoubleIteratorContainer(const U& u, const V& v) : u(u), v(v) {}

        iterator begin() const {
            return iterator(u, v, u.begin(), v.begin());
        }

        iterator end() const {
            return iterator(u, v, u.end(), v.end());
        }

        vector<pair<int, int>> collect() const {
            vector<pair<int, int>> result;
            for (auto p : *this)
                result.push_back(p);
            return result;
        }
    };

    vector<bool> isp;
    vector<int> primes;
    vector<int> mn;

    Sieve(int n, bool gen_primes = false, bool gen_mn = false) {
        isp.assign(n + 1, true); isp[0] = isp[1] = false;
        for (int i = 2; i * i <= n; ++i)
            if (isp[i])
                for (int j = i * i; j <= n; j += i)
                    isp[j] = false;

        if (gen_primes)
            for (int i = 2; i <= n; ++i)
                if (isp[i])
                    primes.push_back(i);

        if (gen_mn) {
            mn.assign(n + 1, -1);
            for (int i = 2; i <= n; ++i) {
                if (isp[i]) {
                    mn[i] = i;
                    if ((ll)i * i <= n)
                        for (int j = i * i; j <= n; j += i)
                            if (mn[j] == -1)
                                mn[j] = i;
                }
            }
        }
    }

    bool is_prime(int k) const {
        return isp[k];
    }

    bool operator[](int k) const {
        return isp[k];
    }

    // can be used as vector<pair<int, int>>, as in function phi() below
    // except doesn't create a vector to avoid heap allocations
    // can be transformed into vector<pair<int, int>> with .collect()
    auto get_prime_divs(int p) const {
        return PrimeIteratorContainer(p, *this);
    }

    // if you want to get prime divs for n = a * b * c where max(a, b, c) < size(sieve), then call get_prime_divs(a, b, c)
    template<typename... Args>
    auto get_prime_divs(int p, Args... args) const {
        return DoubleIteratorContainer(PrimeIteratorContainer(p, *this), get_prime_divs(args...));
    }

    int phi(int n) const {
        auto v = get_prime_divs(n);
        for (auto [p, c] : v)
            n = n / p * (p - 1);
        return n;
    }
};

vector<int> lca_ind;
vector<vector<int>> lca_sparse;
vector<int> lca_p2;
vector<int> lca_depth;
void build_lca_sparse(vector<vector<int>>& g, int root = 0) {
    int n = g.size();
    vector<int> euler;
    lca_ind.resize(n);
    lca_depth.assign(n, -1);
    function<void(int, int)> dfs = [&](int v, int depth) {
        lca_ind[v] = euler.size();
        euler.pb(v);
        lca_depth[v] = depth;
        for (auto k : g[v]) {
            if (lca_depth[k] == -1) {
                dfs(k, depth + 1);
                euler.pb(v);
            }
        }
    };
    dfs(root, 0);
    int m = euler.size();
    int log = 1;
    while ((1 << log) < m)
        ++log;
    lca_sparse.resize(log);
    lca_sparse[0].resize(m);
    lca_p2.resize(m + 1);
    int pp2 = 0;
    for (int i = 1; i < lca_p2.size(); ++i) {
        if (1 << (pp2 + 1) <= i)
            ++pp2;
        lca_p2[i] = pp2;
    }
    lca_p2[0] = 0;
    for (int i = 0; i < m; ++i)
        lca_sparse[0][i] = euler[i];
    for (int i = 1; i < log; ++i) {
        lca_sparse[i].assign(m, 0);
        for (int j = 0; j < m - (1 << (i - 1)); ++j) {
            int v1 = lca_sparse[i - 1][j], v2 = lca_sparse[i - 1][j + (1 << (i - 1))];
            if (lca_depth[v1] < lca_depth[v2])
                lca_sparse[i][j] = v1;
            else
                lca_sparse[i][j] = v2;
        }
    }
}

int get_lca(int u, int v) {
    if (u == v)
        return u;
    u = lca_ind[u];
    v = lca_ind[v];
    if (u > v)
        swap(u, v);
    int v1 = lca_sparse[lca_p2[v - u + 1]][u], v2 = lca_sparse[lca_p2[v - u + 1]][v - (1 << lca_p2[v - u + 1]) + 1];
    if (lca_depth[v1] < lca_depth[v2])
        return v1;
    else
        return v2;
}

int dist(int u, int v) {
    return lca_depth[u] + lca_depth[v] - 2 * lca_depth[get_lca(u, v)];
}

template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};
template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
// auto gcd = std::y_combinator([](auto gcd, int a, int b) -> int {
//     return b == 0 ? a : gcd(b, a % b);
// });

namespace mint_ns {
template<auto P>
struct Modular {
    using value_type = decltype(P);
    value_type value;

    Modular(long long k = 0) : value(norm(k)) {}

    friend Modular<P>& operator += (      Modular<P>& n, const Modular<P>& m) { n.value += m.value; if (n.value >= P) n.value -= P; return n; }
    friend Modular<P>  operator +  (const Modular<P>& n, const Modular<P>& m) { Modular<P> r = n; return r += m; }

    friend Modular<P>& operator -= (      Modular<P>& n, const Modular<P>& m) { n.value -= m.value; if (n.value < 0)  n.value += P; return n; }
    friend Modular<P>  operator -  (const Modular<P>& n, const Modular<P>& m) { Modular<P> r = n; return r -= m; }
    friend Modular<P>  operator -  (const Modular<P>& n)                      { return Modular<P>(-n.value); }

    friend Modular<P>& operator *= (      Modular<P>& n, const Modular<P>& m) { n.value = n.value * 1ll * m.value % P; return n; }
    friend Modular<P>  operator *  (const Modular<P>& n, const Modular<P>& m) { Modular<P> r = n; return r *= m; }

    friend Modular<P>& operator /= (      Modular<P>& n, const Modular<P>& m) { return n *= m.inv(); }
    friend Modular<P>  operator /  (const Modular<P>& n, const Modular<P>& m) { Modular<P> r = n; return r /= m; }

    Modular<P>& operator ++ (   ) { return *this += 1; }
    Modular<P>& operator -- (   ) { return *this -= 1; }
    Modular<P>  operator ++ (int) { Modular<P> r = *this; *this += 1; return r; }
    Modular<P>  operator -- (int) { Modular<P> r = *this; *this -= 1; return r; }

    friend bool operator == (const Modular<P>& n, const Modular<P>& m) { return n.value == m.value; }
    friend bool operator != (const Modular<P>& n, const Modular<P>& m) { return n.value != m.value; }

    explicit    operator       int() const { return value; }
    explicit    operator      bool() const { return value; }
    explicit    operator long long() const { return value; }

    constexpr static value_type mod()      { return     P; }

    value_type norm(long long k) {
        if (!(-P <= k && k < P)) k %= P;
        if (k < 0) k += P;
        return k;
    }

    Modular<P> inv() const {
        value_type a = value, b = P, x = 0, y = 1;
        while (a != 0) { value_type k = b / a; b -= k * a; x -= k * y; swap(a, b); swap(x, y); }
        return Modular<P>(x);
    }
};
template<auto P> Modular<P> pow(Modular<P> m, long long p) {
    Modular<P> r(1);
    while (p) {
        if (p & 1) r *= m;
        m *= m;
        p >>= 1;
    }
    return r;
}

template<auto P> ostream& operator << (ostream& o, const Modular<P>& m) { return o << m.value; }
template<auto P> istream& operator >> (istream& i,       Modular<P>& m) { long long k; i >> k; m.value = m.norm(k); return i; }
template<auto P> string   to_string(const Modular<P>& m) { return to_string(m.value); }

// using Mint = Modular<1000000007>;
using Mint = Modular<998244353>;
// using Mint = long double;

vector<Mint> f, fi;
void init_C(int n) {
    f.assign(n, 1); fi.assign(n, 1);
    for (int i = 2; i < n; ++i) f[i] = f[i - 1] * i;
    fi.back() = Mint(1) / f.back();
    for (int i = n - 2; i >= 0; --i) fi[i] = fi[i + 1] * (i + 1);
}
Mint C(int n, int k) {
    if (k < 0 || k > n) return 0;
    else return f[n] * fi[k] * fi[n - k];
}
}
using namespace mint_ns;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    Sieve sieve(2e5 + 20, true, true);

    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<vector<int>> who(maxe(a) + 1);
    for (int i = 0; i < n; ++i) {
        for (auto [p, c] : sieve.get_prime_divs(a[i]))
            who[p].pb(i);
    }

    vector<int> tin(n), tout(n);
    int tm = 0;
    y_combinator([&](auto dfs, int v, int p) -> void {
        tin[v] = tm++;
        for (int k : g[v]) {
            if (k == p) continue;
            dfs(k, v);
        }
        tout[v] = tm++;
    })(0, -1);

    build_lca_sparse(g, 0);

    vector<bool> marked(n);
    vector<vector<int>> g0(n);

    vector<int> sz(n);

    Mint ans = 0;

    for (auto& vec : who) {
        if (vec.size() <= 2) continue;

        for (int i = 0; i < vec.size(); ++i)
            ans += Mint(lca_depth[vec[i]]) * (vec.size() - 1) * (vec.size() - 2) / 2;
        // for (int i = 0; i < vec.size(); ++i)
        //     for (int j = 0; j < i; ++j)
        //         ans -= Mint(lca_depth[get_lca(vec[i], vec[j])]) * (vec.size() - 2);
        // show(ans);
        // continue;

        for (int v : vec)
            marked[v] = true;
        sort(vec.begin(), vec.end(), [&](int u, int v) {
            return tin[u] < tin[v];
        });
        int S = vec.size();
        for (int i = 0; i + 1 < S; ++i) {
            vec.pb(get_lca(vec[i], vec[i + 1]));
        }
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());

        for (int v : vec)
            sz[v] = 0;

        vector<pair<int, int>> events;
        for (int v : vec) {
            events.eb(tin[v], v);
            events.eb(tout[v], -1);
        }
        sort(events.begin(), events.end());

        auto conn = [&](int u, int v) {
            g0[u].pb(v);
            g0[v].pb(u);
        };

        vector<int> st;
        int root = events[0].second;
        for (auto [_, v] : events) {
            if (v >= 0) {
                if (!st.empty())
                    conn(st.back(), v);
                st.pb(v);
            } else {
                st.pop_back();
            }
        }

        show(g0, root);
        show(marked);

        show(ans);
        y_combinator([&](auto dfs, int v, int p) -> void {
            sz[v] = marked[v];
            for (int k : g0[v]) {
                if (k == p) continue;
                dfs(k, v);
                Mint prs = Mint(sz[v]) * sz[k];
                show(v, prs);
                ans -= prs * (S - 2) * lca_depth[v];
                sz[v] += sz[k];
            }
        })(root, -1);
        show(ans);

        for (int v : vec)
            g0[v].clear();
        for (int v : vec)
            marked[v] = false;
    }

    cout << ans << '\n';

    return 0;
}