/*
    author:  Maksim1744
    created: 02.07.2019 21:28:30
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
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> v;
    int x1 = 0, x2 = n * m - 1;
    v.pb(0);
    while (v.size() < n * m) {
        v.pb(x2);
        ++x1;
        v.pb(x1);
        --x2;
    }
    v.resize(n * m);
    for (auto k : v) {
        cout << k / m + 1 << ' ' << k % m + 1 << '\n';
    }
    // vector<pair<int, int>> al;
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < m; ++j) {
    //         al.eb(i, j);
    //     }
    // }
    // sort(al.begin(), al.end());
    // do {
    //     set<pair<int, int>> d;
    //     for (int i = 0; i < al.size() - 1; ++i) {
    //         d.insert(al[i + 1] - al[i]);
    //     }
    //     if (d.size() < al.size() - 1)
    //         continue;
    //     show(al);
    //     return 0;
    // } while (next_permutation(al.begin(), al.end()));
    // vector<int> vn, vm;
    // int x1 = 1, x2 = n;
    // vn.pb(1);
    // while (vn.size() < n) {
    //     vn.pb(x2);
    //     ++x1;
    //     vn.pb(x1);
    //     --x2;
    // }
    // vn.resize(n);
    // x1 = 1; x2 = m;
    // vm.pb(1);
    // while (vm.size() < m) {
    //     vm.pb(x2);
    //     ++x1;
    //     vm.pb(x1);
    //     --x2;
    // }
    // vm.resize(m);
    // show(vn, vm);
    // int x = 1, y = 1;
    // for (int i = 0; i < m; ++i) {
    //     for (int j = 0; j < n; ++j) {
    //         if (i % 2 == 0)
    //             cout << vn[j] << ' ' << vm[i] << '\n';
    //         else
    //             cout << vn[n - 1 - j] << ' ' << vm[i] << '\n';
    //     }
    // }
    return 0;
}