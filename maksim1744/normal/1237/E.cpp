/*
    author:  Maksim1744
    created: 16.10.2019 19:33:52
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
    int n;
    cin >> n;
    if (__builtin_popcount(n + 1) == 1) {
        if (n == 1) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    } else {
        int k = 1;
        while (k * 4 - 1 < n)
            k *= 2;
        // show(k);
        k *= 2;
        vector<bool> v(k, 0);
        vector<pair<int, int>> check;
        for (int i = 2; i < k; i *= 2) {
            for (int j = i; j + i <= k; j += i * 2) {
                check.eb(j, j + i - 1);
            }
        }
        show(k, check);
        for (auto [l, r] : check) {
            int sm = 0;
            for (int i = l + 1; i <= r; ++i)
                sm += v[i];
            if (sm % 2 == 0)
                v[l] = 1;
        }
        int sz  = k - 1 + sum(v);
        if (sz == n || sz + 1 == n) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
    return 0;
}