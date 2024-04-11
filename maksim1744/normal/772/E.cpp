/*
    author:  Maksim1744
    created: 08.08.2021 12:47:00
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
#include "/mnt/c/C++ libs/print.cpp"
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

    int n;
    cin >> n;

    int last = n + 1;
    int root = n;
    vector<vector<int>> g(n * 2 - 1);
    g[root].pb(0);
    g[root].pb(1);

    vector<int> sz(g.size(), 0);
    vector<bool> blocked(g.size(), false);
    vector<int> par(g.size(), -1);
    par[0] = par[1] = root;

    auto get_centroid = [&](int r) {
        sz.assign(g.size(), 0);
        y_combinator([&](auto dfs, int v) -> void {
            sz[v] = 1;
            for (int k : g[v]) {
                if (blocked[k]) continue;
                dfs(k);
                sz[v] += sz[k];
            }
        })(r);

        return y_combinator([&](auto dfs, int v, int ss) -> int {
            for (int k : g[v])
                if (!blocked[k] && sz[k] * 2 >= ss)
                    return dfs(k, ss);
            return v;
        })(r, sz[r]);
    };

    auto ask = [&](int x, int y, int z) {
        ++x; ++y; ++z;
        cout << x << ' ' << y << ' ' << z << endl;
        char c;
        cin >> c;
        return c;
    };

    auto get_size = y_combinator([&](auto get_size, int v) -> int {
        int res = 1;
        for (int k : g[v])
            if (!blocked[k])
                res += get_size(k);
        return res;
    });

    for (int leaf = 2; leaf < n; ++leaf) {
        show(leaf);
        blocked.assign(blocked.size(), false);
        sz[root] = 0;
        int r = root;
        while (get_size(r) != 1) {
            show(g);
            show(sz);
            show(r);
            int nextr = get_centroid(r);
            assert(g[nextr].size() == 2 && !blocked[g[nextr][0]] && !blocked[g[nextr][1]]);
            int left = g[nextr][0];
            while (!g[left].empty()) {
                left = g[left][0];
            }
            assert(left < n);
            int right = g[nextr][1];
            while (!g[right].empty()) {
                right = g[right][0];
            }
            assert(right < n);
            char res = ask(left, leaf, right);
            if (res == 'X') {
                r = g[nextr][0];
            } else if (res == 'Y') {
                r = g[nextr][1];
            } else {
                blocked[g[nextr][0]] = blocked[g[nextr][1]] = true;
            }
        }

        show(r);

        if (par[r] == -1) {
            g[last].pb(r);
            g[last].pb(leaf);
            par[r] = par[leaf] = last;
            root = last;
            ++last;
        } else {
            int v = par[r];
            assert(count(g[v].begin(), g[v].end(), r));
            g[v].erase(find(g[v].begin(), g[v].end(), r));
            g[v].pb(last);
            g[last].pb(r);
            g[last].pb(leaf);
            par[last] = v;
            par[r] = par[leaf] = last;
            ++last;
        }
    }

    ++par;
    *find(par.begin(), par.end(), 0) = -1;
    cout << -1 << endl;
    cout << par << endl;

    return 0;
}