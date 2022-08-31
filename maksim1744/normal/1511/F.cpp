/*
    author:  Maksim1744
    created: 12.04.2021 18:11:56
*/

#include "bits/stdc++.h"

using namespace std;

#define ll   long long
#define ld   long double

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

template<typename T>             vector<T>& operator--            (vector<T>& v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T>& v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T>& v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>& v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define SHOW_COLORS
#include "C:/C++ libs/print.cpp"
#else
#define show(...)     42
#define mclock        42
#define shows         42
#define debug if (false)
#endif

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

int N;

template<typename T>
struct Matrix {
    vector<vector<T>> m;

    Matrix() {
        m.assign(N, vector<T>(N, 0));
        // for (int i = 0; i < N; ++i) {
        //     for (int j = 0; j < N; ++j) {
        //         m[i][j] = 0;
        //     }
        // }
    }
    // Matrix(std::initializer_list<std::initializer_list<T>> s) {
    //     int i = 0;
    //     for (auto it = s.begin(); it != s.end(); ++it) {
    //         int j = 0;
    //         for (auto it2 = it->begin(); it2 != it->end(); ++it2) {
    //             m[i][j] = *it2;
    //             ++j;
    //         }
    //         ++i;
    //     }
    // }

    static Matrix E() {
        Matrix e;
        for (int i = 0; i < N; ++i) {
            e[i][i] = 1;
        }
        return e;
    }

    vector<T> &operator[](int i) {
        return m[i];
    }

    const vector<T> &operator[](int i) const {
        return m[i];
    }

    Matrix operator * (const Matrix &b) {
        Matrix c;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                for (int k = 0; k < N; ++k) {
                    c[i][k] += m[i][j] * b[j][k];
                }
            }
        }
        return c;
    }

    Matrix &operator *= (const Matrix &other) {
        *this = (*this) * other;
        return *this;
    }

    Matrix &operator *= (const T &x) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                m[i][j] *= x;
            }
        }
        return *this;
    }
    Matrix operator * (const T &x) {
        Matrix a = *this;
        a *= x;
        return a;
    }

    Matrix &operator /= (const T &x) {
        T inv = T(1) / x;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                m[i][j] *= inv;
            }
        }
        return *this;
    }
    Matrix operator / (const T &x) {
        Matrix a = *this;
        a /= x;
        return a;
    }

    Matrix &operator += (const Matrix &other) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                m[i][j] += other[i][j];
            }
        }
        return *this;
    }
    Matrix operator + (const Matrix &other) {
        Matrix a = *this;
        a += other;
        return a;
    }

    Matrix &operator -= (const Matrix &other) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                m[i][j] -= other[i][j];
            }
        }
        return *this;
    }
    Matrix operator - (const Matrix &other) {
        Matrix a = *this;
        a -= other;
        return a;
    }
};

template<typename T>
Matrix<T> pow(Matrix<T> m, ll p) {
    Matrix<T> res = Matrix<T>::E();
    while (p) {
        if (p & 1) res *= m;
        m *= m;
        p >>= 1;
    }
    return res;
}

struct Node {
    bool end = false;
    map<char, Node*> to;
    int id = 0;
};

vector<int> scc(vector<vector<int>>& g) {
    int n = g.size();
    vector<int> topsort; topsort.reserve(n);
    vector<bool> u(n, false);
    function<void(int)> scc_dfs1 = [&](int v) {
        u[v] = true;
        for (auto k : g[v])
            if (!u[k])
                scc_dfs1(k);
        topsort.push_back(v);
    };
    for (int i = 0; i < n; ++i)
        if (!u[i])
            scc_dfs1(i);
    vector<vector<int>> gi(n);
    for (int i = 0; i < n; ++i)
        for (auto j : g[i])
            gi[j].push_back(i);
    int color = 0;
    vector<int> comp(n, -1);
    reverse(topsort.begin(), topsort.end());
    function<void(int, int)> scc_dfs2 = [&](int v, int color) {
        comp[v] = color;
        for (auto k : gi[v])
            if (comp[k] == -1)
                scc_dfs2(k, color);
    };
    for (auto v : topsort)
        if (comp[v] == -1)
            scc_dfs2(v, color++);
    return comp;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    Node *root = new Node();
    vector<Node*> nodes = {root};

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        Node *node = root;
        for (char c : s) {
            if (!node->to.count(c)) {
                Node *n = new Node();
                n->id = nodes.size();
                nodes.pb(n);
                node->to[c] = n;
            }
            node = node->to[c];
        }
        node->end = true;
    }

    show(nodes.size());
    // show(mt.m);

    vector<pair<int, int>> pos;
    for (int i = 0; i < nodes.size(); ++i)
        for (int j = 0; j <= i; ++j)
            pos.eb(j, i);
    sort(pos.begin(), pos.end());

    auto getp = [&](pair<int, int> p) {
        if (p.first > p.second) swap(p.first, p.second);
        int res = (int)lowb(pos, p);
        if (res == pos.size() || pos[res] != p) return -1;
        return res;
    };

    vector<vector<int>> g(pos.size());

    auto ade = [&](pair<int, int> to, pair<int, int> from) {
        g[getp(from)].pb(getp(to));
    };

    for (int i = 0; i < nodes.size(); ++i) {
        for (int j = 0; j <= i; ++j) {
            for (char c = 'a'; c <= 'z'; ++c) {
                if (!nodes[i]->to.count(c)) continue;
                if (!nodes[j]->to.count(c)) continue;
                auto n1 = nodes[i]->to[c];
                auto n2 = nodes[j]->to[c];
                ade({n1->id, n2->id}, {i, j});
                if (n1->end) {
                    ade({0, n2->id}, {i, j});
                }
                if (n2->end) {
                    ade({n1->id, 0}, {i, j});
                }
                if (n1->end && n2->end) {
                    ade({0, 0}, {i, j});
                }
            }
        }
    }

    auto col = scc(g);
    vector<pair<int, int>> pos2;
    for (int i = 0; i < pos.size(); ++i) {
        if (col[i] == col[0]) {
            pos2.pb(pos[i]);
        }
    }
    show(pos.size());
    swap(pos, pos2);
    show(pos.size());

    N = pos.size();
    Matrix<Mint> mt;

    auto ade2 = [&](pair<int, int> to, pair<int, int> from) {
        int i1 = getp(to);
        int i2 = getp(from);
        if (i1 == -1 || i2 == -1) return;
        mt[i1][i2]++;
    };

    for (int i = 0; i < nodes.size(); ++i) {
        for (int j = 0; j <= i; ++j) {
            for (char c = 'a'; c <= 'z'; ++c) {
                if (!nodes[i]->to.count(c)) continue;
                if (!nodes[j]->to.count(c)) continue;
                auto n1 = nodes[i]->to[c];
                auto n2 = nodes[j]->to[c];
                ade2({n1->id, n2->id}, {i, j});
                if (n1->end) {
                    ade2({0, n2->id}, {i, j});
                }
                if (n2->end) {
                    ade2({n1->id, 0}, {i, j});
                }
                if (n1->end && n2->end) {
                    ade2({0, 0}, {i, j});
                }
            }
        }
    }

    // show(mt.m);

    auto res = pow(mt, m);
    cout << res[0][0] << '\n';

    return 0;
}