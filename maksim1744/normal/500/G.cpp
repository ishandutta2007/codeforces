/*
    author:  Maksim1744
    created: 17.06.2021 12:05:47
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
void build_lca_sparse(vector<vector<int>>& g, int root = 0) {
    int n = g.size();
    vector<int> euler;
    lca_ind.resize(n);
    lca_depth.assign(n, -1);
    function<void(int, int)> dfs = [&](int v, int depth) {
        lca_ind[v] = euler.size();
        euler.pb(v);
        lca_depth[v] = depth;
        for (auto k : g[v]) {
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

const ll inf = 2e18;

// finds x and y such that a * x + b * y = c
template<typename T>
pair<T, T> egcd(T a, T b, T c) {
    if (a == 0) {
        // b * y = c
        assert(c % b == 0);
        return {0, c / b};
    }
    // a * x + b * y = c
    // a * x + (b % a + (b/a) * a) * y = c
    // a * (x + (b/a) * y) + (b % a) * y = c
    auto [y0, x0] = egcd(b % a, a, c);
    T y = y0;
    T x = x0 - (b / a) * y;
    return {x, y};
}

pair<ll, ll> extEucMod(ll a, ll b, ll p) {
    if (b == 0) return {1, 0};
    ll m = a / b;
    auto sub = extEucMod(b, a - b * m, p);
    return {sub.second, (sub.first - m*sub.second) % p};
}
ll modInv(ll a, ll p) {
    ll res = extEucMod(p, a, p).second;
    return (res < 0 ? res + p : res);
}
ll gcd(ll a, ll b) { return (b == 0 ? a : gcd(b, a % b)); }
ll mSub(ll a, ll b, ll m) { return (a >= b ? a - b : a - b + m); }
ll posMod(ll a, ll m) { ll res = a % m; return (res < 0 ? res + m : res); }
ll getSteps(ll t, ll ia, ll b, ll m) { return mSub(t, b, m) * ia % m; }

// Returns minimum value of ax + b (mod m) for x \in [0, k]. O(log m) time
ll minRem(ll a, ll b, ll m, ll k) {
    // for (ll g = gcd(a, m); g > 1;) return g * minRem(a/g, b/g, m/g, k) + (b % g);
    ll b0 = b;
    ll m0 = m;
    ll ia0 = modInv(a, m);
    ll na, nb, nm;
    while (true) {
        if (a == 0) return b;
        if (a > m - a && false) {
            na = a % (m - a);
            nb = b % (m - a);
            nm = m - a;
            for (ll steps = getSteps(nb, ia0, b0, m0); steps > k;) {
                ll add = steps - getSteps(nb + nm, ia0, b0, m0);
                return nb + nm * ((steps - k + (add - 1)) / add);
            }
        } else {
            na = posMod(-m, a);
            nb = (b < a ? b : posMod(b - m, a));
            nm = a;
            if (getSteps(nb, ia0, b0, m0) > k) return b;
        }
        a = na; b = nb; m = nm;
    }
    return b;
}

// Returns minimum x such that ax + b (mod m) \in [le, ri] or -1 if there is no such x. O(log m) time
ll firstInRange(ll a, ll b, ll m, ll le, ll ri) {
    // for (ll g = gcd(a, m); g > 1;) return firstInRange(a/g, b/g, m/g, le/g + (le % g > b % g), ri/g - (ri % g < b % g));
    // if (le > ri) return 1e18; // impossible
    ll ia = modInv(a, m);
    return minRem(ia, mSub(le, b, m) * ia % m, m, ri - le);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> col(n, -1);
    y_combinator([&](auto dfs, int v, int color = 0) -> void {
        col[v] = color;
        for (int k : g[v])
            if (col[k] == -1)
                dfs(k, color ^ 1);
    })(0);

    build_lca_sparse(g, 0);

    int T;
    cin >> T;
    while (T--) {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        --u; --v; --x; --y;
        if (col[u] != col[x]) {
            cout << -1 << '\n';
            continue;
        }
        vector<int> verts = {u, v, x, y};
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < i; ++j)
                verts.push_back(get_lca(verts[i], verts[j]));
        sort(verts.begin(), verts.end());
        verts.erase(unique(verts.begin(), verts.end()), verts.end());

        auto on_path = [&](int a, int b, int c) {
            return dist(a, b) == dist(a, c) + dist(b, c);
        };

        vector<int> path;
        for (int k : verts) {
            if (on_path(u, v, k) && on_path(x, y, k))
                path.pb(k);
        }
        show(path);
        if (path.empty()) {
            cout << -1 << '\n';
            continue;
        }
        sort(path.begin(), path.end(), [&](int a, int b) {
            return dist(u, a) < dist(u, b);
        });
        show(path);

        int l1 = path[0];
        int l2 = path.back();

        int ln1 = dist(u, v);
        int ln2 = dist(x, y);
        int lnmid = dist(l1, l2);

        auto solve_eq = [&](ll mod1, ll val1, ll mod2, ll val2) -> ll {
            // t % mod1 = val1, t % mod2 = val2, t -> min
            val1 %= mod1;
            val2 %= mod2;
            ll g = gcd(mod1, mod2);
            if (val1 % g != val2 % g) return inf;
            auto [x, y] = egcd(mod1, -mod2, val2 - val1);
            ll t = x * mod1 + val1;
            ll lc = mod1 / g * mod2;
            t = (t % lc + lc) % lc;
            return t;
        };

        auto solve_res = [&](ll mod, ll l, ll r, ll a) -> ll {
            // ax % mod in [l; r], x -> min
            ll dif = r - l;
            if (dif >= mod) return 0;
            if (dif < 0) return inf;
            l = (l % mod + mod) % mod;
            r = (r % mod + mod) % mod;

            ll g = gcd(a, mod);

            auto solve_internal = [&](ll mod, ll l, ll r, ll a) -> ll {
                if (a == 0) return (l == 0 ? 0 : inf);
                a /= g;
                mod /= g;
                r /= g;
                l = (l + g - 1) / g;
                if (l > r) return inf;
                if (mod == 1) return 0;
                // return firstInRange(a, 0, mod, l, r);

                show(mod, l, r, a);

                ll ainv = egcd(a, mod, 1ll).first;
                ainv = (ainv % mod + mod) % mod;
                show(a, ainv, mod);
                // assert(a * ainv % mod == 1);

                ll b = l * ainv % mod;

                a = ainv;
                ll k = r - l;
                // return minRem(a, b, mod, k);

                assert(gcd(a, mod) == 1);
                // ll ans = inf;
                // for (ll i = 0; i <= k; ++i)
                //     umin(ans, (i * a + b) % mod);
                // return ans;

                ll b0 = b;
                ll mod0 = mod;
                ainv = egcd(a, mod, 1ll).first;
                ainv = (ainv % mod + mod) % mod;

                auto get_steps = [&](ll t, ll ia, ll b, ll m) -> ll {
                    return (t - b + m) % m * ia % m;
                };

                while (true) {
                    // if (a * 2 <= mod) {
                    if (a == 0) return b;
                    show(a, b, mod);
                    if (a < mod - a) {
                        ll s = (b < a ? b : ((b - mod) % a + a) % a);
                        // ll y = (b < a ? 0ll : (mod + s - b) / a);
                        show(s, k);
                        if (get_steps(s, ainv, b0, mod0) > k) return b;

                        ll m1 = a;
                        ll a1 = ((-mod) % a + a) % a;
                        b = s;

                        a = a1; mod = m1;
                    } else {
                        ll s = b % (mod - a);
                        ll a1 = a % (mod - a);
                        ll m1 = mod - a;

                        ll steps = get_steps(s, ainv, b0, mod0);
                        if (steps > k) {
                            ll div = steps - get_steps((s + m1) % mod0, ainv, b0, mod0);
                            return s + m1 * ((steps - k + div - 1) / div);
                        }

                        a = a1;
                        mod = m1;
                        b = s;
                    }
                }

                return inf;
            };

            if (l <= r) return solve_internal(mod, l, r, a);
            else return min(solve_internal(mod, 0, r, a), solve_internal(mod, l, mod - 1, a));
        };

        ll ans = inf;
        if (dist(x, l1) <= dist(x, l2)) {
            show("case 1");
            int s1 = dist(u, l1);
            int s2 = dist(x, l1);
            show(ln1, ln2);
            show(s1, s2);
            show(lnmid);
            // t % 2ln1 = s1 && t % 2ln2 = s2
            {
                ll cur = solve_eq(ln1 * 2, s1, ln2 * 2, s2);
                umin(ans, cur);
            }
            // t % 2ln1 = 2ln1 - lnmid - s1 && t % 2ln2 = 2ln2 - lnmid - s2
            {
                ll cur = solve_eq(ln1 * 2, ln1 * 2 - lnmid - s1, ln2 * 2, ln2 * 2 - lnmid - s2);
                umin(ans, cur);
            }
            // t0 = 2ln1 * x
            // t0 + s1 <= 2ln2 - s2 mod 2ln2
            // t0 + s1 + lnmid >= 2ln2 - lnmid - s2 mod 2ln2
            for (int i = 0; i < 2; ++i) {
                swap(ln1, ln2);
                swap(s1, s2);

                ll cur = solve_res(ln2 * 2, ln2 * 2 - lnmid - s2 - s1 - lnmid, ln2 * 2 - s2 - s1, ln1 * 2);
                if (cur == inf) continue;
                cur *= ln1 * 2;
                cur += s1;
                // (cur + d) % 2ln2 = 2ln2 - s2 - d
                // cur + 2d + s2 = 0 mod ln2
                ll rem = (cur + s2) % (ln2 * 2);
                if (rem) rem = ln2 * 2 - rem;
                assert(rem % 2 == 0);
                rem /= 2;
                cur += rem;
                umin(ans, cur);
            }
        } else {
            show("case 2");
            int s1 = dist(u, l1);
            int s2 = dist(x, l2);
            show(ln1, ln2);
            show(s1, s2);
            show(lnmid);
            // t % 2ln1 = s1 && t % 2ln2 = 2ln2 - lnmid - s2
            {
                ll cur = solve_eq(ln1 * 2, s1, ln2 * 2, ln2 * 2 - lnmid - s2);
                show(cur);
                umin(ans, cur);
            }
            // t % 2ln1 = 2ln1 - lnmid - s1 && t % 2ln2 = s2
            {
                ll cur = solve_eq(ln1 * 2, ln1 * 2 - lnmid - s1, ln2 * 2, s2);
                show(cur);
                umin(ans, cur);
            }
            // t0 = 2ln1 * x
            // t0 + s1 <= s2 + lnmid mod 2ln2
            // t0 + s1 + lnmid >= s2 mod 2ln2
            for (int i = 0; i < 2; ++i) {
                swap(ln1, ln2);
                swap(s1, s2);
                show(ln1, ln2, s1, s2);

                show(ln2 * 2, s2 - s1 - lnmid, s2 + lnmid - s1, ln1 * 2);
                ll cur = solve_res(ln2 * 2, s2 - s1 - lnmid, s2 + lnmid - s1, ln1 * 2);
                show(cur);
                if (cur == inf) continue;
                cur *= ln1 * 2;
                cur += s1;
                // (cur + d) % 2ln2 = s2 + lnmid - d
                // cur + 2d - s2 - lnmid = 0 mod 2ln2
                ll rem = (cur - s2 - lnmid + ln2 * 2 * 10) % (ln2 * 2);
                if (rem) rem = ln2 * 2 - rem;
                assert(rem % 2 == 0);
                rem /= 2;
                cur += rem;
                umin(ans, cur);
            }

            // t0 = 2ln1 * x
            // t0 + ln1 * 2 - s1 - lnmid <= 2ln2 - s2 mod 2ln2
            // t0 + ln1 * 2 - s1 >= 2ln2 - s2 - lnmid mod 2ln2
            for (int i = 0; i < 2; ++i) {
                swap(ln1, ln2);
                swap(s1, s2);
                show(ln1, ln2, s1, s2);

                show(ln2 * 2, ln2 * 2 - s2 - lnmid + s1 - ln1 * 2, ln2 * 2 - s2 - ln1 * 2 + s1 + lnmid, ln1 * 2);
                ll cur = solve_res(ln2 * 2, ln2 * 2 - s2 - lnmid + s1 - ln1 * 2, ln2 * 2 - s2 - ln1 * 2 + s1 + lnmid, ln1 * 2);
                show(cur);
                if (cur == inf) continue;
                cur *= ln1 * 2;
                cur += ln1 * 2 - s1 - lnmid;
                // (cur + d) % 2ln2 = 2ln2 - s2 - d
                // cur + 2d + s2 = 0 mod 2ln2
                ll rem = (cur + s2) % (ln2 * 2);
                if (rem) rem = ln2 * 2 - rem;
                assert(rem % 2 == 0);
                rem /= 2;
                cur += rem;
                umin(ans, cur);
            }
        }

        if (ans == inf) ans = -1;
        cout << ans << '\n';
    }

    return 0;
}