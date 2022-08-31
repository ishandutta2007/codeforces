/*
    author:  Maksim1744
    created: 17.12.2019 19:04:56
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
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].pb(b);
        g[b].pb(a);
    }

    vector<pair<int, int>> maxd(n, {0, 0});
    vector<int> dup(n, 0);
    vector<bool> u(n, false);

    vector<vector<int>> ds(n);

    function<void(int)> dfs1 = [&](int v) {
        u[v] = true;
        for (auto k : g[v]) {
            if (!u[k]) {
                dfs1(k);
                int d = maxd[k].first + 1;
                ds[v].pb(d);
                if (d >= maxd[v].first) {
                    maxd[v].second = maxd[v].first;
                    maxd[v].first = d;
                } else if (d > maxd[v].second) {
                    maxd[v].second = d;
                }
            }
        }
    };
    dfs1(0);

    u.assign(n, false);
    function<void(int, int)> dfs2 = [&](int v, int p) {
        u[v] = true;
        if (p != -1) {
            dup[v] = dup[p] + 1;
            if (maxd[v].first + 1 == maxd[p].first)
                dup[v] = max(dup[v], maxd[p].second + 1);
            else
                dup[v] = max(dup[v], maxd[p].first + 1);
            ds[v].pb(dup[v]);
        }
        for (auto k : g[v]) {
            if (!u[k]) {
                dfs2(k, v);
            }
        }
    };
    dfs2(0, -1);

    vector<int> ans(n * 2 + 25, 1);

    for (int i = 0; i < n; ++i) {
        ans[1] = max(ans[1], (int)g[i].size() + 1);
    }

    vector<vector<pair<int, int>>> dsc(n);

    for (int i = 0; i < n; ++i) {
        sort(ds[i].begin(), ds[i].end());
        for (int j = 0; j < ds[i].size(); ++j) {
            if (j == 0 || ds[i][j] != ds[i][j - 1])
                dsc[i].eb(ds[i][j], 0);
            dsc[i].back().second++;
        }
    }
    // show(dsc);

    u.assign(n, false);
    function<void(int)> dfs3 = [&](int v) {
        u[v] = true;
        for (auto k : g[v]) {
            if (!u[k]) {
                dfs3(k);
                vector<pair<int, int>> cnt;
                int i1 = 0, i2 = 0;
                while (i1 < dsc[v].size() || i2 < dsc[k].size()) {
                    if (i1 == dsc[v].size()) {
                        cnt.pb(dsc[k][i2]);
                        ++i2;
                    } else if (i2 == dsc[k].size()) {
                        cnt.pb(dsc[v][i1]);
                        ++i1;
                    } else {
                        if (dsc[v][i1] < dsc[k][i2]) {
                            cnt.pb(dsc[v][i1]);
                            ++i1;
                        } else if (dsc[v][i1] > dsc[k][i2]) {
                            cnt.pb(dsc[k][i2]);
                            ++i2;
                        } else {
                            cnt.pb(dsc[v][i1]);
                            cnt.back().second += dsc[k][i2].second;
                            ++i1;
                            ++i2;
                        }
                    }
                }
                for (int i = 0; i < cnt.size(); ++i) {
                    if (cnt[i].first == maxd[k].first + 1) {
                        cnt[i].second--;
                        break;
                    }
                }
                for (int i = 0; i < cnt.size(); ++i) {
                    if (cnt[i].first == dup[k]) {
                        cnt[i].second--;
                        break;
                    }
                }
                for (int i = (int)cnt.size() - 2; i >= 0; --i) {
                    cnt[i].second += cnt[i + 1].second;
                }
                for (auto [d, c] : cnt)
                    ans[d * 2] = max(ans[d * 2], c);
            }
        }
    };
    dfs3(0);

    for (int v = 0; v < n; ++v) {
        for (int i = (int)dsc[v].size() - 2; i >= 0; --i) {
            dsc[v][i].second += dsc[v][i + 1].second;
        }
    }

    // show(maxd);
    // printTree(g);
    // show(dsc[1]);

    for (int v = 0; v < n; ++v) {
        for (int i = 0; i < dsc[v].size(); ++i) {
            int w = dsc[v][i].second + 1;
            if (i != 0 && dsc[v][i - 1].first + 1 == dsc[v][i].first)
                w = min(w, dsc[v][i - 1].second);
            else
                w = min(w, dsc[v][i].second);
            int x = 2 * dsc[v][i].first - 1;
            ans[x] = max(ans[x], w);
            x += 2;
            w = dsc[v][i].second;
            if (i + 1 != dsc[v].size())
                w = min(w, dsc[v][i + 1].second + 1);
            else
                w = 0;
            ans[x] = max(ans[x], w);
            x = 2 * dsc[v][i].first;
            ans[x] = max(ans[x], dsc[v][i].second);
        }
    }


    for (int i = n - 2; i >= 2; --i)
        ans[i] = max(ans[i], ans[i + 2]);

    for (int i = 0; i < n; ++i) {
        cout << ans[i + 1] << ' ';
    }
    cout << '\n';

    return 0;
}