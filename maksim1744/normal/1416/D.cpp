#pragma GCC optimize("Ofast")
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
    created: 27.09.2020 18:42:07
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

    int n, m, q;
    cin >> n >> m >> q;
    vector<int> p(n);
    cin >> p;
    --p;
    vector<int> pi(n);
    for (int i = 0; i < n; ++i) {
        pi[p[i]] = i;
    }
    vector<pair<int, int>> e(m);
    for (int i = 0; i < m; ++i) {
        cin >> e[i].first >> e[i].second;
        --e[i].first; --e[i].second;
        e[i].first = p[e[i].first];
        e[i].second = p[e[i].second];
    }
    vector<pair<int, int>> que(q);
    for (int i = 0; i < q; ++i) {
        cin >> que[i];
        que[i].second--;
        if (que[i].first == 1)
            que[i].second = p[que[i].second];
    }
    vector<bool> left(m, true);
    vector<bool> sth(m, false);
    for (int i = 0; i < q; ++i) {
        if (que[i].first == 2) {
            left[que[i].second] = false;
        }
    }
    vector<pair<int, int>> events(q, mp(-1, -1));
    vector<set<int>> sets;

    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        if (left[i]) {
            g[e[i].first].pb(e[i].second);
            g[e[i].second].pb(e[i].first);
        }
    }
    vector<int> u(n, -1);
    int step = 0;
    function<void(int)> dfs = [&](int v) {
        u[v] = step;
        for (auto k : g[v]) {
            if (u[k] == -1) {
                dfs(k);
            }
        }
    };
    for (int i = 0; i < n; ++i) {
        if (u[i] == -1) {
            dfs(i);
            ++step;
        }
    }
    sets.resize(step);
    vector<int> where(n);
    for (int i = 0; i < n; ++i) {
        sets[u[i]].insert(i);
        where[i] = u[i];
    }

    auto un = [&](int i1, int i2) {
        if (sets[i1].size() < sets[i2].size()) swap(i1, i2);
        for (auto k : sets[i2]) {
            sets[i1].insert(k);
            where[k] = i1;
        }
        return mp(i2, i1);
    };
    for (int i = q - 1; i >= 0; --i) {
        if (que[i].first == 1) continue;
        auto [u, v] = e[que[i].second];
        if (where[u] != where[v]) {
            events[i] = un(where[u], where[v]);
        }
    }

    set<int> dead;

    for (int i = 0; i < q; ++i) {
        if (que[i].first == 1) {
            int v = que[i].second;
            if (sets[where[v]].empty()) {
                cout << 0 << '\n';
            } else {
                int ans = *prev(sets[where[v]].end());
                cout << ans + 1 << '\n';
                sets[where[v]].erase(ans);
                dead.insert(ans);
            }
        } else {
            auto [from, to] = events[i];
            if (from == -1) continue;
            for (auto v : sets[from]) {
                sets[to].erase(v);
                where[v] = from;
            }
            auto it = sets[from].begin();
            while (it != sets[from].end()) {
                auto it1 = next(it);
                if (dead.count(*it)) sets[from].erase(it);
                it = it1;
            }
        }
    }

    return 0;
}