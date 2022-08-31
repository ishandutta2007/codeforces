/*
    author:  Maksim1744
    created: 18.09.2019 20:39:36
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
const int N = 10;
const int LN = 5;
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
const int N = 200000 + 10;
const int LN = 20;
#endif

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    cin >> p;
    int ind = mini(p);
    vector<int> p1(n);
    for (int i = 0; i < n; ++i) {
        p1[i] = p[(ind + i) % n];
    }
    swap(p, p1);
    show(p);
    array<array<int, N>, LN> sparse;
    for (int i = 0; i < n; ++i) {
        sparse[0][i] = i;
    }
    for (int i = 1; i < LN; ++i) {
        int ln = (1 << (i));
        for (int j = 0; j + ln <= n; ++j) {
            if (p[sparse[i - 1][j]] < p[sparse[i - 1][j + ln / 2]]) {
                sparse[i][j] = sparse[i - 1][j];
            } else {
                sparse[i][j] = sparse[i - 1][j + ln / 2];
            }
        }
    }
    vector<int> p2(N);
    p2[0] = 0;
    p2[1] = 0;
    int last = 1;
    int cnt = 0;
    for (int i = 1; i < N; ++i) {
        if (i == last * 2) {
            ++cnt;
            last *= 2;
        }
        p2[i] = cnt;
    }
    show(sparse);
    // show(p2);
    auto get_min = [&](int l, int r) {
        // show(l, r);
        int ln = p2[r - l + 1];
        int i1 = sparse[ln][l], i2 = sparse[ln][r - (1 << ln) + 1];
        if (p[i1] < p[i2]) {
            return i1;
        } else {
            return i2;
        }
    };
    function<int(int, int)> calc_d = [&](int l, int r) {
        if (l > r)
            return 0;
        if (l == r)
            return 1;
        int ind = get_min(l, r);
        return 1 + max(calc_d(l, ind - 1), calc_d(ind + 1, r));
    };
    // vector<int> f(n - 1), g;
    // for (int i = 0; i < n - 1; ++i) {
    //     f[i] = p[i + 1];
    // }
    // g = f;
    // reverse(g.begin(), g.end());
    int l = 0, r = n;
    while (r - l > 1) {
        int c = (l + r) / 2;
        int ff = calc_d(1, c), gg = calc_d(c + 1, n - 1);
        if (ff <= gg) {
            l = c;
        } else {
            r = c;
        }
    }
    // #ifdef HOME
    // for (int i = 0; i < n; ++i) {
    //     cout << calc_d(i + 1, n - 1) << '\n';
    // }
    // #endif
    int ff = calc_d(1, l), gg = calc_d(l + 1, n - 1);
    show(l);
    cout << 1 + max(ff, gg) << ' ' << (ind + l + 1 + n * 5) % n << '\n';
    return 0;
}