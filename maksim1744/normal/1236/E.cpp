/*
    author:  Maksim1744
    created: 17.10.2019 17:31:40
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
    int n, m;
    cin >> n >> m;
    if (n == 1) {
        cout << 0 << '\n';
        return 0;
    }
    vector<int> a(m);
    cin >> a;
    --a;
    vector<pair<int, int>> obst(m);
    for (int i = 0; i < m; ++i) {
        obst[i] = {i + 1, a[i]};
    }
    vector<ll> lb(n, 0);
    vector<ll> rb(n, 0);
    {
        vector<vector<pair<int, int>>> byd(n + m + 1);
        for (int i = 0; i < m; ++i) {
            byd[obst[i].first + obst[i].second].pb(obst[i]);
        }
        for (int i = 0; i < n + m + 1; ++i) {
            sort(byd[i].begin(), byd[i].end());
        }
        // show(byd);
        int x = 0, y = n - 1;
        deque<pair<pair<int, int>, pair<int, int>>> path;
        while (x != m + 1 && y > 0) {
            // show(x, y);
            auto ind = lowb(byd[x + y], mp(x, -1));
            int d = 0;
            if (ind == byd[x + y].size()) {
                d = min(y, m + 1 - x);
                path.eb(mp(x, y), mp(x + d, y - d));
                x += d;
                y -= d;
            } else {
                d = min(y, byd[x + y][ind].first - x - 1);
                path.eb(mp(x, y), mp(x + d, y - d));
                ++x;
                x += d;
                y -= d;
            }
        }
        lb[n - 1] = max(0, y);
        // show(path);
        auto has = [](deque<pair<pair<int, int>, pair<int, int>>>& path, pair<int, int> pos) {
            auto ind = lowb(path, mp(mp(pos.first, -1), mp(-1, -1)));
            // showt(pos, path, ind);
            if (ind == path.size())
                return -1;
            if (path[ind].first.first == pos.first) {
                if (path[ind].first == pos)
                    return 1;
                else
                    return -1;
            }
            --ind;
            if (ind < 0)
                return -1;
            if (path[ind].first.first - pos.first == path[ind].first.second - pos.second)
                return 1;
            else
                return -1;
        };
        for (int i = n - 2; i >= 0; --i) {
            int x = 0, y = i;
            deque<pair<pair<int, int>, pair<int, int>>> new_path;
            int intersects = -1;
            while (x != m + 1 && y > 0) {
                // show(x, y);
                auto ind = lowb(byd[x + y], mp(x, -1));
                int d = 0;
                if (ind == byd[x + y].size()) {
                    d = min(y, m + 1 - x);
                    new_path.eb(mp(x, y), mp(x + d, y - d));
                    x += d;
                    y -= d;
                } else {
                    d = min(y, byd[x + y][ind].first - x - 1);
                    new_path.eb(mp(x, y), mp(x + d, y - d));
                    ++x;
                    x += d;
                    y -= d;
                }
                int u = has(path, mp(x, y));
                if (u != -1) {
                    intersects = u;
                    break;
                }
            }
            if (intersects != -1) {
                lb[i] = lb[i + 1];
                // int ind = 0;
                while (path[0].first.first < x) {
                    if (path[0].second.first < x) {
                        path.pop_front();
                    } else {
                        int d = x - path[0].first.first;
                        path[0].first.first += d;
                        path[0].first.second += d;
                    }
                }
                if (path[0].first.first > path[0].second.first)
                    path.pop_front();
                for (int j = (int)new_path.size() - 1; j >= 0; --j) {
                    path.push_front(new_path[j]);
                }
            } else {
                if (new_path.empty())
                    lb[i] = 0;
                else
                    lb[i] = new_path.back().second.second;
                path = new_path;
            }
            // show(new_path, path);
        }
    }
    for (int i = 0; i < obst.size(); ++i) {
        obst[i].second = n - 1 - obst[i].second;
    }
    {
        vector<vector<pair<int, int>>> byd(n + m + 1);
        for (int i = 0; i < m; ++i) {
            byd[obst[i].first + obst[i].second].pb(obst[i]);
        }
        for (int i = 0; i < n + m + 1; ++i) {
            sort(byd[i].begin(), byd[i].end());
        }
        // show(byd);
        int x = 0, y = n - 1;
        deque<pair<pair<int, int>, pair<int, int>>> path;
        while (x != m + 1 && y > 0) {
            // show(x, y);
            auto ind = lowb(byd[x + y], mp(x, -1));
            int d = 0;
            if (ind == byd[x + y].size()) {
                d = min(y, m + 1 - x);
                path.eb(mp(x, y), mp(x + d, y - d));
                x += d;
                y -= d;
            } else {
                d = min(y, byd[x + y][ind].first - x - 1);
                path.eb(mp(x, y), mp(x + d, y - d));
                ++x;
                x += d;
                y -= d;
            }
        }
        rb[n - 1] = max(0, y);
        // show(path);
        auto has = [](deque<pair<pair<int, int>, pair<int, int>>>& path, pair<int, int> pos) {
            auto ind = lowb(path, mp(mp(pos.first, -1), mp(-1, -1)));
            // showt(pos, path, ind);
            if (ind == path.size())
                return -1;
            if (path[ind].first.first == pos.first) {
                if (path[ind].first == pos)
                    return 1;
                else
                    return -1;
            }
            --ind;
            if (ind < 0)
                return -1;
            if (path[ind].first.first - pos.first == path[ind].first.second - pos.second)
                return 1;
            else
                return -1;
        };
        for (int i = n - 2; i >= 0; --i) {
            int x = 0, y = i;
            deque<pair<pair<int, int>, pair<int, int>>> new_path;
            int intersects = -1;
            while (x != m + 1 && y > 0) {
                // show(x, y);
                auto ind = lowb(byd[x + y], mp(x, -1));
                int d = 0;
                if (ind == byd[x + y].size()) {
                    d = min(y, m + 1 - x);
                    new_path.eb(mp(x, y), mp(x + d, y - d));
                    x += d;
                    y -= d;
                } else {
                    d = min(y, byd[x + y][ind].first - x - 1);
                    new_path.eb(mp(x, y), mp(x + d, y - d));
                    ++x;
                    x += d;
                    y -= d;
                }
                int u = has(path, mp(x, y));
                if (u != -1) {
                    intersects = u;
                    break;
                }
            }
            if (intersects != -1) {
                rb[i] = rb[i + 1];
                // int ind = 0;
                while (path[0].first.first < x) {
                    if (path[0].second.first < x) {
                        path.pop_front();
                    } else {
                        int d = x - path[0].first.first;
                        path[0].first.first += d;
                        path[0].first.second += d;
                    }
                }
                if (path[0].first.first > path[0].second.first)
                    path.pop_front();
                for (int j = (int)new_path.size() - 1; j >= 0; --j) {
                    path.push_front(new_path[j]);
                }
            } else {
                if (new_path.empty())
                    rb[i] = 0;
                else
                    rb[i] = new_path.back().second.second;
                path = new_path;
            }
            // show(new_path, path);
        }
    }
    vector<ll> rb1(n);
    for (int i = 0; i < n; ++i) {
        rb1[i] = n - 1 - rb[n - 1 - i];
    }
    swap(rb1, rb);
    // show(rb);
    // show(lb);
    ll res = 0;
    for (int i = 0; i < n; ++i) {
        res += rb[i] - lb[i] + 1;
    }
    cout << res << '\n';
    return 0;
}