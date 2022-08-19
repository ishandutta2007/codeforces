/*
    author:  Maksim1744
    created: 25.06.2022 18:03:45
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
#include "/mnt/c/Libs/tools/print.cpp"
#else
#define show(...) void(0)
#define debugf(fun)   fun
#define debugv(var)   var
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#define OSTREAM(...)    ;
#define OSTREAM0(...)   ;
#endif

const int N = 105;
array<array<array<int, N>, N>, N> d;
array<array<array<int, N>, N>, N> d2;

array<array<int, N>, N> dist;

void test_case(int test) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                d[i][j][k] = 0;
                d2[i][j][k] = 0;
            }
        }
    }

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            string s;
            cin >> s;
            for (int k = 0; k < s.size(); ++k) {
                d[i][i + j + 1][k] = s[k] - '0';
                d[i + j + 1][i][k] = s[k] - '0';
            }
        }
    }
    // if (test != 3) return;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                show(i, j, k, d[i][j][k]);
            }
        }
    }

    for (int to = 1; to < n; ++to) {
        vector<pair<int, int>> e;
        vector<int> with(n, -1);
        vector<bool> u(n, false);

        queue<int> q;

        q.push(0);
        q.push(to);

        auto add_edge = [&](int x, int y) {
            e.eb(x, y);
            u[x] = u[y] = true;
            with[x] = y;
            with[y] = x;
        };

        add_edge(0, to);

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            assert(with[v] != -1);

            for (int k = 0; k < n; ++k) {
                if (u[k]) continue;
                show(v, with[v], k, d[with[v]][k][v]);
                if (d[with[v]][k][v]) {
                    add_edge(v, k);
                    q.push(k);
                }
            }
        }

        if (count(u.begin(), u.end(), true) != n) continue;
        show(e);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dist[i][j] = 1e9;
            }
        }
        for (auto [u, v] : e)
            dist[u][v] = dist[v][u] = 1;
        for (int i = 0; i < n; ++i) {
            dist[i][i] = 0;
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                show(i, j, dist[i][j]);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                for (int k = 0; k < n; ++k) {
                    d2[i][j][k] = (dist[i][k] == dist[j][k]);
                    show(i, j, k, d2[i][j][k], d[i][j][k]);
                }
            }
        }

        bool ok = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (d[i][j][k] != d2[i][j][k]) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) break;
            }
            if (!ok) break;
        }

        if (!ok) continue;
        cout << "Yes\n";
        ++e;
        for (auto p : e)
            cout << p << '\n';
        return;
    }
    cout << "No\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        test_case(test);
    }

    return 0;
}