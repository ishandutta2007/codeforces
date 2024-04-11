/*
    author:  Maksim1744
    created: 19.08.2020 19:58:13
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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    ll a;
    cin >> n >> m >> a;
    vector<ll> money(n);
    cin >> money;
    vector<ll> cost(m);
    cin >> cost;
    sort(money.begin(), money.end());
    sort(cost.begin(), cost.end());
    if (cost[0] > money.back() + a) {
        cout << "0 0\n";
        return 0;
    }
    int l = 0, r = min(n, m) + 1;
    while (r - l > 1) {
        int c = (l + r) / 2;
        int from = money.size() - c;
        ll need = 0;
        for (int j = 0; j < c; ++j) {
            need += max(0ll, cost[j] - money[from + j]);
        }
        if (need <= a) {
            l = c;
        } else {
            r = c;
        }
    }
    cost.resize(l);
    reverse(money.begin(), money.end());
    money.resize(l);
    reverse(money.begin(), money.end());
    n = l;
    show(cost);
    show(money);
    for (int i = 0; i < n; ++i) {
        money[i] = min(money[i], cost[i]);
    }
    // for (int i = 0; i < n; ++i) {
    //     if (a >= money[i]) {
    //         a -= money[i];
    //         money[i] = 0;
    //     }
    // }
    cout << n << ' ' << max(0ll, sum(cost) - a) << '\n';

    return 0;
}