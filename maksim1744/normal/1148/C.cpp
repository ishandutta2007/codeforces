/*
    author:  Maksim1744
    created: 01.06.2019 17:44:19
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

vector<int> p;
vector<pair<int, int>> ans;
int n;

void sw(int i, int j) { 
    if (i == j)
        return;
    if (abs(j - i) * 2 >= n) {
        ans.eb(i, j);
        swap(p[i], p[j]);
        return;
    }
    if (i > j)
        swap(i, j);
    auto f = [&](int u, int v) {
        assert(abs(u - v) * 2 >= n);
        swap(p[u], p[v]);
        ans.eb(u, v);
    };
    if (i * 2 >= n) {
        f(0, i);
        f(0, j);
        f(0, i);
    } else if ((n - 1 - j) * 2 >= n) {
        f(i, n - 1);
        f(j, n - 1);
        f(i, n - 1);
    } else {
        f(i, n - 1);
        f(0, j);
        f(0, n - 1);
        f(i, n - 1);
        f(0, j);
    }
}

int main() {
    cin >> n;
    p.resize(n);
    cin >> p;
    --p;
    vector<int> pos(n);
    for (int i = 0; i < n; ++i) {
        pos[p[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        if (pos[i] != i) {
            pos[p[i]] = pos[i];
            sw(pos[i], i);
        }
    }
    cout << ans.size() << '\n';
    for (auto p : ans) {
        cout << p.first + 1 << ' ' << p.second + 1 << '\n';
    }
    return 0;
}