/*
    author:  Maksim1744
    created: 18.05.2021 14:05:09
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

template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};
template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
// auto gcd = std::y_combinator([](auto gcd, int a, int b) -> int {
//     return b == 0 ? a : gcd(b, a % b);
// });

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int m;
    cin >> m;
    vector<int> a(m);
    cin >> a;
    vector<int> point(m);
    cin >> point;
    --point;

    {
        int p = 1;
        for (int k : a)
            p *= k;
        if (p % 2 == 1 && sum(point) % 2 == 1) {
            cout << "No\n";
            return 0;
        }
    }
    {
        if (m == 1 && point[0] != 0 && point[0] != a[0] - 1) {
            cout << "No\n";
            return 0;
        }
    }

    auto build_2d_cycle = [&](int n, int m, int who = -1) {
        if (who == -1) {
            if (n % 2 == 0) who = 0;
            else who = 1;
        }
        if (who == 0) {
            assert(n % 2 == 0);
            vector<pair<int, int>> cyc;
            for (int i = 0; i < n; ++i) {
                if (i % 2 == 0)
                    for (int j = 1; j < m; ++j)
                        cyc.eb(i, j);
                else
                    for (int j = m - 1; j >= 1; --j)
                        cyc.eb(i, j);
            }
            for (int i = n - 1; i >= 0; --i)
                cyc.eb(i, 0);
            return cyc;
        } else {
            assert(m % 2 == 0);
            vector<pair<int, int>> cyc;
            for (int j = 0; j < m; ++j) {
                if (j % 2 == 0)
                    for (int i = 1; i < n; ++i)
                        cyc.eb(i, j);
                else
                    for (int i = n - 1; i >= 1; --i)
                        cyc.eb(i, j);
            }
            for (int i = m - 1; i >= 0; --i)
                cyc.eb(0, i);
            return cyc;
        }
    };

    auto build_path = y_combinator([&](auto build_path, vector<int> a, vector<int> pt) -> vector<vector<int>> {
        if (a.size() == 1) {
            if (pt[0] != 0 && pt[0] != a[0] - 1) assert(false);
            vector<vector<int>> res;
            for (int i = 0; i < a[0]; ++i) {
                if (pt[0] == 0) res.pb({i});
                else res.pb({a[0] - i - 1});
            }
            return res;
        }
        vector<vector<vector<int>>> coords(a[0]);
        for (int i = 0; i < a[0]; ++i) {
            for (int j = 0; j < a[1]; ++j) {
                coords[i].pb({i, j});
            }
        }
        for (int k = 2; k < a.size(); ++k) {
            int s = coords[0].size();
            for (int i = 0; i < coords.size(); ++i) {
                for (int j = 0; j < coords[i].size(); ++j) {
                    coords[i][j].pb(0);
                }
            }
            for (int d = 1; d < a[k]; ++d) {
                for (int i = 0; i < coords.size(); ++i) {
                    for (int j = 0; j < s; ++j) {
                        coords[i].pb(d % 2 == 1 ? coords[i][s - j - 1] : coords[i][j]);
                        coords[i].back().back() = d;
                    }
                }
            }
        }
        {
            int n = coords.size();
            int m = coords[0].size();
            int x = -1, y = -1;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (coords[i][j] == pt) {
                        assert(x == -1);
                        x = i;
                        y = j;
                    }
                }
            }
            assert(x != -1);
            vector<pair<int, int>> path;
            if (n % 2 == 0 || m % 2 == 0) {
                auto cyc = build_2d_cycle(n, m);
                int ind = -1;
                for (int i = 0; i < cyc.size(); ++i) {
                    if (cyc[i] == mp(x, y))
                        ind = i;
                }
                assert(ind != -1);
                for (int i = 0; i < cyc.size(); ++i) {
                    path.pb(cyc[(i + ind) % cyc.size()]);
                }
            } else {
                auto get_ans = y_combinator([&](auto get_ans, int n, int m, int x, int y) -> vector<pair<int, int>> {
                    if (n > 3 && x > 1) {
                        int d = x / 2;
                        if (n - d * 2 == 1) --d;
                        auto res = get_ans(n - d * 2, m, x - d * 2, y);
                        auto cyc = build_2d_cycle(d * 2, m, 0);
                        show(n, m, x, y);
                        for (int i = 0; i + 1 < res.size(); ++i) {
                            if (res[i].first == 0 && res[i + 1].first == 0) {
                                if (res[i].second > res[i + 1].second) {
                                    reverse(cyc.begin(), cyc.end());
                                }
                                for (auto &p : res)
                                    p.first += d * 2;
                                int ij = -1;
                                for (int j = 1; j < cyc.size(); ++j) {
                                    if (cyc[j].second == res[i].second && cyc[j - 1].second == res[i + 1].second && cyc[j].first == d * 2 - 1) {
                                        ij = j;
                                        break;
                                    }
                                }
                                assert(ij != -1);
                                vector<pair<int, int>> ans;
                                for (int j = 0; j < i + 1; ++j) {
                                    ans.pb(res[j]);
                                }
                                for (int i = 0; i < cyc.size(); ++i) {
                                    ans.pb(cyc[(i + ij) % cyc.size()]);
                                }
                                for (int j = i + 1; j < res.size(); ++j)
                                    ans.pb(res[j]);
                                show(ans);
                                return ans;
                            }
                        }
                        assert(false);
                    } else if (n > 3 && x + 2 <= n - 1) {
                        int d = (n - x - 1) / 2;
                        if (x == 0) --d;
                        auto res = get_ans(n - d * 2, m, x, y);
                        auto cyc = build_2d_cycle(d * 2, m, 0);
                        show(n, m, x, y);
                        show(res);
                        cyc.insert(cyc.begin(), cyc.back());
                        cyc.pop_back();
                        for (int i = 0; i + 1 < res.size(); ++i) {
                            if (res[i].first == n - d * 2 - 1 && res[i + 1].first == n - d * 2 - 1) {
                                if (res[i].second < res[i + 1].second) {
                                    reverse(cyc.begin(), cyc.end());
                                }
                                int ij = -1;
                                for (int j = 1; j < cyc.size(); ++j) {
                                    if (cyc[j].second == res[i].second && cyc[j - 1].second == res[i + 1].second && cyc[j].first == 0) {
                                        ij = j;
                                        break;
                                    }
                                }
                                assert(ij != -1);
                                vector<pair<int, int>> ans;
                                for (int j = 0; j < i + 1; ++j) {
                                    ans.pb(res[j]);
                                }
                                for (auto &p : cyc)
                                    p.first += n - d * 2;
                                for (int i = 0; i < cyc.size(); ++i) {
                                    ans.pb(cyc[(i + ij) % cyc.size()]);
                                }
                                for (int j = i + 1; j < res.size(); ++j)
                                    ans.pb(res[j]);
                                show(ans);
                                return ans;
                            }
                        }
                        assert(false);
                    } else if (n != 3 || m != 3) {
                        swap(n, m);
                        swap(x, y);
                        auto path = get_ans(n, m, x, y);
                        for (auto &p : path)
                            swap(p.first, p.second);
                        return path;
                    } else {
                        assert(n == 3 && m == 3);
                        vector<vector<bool>> u(3, vector<bool>(3, false));
                        vector<pair<int, int>> ans;
                        int dx = 0, dy = 1;
                        while (ans.size() < 9) {
                            ans.eb(x, y);
                            u[x][y] = true;
                            if (ans.size() == 9) break;
                            while (true) {
                                if (x + dx >= 0 && x + dx < 3 && y + dy >= 0 && y + dy < 3 && !u[x + dx][y + dy]) {
                                    x += dx;
                                    y += dy;
                                    break;
                                } else {
                                    swap(dx, dy);
                                    dy *= -1;
                                }
                            }
                        }
                        show(ans);
                        return ans;
                    }
                    return {};
                });
                path = get_ans(n, m, x, y);
                show(path);
            }
            vector<vector<int>> res;
            for (auto [x, y] : path)
                res.pb(coords[x][y]);
            auto er = res;
            show(a, pt);
            sort(er.begin(), er.end());
            er.erase(unique(er.begin(), er.end()), er.end());
            assert(er.size() == res.size());
            return res;
        }
        return {};
    });

    auto build_cycle = [&](vector<int> a) -> vector<vector<int>> {
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] % 2 == 0 && a.size() != 1) {
                vector<int> b = a;
                b.erase(b.begin() + i);
                auto path = build_path(b, vector<int>(b.size(), 0));
                path.erase(path.begin());
                int d = a[i];
                vector<vector<int>> result;
                for (int j = 0; j < d; ++j) {
                    for (auto v : path) {
                        v.insert(v.begin() + i, j);
                        result.pb(v);
                    }
                    reverse(path.begin(), path.end());
                }
                for (int j = d - 1; j >= 0; --j) {
                    vector<int> v(a.size(), 0);
                    v[i] = j;
                    result.pb(v);
                }
                return result;
            }
        }
        return {};
    };

    vector<vector<int>> path;

    path = build_cycle(a);
    show(path);
    if (!path.empty()) {
        int ind = -1;
        for (int i = 0; i < path.size(); ++i) {
            if (path[i] == point)
                ind = i;
        }
        assert(ind != -1);
        vector<vector<int>> tmp;
        for (int i = 0; i < path.size(); ++i) {
            tmp.pb(path[(i + ind) % path.size()]);
        }
        swap(path, tmp);
        path.pb(path[0]);
        cout << "Cycle\n";
    } else {
        path = build_path(a, point);
        if (m == 1 && a[0] == 2) {
            cout << "Cycle\n";
            path.pb(path[0]);
        } else {
            cout << "Path\n";
        }
    }

    show(path);
    for (int i = 1; i < path.size(); ++i) {
        int ind = 0;
        while (path[i][ind] == path[i - 1][ind])
            ++ind;
        if (path[i][ind] > path[i - 1][ind]) cout << "inc ";
        else cout << "dec ";
        cout << ind + 1 << '\n';
    }

    return 0;
}