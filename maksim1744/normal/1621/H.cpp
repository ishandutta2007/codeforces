/*
    author:  Maksim1744
    created: 05.01.2022 13:14:48
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
#include "/mnt/c/Libs/tools/print.cpp"
#else
#define show(...) void(0)
#define debugf(fun)   fun
#define debugv(var)   var
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#define OSTREAM(...)    ;
#define OSTREAM0(...)   ;
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

struct Q {
    vector<int> pass, fine;
    int ind;
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        int w;
        cin >> w;
        g[u].eb(v, w);
        g[v].eb(u, w);
    }
    int k;
    cin >> k;
    string s;
    cin >> s;

    vector<pair<int, ll>> up(n);
    up[0] = {0, 0};
    vector<int> par(n);

    y_combinator([&](auto dfs, int v, int p, int t) -> void {
        par[v] = p;
        if (p != -1) {
            if (s[p] == s[v]) {
                up[v] = {up[p].first, up[p].second + t};
            } else {
                up[v] = {p, t};
            }
        }
        for (auto [k, t] : g[v]) {
            if (k == p) continue;
            dfs(k, v, t);
        }
    })(0, -1, 0);

    vector<int> pass(k), fine(k);
    cin >> pass >> fine;

    ll T;
    cin >> T;

    vector<ll> ans;
    vector<vector<Q>> que(n);

    int q;
    cin >> q;
    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            char i;
            int c;
            cin >> i >> c;
            pass[i - 'A'] = c;
        } else if (tp == 2) {
            char i;
            int c;
            cin >> i >> c;
            fine[i - 'A'] = c;
        } else {
            int v;
            cin >> v;
            --v;
            if (s[v] == s[0]) {
                ans.pb(0);
                continue;
            }
            que[v].pb({pass, fine, (int)ans.size()});
            ans.pb(-1);
            continue;
        }
    }

    vector<set<int>> sets;

    auto get_pref = [&](int v, const vector<int>& pass, const vector<int>& fine) {
        int u = up[v].first;
        map<int, ll> pref;
        ll total = 0;
        ll curlen = 0;
        pref[0] = 0;
        pref[T] = 0;
        while (u != 0) {
            auto [k, len] = up[u];
            int z = s[u] - 'A';
            if (len % T == 0) {
                total += min((__int128)pass[z], (__int128)fine[z] * (len / T));
                u = k;
                curlen += len;
                continue;
            }
            ll c1 = min((__int128)pass[z], (__int128)fine[z] * (len / T));
            ll c2 = min((__int128)pass[z], (__int128)fine[z] * (len / T + 1));
            if (c1 == c2) {
                total += c1;
                u = k;
                curlen += len;
                continue;
            }
            total += c1;
            ll r = 0, l = -(len % T) + 1;
            l -= (curlen) % T;
            r -= (curlen) % T;
            l = (l % T + T) % T;
            r = (r % T + T) % T;
            if (l <= r) {
                pref[l] += (c2 - c1);
                pref[r + 1] -= (c2 - c1);
            } else {
                pref[l] += (c2 - c1);
                pref[T] -= (c2 - c1);
                pref[0] += (c2 - c1);
                pref[r + 1] -= (c2 - c1);
            }
            u = k;
            curlen += len;
        }
        ll last = total;
        for (auto& [ind, c] : pref) {
            c += last;
            last = c;
        }
        return pref;
    };

    auto mrg = [&](int i1, int i2) {
        if (sets[i1].size() < sets[i2].size()) swap(i1, i2);
        for (int k : sets[i2])
            sets[i1].insert(k);
        return i1;
    };

    y_combinator([&](auto dfs, int v) -> int {
        int cur = sets.size();
        sets.eb();
        sets.back().insert(up[v].second % T);
        for (auto [k, _] : g[v]) {
            if (k == par[v]) continue;
            if (s[k] == s[v]) {
                int ind = dfs(k);
                cur = mrg(cur, ind);
            } else {
                dfs(k);
            }
        }

        for (const auto& q : que[v]) {
            auto pref = get_pref(v, q.pass, q.fine);
            auto it = pref.begin();
            ll res = 1e18;
            show(q.ind, v, pref, sets[cur]);
            while (next(it) != pref.end()) {
                auto its = sets[cur].lower_bound(it->first);
                if (its != sets[cur].end() && *its < next(it)->first) {
                    res = min(res, it->second);
                }
                ++it;
            }
            show(res);
            ans[q.ind] = res;
        }

        return cur;
    })(0);

    for (ll k : ans)
        cout << k << '\n';

    return 0;
}