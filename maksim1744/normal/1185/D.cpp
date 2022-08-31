/*
    author:  Maksim1744
    created: 19.06.2019 18:05:53
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
    if (n <= 3) {
        cout << 2 << '\n';
        return 0;
    }
    vector<pair<int, int>> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i].first;
        b[i].second = i + 1;
    }
    sort(b.begin(), b.end());
    vector<int> d(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        d[i] = b[i + 1].first - b[i].first;
    }
    bool ok0 = true;
    for (int i = 0; i < n - 3; ++i) {
        if (b[i + 2].first + b[i].first != 2 * b[i + 1].first) {
            ok0 = false;
            break;
        }
    }
    if (ok0) {
        cout << b.back().second << '\n';
        return 0;
    }
    ok0 = true;
    for (int i = 1; i < n - 2; ++i) {
        if (b[i + 2].first + b[i].first != 2 * b[i + 1].first) {
            ok0 = false;
            break;
        }
    }
    if (ok0) {
        cout << b[0].second << '\n';
        return 0;
    }
    map<int, int> dc;
    for (auto r : d) {
        ++dc[r];
    }
    if (dc.size() > 3) {
        cout << -1 << '\n';
    } else if (dc.size() == 1) {
        cout << b[0].second << '\n';
    } else {
        int x = (--dc.end())->first;
        show(x);
        int bad = -1;
        show(d);
        for (int i = 0; i < n - 1; ++i) {
            if (d[i] != x) {
                bad = i + 1;
                break;
            }
        }
        int badi = b[bad].second;
        show(b, bad);
        b.erase(b.begin() + bad);
        show(b);
        bool ok = true;
        for (int i = 0; i < b.size() - 2; ++i) {
            if (b[i + 2].first + b[i].first != 2 * b[i + 1].first) {
                ok = false;
                break;
            }
        }
        if (!ok)
            badi = -1;
        cout << badi << '\n';
    }
    return 0;
}