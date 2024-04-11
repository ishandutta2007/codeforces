/*
    author:  Maksim1744
    created: 28.05.2021 03:39:05
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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    const int inf = 1e9 + 1e5;
    int n, m;
    cin >> n >> m;
    if (n == 1) {
        cout << 0 << '\n';
        return 0;
    }
    vector<vector<pair<int, pair<int, int>>>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v, l, r;
        cin >> u >> v >> l >> r;
        --u; --v;
        g[u].eb(v, mp(l, r));
        g[v].eb(u, mp(l, r));
    }

    show(g);

    vector<vector<vector<pair<int, int>>>> segs(n, vector<vector<pair<int, int>>>(2));
    vector<vector<vector<int>>> who(n, vector<vector<int>>(2));
    vector<vector<vector<int>>> d(n, vector<vector<int>>(2));
    int last = 0;
    for (int v = 0; v < n; ++v) {
        sort(g[v].begin(), g[v].end(), [&](const auto &a, const auto &b) {
            return a.second.first < b.second.first;
        });
        for (int e = 0; e < 2; ++e) {
            vector<pair<int, int>> seg;
            for (auto [k, lr] : g[v]) {
                auto [l, r] = lr;
                l += (l % 2 != e);
                r -= (r % 2 != e);
                if (l > r) continue;
                if (!seg.empty() && seg.back().second >= l)
                    seg.back().second = max(seg.back().second, r);
                else
                    seg.eb(l, r);
            }
            swap(segs[v][e], seg);
            for (int i = 0; i < segs[v][e].size(); ++i) {
                who[v][e].pb(last++);
                d[v][e].pb(inf);
            }
        }
    }

    show(segs);
    show(who);

    if (segs[0][0].empty() || segs[0][0][0].first != 0) {
        cout << -1 << '\n';
        return 0;
    }

    assert(who[0][0][0] == 0);
    d[0][0][0] = 0;

    pq<pair<int, tuple<int, int, int>>> s;
    s.emplace(0, make_tuple(0, 0, 0));

    while (!s.empty()) {
        auto [dd, tpl] = s.top();
        s.pop();
        auto [v, e, seg] = tpl;
        if (d[v][e][seg] != dd) continue;
        if (v == n - 1) {
            break;
            return 0;
        }
        show(v, e, seg, dd);
        auto [L, R] = segs[v][e][seg];
        int ind = lower_bound(g[v].begin(), g[v].end(), mp(-1, mp(L - 1, -1)), [&](const auto &a, const auto &b) {
            return a.second.first < b.second.first;
        }) - g[v].begin();
        show(ind);
        for (; ind < g[v].size(); ++ind) {
            if (g[v][ind].second.first > R) break;
            if (g[v][ind].second.second <= dd) continue;
            int k = g[v][ind].first;
            auto [l, r] = g[v][ind].second;
            l += (l % 2 != e);
            if (l > r) continue;
            int tm = max(dd, l) + 1;
            int to_ind = lower_bound(segs[k][e ^ 1].begin(), segs[k][e ^ 1].end(), mp(tm, -1)) - segs[k][e ^ 1].begin();
            if (to_ind == segs[k][e ^ 1].size() || segs[k][e ^ 1][to_ind].first > tm) --to_ind;
            show(k, to_ind, l, r, tm);
            if(to_ind >= 0 && to_ind < segs[k][e ^ 1].size() && segs[k][e ^ 1][to_ind].first <= tm && tm <= segs[k][e ^ 1][to_ind].second)
            if (d[k][e ^ 1][to_ind] > tm) {
                d[k][e ^ 1][to_ind] = tm;
                s.emplace(tm, make_tuple(k, e ^ 1, to_ind));
            }
        }
    }
    show(d);
    int ans = inf;
    for (int e = 0; e < 2; ++e) {
        for (int x : d[n - 1][e])
            umin(ans, x);
    }
    if (ans == inf) ans = -1;
    cout << ans << '\n';

    return 0;
}