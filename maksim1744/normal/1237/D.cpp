/*
    author:  Maksim1744
    created: 16.10.2019 17:57:16
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
const int N = 100;
const int LN = 10;
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
const int N = 300020;
const int LN = 20;
#endif

const int inf = 1'000'000'000 + 10;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    int mn = mine(a);
    int mx = maxe(a);
    if (mn * 2 >= mx) {
        for (int i = 0; i < n; ++i) {
            cout << -1 << ' ';
        }
        cout << '\n';
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        a.pb(a[i]);
    }
    for (int i = 0; i < n; ++i) {
        a.pb(a[i]);
    }
    n *= 3;
    array<array<int, N>, LN> sparse;
    for (int i = 0; i < n; ++i) {
        sparse[0][i] = a[i];
    }
    for (int lg = 1; lg < LN; ++lg) {
        int sz = (1 << lg);
        for (int j = 0; j + sz <= n; ++j) {
            int i1 = sparse[lg - 1][j];
            int i2 = sparse[lg - 1][j + sz / 2];
            // if (a[i1] <= a[i2])
            sparse[lg][j] = min(i1, i2);
        }
    }
    // show(sparse);
    array<int, N> p2;
    p2[0] = 0;
    p2[1] = 0;
    int pp2 = 1;
    int lg = 0;
    for (int i = 2; i < p2.size(); ++i) {
        if (pp2 * 2 <= i) {
            pp2 *= 2;
            ++lg;
        }
        p2[i] = lg;
    }
    // show(p2);
    auto ask = [&](int l, int r) {
        if (r < l)
            return inf;
        int sz = p2[r - l + 1];
        return min(sparse[sz][l], sparse[sz][r - (1 << sz) + 1]);
    };
    vector<int> next(n, n);
    for (int i = 0; i < n; ++i) {
        show(ask(i+1,n-1));
        if (ask(i + 1, n - 1) * 2 >= a[i]) {
            // cout << -1 << ' ';
            continue;
        }
        int l = i, r = n;
        while (r - l > 1) {
            int c = (l + r) / 2;
            int k = ask(i + 1, c);
            if (k * 2 < a[i]) {
                r = c;
            } else {
                l = c;
            }
        }
        // cout << (r - i + 1) << ' ';
        next[i] = r;
    }
    // cout << '\n';
    // int imx = maxi(a);
    // if (imx >= n)
    //     imx -= n;
    // vector<int> ans()
    vector<int> ans(n, n);
    for (int i = n - 2; i >= 0; --i) {
        ans[i] = min(next[i], ans[i + 1]);
    }
    for (int i = 0; i < n / 3; ++i) {
        cout << ans[i] - i << ' ';
    }
    cout << '\n';
    return 0;
}