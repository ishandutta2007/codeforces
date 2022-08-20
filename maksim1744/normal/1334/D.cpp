/*
    author:  Maksim1744
    created: 10.04.2020 17:47:08
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

void solve() {
    ll n, l, r;
    cin >> n >> l >> r;
    vector<ll> cnt(n);
    for (int i = 0; i < n; ++i) {
        cnt[i] = (n - i - 1) * 2;
    }
    cnt[0] = (n - 1) * 2 - 1;
    cnt[n - 1] = 1;
    vector<pair<ll, ll>> lr(n);
    lr[0] = {1, 1 + cnt[0]};
    for (int i = 1; i < n; ++i) {
        lr[i].first = lr[i - 1].second + 1;
        lr[i].second = lr[i].first + cnt[i] - 1;
    }
    ll st = 0;
    ll sti = 0;
    for (int i = 0; i < n; ++i) {
        if (lr[i].second >= l) {
            sti = i;
            break;
        }
    }
    st = lr[sti].first;
    vector<ll> al;
    while (sti < n && lr[sti].first <= r) {
        if (sti == 0) {
            al.pb(1);
            for (int i = 2; i <= n; ++i) {
                al.pb(i);
                if (i != n) al.pb(1);
            }
        } else if (sti == n - 1) {
            al.pb(1);
        } else {
            for (int i = 0; i < cnt[sti] / 2; ++i) {
                al.pb(sti + 1);
                al.pb(sti + 2 + i);
            }
        }
        ++sti;
    }
    ll from = l - st;
    for (int i = 0; i < r - l + 1; ++i) {
        cout << al[from + i] << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    while (T--)
        solve();

    return 0;
}