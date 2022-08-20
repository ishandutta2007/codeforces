/*
    author:  Maksim1744
    created: 05.05.2021 17:55:12
*/

#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;

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

template<typename T>             vector<T>& operator--            (vector<T> &v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T> &v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>  v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U> &p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>  p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define SHOW_COLORS
#include "C:/C++ libs/print.cpp"
#else
#define show(...) void(0)
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#endif

const vector<pair<int, int>> D = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    ll w;
    cin >> n >> m >> w;
    vector<vector<ll>> a(n, vector<ll>(m));
    cin >> a;

    const int inf = 1e9;
    auto get_dist = [&](pair<int, int> p) {
        vector<vector<int>> d(n, vector<int>(m, inf));
        d[p.first][p.second] = 0;
        queue<pair<int, int>> q;
        q.emplace(p);
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (auto [dx, dy] : D) {
                int x1 = x + dx, y1 = y + dy;
                if (x1 < 0 || y1 < 0 || x1 >= n || y1 >= m) continue;
                if (a[x1][y1] == -1) continue;
                if (d[x1][y1] <= d[x][y] + 1) continue;
                d[x1][y1] = d[x][y] + 1;
                q.emplace(x1, y1);
            }
        }
        return d;
    };

    auto d1 = get_dist({0, 0});
    auto d2 = get_dist({n - 1, m - 1});
    ll ans = 1e18;
    if (d1[n - 1][m - 1] != inf)
        ans = d1[n - 1][m - 1] * w;

    ll min1 = 1e18;
    ll min2 = 1e18;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] > 0 && d1[i][j] != inf) {
                min1 = min(min1, a[i][j] + d1[i][j] * w);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] > 0 && d2[i][j] != inf) {
                min2 = min(min2, a[i][j] + d2[i][j] * w);
            }
        }
    }

    ans = min(ans, min1 + min2);

    if (ans > 1e16) {
        ans = -1;
    }
    cout << ans << '\n';

    return 0;
}