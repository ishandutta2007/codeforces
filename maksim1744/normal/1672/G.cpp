/*
    author:  Maksim1744
    created: 23.04.2022 18:03:04
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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    cin >> v;
    if (n % 2 == 0 && m % 2 == 1) {
        vector<string> v2(m, string(n, '.'));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                v2[j][i] = v[i][j];
            }
        }
        swap(n, m);
        swap(v, v2);
    }


    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cnt += (v[i][j] == '?');
        }
    }
    Mint two = 2;
    if (n == 1 || m == 1) {
        set<char> s;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (v[i][j] != '?')
                    s.insert(v[i][j]);
            }
        }
        if (s.size() == 2) {
            cout << 0 << '\n';
        } else {
            cout << (s.empty() ? 2 : 1) << '\n';
        }
        return 0;
    }
    if (n % 2 == 0 && m % 2 == 0) {
        cout << pow(two, cnt) << '\n';
    } else if (n % 2 == 1 && m % 2 == 0) {
        vector<int> who(m, 0);
        int cnt = 0;

        int al = 0;
        vector<int> xr(m, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == n - 1 && j != 0) continue;
                if (v[i][j] == '1') {
                    if (j == 0) al ^= 1;
                    else xr[j] ^= 1;
                    v[i][j] = '0';
                }
            }
        }
        show(al);
        show(xr);
        for (int i = 1; i < m; ++i) {
            if (v.back()[i] != '?') {
                if (xr[i] ^ al) {
                    v.back()[i] ^= '0' ^ '1';
                }
            }
        }

        vector<int> inter;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == n - 1 && j != 0) {
                    if (v[i][j] != '?')
                        inter.pb(j);
                    continue;
                }
                if (v[i][j] != '?') continue;
                ++cnt;
                who[j] = 1;
            }
        }
        show(inter);
        show(v);
        show(who);
        if (inter.empty()) {
            cout << pow(two, cnt) << '\n';
        } else {
            int sz = 0;
            for (int k : inter)
                sz += who[k];
            sz += who[0];
            if (sz == inter.size() + 1)
                sz = inter.size();

            bool ok = false;
            {
                bool ok1 = true;
                for (int i : inter) {
                    if (!who[i] && v.back()[i] == '1')
                        ok1 = false;
                }
                if (ok1) ok = true;
            }
            if (who[0]) {
                bool ok1 = true;
                for (int i : inter) {
                    if (!who[i] && v.back()[i] == '0')
                        ok1 = false;
                }
                if (ok1) ok = true;
            }
            if (!ok) {
                cout << 0 << '\n';
            } else {
                assert(cnt >= sz);
                cout << pow(two, cnt - sz) << '\n';
            }
        }
    } else if (n % 2 == 1 && m % 2 == 1) {
        int al = 0;
        auto xr = [&](int i, int j) {
            if (v[i][j] != '?')
                v[i][j] ^= '0' ^ '1';
        };
        for (int i = 0; i + 1 < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i != 0 && j == m - 1) continue;
                if (v[i][j] != '1') continue;
                v[i][j] = '0';
                if (i == 0) {
                    al ^= 1;
                    xr(n - 1, j);
                    xr(n - 1, m - 1);
                } else {
                    xr(i, m - 1);
                    xr(n - 1, j);
                    xr(n - 1, m - 1);
                }
            }
        }
        if (al) {
            for (int i = 1; i < n - 1; ++i) {
                xr(i, m - 1);
            }
            for (int i = 0; i < m; ++i) {
                xr(n - 1, i);
            }
        }

        DSU d(m);
        const int N = 4000;
        // const int N = 6;
        const int N2 = N / 2;
        using B = bitset<N>;
        vector<B> basis;
        for (int i = 1; i < n - 1; ++i) {
            vector<int> here;
            for (int j = 0; j < m - 1; ++j) {
                if (v[i][j] == '?')
                    here.pb(j);
            }
            if (here.empty()) continue;
            B fr = 0;
            fr.set(i);
            fr.set(N2 + here[0]);
            fr.set(N2 + m - 1);
            basis.pb(fr);
            for (int k = 1; k < here.size(); ++k) {
                d.un(here[0], here[k]);
            }
        }
        show(v);
        B extra = 0;
        {
            vector<int> here;
            for (int j = 0; j < m; ++j) {
                if (v[0][j] == '?')
                    here.pb(j);
            }
            if (!here.empty()) {
                for (int i = 1; i + 1 < n; ++i)
                    extra.set(i);
                for (int i = 0; i < m; ++i)
                    extra.set(N2 + i);
                if (here[0] != m - 1) {
                    extra.flip(N2 + m - 1);
                    extra.flip(N2 + here[0]);
                }
                for (int k = 1; k < here.size(); ++k) {
                    d.un(here[0], here[k]);
                }
            }
        }

        show(basis);

        B mask = 0;
        for (int i = 1; i + 1 < n; ++i) {
            if (v[i].back() != '?') mask.set(i);
        }
        for (int i = 0; i < m; ++i) {
            if (v.back()[i] != '?') mask.set(N2 + i);
        }
        for (auto& x : basis)
            x &= mask;
        show(mask);
        show(extra);
        extra &= mask;

        {
            vector<B> basis2;
            for (auto b : basis) {
                int c = b.count();
                if (c > 2) {
                    basis2.pb(b);
                } else if (c == 0) {
                    continue;
                } else {
                    int ind = b._Find_first();
                    if (ind < N2) {
                        basis2.pb(b);
                    } else {
                        int ind2 = b._Find_next(ind);
                        d.un(ind - N2, ind2 - N2);
                    }
                }
            }
            swap(basis, basis2);
        }
        show(basis);

        map<int, vector<int>> comps;
        for (int i = 0; i < m; ++i) {
            comps[d.par(i)].pb(i);
        }
        show(comps);
        show(mask);
        for (auto& [u, v] : comps) {
            if (v.size() < 2) continue;
            bool haveout = false;
            for (int k : v)
                if (!mask.test(N2 + k))
                    haveout = true;

            if (haveout) {
                for (int k : v) {
                    if (mask.test(N2 + k)) {
                        B b = 0;
                        b.set(N2 + k);
                        basis.pb(b);
                    }
                }
            } else {
                for (int i = 0; i + 1 < v.size(); ++i) {
                    B b = 0;
                    b.set(N2 + v[i]);
                    b.set(N2 + v[i + 1]);
                    basis.pb(b);
                }
            }
        }
        show(basis);

        B my = 0;
        for (int i = 1; i + 1 < n; ++i) {
            if (v[i].back() == '1')
                my.set(i);
        }
        for (int i = 0; i < m; ++i) {
            if (v.back()[i] == '1')
                my.set(N2 + i);
        }

        bool ok = false;
        for (int it = 0; it < 2; ++it) {
            B cur = my;
            if (it == 1) cur ^= extra;
            for (const auto& b : basis) {
                if (b == 0) assert(false);
                int ind = b._Find_first();
                if (cur[ind])
                    cur ^= b;
            }
            if (cur.count() == 0)
                ok = true;
        }

        if (!ok) {
            cout << 0 << '\n';
        } else {
            int sz = basis.size();
            for (const auto& b : basis) {
                if (b == 0) assert(false);
                int ind = b._Find_first();
                if (extra[ind])
                    extra ^= b;
            }
            if (extra.count()) ++sz;
            int cnt = 0;
            for (int i = 0; i < n - 1; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (i != 0 && j == m - 1) continue;
                    cnt += (v[i][j] == '?');
                }
            }
            assert(cnt >= sz);
            cout << pow(two, cnt - sz) << '\n';
        }
    } else {
        assert(false);
    }

    return 0;
}