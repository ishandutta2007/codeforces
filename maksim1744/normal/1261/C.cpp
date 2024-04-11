/*
    author:  Maksim1744
    created: 24.11.2019 11:33:35
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
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    cin >> v;
    int T = 1e8;
    vector<vector<int>> dp(n, vector<int>(m));
    for (int ii = 0; ii < 4; ++ii) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 || j == 0) {
                    dp[i][j] = (v[i][j] == 'X');
                    continue;
                }
                if (v[i][j] == '.') {
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                if (v[i - dp[i][j] + 1][j - dp[i][j] + 1] != 'X')
                    --dp[i][j];
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (v[i][j] == '.')
                    continue;
                int cnt = 0;
                if (i == n - 1 || v[i + 1][j] == '.')
                    ++cnt;
                if (j == m - 1 || v[i][j + 1] == '.')
                    ++cnt;
                if (cnt == 2) {
                    T = min(T, dp[i][j]);
                }
            }
        }

        if (ii % 2 == 0) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m / 2; ++j) {
                    swap(v[i][j], v[i][m - 1 - j]);
                }
            }
        } else {
            for (int i = 0; i < n / 2; ++i) {
                for (int j = 0; j < m; ++j) {
                    swap(v[i][j], v[n - 1 - i][j]);
                }
            }
        }
    }
    T = (T - 1) / 2;
    cout << T << '\n';
    queue<pair<int, int>> q;
    vector<vector<bool>> u(n, vector<bool>(m, false));
    vector<vector<int>> d(n, vector<int>(m, 1e8));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (v[i][j] == '.') {
                q.emplace(i, j);
                u[i][j] = true;
                d[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (v[i][j] == '.')
                continue;
            if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                q.emplace(i, j);
                u[i][j] = true;
                d[i][j] = 1;
            }
        }
    }
    auto check = [&](int i, int j) {
        if (i < 0 || j < 0 || i >= n || j >= m)
            return false;
        return true;
    };
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (dx == 0 && dy == 0)
                    continue;
                int i = x + dx, j = y + dy;
                if (check(i, j) && !u[i][j]) {
                    u[i][j] = true;
                    d[i][j] = d[x][y] + 1;
                    q.emplace(i, j);
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (d[i][j] > T) {
                v[i][j] = 'X';
            } else {
                v[i][j] = '.';
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << v[i] << '\n';
    }
    return 0;
}