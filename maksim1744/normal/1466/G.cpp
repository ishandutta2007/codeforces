/*
    author:  Maksim1744
    created: 30.12.2020 18:13:33
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
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define TAG_LENGTH       25
#define LR_LEFT          left
#define LR_RIGHT         right
#define LR_VALUE         value
#define LR_SECOND_VALUE  mn
#include "C:/C++ libs/print.cpp"
#else
#define showl            42;
#define shows            42;
#define show(...)        42;
#define showm(...)       42;
#define showt(...)       42;
#define printTree(...)   42;
#define printGraph(...)  42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#define printWGraph(...) 42;
#define debug     if (false)
#endif

template<auto P>
struct Modular {
    using value_type = decltype(P);
    value_type value;

    Modular(ll k = 0) : value(norm(k)) {}

    Modular<P>& operator += (const Modular<P>& m)       { value += m.value; if (value >= P) value -= P; return *this; }
    Modular<P>  operator +  (const Modular<P>& m) const { Modular<P> r = *this; return r += m; }

    Modular<P>& operator -= (const Modular<P>& m)       { value -= m.value; if (value <  0) value += P; return *this; }
    Modular<P>  operator -  (const Modular<P>& m) const { Modular<P> r = *this; return r -= m; }
    Modular<P>  operator -                     () const { return Modular<P>(-value); }

    Modular<P>& operator *= (const Modular<P> &m)       { value = value * 1ll * m.value % P; return *this; }
    Modular<P>  operator *  (const Modular<P>& m) const { Modular<P> r = *this; return r *= m; }

    Modular<P>& operator /= (const Modular<P> &m)       { return *this *= m.inv(); }
    Modular<P>  operator /  (const Modular<P>& m) const { Modular<P> r = *this; return r /= m; }

    Modular<P>& operator ++                    ()       { return *this += 1; }
    Modular<P>& operator --                    ()       { return *this -= 1; }
    Modular<P>  operator ++                 (int)       { Modular<P> r = *this; *this += 1; return r; }
    Modular<P>  operator --                 (int)       { Modular<P> r = *this; *this -= 1; return r; }

    bool        operator == (const Modular<P>& m) const { return value == m.value; }
    bool        operator != (const Modular<P>& m) const { return value != m.value; }

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

using Mint = Modular<1000000007>;
// using Mint = Modular<998244353>;
// using Mint = long double;

Mint count_occur(const string &s, const string &s0) {
    string t = s + s0;

    vector<int> z(t.size(), 0);
    for (int i = 1, l = 0, r = 0; i < t.size(); ++i) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < t.size() && t[z[i]] == t[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }

    Mint ans = 0;
    for (int i = s.size(); i < t.size(); ++i)
        ans += (z[i] >= s.size());
    return ans;
}

string t;
vector<vector<Mint>> cnt;
vector<Mint> p2;

Mint calcc(char c, int l, int r) {
    c -= 'a';
    Mint res = cnt[c][r];
    if (l != 0)
        res -= cnt[c][l - 1] * p2[r - l + 1];
    return res;
}

Mint calc(const string &s, int k, bool sub_last, int l = 0) {
    assert(!s.empty());
    if (l > k - 1) return 0;
    if (s.size() == 1) {
        // Mint ans = cnt[k - 1][s[0] - 'a'];
        Mint ans = 228;
        ans = calcc(s[0], l, k - 1);
        // {
        //     ans = 0;
        //     string u = t.substr(l, k - l);
        //     for (auto c : u) {
        //         ans = ans * 2;
        //         if (c == s[0]) ++ans;
        //     }
        // }
        if (sub_last && t[0] == s[0]) ans -= 1;
        return ans;
    }
    Mint ans = 0;
    for (int rem = 0; rem < 2; ++rem) {
        string ss;
        bool ok = true;
        for (int i = 0; i < s.size(); ++i) {
            if (i % 2 == rem) {
                if (s[i] != t[l]) {
                    ok = false;
                    break;
                }
            } else {
                ss.pb(s[i]);
            }
        }
        if (ok) {
            // ans += calc(ss, k, (s.size() - 1) % 2 == rem ? true : sub_last, l + 1);
            ans += calc(ss, k, false, l + 1);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, q;
    cin >> n >> q;
    string s0;
    cin >> s0;
    cin >> t;

    cnt.resize(26);
    for (int i = 0; i < 26; ++i) {
        cnt[i].assign(t.size(), 0);
        cnt[i][0] = (t[0] == 'a' + i);
        for (int j = 1; j < t.size(); ++j) {
            cnt[i][j] = cnt[i][j - 1] * 2 + (t[j] == 'a' + i);
        }
    }

    // cnt.assign(t.size(), vector<Mint>(26, 0));
    // cnt[0][t[0] - 'a'] = 1;
    // for (int i = 1; i < t.size(); ++i) {
    //     cnt[i] = cnt[i - 1];
    //     for (int j = 0; j < 26; ++j) {
    //         cnt[i][j] *= 2;
    //     }
    //     cnt[i][t[i] - 'a'] += 1;
    // }

    string S = s0;
    string Sr = S;
    reverse(Sr.begin(), Sr.end());
    S.pb('#');
    Sr.pb('#');
    vector<string> que(q);
    vector<int> inds(q);
    for (int i = 0; i < q; ++i) {
        cin >> inds[i] >> que[i];
    }
    for (auto s : que) {
        S += s;
        S.pb('#');
        reverse(s.begin(), s.end());
        Sr += s;
        Sr.pb('#');
    }

    vector<int> z(S.size(), 0);
    for (int i = 1, l = 0, r = 0; i < S.size(); ++i) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < S.size() && S[z[i]] == S[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    vector<int> zr(Sr.size(), 0);
    for (int i = 1, l = 0, r = 0; i < Sr.size(); ++i) {
        if (i <= r)
            zr[i] = min(r - i + 1, zr[i - l]);
        while (i + zr[i] < Sr.size() && Sr[zr[i]] == Sr[i + zr[i]])
            ++zr[i];
        if (i + zr[i] - 1 > r)
            l = i, r = i + zr[i] - 1;
    }

    p2.assign(max((int)S.size(), (int)t.size()) + 5, 1);
    for (int i = 1; i < p2.size(); ++i)
        p2[i] = p2[i - 1] * 2;

    int ind = s0.size() + 1;
    for (int ii = 0; ii < q; ++ii) {
        string s = que[ii];
        vector<int> start0(s.size());
        for (int i = 0; i < s.size(); ++i) {
            start0[i] = (z[ind] >= min(s0.size(), s.size() - i));
            ++ind;
        }
        ++ind;
        // if (ii != 1) continue;

        int k = inds[ii];

        Mint ans = 0;
        if (s.size() <= s0.size()) {
            ans += count_occur(s, s0) * p2[k];
        }

        show(start0);

        for (int i = 0; i < min(s0.size() + 1, s.size()); ++i) {
            string ss;
            bool ok = true;
            if (i != 0) {
                int val = zr[ind - 1 - i];
                show(val, i);
                if (val < i) continue;
            }
            bool sub_last = true;
            for (int j = i; j < s.size(); j += s0.size() + 1) {
                if (j + 1 < s.size() && !start0[j + 1]) {
                    if (i == 2) show(j);
                    ok = false;
                    break;
                }
                if (j + 1 == s.size())
                    sub_last = false;
                ss.pb(s[j]);
            }
            sub_last = false;
            if (ok) {
                show(start0);
                show(ss, sub_last, i);
                Mint cur = calc(ss, k, sub_last);
                ans += cur;
                show(cur);
            }
            shows;
        }

        cout << ans << '\n';
    }


    return 0;
}