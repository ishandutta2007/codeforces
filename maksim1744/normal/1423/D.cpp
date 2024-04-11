/*
    author:  Maksim1744
    created: 08.05.2021 20:05:14
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

template<typename T>
using pq = priority_queue<T, vector<T>, greater<T>>;

const vector<pair<int, int>> D = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}, {0, 0}};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    int k, t, w;
    cin >> k >> t >> w;
    vector<vector<char>> v(n, vector<char>(m));
    cin >> v;
    vector<char> day(w);
    cin >> day;

    vector<vector<int>> res_time(n, vector<int>(m, -1));
    for (int i = 0; i < t; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        assert(res_time[a][b] == -1);
        res_time[a][b] = c;
    }

    const int inf = 1e9;
    vector d(n, vector(m, vector<int>(k + 1, inf)));
    pair<int, int> st, fin;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (v[i][j] == 'M') {
                st = {i, j};
                v[i][j] = 'S';
            } else if (v[i][j] == 'P') {
                fin = {i, j};
                v[i][j] = 'S';
            }
        }
    }

    d[st.first][st.second][0] = 0;
    pq<pair<int, tuple<int, int, int>>> s;
    s.emplace(0, make_tuple(st.first, st.second, 0));

    auto can = [&](int x1, int y1, int x2, int y2) {
        if (x1 < 0 || x2 < 0 || x1 >= n || x2 >= n) return false;
        if (y1 < 0 || y2 < 0 || y1 >= m || y2 >= m) return false;
        if (v[x2][y2] != 'S') return false;
        if (abs(x1 - x2) + abs(y1 - y2) <= 1) return true;
        if (x1 == x2) return v[x1][(y1 + y2) / 2] == 'S';
        if (y1 == y2) return v[(x1 + x2) / 2][y1] == 'S';
        return v[x1][y2] == 'S' || v[x2][y1] == 'S';
    };

    while (!s.empty()) {
        auto [dd, p] = s.top();
        s.pop();
        auto [x, y, dk] = p;
        if (d[x][y][dk] < dd) continue;
        if (dd >= day.size()) continue;
        int x0 = x, y0 = y;
        if (day[dd] == 'C') {
        } else if (day[dd] == 'N') {
            --x;
        } else if (day[dd] == 'S') {
            ++x;
        } else if (day[dd] == 'E') {
            ++y;
        } else {
            --y;
        }
        if (dk != k) {
            for (auto [dx, dy] : D) {
                int x1 = x + dx;
                int y1 = y + dy;
                if (!can(x0, y0, x1, y1)) continue;
                if (dd + 1 >= d[x1][y1][dk + 1]) continue;
                d[x1][y1][dk + 1] = dd + 1;
                s.emplace(d[x1][y1][dk + 1], make_tuple(x1, y1, dk + 1));
                if (res_time[x1][y1] != -1 && res_time[x1][y1] > dd) {
                    if (d[x1][y1][0] > res_time[x1][y1]) {
                        d[x1][y1][0] = res_time[x1][y1];
                        s.emplace(d[x1][y1][0], make_tuple(x1, y1, 0));
                    }
                }
            }
        }
    }
    int ans = mine(d[fin.first][fin.second]);
    if (ans == inf) ans = -1;
    cout << ans << '\n';

    return 0;
}