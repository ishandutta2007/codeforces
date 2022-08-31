/*
    author:  Maksim1744
    created: 31.01.2021 01:00:49
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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    ll n, k;
    cin >> n >> k;
    if (k == 1) {
        cout << 1 << '\n';
        return 0;
    }
    if (k == 2) {
        cout << n << '\n';
        return 0;
    }
    k -= 2;
    ll l = -1, r = n + 10;
    while (r - l > 1) {
        ll c = (l + r) / 2;
        map<ll, ll> m;
        function<ll(ll, ll)> count = [&](ll l, ll r) {
            if (l + 1 >= r) return 0ll;
            if (m.count(r - l)) return m[r - l];
            ll mid = (l + r) / 2;
            if (abs(mid - l) < c) return 0ll;
            return m[r - l] = count(l, mid) + count(mid, r) + 1;
        };
        auto cnt = count(1, n);
        // show(c, cnt);
        if (cnt < k)
            r = c;
        else
            l = c;
    }

    ll d = l;
    show(d);

    map<pair<ll, ll>, ll> m;
    function<ll(ll, ll, ll)> count = [&](ll l, ll r, ll d) {
        if (l + 1 >= r) return 0ll;
        if (m.count({r - l, d})) return m[{r - l, d}];
        ll mid = (l + r) / 2;
        if (abs(mid - l) < d) return 0ll;
        return m[{r - l, d}] = count(l, mid, d) + count(mid, r, d) + 1;
    };

    map<ll, ll> m2;
    function<ll(ll, ll)> count2 = [&](ll l, ll r) {
        if (l + 1 >= r) return 0ll;
        if (m2.count(r - l)) return m2[r - l];
        ll mid = (l + r) / 2;
        if (abs(mid - l) < d) return 0ll;
        return m2[r - l] = count2(l, mid) + count2(mid, r) + (mid - l == d);
    };

    k -= count(1, n, d + 1);

    function<ll(ll, ll, ll)> get_ans = [&](ll l, ll r, ll k) {
        show(l, r, k);
        ll mid = (l + r) / 2;
        k -= (mid - l == d);
        if (k == 0) return mid;
        ll cnt = count2(l, mid);
        show(cnt);
        if (cnt >= k) return get_ans(l, mid, k);
        else return get_ans(mid, r, k - cnt);
    };

    cout << get_ans(1, n, k) << '\n';

    return 0;
}