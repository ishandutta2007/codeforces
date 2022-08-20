/*
    author:  Maksim1744
    created: 04.06.2020 19:07:19
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
mt19937_64 rng(346834);
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
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#endif

ll rnd (ll l, ll r) { return (ll)(rng() % (r - l + 1)) + l; }
ll rnd (ll r)       { return rng() % r; }
ll rnd ()           { return rng(); }
ld rndf()           { return (ld)rng() / (ld)ULLONG_MAX; }
ld rndf(ld l, ld r) { return rndf() * (r - l) + l; }

void test_case() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
    }
    vector<bool> u(n, false);
    vector<bool> in, out;
    auto check = [&](int v) {
        u.assign(n, false);
        in.assign(n, false);
        out.assign(n, false);
        bool ok = true;
        function<void(int)> dfs = [&](int v) {
            in[v] = true;
            u[v] = true;
            if (!ok) return;
            for (auto k : g[v]) {
                if (!u[k]) {
                    dfs(k);
                } else {
                    if (out[k]) {
                        ok = false;
                    }
                }
                if (!ok) break;
            }
            out[v] = true;
        };
        dfs(v);
        return ok;
    };
    int good = -1;
    for (int i = 0; i < 150; ++i) {
        int v = rnd(n);
        if (check(v)) {
            good = v;
            break;
        }
    }
    if (good == -1) {
        cout << -1 << '\n';
        return;
    }
    u.assign(n, false);
    vector<int> up1(n, n + 20);
    vector<int> up2(n, n + 20);
    vector<int> who1(n);
    vector<int> lvl(n, -1);
    vector<int> ans = {good};
    vector<vector<int>> next(n);
    function<void(int, int)> dfs = [&](int v, int level) {
        u[v] = true;
        lvl[v] = level;
        for (auto k : g[v]) {
            if (u[k]) {
                if (lvl[k] <= up1[v]) {
                    up2[v] = up1[v];
                    up1[v] = lvl[k];
                    who1[v] = k;
                } else if (lvl[k] < up2[v]) {
                    up2[v] = lvl[k];
                }
            } else {
                dfs(k, level + 1);
                if (up1[k] < up1[v])
                    who1[v] = who1[k];
                vector<int> vv = {up1[v], up2[v], up1[k], up2[k]};
                sort(vv.begin(), vv.end());
                up1[v] = vv[0];
                up2[v] = vv[1];
            }
        }
        if (lvl[v] == 0) return;
        if (up2[v] >= lvl[v]) {
            if (up1[v] == 0)
                ans.pb(v);
            else
                next[who1[v]].pb(v);
        }
    };
    dfs(good, 0);
    // show(up1);
    // show(up2);
    // show(next);
    u.assign(n, false);
    function<void(int)> dfs2 = [&](int v) {
        u[v] = true;
        ans.pb(v);
        for (auto k : next[v]) {
            if (!u[k])
                dfs2(k);
        }
    };
    // show(ans);
    int sz = ans.size();
    for (int i = 0; i < sz; ++i) {
        if (!u[ans[i]])
            dfs2(ans[i]);
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    ++ans;
    // show(ans);
    if (ans.size() * 5 < n) {
        ans = {-1};
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        test_case();
    }

    return 0;
}