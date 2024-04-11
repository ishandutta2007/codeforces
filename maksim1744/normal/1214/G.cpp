/*
    author:  Maksim1744
    created: 28.05.2021 14:45:06
*/

#pragma GCC target("popcnt")
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

const int N = 2000;
struct B {
    array<uint64_t, N / 64 + 1> a;
    B() {
        a.fill(0);
    }

    void set(int i) {
        a[i >> 6] |= (uint64_t(1) << i);
    }

    void operator ^= (const B &other) {
        for (int i = 0; i < a.size(); ++i)
            a[i] ^= other.a[i];
    }

    int count() const {
        int ans = 0;
        for (auto x : a)
            ans += __builtin_popcountll(x);
        return ans;
    }

    int _Find_first() const {
        int i = 0;
        while (a[i] == 0) ++i;
        return __builtin_ctzll(a[i]) + i * 64;
    }

    bool operator == (const B &other) const {
        return a == other.a;
    }
};

B operator ^ (const B &a, const B &b) {
    B res = a;
    res ^= b;
    return res;
}
B operator & (const B &a, const B &b) {
    B res = a;
    for (int i = 0; i < a.a.size(); ++i) {
        res.a[i] &= b.a[i];
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;
    vector<B> pref1(N + 1);
    for (int i = 1; i < pref1.size(); ++i) {
        pref1[i] = pref1[i - 1];
        pref1[i].set(i - 1);
    }

    vector<B> cur(n);
    vector<int> cnt(n);
    set<pair<int, int>> scur;
    for (int i = 0; i < n; ++i) {
        scur.emplace(0, i);
    }
    set<pair<int, int>> prs;

    auto ad = [&](pair<int, int> a_, pair<int, int> b_) {
        int a = a_.second;
        int b = b_.second;
        if (a > b) swap(a, b);
        auto nd = cur[a] & cur[b];
        if (nd == cur[a] || nd == cur[b]) return;
        prs.emplace(a, b);
    };
    auto dl = [&](pair<int, int> a_, pair<int, int> b_) {
        int a = a_.second;
        int b = b_.second;
        if (a > b) swap(a, b);
        prs.erase({a, b});
    };

    while (q--) {
        int a, l, r;
        cin >> a >> l >> r;
        --a; --l; --r;
        auto it = scur.find({cnt[a], a});
        cur[a] ^= pref1[r + 1] ^ pref1[l];
        assert(it != scur.end());
        if (it != scur.begin()) {
            dl(*prev(it), *it);
        }
        if (next(it) != scur.end()) {
            dl(*it, *next(it));
        }
        ++it;
        scur.erase(*prev(it));
        if (it != scur.end() && it != scur.begin()) {
            ad(*prev(it), *it);
        }
        cnt[a] = cur[a].count();
        it = scur.emplace(cnt[a], a).first;
        if (next(it) != scur.end() && it != scur.begin()) {
            dl(*prev(it), *next(it));
        }
        if (next(it) != scur.end()) {
            ad(*it, *next(it));
        }
        if (it != scur.begin()) {
            ad(*prev(it), *it);
        }

        if (prs.empty()) {
            cout << -1 << '\n';
        } else {
            auto [x1, x2] = *prs.begin();
            auto x = cur[x1], y = cur[x2];
            auto z = x & y;
            int y1 = (x ^ z)._Find_first();
            int y2 = (y ^ z)._Find_first();
            if (x1 > x2) swap(x1, x2);
            if (y1 > y2) swap(y1, y2);
            cout << x1 + 1 << ' ' << y1 + 1 << ' ' << x2 + 1 << ' ' << y2 + 1 << '\n';
        }
    }

    return 0;
}