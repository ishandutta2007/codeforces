/*
    author:  Maksim1744
    created: 18.12.2021 21:32:40
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

vector<pair<int, int>> edmonds(vector<vector<int>>& g) {
    int n = g.size();
    vector<int> match(n, -1);
    vector<int> p(n);
    vector<bool> u(n);
    vector<bool> ulca(n);
    vector<int> q(n + 5, -1);
    vector<int> base(n);
    vector<bool> blossom(n);
    int ql = 0, qr = 0;

    auto lca = [&](int a, int b) {
        ulca.assign(n, false);
        while (true) {
            a = base[a];
            ulca[a] = true;
            if (match[a] == -1)
                break;
            a = p[match[a]];
        }
        while (true) {
            b = base[b];
            if (ulca[b]) return b;
            b = p[match[b]];
        }
        return -1;
    };

    auto mark_path = [&](int v, int b, int k) {
        while (base[v] != b) {
            blossom[base[v]] = true;
            blossom[base[match[v]]] = true;
            p[v] = k;
            k = match[v];
            v = p[match[v]];
        }
    };

    auto find_path = [&](int root) {
        p.assign(n, -1);
        u.assign(n, false);
        for (int i = 0; i < n; ++i)
            base[i] = i;
        ql = qr = 0;
        q[qr++] = root;
        u[root] = true;
        while (ql < qr) {
            int v = q[ql++];
            for (auto k : g[v]) {
                if (base[v] == base[k] || match[v] == k) {
                    continue;
                } else if (k == root || (match[k] != -1 && p[match[k]] != -1)) {
                    blossom.assign(n, false);
                    int b = lca(v, k);
                    mark_path(v, b, k);
                    mark_path(k, b, v);
                    for (int i = 0; i < n; ++i) {
                        if (blossom[base[i]]) {
                            base[i] = b;
                            if (!u[i]) {
                                u[i] = true;
                                q[qr++] = i;
                            }
                        }
                    }
                } else if (p[k] == -1) {
                    p[k] = v;
                    if (match[k] == -1)
                        return k;
                    k = match[k];
                    u[k] = true;
                    q[qr++] = k;
                }
            }
        }
        return -1;
    };

    for (int i = 0; i < n; ++i) {
        if (match[i] == -1) {
            int v = find_path(i);
            while (v != -1) {
                match[v] = p[v];
                int k = match[p[v]];
                match[p[v]] = v;
                v = k;
            }
        }
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; ++i)
        if (match[i] > i)
            ans.eb(i, match[i]);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    vector<pair<int, int>> segs;

    {
        int last = -1;
        for (int i = 0; i <= n; ++i) {
            if (i == n || a[i] != 0) {
                if (last != i - 1)
                    segs.eb(last + 1, i - 1);
                last = i;
            }
        }
    }

    if (n == count(a.begin(), a.end(), 0)) {
        for (int i = 0; i < n; ++i) {
            a[i] = i / 2 + 1;
        }
        cout << a << '\n';
        return 0;
    }

    if (!segs.empty()) {
        if (segs[0].first == 0) {
            int ln = segs[0].second - segs[0].first + 1;
            if (ln % 2 == 1) {
                a[segs[0].second] = a[segs[0].second + 1];
            }
            segs.erase(segs.begin());
        }
    }
    if (!segs.empty()) {
        if (segs.back().second == n - 1) {
            int ln = segs.back().second - segs.back().first + 1;
            if (ln % 2 == 1) {
                a[segs.back().first] = a[segs.back().first - 1];
            }
            segs.pop_back();
        }
    }

    vector<vector<int>> comps;
    auto do_odd = [&](bool fill_trees) {
        comps.clear();

        vector<bool> has_pair(n + 1, false);
        for (int i = 0; i + 1 < n; ++i) {
            if (a[i] == a[i + 1]) {
                has_pair[a[i]] = true;
            }
        }

        vector<int> nums;
        vector<pair<pair<int, int>, pair<int, int>>> odd;
        for (int i = 1; i <= n; ++i) {
            if (has_pair[i]) {
                odd.eb(mp(i, i), mp(-1, -1));
            }
        }
        for (auto [l, r] : segs) {
            int ln = r - l + 1;
            if (ln % 2 == 1 && a[l] == 0 && a[r] == 0) {
                odd.eb(mp(a[l - 1], a[r + 1]), mp(l, r));
            }
        }
        for (auto [ab, _] : odd) {
            nums.pb(ab.first);
            nums.pb(ab.second);
        }
        show(odd);
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        for (auto& [ab, _] : odd) {
            ab.first = lowb(nums, ab.first);
            ab.second = lowb(nums, ab.second);
        }

        vector<vector<pair<int, int>>> g(nums.size());
        for (int i = 0; i < odd.size(); ++i) {
            auto [u, v] = odd[i].first;
            g[u].eb(v, i);
            g[v].eb(u, i);
        }

        vector<int> u(n, 0);
        int ustep = 1;
        vector<bool> uodd(odd.size(), false);
        show(g);
        for (int i = 0; i < nums.size(); ++i) {
            ++ustep;
            if (!u[i]) {
                shows;
                show(i);
                int vcyc = -1;
                vector<int> here;
                y_combinator([&](auto dfs, int v, int pi) -> void {
                    u[v] = ustep;
                    here.pb(v);
                    for (auto [k, ei] : g[v]) {
                        if (ei == pi) continue;
                        if (u[k] != ustep) {
                            dfs(k, ei);
                        } else {
                            vcyc = v;
                        }
                    }
                })(i, -1);
                show(here, vcyc);
                if (fill_trees && vcyc == -1) vcyc = i;

                if (vcyc != -1) {
                    ++ustep;
                    y_combinator([&](auto dfs, int v) -> void {
                        show(v);
                        u[v] = ustep;
                        for (auto [k, ei] : g[v]) {
                            if (u[k] == ustep) continue;
                            show(k, ei);
                            assert(!uodd[ei]);
                            if (k == odd[ei].first.first) {
                                if (odd[ei].second.first != -1) a[odd[ei].second.first] = nums[k];
                                uodd[ei] = true;
                            } else {
                                assert(k == odd[ei].first.second);
                                if (odd[ei].second.second != -1) a[odd[ei].second.second] = nums[k];
                                uodd[ei] = true;
                            }
                            dfs(k);
                        }
                    })(vcyc);
                    if (!fill_trees) {
                        bool ok = false;
                        for (int i = 0; i < odd.size(); ++i) {
                            if (uodd[i]) continue;
                            if (odd[i].first.first == vcyc) {
                                if (odd[i].second.first != -1) a[odd[i].second.first] = nums[vcyc];
                                ok = true;
                                break;
                            } else if (odd[i].first.second == vcyc) {
                                if (odd[i].second.second != -1) a[odd[i].second.second] = nums[vcyc];
                                ok = true;
                                break;
                            }
                        }
                        assert(ok);
                    }
                } else {
                    comps.pb(here);
                }
            }
        }
        for (auto& v : comps)
            for (int& k : v)
                k = nums[k];
    };

    show(a);
    do_odd(false);
    show(a);

    {
        vector<pair<pair<int, int>, pair<int, int>>> even;

        vector<bool> has_pair(n + 1, false);
        for (int i = 0; i + 1 < n; ++i) {
            if (a[i] == a[i + 1]) {
                has_pair[a[i]] = true;
            }
        }
        for (auto [l, r] : segs) {
            int ln = r - l + 1;
            if (has_pair[a[l - 1]] || has_pair[a[r + 1]] || a[l - 1] == a[r + 1]) continue;
            if (ln % 2 == 0) {
                even.eb(mp(a[l - 1], a[r + 1]), mp(l, r));
            }
        }

        vector<int> nums;
        for (auto& v : comps)
            for (int k : v)
                nums.pb(k);

        for (auto [ab, _] : even) {
            nums.pb(ab.first);
            nums.pb(ab.second);
        }
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());

        if (!nums.empty()) {
            DSU d(nums.size());
            for (auto& v : comps) {
                for (int i = 0; i + 1 < v.size(); ++i) {
                    d.un(lowb(nums, v[i]), lowb(nums, v[i + 1]));
                }
            }

            vector<int> pars;
            for (int i = 0; i < nums.size(); ++i) {
                if (d.par(i) == i) {
                    pars.pb(i);
                }
            }

            vector<vector<int>> g(pars.size());
            for (auto& [ab, _] : even) {
                auto& [a, b] = ab;
                a = lowb(nums, a);
                b = lowb(nums, b);
            }
            map<pair<int, int>, int> eind;
            for (int i = 0; i < even.size(); ++i) {
                auto [a, b] = even[i].first;
                a = d.par(a);
                b = d.par(b);
                a = lowb(pars, a);
                b = lowb(pars, b);
                if (eind.count({a, b})) continue;
                g[a].pb(b);
                g[b].pb(a);
                eind[{a, b}] = i;
                eind[{b, a}] = i;
            }

            auto mt = edmonds(g);
            show(mt);
            for (auto p : mt) {
                assert(eind.count(p));
                auto [ab, ij] = even[eind[p]];
                a[ij.first] = nums[ab.first];
                a[ij.second] = nums[ab.second];
            }
        }
    }
    show(a);

    do_odd(true);

    show(a);
    set<int> left;
    for (int i = 1; i <= n; ++i)
        left.insert(i);
    for (int i = 0; i + 1 < n; ++i) {
        if (a[i] == a[i + 1])
            left.erase(a[i]);
    }

    for (int i = 0; i + 1 < n; ++i) {
        if (a[i] == 0 && a[i + 1] == 0) {
            a[i] = a[i + 1] = *left.begin();
            left.erase(left.begin());
        }
    }
    show(a);
    for (int i = 0; i < n; ++i)
        if (a[i] == 0)
            a[i] = n;
    show(a);
    cout << a << '\n';

    return 0;
}