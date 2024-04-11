/*
    author:  Maksim1744
    created: 08.06.2021 11:38:46
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

vector<int> lca_ind;
vector<vector<int>> lca_sparse;
vector<int> lca_p2;
vector<int> lca_depth;
void build_lca_sparse(vector<vector<pair<int, int>>>& g, int root = 0) {
    int n = g.size();
    vector<int> euler;
    lca_ind.resize(n);
    lca_depth.assign(n, -1);
    function<void(int, int)> dfs = [&](int v, int depth) {
        lca_ind[v] = euler.size();
        euler.pb(v);
        lca_depth[v] = depth;
        for (auto [k, w] : g[v]) {
            if (lca_depth[k] == -1) {
                dfs(k, depth + 1);
                euler.pb(v);
            }
        }
    };
    dfs(root, 0);
    int m = euler.size();
    int log = 1;
    while ((1 << log) < m)
        ++log;
    lca_sparse.resize(log);
    lca_sparse[0].resize(m);
    lca_p2.resize(m + 1);
    int pp2 = 0;
    for (int i = 1; i < lca_p2.size(); ++i) {
        if (1 << (pp2 + 1) <= i)
            ++pp2;
        lca_p2[i] = pp2;
    }
    lca_p2[0] = 0;
    for (int i = 0; i < m; ++i)
        lca_sparse[0][i] = euler[i];
    for (int i = 1; i < log; ++i) {
        lca_sparse[i].assign(m, 0);
        for (int j = 0; j < m - (1 << (i - 1)); ++j) {
            int v1 = lca_sparse[i - 1][j], v2 = lca_sparse[i - 1][j + (1 << (i - 1))];
            if (lca_depth[v1] < lca_depth[v2])
                lca_sparse[i][j] = v1;
            else
                lca_sparse[i][j] = v2;
        }
    }
}

int get_lca(int u, int v) {
    if (u == v)
        return u;
    u = lca_ind[u];
    v = lca_ind[v];
    if (u > v)
        swap(u, v);
    int v1 = lca_sparse[lca_p2[v - u + 1]][u], v2 = lca_sparse[lca_p2[v - u + 1]][v - (1 << lca_p2[v - u + 1]) + 1];
    if (lca_depth[v1] < lca_depth[v2])
        return v1;
    else
        return v2;
}

int dist(int u, int v) {
    return lca_depth[u] + lca_depth[v] - 2 * lca_depth[get_lca(u, v)];
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd (ll l, ll r) { return (ll)(rng() % (r - l + 1)) + l; }
ll rnd (ll r)       { return rng() % r; }
ll rnd ()           { return rng(); }
ld rndf()           { return (ld)rng() / (ld)ULLONG_MAX; }
ld rndf(ld l, ld r) { return rndf() * (r - l) + l; }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    ll k;
    cin >> n >> k;

    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].eb(v, i);
        g[v].eb(u, i);
    }

    auto build_with_weight = [&](const vector<int> &val) {
        vector<pair<int, int>> res;

        vector<vector<int>> sets;

        auto mrg = [&](int i1, int i2) {
            if (sets[i1].size() < sets[i2].size())
                swap(i1, i2);
            for (int v : sets[i2])
                sets[i1].pb(v);
            return i1;
        };

        y_combinator([&](auto dfs, int v, int p = -1, int left = 0) -> int {
            int cur = sets.size();
            sets.pb(vector<int>{v});
            set<pair<int, int>, greater<pair<int, int>>> best;
            int have = 1;
            best.emplace(sets[cur].size(), cur);
            for (auto [k, i] : g[v]) {
                if (k != p) {
                    int x = dfs(k, v, val[i]);
                    if (sets[x].empty()) continue;
                    best.emplace(sets[x].size(), x);
                    have += sets[x].size();
                }
            }
            assert(have % 2 == left % 2);
            assert(have >= left);
            while (have != left) {
                have -= 2;
                assert(best.size() >= 2);
                auto [sz1, v1] = *best.begin();
                best.erase(best.begin());
                auto [sz2, v2] = *best.begin();
                best.erase(best.begin());
                res.eb(sets[v1].back(), sets[v2].back());
                sets[v1].pop_back();
                sets[v2].pop_back();
                --sz1;
                --sz2;
                if (sz1 != 0) best.emplace(sz1, v1);
                if (sz2 != 0) best.emplace(sz2, v2);
            }
            int v0 = cur;
            for (auto [sz, v] : best)
                if (v != v0)
                    cur = mrg(v, cur);
            return cur;
        })(0);

        return res;
    };

    build_lca_sparse(g, 0);

    vector<int> mxs(n - 1);
    y_combinator([&](auto dfs, int v, int p = -1) -> int {
        int s = 1;
        for (auto [k, i] : g[v]) {
            if (k != p) {
                int s0 = dfs(k, v);
                s += s0;
                mxs[i] = min(s0, n - s0);
            }
        }
        return s;
    })(0);

    ll sm = sum(mxs);
    if (k > sm || k % 2 != sm % 2) {
        cout << "NO\n";
        return 0;
    }

    {
        auto res = build_with_weight(mxs);
        // vector<pair<int, int>> del;
        for (int i = 0; i < 7e6; ++i) {
            if (sm - k < 2e6) break;
            if (res.size() < 2) break;
            int i1 = rnd(res.size());
            int i2 = rnd(res.size());
            if (i1 == i2) continue;
            if (i1 > i2) swap(i1, i2);
            if (rnd(2))
                swap(res[i1].first, res[i1].second);
            int was = dist(res[i1].first, res[i1].second) + dist(res[i2].first, res[i2].second);
            int now = dist(res[i1].first, res[i2].second) + dist(res[i2].first, res[i1].second);
            if (now <= was && sm - was + now >= k) {
                sm = sm - was + now;
                swap(res[i1].second, res[i2].second);
            }
            // if (dist(res[i2].first, res[i2].second) <= 20) {
            //     del.pb(res[i2]);
            //     swap(res[i2], res.back());
            //     res.pop_back();
            // }
            // if (dist(res[i1].first, res[i1].second) <= 20) {
            //     del.pb(res[i1]);
            //     swap(res[i1], res.back());
            //     res.pop_back();
            // }
        }

        // for (auto p : del)
        //     res.pb(p);
        // show(res);
        // show(sm);

        vector<int> vals(n);
        for (auto [u, v] : res) {
            vals[u]++;
            vals[v]++;
            vals[get_lca(u, v)] -= 2;
        }

        y_combinator([&](auto dfs, int v, int p = -1) -> int {
            int res = vals[v];
            for (auto [k, i] : g[v]) {
                if (k != p) {
                    int cur = dfs(k, v);
                    mxs[i] = cur;
                    res += cur;
                }
            }
            return res;
        })(0);
    }

    {
        vector<vector<int>> with_val(n + 1);
        for (int i = 0; i < mxs.size(); ++i)
            with_val[mxs[i]].pb(i);
        for (int i = n; i >= 0; --i) {
            if (sm == k) break;
            if (i < 2) {
                cout << "NO\n";
                return 0;
            }
            while (!with_val[i].empty() && sm > k) {
                int ind = with_val[i].back();
                with_val[i].pop_back();
                mxs[ind] -= 2;
                sm -= 2;
                with_val[i - 2].pb(ind);
            }
        }
    }

    // priority_queue<pair<int, int>> mxss;
    // for (int i = 0; i < n - 1; ++i)
    //     mxss.emplace(mxs[i], i);
    // while (sm != k) {
    //     auto [val, ind] = mxss.top();
    //     mxss.pop();
    //     if (val < 2) {
    //         cout << "NO\n";
    //         return 0;
    //     }
    //     int can = 2;
    //     if (!mxss.empty())
    //         can = max(can, val - mxss.top().first);
    //     can = min((ll)can, sm - k);
    //     mxs[ind] -= 2;
    //     val -= 2;
    //     sm -= 2;
    //     mxss.emplace(mxs[ind], ind);
    // }

    auto res = build_with_weight(mxs);
    assert(res.size() == n / 2);
    cout << "YES\n";
    ++res;
    for (auto p : res)
        cout << p << '\n';

    return 0;
}