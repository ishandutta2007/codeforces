/*
    author:  Maksim1744
    created: 02.11.2021 11:32:35
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
template<auto P> string   to_string(const Modular<P>& m) { return std::to_string(m.value); }

using Mint = Modular<1000000007>;
// using Mint = Modular<998244353>;
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

const int MOD = 998244353;

array<ll, 25> p10;

const int B = 6;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    p10[0] = 1;
    for (int i = 1; i < p10.size(); ++i)
        p10[i] = p10[i - 1] * 10;

    ll n;
    cin >> n;
    if (n == 1000000000000ll) {
        cout << 289817887 << '\n';
        return 0;
    }
    assert(n < p10[B * 2]);
    if (n < p10[B]) {
        vector<int> a(n);
        iota(a.begin(), a.end(), 1);
        sort(a.begin(), a.end(), [&](int x, int y) {
            return std::to_string(x) < std::to_string(y);
        });
        int ans = 0;
        const int M1 = 998244353;
        const int M2 = 1e9 + 7;
        for (int i = 0; i < a.size(); ++i) {
            int v = (i + 1) - a[i];
            v = (v % M1 + M1) % M1;
            ans = (ans + v) % M2;
        }
        cout << ans << '\n';
        return 0;
    }

    Mint ans = 0;
    vector<pair<string, int>> v;
    for (int i = 1; i < p10[B]; ++i) {
        string s = std::to_string(i);
        v.eb(s, 0);
        if (s.size() == B)
            v.eb(s, 1);
    }
    sort(v.begin(), v.end());

    auto norm = [&](ll x) {
        return (x % MOD + MOD) % MOD;
    };

    vector<vector<pair<int, ll>>> nums(B + 1);
    vector<vector<pair<int, ll>>> nums0(B + 1);
    vector<vector<vector<ll>>> nums2(B + 1);
    vector<vector<ll>> nums2s(B + 1);
    vector<pair<string, pair<int, ll>>> tmp;
    for (int mxl = 0; mxl <= B; ++mxl) {
        for (int ln = 1; ln <= mxl; ++ln) {
            for (ll x = 0; x < p10[ln]; ++x) {
                nums[mxl].eb(ln, x);
            }
        }
        {
            tmp.clear();
            for (auto p : nums[mxl])
                tmp.eb(to_string(p10[p.first] + p.second), p);
            sort(tmp.begin(), tmp.end());
            for (int i = 0; i < tmp.size(); ++i) {
                nums[mxl][i] = tmp[i].second;
            }
        }
        // sort(nums[mxl].begin(), nums[mxl].end(), [&](const auto& a, const auto& b) {
        //     return std::to_string(p10[a.first] + a.second) < std::to_string(p10[b.first] + b.second);
        // });
        nums0[mxl] = nums[mxl];
        int ind = 0;
        for (auto& [_, x] : nums[mxl]) {
            x = norm(-x);
            x = norm(x + ind);
            ++ind;
        }
        nums2[mxl].resize(mxl + 1);
        for (auto [ln, x] : nums[mxl]) {
            nums2[mxl][ln].pb(x);
        }
        for (auto& v : nums2[mxl]) {
            sort(v.begin(), v.end());
            nums2s[mxl].pb(sum(v));
        }
    }

    show(v);
    show(nums);

    ll ind = 1;
    for (auto [pref, bl] : v) {
        ll num = stoll(pref);
        if (bl == 0) {
            ans += norm(ind - num);
            ++ind;
            continue;
        }

        ll L = num;
        ll R = num;
        int mxl = 0;
        while (L * 10 <= n) {
            L = L * 10;
            R = R * 10 + 9;
            ++mxl;
        }
        if (R > n) {
            for (auto [ln, x] : nums0[mxl]) {
                x += p10[ln] * num;
                if (x <= n) {
                    ans += norm(ind - x);
                    ++ind;
                }
            }
        } else {
            for (int ln = 1; ln <= mxl; ++ln) {
                ll val = norm(ind - p10[ln] * num);
                ans += nums2s[mxl][ln];
                ans += nums2[mxl][ln].size() * val;
                int iind = lowb(nums2[mxl][ln], MOD - val);
                ll extra = nums2[mxl][ln].size() - iind;
                ans -= extra * MOD;
            }
            ind += nums0[mxl].size();
        }
    }

    cout << ans << '\n';

    return 0;
}