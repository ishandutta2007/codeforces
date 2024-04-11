/*
    author:  Maksim1744
    created: 30.09.2020 00:40:48
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

const vector<pair<int, int>> D = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
const string SD = "UDRL";

bool matching_dfs(int v, vector<vector<int>>& g, vector<int>& from, vector<bool>& u) {
    u[v] = true;
    for (auto k : g[v]) {
        if (from[k] == -1 || (!u[from[k]] && matching_dfs(from[k], g, from, u))) {
            from[k] = v;
            return true;
        }
    }
    return false;
}

vector<pair<int, int>> find_matching(vector<vector<int>>& g, vector<int> a) {
    bool rev = false;
    // if (2 * a.size() > g.size()) {
    //     rev = true;
    //     vector<bool> has(g.size(), false);
    //     for (auto v : a)
    //         has[v] = true;
    //     a.clear();
    //     a.reserve(g.size() - a.size());
    //     for (int i = 0; i < g.size(); ++i)
    //         if (!has[i])
    //             a.push_back(i);
    // }
    vector<bool> u(g.size(), false);
    vector<int> from(g.size(), -1);
    for (auto v : a)
        if (matching_dfs(v, g, from, u))
            u.assign(g.size(), false);
    vector<pair<int, int>> result;
    for (int v = 0; v < from.size(); ++v) {
        if (from[v] != -1) {
            if (rev) result.emplace_back(v, from[v]);
            else result.emplace_back(from[v], v);
        }
    }
    return result;
}

void test_case(int test) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> sm(n, vector<int>(m));
    cin >> sm;

    vector<string> dirs(n, string(m, '.'));

    auto check = [&](int i, int j) {
        return i >= 0 && j >= 0 && i < n && j < m;
    };

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < 4; ++k) {
                if (check(i + D[k].first, j + D[k].second) && sm[i + D[k].first][j + D[k].second] < sm[i][j]) {
                    dirs[i][j] = SD[k];
                    break;
                }
            }
        }
    }

    set<int> bad;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (dirs[i][j] == '.')
                bad.insert(sm[i][j]);
        }
    }

    printMatrix(dirs);

    map<int, vector<pair<int, int>>> al;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (bad.count(sm[i][j])) {
                al[sm[i][j]].eb(i, j);
            }
        }
    }

    vector<vector<int>> num(n, vector<int>(m, -1));

    show(al);

    vector<vector<int>> vals(n, vector<int>(m, 0));

    for (auto [k, p] : al) {
        int x = 0;
        sort(p.begin(), p.end(), [&](const pair<int, int> &a, const pair<int, int> &b) {
            return dirs[a.first][a.second] == '.' && dirs[b.first][b.second] != '.';
        });
        for (auto [u, v] : p) {
            num[u][v] = x;
            ++x;
        }
        vector<vector<int>> g(x);
        for (auto [i, j] : p) {
            for (auto [di, dj] : D) {
                if (check(i + di, j + dj) && sm[i + di][j + dj] == sm[i][j])
                    g[num[i][j]].pb(num[i + di][j + dj]);
            }
        }

        vector<int> l, r;
        vector<pair<int, int>> pl, pr;
        int needl = 0, needr = 0;
        for (auto [i, j] : p) {
            if ((i + j) % 2 == 0) {
                l.pb(num[i][j]);
                if (dirs[i][j] == '.') ++needl;
                pl.eb(i, j);
            } else {
                r.pb(num[i][j]);
                if (dirs[i][j] == '.') ++needr;
                pr.eb(i, j);
            }
        }

        if (k == 3) {
            show(pl);
            show(pr);
        }

        vector<bool> ul(l.size(), false), ur(r.size(), false);
        auto m1 = find_matching(g, l);
        for (auto [u, v] : m1) {
            ul[lowb(l, u)] = true;
        }
        for (int i = 0; i < needl; ++i) {
            if (!ul[i]) {
                cout << "NO\n";
                return;
            }
        }
        auto m2 = find_matching(g, r);
        for (auto [u, v] : m2) {
            ur[lowb(r, u)] = true;
        }
        for (int i = 0; i < needr; ++i) {
            if (!ur[i]) {
                cout << "NO\n";
                return;
            }
        }

        vector<vector<int>> g1(g.size());

        for (auto k : l) {
            for (auto u : g[k]) {
                if (ul[lowb(l, k)] && ur[lowb(r, u)])
                    g1[k].pb(u);
            }
        }
        for (auto k : r) {
            for (auto u : g[k]) {
                if (ul[lowb(l, u)] && ur[lowb(r, k)])
                    g1[k].pb(u);
            }
        }

        auto m3 = find_matching(g1, l);

        for (auto [a, b] : m3) {
            auto p1 = pl[lowb(l, a)], p2 = pr[lowb(r, b)];
            for (int k = 0; k < 4; ++k) {
                if (p1 + D[k] == p2) {
                    dirs[p1.first][p1.second] = SD[k];
                    dirs[p2.first][p2.second] = SD[k ^ 1];
                    vals[p1.first][p1.second] = 1;
                    vals[p2.first][p2.second] = sm[p1.first][p1.second] - 1;
                    break;
                }
            }
        }
        if (k == 3) {
            show(l);
            show(r);
            show(g);
            show(g1);
            show(m1);
            show(m2);
            show(m3);
        }
    }
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < m; ++j) {
    //         if (dirs[i][j] == '.') {
    //             cout << "NO\n";
    //             return;
    //         }
    //     }
    // }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (vals[i][j] == 0) {
                for (int k = 0; k < 4; ++k) {
                    if (SD[k] == dirs[i][j]) {
                        vals[i][j] = sm[i][j] - sm[i + D[k].first][j + D[k].second];
                        break;
                    }
                }
            }
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << vals[i][j] << ' ';
        }
        cout << '\n';
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << dirs[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        test_case(test);
    }

    return 0;
}