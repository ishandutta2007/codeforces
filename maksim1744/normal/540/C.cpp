/*
    author:  Maksim1744
    created: 17.08.2020 15:51:41
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

vector<pair<int, int>> D = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    cin >> v;
    pair<int, int> s, f;
    cin >> s >> f;
    --s.first; --s.second;
    --f.first; --f.second;
    auto check = [&](int x, int y) {
        return 0 <= x && x < n && 0 <= y && y < m;
    };
    if (s == f) {
        for (auto [dx, dy] : D) {
            if (check(s.first + dx, s.second + dy) && v[s.first + dx][s.second + dy] == '.') {
                cout << "YES\n";
                return 0;
            }
        }
        cout << "NO\n";
        return 0;
    }

    vector<vector<bool>> u(n, vector<bool>(m, false));
    function<void(int, int)> dfs = [&](int x, int y) {
        u[x][y] = true;
        for (auto [dx, dy] : D) {
            if (check(x + dx, y + dy) && !u[x + dx][y + dy]) {
                if (mp(x + dx, y + dy) == f) {
                    u[f.first][f.second] = true;
                    return;
                }
                if (v[x + dx][y + dy] == '.') {
                    dfs(x + dx, y + dy);
                }
            }
        }
    };
    dfs(s.first, s.second);
    if (!u[f.first][f.second]) {
        cout << "NO\n";
        return 0;
    }
    if (v[f.first][f.second] == 'X') {
        cout << "YES\n";
        return 0;
    }
    int have = 0;
    for (auto [dx, dy] : D) {
        if (check(f.first + dx, f.second + dy)) {
            if (mp(f.first + dx, f.second + dy) == s || v[f.first + dx][f.second + dy] == '.')
                ++have;
        }
    }
    if (have >= 2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}