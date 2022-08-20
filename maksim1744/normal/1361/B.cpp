/*
    author:  Maksim1744
    created: 04.06.2020 17:51:17
*/

#include <bits/stdc++.h>

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

const ll mod = 1e9 + 7;

long long mpow(long long a, long long p, long long mod = mod) {
    long long res = 1;
    while (p) {
        if (p & 1) res = res * a % mod;
        p >>= 1;
        a = a * a % mod;
    }
    return res;
}

ll inv(ll k, ll mod = mod) {
    return mpow(k, mod - 2, mod);
}

void test_case() {
    ll n, p;
    cin >> n >> p;
    vector<ll> k(n);
    cin >> k;
    sort(k.begin(), k.end());
    if (p == 1) {
        cout << k.size() % 2 << '\n';
        return;
    }
    vector<pair<ll, ll>> cnt;
    for (int i = 0; i < n; ++i) {
        if (i == 0 || k[i] != k[i - 1])
            cnt.eb(k[i], 0);
        cnt.back().second++;
    }
    reverse(cnt.begin(), cnt.end());
    // ll dif = 0;
    // // cnt.eb(cnt.back().first + 1, 0);
    // set<pair<ll, ll>> dif;
    // reverse(cnt.begin(), cnt.end());
    // for (auto [deg, c] : cnt) {
    //     if (dif.empty()) {
    //         if (c % 2 == 1) {
    //             dif.emplace(deg, 1);
    //         }
    //     } else {

    //     }
    // }
    auto cmp = [&](set<pair<ll, ll>>& l, set<pair<ll, ll>>& r) {
        while (!l.empty() && !r.empty()) {
            auto pl = *--l.end();
            auto pr = *--r.end();
            l.erase(--l.end());
            r.erase(--r.end());
            if (pl.first != pr.first) {
                l.insert(pl);
                r.insert(pr);
                return pl.first < pr.first;
            }
            if (pl == pr) continue;
            if (pl.second > pr.second) {
                pl.second -= pr.second;
                l.insert(pl);
                break;
            } else {
                pr.second -= pl.second;
                r.insert(pr);
                break;
            }
        }
        if (l.empty() && r.empty()) return false;
        if (l.empty()) return true;
        if (r.empty()) return false;
        return ((--l.end())->first < (--r.end())->first);
    };
    ll P = p;
    function<void(set<pair<ll, ll>>&, ll)> add = [&](set<pair<ll, ll>>& s, ll deg) {
        show(s, deg);
        pair<ll, ll> p = make_pair(deg, 0);
        auto it = s.lower_bound(p);
        if (it == s.end() || it->first != deg) {
            s.emplace(deg, 1);
            show(s);
            return;
        }
        p = *it;
        s.erase(it);
        p.second++;
        ll cnt = p.second / P;
        p.second %= P;
        if (p.second != 0) s.insert(p);
        if (cnt == 1) add(s, deg + 1);
        show(s);
    };
    set<pair<ll, ll>> l, r;
    for (auto [deg, c] : cnt) {
        if (l.empty() && r.empty()) {
            if (c % 2 == 1) {
                r.emplace(deg, 1);
            }
        } else {
            for (int i = 0; i < c; ++i) {
                if (!cmp(l, r)) swap(l, r);
                add(l, deg);
            }
        }
        show(l, r);
    }
    auto calc = [&](set<pair<ll, ll>>& s) {
        ll ans = 0;
        for (auto [d, c] : s) {
            ll x = mpow(P, d);
            x = x * c % mod;
            ans = (ans + x) % mod;
        }
        return ans;
    };
    ll dif = calc(l) - calc(r);
    if (cmp(l, r)) {
        dif = -dif;
    }
    dif = ((dif % mod) + mod) % mod;
    cout << dif << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        test_case();
    }

    return 0;
}