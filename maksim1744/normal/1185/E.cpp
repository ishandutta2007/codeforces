/*
    author:  Maksim1744
    created: 19.06.2019 18:18:08
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
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<string> f(n);
        cin >> f;
        vector<vector<pair<int, int>>> c(26);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (f[i][j] != '.') {
                    c[f[i][j] - 'a'].eb(i, j);
                }
            }
        }
        pair<int, int> lst = {-1, -1};
        int cl = -1;
        for (int i = 0; i < 26; ++i) {
            for (auto pr : c[i]) {
                lst = pr;
                cl = i;
            }
        }
        if (lst.first == -1) {
            cout << "YES\n";
            cout << 0 << '\n';
            continue;
        }
        bool ok = true;
        vector<pair<pair<int, int>, pair<int, int>>> ans;
        vector<string> f1(n, string(m, '.'));
        for (int i = 0; i < cl + 1; ++i) {
            if (c[i].size() == 0) {
                ans.eb(lst, lst);
                f1[lst.first][lst.second] = 'a' + i;
                continue;
            }
            bool dy = false, dx = false;
            for (int j = 0; j + 1 < c[i].size(); ++j) {
                if (c[i][j].first != c[i][j + 1].first) {
                    dx = true;
                }
                if (c[i][j].second != c[i][j + 1].second) {
                    dy = true;
                }
            }
            if (dx && dy) {
                ok = false;
                break;
            }
            ans.eb(c[i][0], c[i].back());
            pair<int, int> d;
            if (dx) {
                d = {1, 0};
            } else {
                d = {0, 1};
            }
            show(c[i], d);
            auto p = c[i][0];
            while (p != c[i].back() + d) {
                f1[p.first][p.second] = 'a' + i;
                p = p + d;
            }
        }
        if (f != f1)
            ok = false;
        if (!ok) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            cout << ans.size() << '\n';
            for (auto p : ans) {
                cout << p.first.first + 1 << ' ' << p.first.second + 1 << ' ' << p.second.first + 1 << ' ' << p.second.second + 1 << '\n';
            }
        }
    }
    return 0;
}