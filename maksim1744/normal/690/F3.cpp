/*
    author:  Maksim1744
    created: 15.05.2021 00:02:34
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

struct DSU {
    vector<int> rk;
    vector<int> p;
    int n;

    DSU(int n = 1) : n(n) {
        reset(n);
    }

    void reset(int n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        rk.assign(n, 1);
    }

    int par(int v) {
        return v == p[v] ? v : p[v] = par(p[v]);
    }

    bool un(int u, int v) {
        u = par(u);
        v = par(v);
        if (u == v) return false;
        if (rk[u] > rk[v]) swap(u, v);
        p[u] = v;
        rk[v] += rk[u];
        return true;
    }

    bool check(int u, int v) {
        return par(u) == par(v);
    }
};

const int mod1 = 1e9 + 7;
const int base1 = 18592197;
const int N = 2e3 + 20;
array<ll, N> deg1;

struct Hash {
    int sz;
    int val1;

    auto tpl() const {
        return make_tuple(sz, val1);
    }

    bool operator < (const Hash &other) const {
        return tpl() < other.tpl();
    }

    bool operator == (const Hash &other) const {
        return tpl() == other.tpl();
    }
    bool operator != (const Hash &other) const {
        return tpl() != other.tpl();
    }
};

ostream &operator << (ostream &o, const Hash &h) {
    return o << "[" << "sz=" << h.sz << ", val1=" << h.val1 << "]";
}

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

vector<int> cent(const vector<vector<int>> &g) {
    int n = g.size();
    vector<int> d(n);
    for (int i = 0; i < n; ++i) {
        d[i] = g[i].size();
    }
    if (n == 1) return {0};
    set<int> left;
    vector<int> cur;
    for (int i = 0; i < n; ++i) {
        if (d[i] == 1)
            cur.pb(i);
        left.insert(i);
    }
    while (left.size() > 2) {
        vector<int> next;
        for (auto k : cur) {
            left.erase(k);
        }
        for (auto k : cur) {
            for (auto v : g[k]) {
                d[v]--;
                if (d[v] == 1 && left.count(v)) {
                    next.pb(v);
                }
            }
        }
        swap(cur, next);
    }
    return vector<int>(left.begin(), left.end());
}

Hash calc_unrooted_hash(const vector<vector<int>> &g) {
    auto c = cent(g);
    vector<Hash> res;
    vector<Hash> tmp(g.size());
    for (int v : c) {
        y_combinator([&](auto dfs, int v, int p = -1) -> void {
            vector<pair<Hash, int>> ch;
            for (int k : g[v]) {
                if (k != p) {
                    dfs(k, v);
                    ch.eb(tmp[k], k);
                }
            }
            sort(ch.begin(), ch.end());
            Hash cur;
            cur.sz = 1;
            cur.val1 = base1;
            for (auto [h, k] : ch) {
                cur.val1 += (ll)h.val1 * deg1[cur.sz] % mod1;
                cur.val1 %= mod1;
                cur.sz += h.sz;
            }
            cur.val1 += (ll)cur.val1 * deg1[cur.sz] % mod1;
            cur.val1 %= mod1;
            cur.sz++;
            tmp[v] = cur;
        })(v);
        res.pb(tmp[v]);
    }
    assert(res.size() == 1 || res.size() == 2);
    Hash ans = res[0];
    if (res.size() == 2) {
        ans.sz = ans.sz + 10000 + res[1].sz;
        ans.val1 = (ans.val1 + res[1].val1) % mod1;
    }
    return ans;
}

void test_case(int test) {
    int n, k;
    cin >> n >> k;
    assert(k == 2);
    int m1, m2;
    cin >> m1;
    vector<pair<int, int>> e1(m1);
    cin >> e1;
    --e1;
    cin >> m2;
    vector<pair<int, int>> e2(m2);
    cin >> e2;
    --e2;

    vector<vector<int>> g1(n);
    for (auto [u, v] : e1) {
        g1[u].pb(v);
        g1[v].pb(u);
    }
    vector<vector<int>> g2(n);
    for (auto [u, v] : e2) {
        g2[u].pb(v);
        g2[v].pb(u);
    }

    vector<vector<int>> comps1;
    vector<int> where1(n);
    int removed1 = -1;
    vector<vector<int>> comps2;
    vector<int> where2(n);
    int removed2 = -1;

    {
        DSU d(n);
        for (auto [u, v] : e1)
            d.un(u, v);
        map<int, vector<int>> mcomps;
        for (int i = 0; i < n; ++i) {
            mcomps[d.par(i)].pb(i);
        }
        for (auto [a, b] : mcomps) {
            if (removed1 == -1 && b.size() == 1) {
                removed1 = b[0];
                continue;
            }
            for (int u : b)
                where1[u] = comps1.size();
            comps1.pb(b);
        }
    }
    {
        DSU d(n);
        for (auto [u, v] : e2)
            d.un(u, v);
        map<int, vector<int>> mcomps;
        for (int i = 0; i < n; ++i) {
            mcomps[d.par(i)].pb(i);
        }
        for (auto [a, b] : mcomps) {
            if (removed2 == -1 && b.size() == 1) {
                removed2 = b[0];
                continue;
            }
            for (int u : b)
                where2[u] = comps2.size();
            comps2.pb(b);
        }
    }

    vector<Hash> hashes1(n);
    vector<Hash> hashes2(n);
    vector<vector<Hash>> ch_hashes1(n);
    vector<vector<Hash>> ch_unrooted_hashes1(n);
    vector<vector<Hash>> ch_hashes2(n);
    vector<Hash> tmp(n);
    vector<Hash> unrooted_comps2;
    for (int i = 0; i < n; ++i) {
        if (i != removed1) {
            y_combinator([&](auto dfs, int v, int p = -1) -> void {
                vector<pair<Hash, int>> ch;
                for (int k : g1[v]) {
                    if (k != p) {
                        dfs(k, v);
                        ch.eb(tmp[k], k);
                    }
                }
                sort(ch.begin(), ch.end());
                Hash cur;
                cur.sz = 1;
                cur.val1 = base1;
                for (auto [h, k] : ch) {
                    cur.val1 += (ll)h.val1 * deg1[cur.sz] % mod1;
                    cur.val1 %= mod1;
                    cur.sz += h.sz;
                }
                cur.val1 += (ll)cur.val1 * deg1[cur.sz] % mod1;
                cur.val1 %= mod1;
                cur.sz++;
                tmp[v] = cur;
                if (p == -1) {
                    for (auto [a, b] : ch)
                        ch_hashes1[v].pb(a);
                    hashes1[v] = tmp[v];
                }
            })(i);

            for (int k : g1[i]) {
                vector<vector<int>> g0;
                map<int, int> num;
                y_combinator([&](auto dfs, int v, int p) -> void {
                    num[v] = g0.size();
                    g0.eb();
                    for (int k : g1[v]) {
                        if (k != p) {
                            dfs(k, v);
                            g0[num[v]].pb(num[k]);
                            g0[num[k]].pb(num[v]);
                        }
                    }
                })(k, i);
                ch_unrooted_hashes1[i].pb(calc_unrooted_hash(g0));
            }
        }
    }
    show(hashes1);
    show(ch_hashes1);


    for (int i = 0; i < n; ++i) {
        if (i != removed2) {
            y_combinator([&](auto dfs, int v, int p = -1) -> void {
                vector<pair<Hash, int>> ch;
                for (int k : g2[v]) {
                    if (k != p) {
                        dfs(k, v);
                        ch.eb(tmp[k], k);
                    }
                }
                sort(ch.begin(), ch.end());
                Hash cur;
                cur.sz = 1;
                cur.val1 = base1;
                for (auto [h, k] : ch) {
                    cur.val1 += (ll)h.val1 * deg1[cur.sz] % mod1;
                    cur.val1 %= mod1;
                    cur.sz += h.sz;
                }
                cur.val1 += (ll)cur.val1 * deg1[cur.sz] % mod1;
                cur.val1 %= mod1;
                cur.sz++;
                tmp[v] = cur;
                if (p == -1) {
                    for (auto [a, b] : ch)
                        ch_hashes2[v].pb(a);
                    hashes2[v] = tmp[v];
                }
            })(i);
        }
    }

    for (int i = 0; i < comps2.size(); ++i) {
        vector<vector<int>> g0;
        map<int, int> num;
        y_combinator([&](auto dfs, int v, int p = -1) -> void {
            num[v] = g0.size();
            g0.eb();
            for (int k : g2[v]) {
                if (k != p) {
                    dfs(k, v);
                    g0[num[v]].pb(num[k]);
                    g0[num[k]].pb(num[v]);
                }
            }
        })(comps2[i][0]);
        unrooted_comps2.pb(calc_unrooted_hash(g0));
    }

    show(comps1);
    show(comps2);

    show(ch_unrooted_hashes1);
    show(unrooted_comps2);

    for (int i = 0; i < n; ++i) {
        shows;
        if (i == removed2) continue;
        if (g2[i].size() == comps1.size()) {
            show(i);
            y_combinator([&](auto dfs, int v, int p = -1) -> void {
                vector<pair<Hash, int>> ch;
                for (int k : g2[v]) {
                    if (k != p) {
                        dfs(k, v);
                        ch.eb(tmp[k], k);
                    }
                }
                sort(ch.begin(), ch.end());
                Hash cur;
                cur.sz = 1;
                cur.val1 = base1;
                for (auto [h, k] : ch) {
                    cur.val1 += (ll)h.val1 * deg1[cur.sz] % mod1;
                    cur.val1 %= mod1;
                    cur.sz += h.sz;
                }
                cur.val1 += (ll)cur.val1 * deg1[cur.sz] % mod1;
                cur.val1 %= mod1;
                cur.sz++;
                tmp[v] = cur;
            })(i);
            set<pair<Hash, pair<int, int>>> has;
            for (int i = 0; i < comps1.size(); ++i) {
                for (int j : comps1[i]) {
                    has.emplace(hashes1[j], mp(i, j));
                }
            }
            // show(tmp);
            vector<pair<int, int>> matches;
            vector<int> unmatched;
            for (int k : g2[i]) {
                auto h = tmp[k];
                auto it = has.lower_bound(mp(h, mp(-1, -1)));
                if (it == has.end() || it->first != h) {
                    unmatched.pb(k);
                } else {
                    matches.eb(k, it->second.second);
                    int c = it->second.first;
                    for (int j : comps1[c]) {
                        has.erase({hashes1[j], mp(c, j)});
                    }
                }
            }
            if (unmatched.size() != 1) continue;
            show(matches);
            show(unmatched);

            int k = unmatched[0];
            int other2 = k;
            // int comp2 = where2[k];

            vector<vector<int>> g0;
            map<int, int> num;
            y_combinator([&](auto dfs, int v, int p = -1) -> void {
                num[v] = g0.size();
                g0.eb();
                for (int k : g2[v]) {
                    if (k != p) {
                        dfs(k, v);
                        g0[num[v]].pb(num[k]);
                        g0[num[k]].pb(num[v]);
                    }
                }
            })(k, i);

            show(k, i, g0);

            auto h = calc_unrooted_hash(g0);
            int comp1 = has.begin()->second.first;

            show(h, comp1);

            for (int v1 : comps1[comp1]) {
                if (g1[v1].size() != comps2.size()) continue;
                set<pair<Hash, int>> ms;
                // for (int k : g1[v1]) {
                for (int k = 0; k < g1[v1].size(); ++k) {
                    auto h = ch_unrooted_hashes1[v1][k];
                    ms.emplace(h, k);
                }
                show(v1, ms);
                bool ok = true;
                for (int j = 0; j < comps2.size(); ++j) {
                    if (j == where2[i]) continue;
                    auto it = ms.lower_bound(mp(unrooted_comps2[j], -1));
                    if (it == ms.end() || it->first != unrooted_comps2[j]) {
                        ok = false;
                        break;
                    }
                    ms.erase(it);
                }
                if (!ok) continue;
                show(v1, ms);
                int otheri = ms.begin()->second;
                int other = g1[v1][otheri];
                show(other);
                set<Hash> pos;

                y_combinator([&](auto dfs, int v, int p = -1) -> void {
                    vector<pair<Hash, int>> ch;
                    for (int k : g1[v]) {
                        if (k != p && k != v1) {
                            dfs(k, v);
                            ch.eb(tmp[k], k);
                        }
                    }
                    sort(ch.begin(), ch.end());
                    Hash cur;
                    cur.sz = 1;
                    cur.val1 = base1;
                    for (auto [h, k] : ch) {
                        cur.val1 += (ll)h.val1 * deg1[cur.sz] % mod1;
                        cur.val1 %= mod1;
                        cur.sz += h.sz;
                    }
                    cur.val1 += (ll)cur.val1 * deg1[cur.sz] % mod1;
                    cur.val1 %= mod1;
                    cur.sz++;
                    tmp[v] = cur;
                })(other);
                Hash need = tmp[other];
                show(need);
                show(h);

                if (h == ch_unrooted_hashes1[v1][otheri]) {
                    cout << "YES\n";

                    vector<pair<int, int>> ans;
                    set<int> nused;
                    for (int i = 0; i < n; ++i)
                        nused.insert(i);
                    y_combinator([&](auto dfs, int v, int p = -1) -> void {
                        if (p != -1)
                            ans.eb(v, p);
                        nused.erase(v);
                        for (int k : g2[v])
                            if (k != p && k != other2)
                                dfs(k, v);
                    })(i);

                    map<int, int> curnum1;
                    show(ans);
                    show(nused);

                    show(i, v1, other);

                    y_combinator([&](auto dfs, int v, int p = -1) -> void {
                        curnum1[v] = *nused.begin();
                        nused.erase(nused.begin());
                        if (p != -1)
                            ans.eb(curnum1[v], curnum1[p]);
                        for (int k : g1[v])
                            if (k != p && k != other)
                                dfs(k, v);
                    })(v1);

                    show(ans);
                    show(curnum1);
                    show(nused);

                    for (auto [v2, _1] : num) {
                        y_combinator([&](auto dfs, int v, int p = -1) -> void {
                            vector<pair<Hash, int>> ch;
                            for (int k : g2[v]) {
                                if (k != p && k != i) {
                                    dfs(k, v);
                                    ch.eb(tmp[k], k);
                                }
                            }
                            sort(ch.begin(), ch.end());
                            Hash cur;
                            cur.sz = 1;
                            cur.val1 = base1;
                            for (auto [h, k] : ch) {
                                cur.val1 += (ll)h.val1 * deg1[cur.sz] % mod1;
                                cur.val1 %= mod1;
                                cur.sz += h.sz;
                            }
                            cur.val1 += (ll)cur.val1 * deg1[cur.sz] % mod1;
                            cur.val1 %= mod1;
                            cur.sz++;
                            tmp[v] = cur;
                        })(v2);

                        show(tmp[v2]);

                        if (tmp[v2] == need) {
                            map<int, int> curnum2;
                            show(ans, nused);
                            y_combinator([&](auto dfs, int v, int p = -1) -> void {
                                if (v == i) {
                                    ans.eb(i, curnum2[p]);
                                    return;
                                }
                                curnum2[v] = *nused.begin();
                                nused.erase(nused.begin());
                                if (p != -1)
                                    ans.eb(curnum2[v], curnum2[p]);
                                for (int k : g2[v])
                                    if (k != p)
                                        dfs(k, v);
                            })(v2);

                            show(ans);

                            ans.eb(curnum1[v1], curnum2[v2]);

                            show(ans);
                            ++ans;
                            show(ans);

                            for (auto p : ans)
                                cout << p << '\n';

                            return;
                        }
                    }

                    assert(false);
                }
            }
        } else if (g2[i].size() + 1 == comps1.size()) {
            show(i);
            y_combinator([&](auto dfs, int v, int p = -1) -> void {
                vector<pair<Hash, int>> ch;
                for (int k : g2[v]) {
                    if (k != p) {
                        dfs(k, v);
                        ch.eb(tmp[k], k);
                    }
                }
                sort(ch.begin(), ch.end());
                Hash cur;
                cur.sz = 1;
                cur.val1 = base1;
                for (auto [h, k] : ch) {
                    cur.val1 += (ll)h.val1 * deg1[cur.sz] % mod1;
                    cur.val1 %= mod1;
                    cur.sz += h.sz;
                }
                cur.val1 += (ll)cur.val1 * deg1[cur.sz] % mod1;
                cur.val1 %= mod1;
                cur.sz++;
                tmp[v] = cur;
            })(i);
            set<pair<Hash, pair<int, int>>> has;
            for (int i = 0; i < comps1.size(); ++i) {
                for (int j : comps1[i]) {
                    has.emplace(hashes1[j], mp(i, j));
                }
            }
            // show(tmp);
            vector<pair<int, int>> matches;
            vector<int> unmatched;
            for (int k : g2[i]) {
                auto h = tmp[k];
                auto it = has.lower_bound(mp(h, mp(-1, -1)));
                if (it == has.end() || it->first != h) {
                    unmatched.pb(k);
                } else {
                    matches.eb(k, it->second.second);
                    int c = it->second.first;
                    for (int j : comps1[c]) {
                        has.erase({hashes1[j], mp(c, j)});
                    }
                }
            }
            if (unmatched.size() != 0) continue;
            int comp = has.begin()->second.first;
            {
                set<pair<Hash, int>> has;
                show(matches);
                show(unmatched);
                show(has);
                show(comp);
                for (int ii = 0; ii < comps2.size(); ++ii) {
                    if (ii == where2[i]) continue;
                    for (int j : comps2[ii]) {
                        has.emplace(hashes2[j], ii);
                    }
                }

                for (int k : comps1[comp]) {
                    bool ok = true;
                    vector<pair<Hash, int>> rms;
                    show(k);
                    show(has);
                    show(ch_hashes1[k]);
                    for (auto h : ch_hashes1[k]) {
                        auto it = has.lower_bound({h, -1});
                        if (it == has.end() || it->first != h) {
                            ok = false;
                            break;
                        } else {
                            rms.pb(*it);
                            has.erase(it);
                        }
                    }
                    if (!ok) {
                        for (auto p : rms)
                            has.insert(p);
                        continue;
                    }
                    show(ok);

                    cout << "YES\n";
                    show(matches);
                    show(k);

                    set<int> nused;
                    for (int i = 0; i < n; ++i)
                        nused.insert(i);
                    vector<pair<int, int>> ans;

                    matches.eb(-1, k);
                    show(matches);

                    for (auto [v2, v1] : matches) {
                        y_combinator([&](auto dfs, int v, int p = -1) -> void {
                            nused.erase(v);
                            for (int k : g1[v]) {
                                if (k != p) {
                                    ans.eb(v, k);
                                    dfs(k, v);
                                }
                            }
                        })(v1);
                        ans.eb(removed1, v1);
                    }

                    show(ans);
                    assert(ans.size() == n - 1);
                    for (auto [a, b] : ans)
                        cout << a + 1 << ' ' << b + 1 << '\n';

                    return;
                }
            }
        }
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    deg1[0] = 1;
    for (int i = 1; i < deg1.size(); ++i)
        deg1[i] = deg1[i - 1] * base1 % mod1;

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        test_case(test);
    }

    return 0;
}