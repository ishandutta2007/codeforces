/*
    author:  Maksim1744
    created: 07.05.2019 15:10:10
*/

#include <bits/stdc++.h>

using namespace std;

#define ll   long long
#define ld   long double

#define mp   make_pair
#define pb   push_back
#define eb   emplace_back

#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

template<typename T>             istream& operator>>(istream& is,  vector<T>& v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>& v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}

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
#define showt(...)       42;
#define printTree(...)   42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#endif

mt19937_64 rng(8194738374ll);
ll rnd (ll l, ll r) { return (ll)(rng() % (r - l + 1)) + l; }
ll rnd (ll r)       { return rng() % r; }
ll rnd ()           { return rng(); }
ld rndf()           { return (ld)rng() / (ld)ULLONG_MAX; }
ld rndf(ld l, ld r) { return rndf() * (r - l) + l; }

ll n, k;
#ifdef HOME
ll pos = -1;
int counter = 0;
bool ask(ll l, ll r) {
    ++counter;
    if (pos == -1)
        pos = rnd(1, n);
    assert(1 <= l && l <= r && r <= n);
    if (l == r && l == pos) {
        cout << "WIN, count = " << counter;
        exit(0);
    }
    if (l <= pos && pos <= r) {
        pos = rnd(max(1ll, pos - k), min(n, pos + k));
        return true;
    } else {
        pos = rnd(max(1ll, pos - k), min(n, pos + k));
        return false;
    }
}
#else
bool ask(ll l, ll r) {
    cout << l << ' ' << r << endl;
    string s;
    cin >> s;
    assert(s != "Bad");
    if (s == "Yes")
        if (l == r)
            exit(0);
        else
            return true;
    else
        return false;
}
#endif

int main() {
    cin >> n >> k;
    ll l = 1, r = n;
    // ll s = r - l;
    for (int i = 0; i < 70; ++i) {
        ll s1 = r - l;
        ll m = (l + r) / 2;
        if (ask(l, m)) {
            l = max(1ll, l - k);
            r = min(n, m + k);
        } else {
            l = max(1ll, m - k);
            r = min(n, r + k);
        }
        // s = r - l;
        // if (s <= 40)
        //     break;
    }
    // show(s);
    while (true) {
        ll c = rnd(l, r);
        ask(c, c);
        l = max(1ll, l - k);
        r = min(n, r + k);
        for (int i = 0; i < 10; ++i) {
            ll m = (l + r) / 2;
            if (ask(l, m)) {
                l = max(1ll, l - k);
                r = min(n, m + k);
            } else {
                l = max(1ll, m - k);
                r = min(n, r + k);
            }
            if (r - l <= k * 4)
                break;
        }
    }
    return 0;
}