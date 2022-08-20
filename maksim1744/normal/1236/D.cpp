/*
    author:  Maksim1744
    created: 17.10.2019 16:58:34
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
    ll n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> v(k);
    cin >> v;
    for (int i = 0; i < k; ++i) {
        v[i].first--;
        v[i].second--;
    }
    vector<vector<int>> by_row(n), by_col(m);
    for (int i = 0; i < k; ++i) {
        by_row[v[i].first].pb(v[i].second);
        by_col[v[i].second].pb(v[i].first);
    }
    for (int i = 0; i < n; ++i) {
        sort(by_row[i].begin(), by_row[i].end());
    }
    for (int i = 0; i < m; ++i) {
        sort(by_col[i].begin(), by_col[i].end());
    }
    ll visited = 1;
    int x = 0, y = 0;
    int lx = 0, ly = 0, rx = n - 1, ry = m - 1;
    show(by_col, by_row);
    while (lx <= rx && ly <= ry && visited + k < n * m) {
        showt("1", x, y, lx, rx, ly, ry);
        auto ind = lowb(by_row[x], y);
        show(ind);
        if (ind != by_row[x].size()) {
            ry = min(ry, by_row[x][ind] - 1);
        }
        visited += ry - y;
        y = ry;
        ++lx;
        if (!(lx <= rx && ly <= ry && visited + k < n * m))
            break;
        showt("2", x, y, lx, rx, ly, ry);
        ind = lowb(by_col[y], x);
        if (ind != by_col[y].size()) {
            rx = min(rx, by_col[y][ind] - 1);
        }
        visited += rx - x;
        x = rx;
        --ry;
        if (!(lx <= rx && ly <= ry && visited + k < n * m))
            break;
        showt("3", x, y, lx, rx, ly, ry);
        ind = lowb(by_row[x], y);
        --ind;
        if (ind != -1) {
            ly = max(ly, by_row[x][ind] + 1);
        }
        visited += y - ly;
        y = ly;
        --rx;
        if (!(lx <= rx && ly <= ry && visited + k < n * m))
            break;
        showt("4", x, y, lx, rx, ly, ry);
        ind = lowb(by_col[y], x);
        --ind;
        if (ind != -1) {
            lx = max(lx, by_col[y][ind] + 1);
        }
        visited += x - lx;
        x = lx;
        ++ly;
    }
    shows;
    show(x, y, visited);
    if (visited + k == n * m) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}