/*
    author:  Maksim1744
    created: 11.07.2021 17:54:38
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
#include "C:/C++ libs/print.cpp"
#else
#define show(...) void(0)
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#endif

vector<pair<int, int>> edmonds(vector<vector<int>>& g) {
    int n = g.size();
    vector<int> match(n, -1);
    vector<int> p(n);
    vector<bool> u(n);
    vector<bool> ulca(n);
    vector<int> q(n + 5, -1);
    vector<int> base(n);
    vector<bool> blossom(n);
    int ql = 0, qr = 0;

    auto lca = [&](int a, int b) {
        ulca.assign(n, false);
        while (true) {
            a = base[a];
            ulca[a] = true;
            if (match[a] == -1)
                break;
            a = p[match[a]];
        }
        while (true) {
            b = base[b];
            if (ulca[b]) return b;
            b = p[match[b]];
        }
        return -1;
    };

    auto mark_path = [&](int v, int b, int k) {
        while (base[v] != b) {
            blossom[base[v]] = true;
            blossom[base[match[v]]] = true;
            p[v] = k;
            k = match[v];
            v = p[match[v]];
        }
    };

    auto find_path = [&](int root) {
        p.assign(n, -1);
        u.assign(n, false);
        for (int i = 0; i < n; ++i)
            base[i] = i;
        ql = qr = 0;
        q[qr++] = root;
        u[root] = true;
        while (ql < qr) {
            int v = q[ql++];
            for (auto k : g[v]) {
                if (base[v] == base[k] || match[v] == k) {
                    continue;
                } else if (k == root || (match[k] != -1 && p[match[k]] != -1)) {
                    blossom.assign(n, false);
                    int b = lca(v, k);
                    mark_path(v, b, k);
                    mark_path(k, b, v);
                    for (int i = 0; i < n; ++i) {
                        if (blossom[base[i]]) {
                            base[i] = b;
                            if (!u[i]) {
                                u[i] = true;
                                q[qr++] = i;
                            }
                        }
                    }
                } else if (p[k] == -1) {
                    p[k] = v;
                    if (match[k] == -1)
                        return k;
                    k = match[k];
                    u[k] = true;
                    q[qr++] = k;
                }
            }
        }
        return -1;
    };

    for (int i = 0; i < n; ++i) {
        if (match[i] == -1) {
            int v = find_path(i);
            while (v != -1) {
                match[v] = p[v];
                int k = match[p[v]];
                match[p[v]] = v;
                v = k;
            }
        }
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; ++i)
        if (match[i] > i)
            ans.eb(i, match[i]);
    return ans;
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

struct DSU {
    vector<int> rk;
    vector<int> p;
    int n;

    DSU(int n = 1) : n(n) {
        reset(n);
    }

    void reset(int n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        rk.assign(n, 1);
    }

    int par(int v) {
        return v == p[v] ? v : p[v] = par(p[v]);
    }

    bool un(int u, int v) {
        u = par(u);
        v = par(v);
        if (u == v) return false;
        if (rk[u] > rk[v]) swap(u, v);
        p[u] = v;
        rk[v] += rk[u];
        return true;
    }

    bool check(int u, int v) {
        return par(u) == par(v);
    }
};

namespace mint_ns {
template<auto P>
struct Modular {
    using value_type = decltype(P);
    value_type value;

    Modular(ll k = 0) : value(norm(k)) {}

    friend Modular<P>& operator += (      Modular<P> &n, const Modular<P>& m) { n.value += m.value; if (n.value >= P) n.value -= P; return n; }
    friend Modular<P>  operator +  (const Modular<P> &n, const Modular<P>& m) { Modular<P> r = n; return r += m; }

    friend Modular<P>& operator -= (      Modular<P> &n, const Modular<P>& m) { n.value -= m.value; if (n.value < 0)  n.value += P; return n; }
    friend Modular<P>  operator -  (const Modular<P> &n, const Modular<P>& m) { Modular<P> r = n; return r -= m; }
    friend Modular<P>  operator -  (const Modular<P> &n)                      { return Modular<P>(-n.value); }

    friend Modular<P>& operator *= (      Modular<P> &n, const Modular<P>& m) { n.value = n.value * 1ll * m.value % P; return n; }
    friend Modular<P>  operator *  (const Modular<P> &n, const Modular<P>& m) { Modular<P> r = n; return r *= m; }

    friend Modular<P>& operator /= (      Modular<P> &n, const Modular<P>& m) { return n *= m.inv(); }
    friend Modular<P>  operator /  (const Modular<P> &n, const Modular<P>& m) { Modular<P> r = n; return r /= m; }

    Modular<P>& operator ++                    ()       { return *this += 1; }
    Modular<P>& operator --                    ()       { return *this -= 1; }
    Modular<P>  operator ++                 (int)       { Modular<P> r = *this; *this += 1; return r; }
    Modular<P>  operator --                 (int)       { Modular<P> r = *this; *this -= 1; return r; }

    friend bool operator == (const Modular<P> &n, const Modular<P>& m) { return n.value == m.value; }
    friend bool operator != (const Modular<P> &n, const Modular<P>& m) { return n.value != m.value; }

    explicit    operator       int() const { return value; }
    explicit    operator      bool() const { return value; }
    explicit    operator long long() const { return value; }

    constexpr static value_type mod()      { return     P; }

    value_type norm(ll k) {
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
template<auto P> Modular<P> pow(Modular<P> m, ll p) {
    Modular<P> r(1);
    while (p) {
        if (p & 1) r *= m;
        m *= m;
        p >>= 1;
    }
    return r;
}

template<auto P> ostream& operator << (ostream& o, const Modular<P> &m) { return o << m.value; }
template<auto P> istream& operator >> (istream& i,       Modular<P> &m) { ll k; i >> k; m.value = m.norm(k); return i; }
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

void test_case(int test) {
    int n;
    cin >> n;
    vector<vector<int>> a(n * 2, vector<int>(n));
    cin >> a;
    --a;
    vector<vector<int>> g(n * 2);
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            bool con = false;
            for (int k = 0; k < n; ++k) {
                if (a[i][k] == a[j][k]) {
                    con = true;
                    break;
                }
            }
            if (con) {
                g[i].pb(j);
                g[j].pb(i);
            }
        }
    }

    auto mat = edmonds(g);
    vector<bool> u(n * 2, false);

    vector<int> magic;
    vector<int> with(n * 2);
    for (auto [a, b] : mat) {
        with[a] = b;
        with[b] = a;
    }

    auto take = y_combinator([&](auto take, int i) -> void {
        if (u[i]) return;
        magic.pb(i);
        u[i] = true;
        for (int k : g[i]) {
            if (u[k]) continue;
            u[k] = true;
            int t = with[k];
            if (!u[t]) {
                take(t);
            }
        }
    });

    while (true) {
        bool ch = false;
        for (int i = 0; i < n; ++i) {
            vector<int> cnt(n, 0);
            vector<int> who(n, 0);
            for (int j = 0; j < n * 2; ++j) {
                if (u[j]) continue;
                cnt[a[j][i]]++;
                who[a[j][i]] = j;
            }
            for (int j = 0; j < n; ++j) {
                if (cnt[j] == 1) {
                    take(who[j]);
                    ch = true;
                }
            }
        }
        if (!ch) break;
    }

    vector<vector<vector<int>>> where(n, vector<vector<int>>(n));
    Mint ans = 1;
    for (int i = 0; i < n * 2; ++i) {
        if (u[i]) continue;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                where[i][j].clear();
            }
        }
        for (int i = 0; i < n * 2; ++i) {
            if (u[i]) continue;
            for (int j = 0; j < n; ++j) {
                where[j][a[i][j]].pb(i);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                assert(where[i][j].size() == 0 || where[i][j].size() == 2);
            }
        }
        auto check = [&](int i) -> pair<bool, vector<int>> {
            vector<int> gr(n * 2, -1);
            auto dfs = y_combinator([&](auto dfs, int v) -> void {
                gr[v] = 0;
                for (int k : g[v]) {
                    if (u[k]) continue;
                    if (gr[k] != -1) continue;
                    gr[k] = 1;
                    for (int i = 0; i < n; ++i) {
                        int other = (where[i][a[k][i]][0] ^ where[i][a[k][i]][1] ^ k);
                        if (u[other]) continue;
                        if (gr[other] != -1) continue;
                        dfs(other);
                    }
                }
            });
            dfs(i);
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (where[i][j].empty()) continue;
                    int a = where[i][j][0];
                    int b = where[i][j][1];
                    if (gr[a] == -1 && gr[b] == -1) continue;
                    if (gr[a] == -1 || gr[b] == -1) return {false, gr};
                    if (gr[a] == gr[b]) return {false, gr};
                }
            }
            return {true, gr};
        };
        auto [b1, gr1] = check(i);
        auto [b2, gr2] = check(with[i]);
        if (b1 && b2) ans *= 2;
        vector<int> gr;
        if (b1) {
            gr = gr1;
        } else if (b2) {
            gr = gr2;
        } else {
            assert(false);
        }
        for (int i = 0; i < n * 2; ++i) {
            if (gr[i] == 0) {
                take(i);
            }
        }
    }
    sort(magic.begin(), magic.end());
    ++magic;
    DSU d(n);
    cout << ans << '\n';
    cout << magic << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        test_case(test);
    }

    return 0;
}