/*
    author:  Maksim1744
    created: 28.02.2021 18:28:40
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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd (ll l, ll r) { return (ll)(rng() % (r - l + 1)) + l; }
ll rnd (ll r)       { return rng() % r; }
ll rnd ()           { return rng(); }
ld rndf()           { return (ld)rng() / (ld)ULLONG_MAX; }
ld rndf(ld l, ld r) { return rndf() * (r - l) + l; }

void test_case(int test) {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        p[i] = i;
    }
    // #ifndef HOUSE
    // for (int i = 0; i < n; ++i) {
    //     swap(p[i], p[rnd(i, n - 1)]);
    // }
    // #endif

    auto ask = [&](vector<int> v1, vector<int> v2) {
        if (v1.empty() || v2.empty()) return 0;
        cout << "? " << v1.size() << ' ' << v2.size() << endl;
        for (int k : v1)
            cout << p[k] + 1 << ' ';
        cout << endl;
        for (int k : v2)
            cout << p[k] + 1 << ' ';
        cout << endl;
        int x;
        cin >> x;
        return x;
    };

    auto say = [&](vector<int> v) {
        cout << "! " << v.size() << ' ';
        for (int k : v) {
            cout << p[k] + 1 << ' ';
        }
        cout << endl;
    };

    vector<int> a;
    int ind = -1;
    for (int i = 1; i < n; ++i) {
        a.pb(i - 1);
        if (ask(a, {i}) != 0) {
            ind = i;
            break;
        }
    }
    assert(ind != -1);
    vector<int> ans;
    for (int i = ind + 1; i < n; ++i) {
        if (ask({ind}, {i}) == 0)
            ans.pb(i);
    }
    show(ind);

    int l = -1, r = ind - 1;
    while (r - l > 1) {
        int c = (l + r) / 2;
        vector<int> v;
        for (int i = 0; i <= c; ++i) {
            v.pb(i);
        }
        if (ask(v, {ind}) == 0) {
            l = c;
        } else {
            r = c;
        }
    }
    show(l, r);

    for (int i = 0; i < ind; ++i)
        if (i != r)
            ans.pb(i);

    say(ans);
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