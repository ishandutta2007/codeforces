/*
    author:  Maksim1744
    created: 13.10.2019 13:32:14
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
#define showt(...)       42;
#define printTree(...)   42;
#define printGraph(...)  42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#define printWGraph(...) 42;
#endif

int main() {
    ll n;
    cin >> n;
    ll k;
    cin >> k;
    auto get_mx = [](ll n) {
        if (n % 2 == 0) {
            return (n * (n + 1) / 2 - (n / 2) * (n / 2 + 1) / 2) * 2;
        } else {
            return (n * (n + 1) / 2 - (n / 2) * (n / 2 + 1) / 2) * 2 - (n + 1) / 2;
        }
    };
    auto get_mn = [](ll n) {
        return n * (n + 1) / 2;
    };
    if (k < get_mn(n)) {
        cout << -1 << '\n';
        return 0;
    }
    if (k > get_mx(n))
        k = get_mx(n);
    int ind = -1;
    for (ll i = 1; i <= n; ++i) {
        if (get_mx(i) + n * (n + 1) / 2 - i * (i + 1) / 2 >= k) {
            ind = i;
            break;
        }
    }
    vector<int> v(n);
    for (int i = ind - 1; i < n; ++i) {
        v[i] = i + 1;
    }
    for (int i = 0; i < ind - 1; ++i) {
        v[i] = ind - i - 1;
    }
    ll now = 0;
    int last = ind - 2;
    for (int i = 0; i < n; ++i) {
        now += max(i + 1, v[i]);
    }
    show(now, k);
    while (now < k && last >= 0) {
        now -= max(last + 1, v[last]) + max(last + 2, v[last + 1]);
        swap(v[last], v[last + 1]);
        now += max(last + 1, v[last]) + max(last + 2, v[last + 1]);
        --last;
    }
    cout << now << '\n';
    for (int i = 0; i < n; ++i) {
        cout << i + 1 << ' ';
    }
    cout << '\n';
    cout << v << '\n';
    // show(v);
    return 0;
}