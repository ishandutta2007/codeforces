/*
    author:  Maksim1744
    created: 26.05.2021 00:08:10
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

struct dinic_edge {
    int from, to;
    long long mx;
};

vector<dinic_edge> e0;

long long max_flow_dinic(vector<vector<pair<int, long long>>> g_main, int s, int t) {
    int n = g_main.size();
    vector<vector<int>> g(n);
    vector<dinic_edge> e;
    for (int u = 0; u < n; ++u) {
        for (auto pr : g_main[u]) {
            int v = pr.first;
            long long w = pr.second;
            g[u].push_back(e.size());
            e.push_back({u, v, w});
            g[v].push_back(e.size());
            e.push_back({v, u, 0});
        }
    }
    long long flow = 0;
    vector<int> layer(n, -5);
    vector<int> q(n + 10);
    int ql, qr;
    vector<int> ptr(n, 0);
    for (int i = 0; i < n; ++i) {
        layer.assign(n, -5);
        ptr.assign(n, 0);
        ql = 0;
        qr = 1;
        q[0] = s;
        layer[s] = 0;
        while (ql < qr) {
            int v = q[ql++];
            for (auto k : g[v]) {
                if (e[k].mx > 0 && layer[e[k].to] == -5) {
                    layer[e[k].to] = layer[v] + 1;
                    q[qr++] = e[k].to;
                }
            }
        }
        if (layer[t] == -5)
            break;
        long long prev_flow = flow;
        while (true) {
            function<long long(int, long long)> go = [&](int v, long long now) -> long long {
                if (v == t)
                    return now;
                while (ptr[v] < g[v].size()) {
                    if (layer[v] + 1 == layer[e[g[v][ptr[v]]].to] && e[g[v][ptr[v]]].mx > 0) {
                        long long next = min(now, e[g[v][ptr[v]]].mx);
                        long long x = go(e[g[v][ptr[v]]].to, next);
                        if (x > 0) {
                            e[g[v][ptr[v]]].mx -= x;
                            e[g[v][ptr[v]]^1].mx += x;
                            return x;
                        } else {
                            ++ptr[v];
                        }
                    } else {
                        ++ptr[v];
                    }
                }
                return 0;
            };
            long long el_flow = go(s, 1e9l * 1e9l * 4l);
            if (el_flow == 0)
                break;
            flow += el_flow;
        }
        if (flow == prev_flow)
            break;
    }
    e0 = e;
    return flow;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    int ln = 0;
    {
        int p10 = 1;
        while (n >= p10) {
            p10 *= 10;
            ++ln;
        }
    }
    show(ln);
    vector<vector<int>> cnt(ln + 1, vector<int>(ln + 1, 0));
    vector<int> first(ln + 1);
    vector<int> last(ln + 1);
    first[1] = 1;
    last[1] = 9;
    for (int i = 2; i < first.size(); ++i) {
        first[i] = first[i - 1] * 10;
        last[i] = last[i - 1] * 10 + 9;
    }
    last.back() = n;
    vector<pair<int, int>> ans;
    for (int i = 0; i < n - 1; ++i) {
        string s, t;
        cin >> s >> t;
        // if (s.size() == t.size()) {
        //     int k = s.size();
        //     if (cur[k] == last[k]) {
        //         cout << -1 << '\n';
        //         return 0;
        //     }
        //     ans.eb(first[k], cur[k]);
        //     ++cur[k];
        // } else {
        cnt[s.size()][t.size()]++;
        if (t.size() != s.size())
            cnt[t.size()][s.size()]++;
        // }
    }

    vector<pair<int, int>> edges;
    for (int i = 0; i < ln; ++i) {
        for (int j = 0; j < i; ++j) {
            edges.eb(i + 1, j + 1);
        }
    }

    show(edges);

    auto cnt0 = cnt;
    for (int msk = 0; msk < (1 << edges.size()); ++msk) {
        DSU d(n + 1);
        bool ok = true;
        auto cnt = cnt0;
        for (int j = 0; j < edges.size(); ++j) {
            if ((msk >> j) & 1) {
                auto [u, v] = edges[j];
                --cnt[u][v];
                --cnt[v][u];
                if (cnt[u][v] < 0) ok = false;
                if (d.check(u, v)) ok = false;
                d.un(u, v);
            }
        }
        for (int i = 1; i <= ln; ++i)
            if (!d.check(1, i))
                ok = false;
        if (!ok) continue;
        auto cur = first;
        ++cur;
        vector<pair<int, int>> prs;
        for (int i = 1; i <= ln; ++i)
            for (int j = 1; j < i; ++j)
                prs.eb(i, j);

        vector<vector<pair<int, ll>>> g(prs.size() + ln + 2);
        int sz = g.size() - 2;
        for (int i = 0; i < prs.size(); ++i) {
            auto [u, v] = prs[i];
            g[sz].eb(i, cnt[u][v]);
            g[i].eb(prs.size() + v - 1, 1e9);
            g[i].eb(prs.size() + u - 1, 1e9);
        }
        show(cnt);

        int need = n - 1 - (ln - 1);
        show(last);
        show(first);
        for (int i = 0; i < ln; ++i) {
            int k = last[i + 1] - first[i + 1] - cnt[i + 1][i + 1];
            show(k);
            if (k < 0) {
                ok = false;
                break;
            }
            g[i + prs.size()].eb(sz + 1, last[i + 1] - first[i + 1] - cnt[i + 1][i + 1]);
            need -= cnt[i + 1][i + 1];
        }
        if (!ok) continue;

        auto fl = max_flow_dinic(g, sz, sz + 1);
        show(fl, need);
        assert(fl <= need);
        if (fl == need) {
            for (int i = 1; i <= ln; ++i) {
                for (int j = 0; j < cnt[i][i]; ++j) {
                    ans.eb(first[i], cur[i]);
                    ++cur[i];
                }
            }
            for (int i = 0; i < e0.size(); i += 2) {
                if (e0[i].to >= prs.size() && e0[i].to - prs.size() < ln) {
                    int to = e0[i].to - prs.size();
                    ++to;
                    auto [u, v] = prs[e0[i].from];
                    assert(u == to || v == to);
                    int fr = u ^ v ^ to;
                    int fl = (int)1e9 - e0[i].mx;
                    show(fr, to, fl);
                    for (int i = 0; i < fl; ++i) {
                        ans.eb(first[fr], cur[to]);
                        ++cur[to];
                    }
                }
            }
            for (int i = 0; i < edges.size(); ++i) {
                if ((msk >> i) & 1) {
                    auto [u, v] = edges[i];
                    ans.eb(first[u], first[v]);
                }
            }

            for (auto [u, v] : ans)
                cout << u << ' ' << v << '\n';

            return 0;
        }
    }
    cout << -1 << '\n';

    return 0;
}