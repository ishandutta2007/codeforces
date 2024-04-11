/*
    author:  Maksim1744
    created: 26.05.2021 01:36:54
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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, k, c;
    cin >> n >> k >> c;
    init_C((1 << c) + 20);

    vector<vector<vector<int>>> partitions(k + 1);
    vector<vector<Mint>> cnts;
    for (int n = 0; n <= k; ++n) {
        {
            vector<vector<vector<vector<int>>>> partitions_dp(n + 1, vector<vector<vector<int>>>(n + 1));
            partitions_dp[0][0].push_back({});
            for (int n = 1; n < partitions_dp.size(); ++n) {
                for (int last = 1; last <= n; ++last) {
                    for (int x = 0; x <= last; ++x) {
                        for (auto v : partitions_dp[n - last][x]) {
                            v.pb(last);
                            partitions_dp[n][last].pb(v);
                        }
                    }
                }
            }
            for (auto &x : partitions_dp.back())
                for (auto v : x)
                    partitions[n].pb(v);
        }

        cnts.eb();
        for (auto v : partitions[n]) {
            Mint res = f[n];
            for (int u : v)
                res /= f[u];
            map<int, int> m;
            for (int u : v)
                m[u]++;
            res *= f[v.size()];
            for (auto [a, b] : m)
                res /= f[b];
            cnts.back().pb(res);
        }
    }

    int total_xor = 0;
    map<int, int> m;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        int y = x - x % 16;
        x %= 16;
        if (y == 0) {
            m[x]++;
            continue;
        }
        int e = 1;
        while ((e & y) == 0) e <<= 1;
        total_xor ^= (y ^ e);
        m[e ^ x]++;
    }

    deque<pair<int, vector<vector<pair<int, Mint>>>>> probs;

    for (auto [x, c] : m) {
        probs.eb();
        probs.back().first = c;
        probs.back().second.resize(k + 1);
        for (int i = 0; i <= k; ++i) {
            map<int, Mint> mm;
            for (int j = 0; j < partitions[i].size(); ++j) {
                int val = (c % 2 == 0 ? 0 : x);
                for (auto u : partitions[i][j])
                    val ^= (x ^ (x - u));
                mm[val] += cnts[i][j] * C(c, partitions[i][j].size());
            }
            Mint tot = pow(Mint(c), i);
            for (auto p : mm)
                if (p.second != 0)
                    probs.back().second[i].eb(p.first, p.second / tot);
        }
    }

    auto mrg = [&](const pair<int, vector<vector<pair<int, Mint>>>> &a, const pair<int, vector<vector<pair<int, Mint>>>> &b) {
        vector<vector<pair<int, Mint>>> res(k + 1);
        vector<pair<int, Mint>> tmp;
        int tot = a.first + b.first;
        for (int i = 0; i < k + 1; ++i) {
            for (int j = 0; j + i < k + 1; ++j) {
                Mint X = pow(Mint(a.first), i) * pow(Mint(b.first), j) / pow(Mint(tot), i + j) * C(i + j, i);
                for (auto p1 : a.second[i])
                    for (auto p2 : b.second[j])
                        res[i + j].eb(p1.first ^ p2.first, p1.second * p2.second * X);
                sort(res[i + j].begin(), res[i + j].end(), [&](const auto &a, const auto &b) {
                    return a.first < b.first;
                });
                tmp.clear();
                for (auto [a, b] : res[i + j]) {
                    if (!tmp.empty() && tmp.back().first == a)
                        tmp.back().second += b;
                    else
                        tmp.eb(a, b);
                }
                swap(res[i + j], tmp);
            }
        }
        return make_pair(tot, res);
    };

    while (probs.size() >= 2) {
        auto a = probs.back();
        probs.pop_back();
        auto b = probs.back();
        probs.pop_back();
        probs.push_front(mrg(a, b));
    }

    vector<Mint> res(1 << c);
    for (auto [a, b] : probs[0].second.back())
        res[total_xor ^ a] += b;
    cout << res << '\n';

    return 0;
}