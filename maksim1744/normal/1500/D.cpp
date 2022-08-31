#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("unswitch-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("rename-registers")
#pragma GCC optimize("move-loop-invariants")
#pragma GCC optimize("function-sections")
#pragma GCC optimize("data-sections")
#pragma GCC optimize("branch-target-load-optimize")
#pragma GCC optimize("branch-target-load-optimize2")
#pragma GCC optimize("btr-bb-exclusive")
#pragma GCC target("sse2")
#pragma GCC target("sse3")
#pragma GCC target("sse4.1")
#pragma GCC target("sse4.2")
#pragma GCC target("popcnt")
#pragma GCC target("abm")
#pragma GCC target("mmx")
#pragma GCC target("tune=native")

/*
    author:  Maksim1744
    created: 13.03.2021 14:26:55
*/

#include "bits/stdc++.h"

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
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define SHOW_COLORS
#include "C:/C++ libs/print.cpp"
#else
#define show(...)     42
#define mclock        42
#define shows         42
#define debug if (false)
#endif

array<array<int, 1600>, 1600> a;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, q;
    cin >> n >> q;
    // vector<vector<int>> a(n, vector<int>(n));
    // cin >> a;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> best(n, vector<int>(n));
    vector<vector<vector<pair<int, int>>>> sq_colors(n, vector<vector<pair<int, int>>>(n));
    vector<vector<pair<int, int>>> col_colors(n);
    vector<pair<int, int>> row_colors;
    for (int i = 0; i < n; ++i) {
        best[0][i] = 1;
        col_colors[i].eb(1, a[0][i]);
        sq_colors[0][i].eb(1, a[0][i]);
    }

    auto ad = [&](vector<pair<int, int>> &v, int p) {
        v.insert(v.begin(), mp(1, p));
        for (int k = 1; k < v.size(); ++k) {
            if (v[k].second == p) {
                v.erase(v.begin() + k);
                break;
            }
        }
        if (v.size() > q + 1)
            v.resize(q + 1);
    };

    show(col_colors);
    vector<int> inds;
    vector<int> gd;

    for (int i = 1; i < n; ++i) {
        row_colors.clear();
        row_colors.eb(1, a[i][0]);
        if (i >= 2) {
            sq_colors[i - 2].clear();
            sq_colors[i - 2].shrink_to_fit();
        }
        best[i][0] = 1;
        sq_colors[i][0].eb(1, a[i][0]);
        for (int j = 1; j < n; ++j) {
            shows;
            for (auto &p : col_colors[j])
                p.first++;
            ad(col_colors[j], a[i][j]);
            for (auto &p : row_colors)
                p.first++;
            set<int> s;
            for (auto &p : sq_colors[i - 1][j - 1])
                p.first++;
            vector<vector<pair<int, int>>*> vs = {
                &col_colors[j],
                &row_colors,
                &sq_colors[i - 1][j - 1],
            };
            inds.assign(3, 0);
            gd.clear();
            bool found = false;
            show(i, j);
            show(vs);
            while (true) {
                gd.clear();
                for (int i = 0; i < 3; ++i) {
                    if (inds[i] == vs[i]->size()) continue;
                    gd.pb(i);
                }
                if (gd.empty()) break;
                int ii = gd[0];
                for (int i = 0; i < gd.size(); ++i) {
                    if ((*vs[gd[i]])[inds[gd[i]]].first < (*vs[ii])[inds[ii]].first)
                        ii = gd[i];
                }
                if (s.count((*vs[ii])[inds[ii]].second)) {
                    ++inds[ii];
                    continue;
                }
                s.insert((*vs[ii])[inds[ii]].second);
                if (s.size() > q) {
                    best[i][j] = (*vs[ii])[inds[ii]].first - 1;
                    found = true;
                    break;
                }
                sq_colors[i][j].eb((*vs[ii])[inds[ii]]);
            }
            if (!found) {
                best[i][j] = best[i - 1][j - 1] + 1;
            }
            best[i][j] = min(best[i][j], best[i - 1][j - 1] + 1);
            while (!sq_colors[i][j].empty() && sq_colors[i][j].back().first > best[i][j])
                sq_colors[i][j].pop_back();

            show(sq_colors[i][j]);

            ad(row_colors, a[i][j]);
        }
    }

    show(sq_colors);

    show(best);
    vector<int> ans(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ans[best[i][j]]++;
        }
    }
    for (int i = n; i >= 1; --i)
        ans[i - 1] += ans[i];

    for (int i = 1; i <= n; ++i)
        cout << ans[i] << '\n';

    return 0;
}