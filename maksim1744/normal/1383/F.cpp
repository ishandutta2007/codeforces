/*
    author:  Maksim1744
    created: 06.05.2021 21:52:22
*/

#pragma GCC target("avx,avx2")
#pragma GCC target("popcnt")
#pragma GCC target("sse,sse2,sse3,sse4.1")

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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd (ll l, ll r) { return (ll)(rng() % (r - l + 1)) + l; }
ll rnd (ll r)       { return rng() % r; }
ll rnd ()           { return rng(); }
ld rndf()           { return (ld)rng() / (ld)ULLONG_MAX; }
ld rndf(ld l, ld r) { return rndf() * (r - l) + l; }

int sz2;

auto start_time = clock();

int caap = 1e9;

using T = int;
struct edge {
int from;
int to;
T c;
T f;
};
class flow_graph {
  public:
  static constexpr T eps = (T) 1e-9;
  vector< vector<int> > g;
  vector<edge> edges;
  int n;
  int st;
  int fin;
  T flow;
  flow_graph() {}
  flow_graph(int _n, int _st, int _fin) : n(_n), st(_st), fin(_fin) {
    assert(0 <= st && st < n && 0 <= fin && fin < n && st != fin);
    g.resize(n);
    flow = 0;
  }
  void clear_flow() {
    flow = 0;
  }
   
  int add(int from, int to, T forward_cap, T backward_cap) {
    assert(0 <= from && from < n && 0 <= to && to < n);
    int id = (int) edges.size();
    g[from].push_back(id);
    edges.push_back({from, to, forward_cap, 0});
    g[to].push_back(id + 1);
    edges.push_back({to, from, backward_cap, 0});
    return id;
  }

  void srt() {
    for (auto &v : g) {
        // for (int i = 0; i < v.size(); ++i) {
        //     swap(v[i], v[rnd(i, v.size() - 1)]);
        // }
        sort(v.begin(), v.end(), [&](int i, int j) {
            return edges[i].c < edges[j].c;
        });
    }
  }
};

using T = int;
class dinic {
  public:
  flow_graph &g;
  vector<int> ptr;
  vector<int> d;
  vector<int> q;
  dinic(flow_graph &_g) : g(_g) {
    ptr.resize(g.n);
    d.resize(g.n);
    q.resize(g.n);
  }
  bool expath() {
    fill(d.begin(), d.end(), -1);
    q[0] = g.fin;
    d[g.fin] = 0;
    int beg = 0, end = 1;
    while (beg < end) {
      int i = q[beg++];
      for (int id : g.g[i]) {
        const auto &e = g.edges[id];
        const auto &back = g.edges[id ^ 1];
        if (back.c - back.f > g.eps && d[e.to] == -1) {
          d[e.to] = d[i] + 1;
          if (e.to == g.st) {
            return true;
          }
          q[end++] = e.to;
        }
      }
    }
    return false;
  }
   
  T dfs(int v, T w) {
    if (v == g.fin) {
      return w;
    }
    int &j = ptr[v];
    while (j >= 0) {
      int id = g.g[v][j];
      const auto &e = g.edges[id];
      if (e.c - e.f > g.eps && d[e.to] == d[v] - 1) {
        T t = dfs(e.to, min(e.c - e.f, w));
        if (t > g.eps) {
          g.edges[id].f += t;
          g.edges[id ^ 1].f -= t;
          return t;
        }
      }
      j--;
    }
    return 0;
  }
  T max_flow() {
    while (expath()) {
      for (int i = 0; i < g.n; i++) {
        ptr[i] = (int) g.g[i].size() - 1;
      }
      while (true) {
        T add = dfs(g.st, numeric_limits<T>::max());
        if (add <= g.eps) {
          break;
        }
        g.flow += add;
        if (g.flow >= caap) break;
      }
      if (g.flow >= caap) break;
    }
    return g.flow;
  }
  vector<bool> min_cut() {
    max_flow();
    vector<bool> ret(g.n);
    for (int i = 0; i < g.n; i++) {
      ret[i] = (d[i] != -1);
    }
    return ret;
  }
  array<char, (int)1e4 + 20> u;
  array<pair<int, pair<int, int>>, (int)1e4 + 20> st;
  T dfs3() {
    st[0] = {g.st, mp((int)g.g[g.st].size() - 1, 10000)};
    int ist = 1;
    bool found = false;
    int f = 0;
    while (ist) {
        auto &[v, indmx] = st[ist - 1];
        auto &[ind, mx] = indmx;
        u[v] = 1;
        if (v == g.fin) {
            f = mx;
            found = true;
            --ist;
            continue;
        }
        if (found) {
            ++ind;
            auto &e = g.edges[g.g[v][ind]];
            auto &back = g.edges[g.g[v][ind] ^ 1];
            if (ind + 1 < g.g[v].size() && g.g[v][ind + 1] < sz2)
                swap(g.g[v][ind], g.g[v][ind + 1]);
            e.f += f;
            back.f -= f;
            --ist;
        } else if (ind == -1) {
            --ist;
        } else {
            auto &e = g.edges[g.g[v][ind]];
            if (e.c - e.f == 0 || u[e.to]) {
                --ind;
                continue;
            }
            st[ist] = {e.to, mp((int)g.g[e.to].size() - 1, min(mx, e.c - e.f))};
            ++ist;
            --ind;
        }
    }
    return f;
  }

  T dfs2(int v, int mx = 1e9) {
    u[v] = true;
    if (v == g.fin)
        return mx;
    for (int ind = (int)g.g[v].size() - 1; ind >= 0; --ind) {
        auto &e = g.edges[g.g[v][ind]];
        if (e.c - e.f && !u[e.to]) {
            int cur = dfs2(e.to, min(mx, e.c - e.f));
            if (cur == 0) continue;
            auto &back = g.edges[g.g[v][ind] ^ 1];
            back.f -= cur;
            e.f += cur;
            return cur;
        }
    }
    return 0;
  }

  array<int, (int)1e4 + 20> val;
  array<int, (int)1e4 + 20> vali;
  T bfs2() {
    static array<int, (int)1e4 + 20> q;
    for (int i = 0; i < g.n; ++i) {
        val[i] = 0;
        vali[i] = -1;
    }
    int ql = 0, qr = 1;
    q[0] = g.st;
    val[0] = 1e9;
    while (ql < qr) {
        int v = q[ql];
        ++ql;
        if (v == g.fin) break;
        for (int ind = 0; ind < g.g[v].size(); ++ind) {
            auto &e = g.edges[g.g[v][ind]];
            if (e.c - e.f == 0) continue;
            int to = e.to;
            if (val[to] == 0) q[qr++] = to;
            int cur = min(val[v], e.c - e.f);
            if (cur > val[to]) {
                val[to] = cur;
                vali[to] = g.g[v][ind];
            }
        }
    }
    int f = val[g.fin];
    if (f == 0) return 0;
    int v = g.fin;
    while (v != g.st) {
        int ind = vali[v];
        g.edges[ind].f += f;
        g.edges[ind ^ 1].f -= f;
        v = g.edges[ind].from;
    }
    return f;
  }

  T max_flow2() {
    while (true) {
        for (int i = 0; i < g.n; ++i)
            u[i] = 0;
        // int f = bfs2();
        int f = dfs3();
        show(f);
        if (f == 0) break;
        g.flow += f;
        if (g.flow >= caap) break;
    }
    show(g.flow);
    return g.flow;
  }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m, k, q;
    cin >> n >> m >> k >> q;

    vector<pair<int, int>> extra;
    flow_graph fg0(n, 0, n - 1);

    map<pair<int, int>, int> tote;

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        if (i < k) {
            extra.eb(u, v);
        } else {
            tote[{u, v}] += w;
        }
    }
    for (auto [uv, w] : tote) {
        auto [u, v] = uv;
        fg0.add(u, v, w, 0);
    }

    int initial = dinic(fg0).max_flow();
    flow_graph fg(n, 0, n - 1);

    map<pair<int, int>, int> e1;

    for (int j = 0; j < fg0.edges.size(); ++j) {
        auto &e = fg0.edges[j];
        e1[{e.from, e.to}] += e.c - e.f;
        e1[{e.to, e.from}] += 0;
    }

    show(e1);

    for (auto [uv, w] : e1) {
        auto [u, v] = uv;
        if (u >= v) continue;
        int tot = e1[{u, v}] - e1[{v, u}];
        if (tot == 0) continue;
        if (tot < 0) swap(u, v);
        tot = abs(tot);
        show(u, v, tot);
        fg.add(u, v, tot, 0);
    }

    const int inf = 250;

    vector<int> prec(1 << k, inf);

    mclock;

    int done = 0;
    int real_done = 0;

    auto first_dif = [&](int i, int j) {
        for (int b = k - 1; b >= 0; --b) {
            if (((i >> b) & 1) != ((j >> b) & 1))
                return b;
        }
        return 0;
    };

    fg.srt();

    vector<vector<edge>> meme(1 << k);
    vector<int> memf(1 << k);
    for (auto [u, v] : extra)
        fg.add(u, v, 0, 0);
    int sz = fg.edges.size();
    sz2 = sz - k * 2;

    dinic d(fg);

    vector<array<int, (int)2e4 + 200>> mem(1 << k);

    for (int i = ((1 << k) - 1); i >= 0; --i) {
        ++done;
        if (i == (1 << k) - 1) {
            caap = (k - __builtin_popcount(i)) * 25;
            for (int j = 0; j < (1 << k); ++j) {
                if (i == j) continue;
                if ((i & j) == j && prec[j] <= prec[i])
                    caap = min(caap, prec[j]);
                if ((i & j) == i && prec[j] + 25 * __builtin_popcount(i ^ j) <= prec[i])
                    caap = min(caap, prec[j] + 25 * __builtin_popcount(i ^ j));
            }
            if (caap == 0) prec[i] = 0;
            else {
                ++real_done;
                prec[i] = d.max_flow2();
            }
        } else {
            int b = first_dif(i, (1 << k) - 1);
            for (int j = 0; j < sz; ++j) {
                fg.edges[j].f = mem[i ^ (1 << b)][j];
            }
            for (int j = 0; j < k; ++j) {
                if (((i >> j) & 1) == 0)
                    fg.edges[sz - (k - j) * 2].c = inf;
                else
                    fg.edges[sz - (k - j) * 2].c = 0;
            }
            fg.flow = memf[i ^ (1 << b)];

            caap = (k - __builtin_popcount(i)) * 25;
            for (int j = 0; j < (1 << k); ++j) {
                if (i == j) continue;
                if ((i & j) == j && prec[j] <= prec[i])
                    caap = min(caap, prec[j]);
                if ((i & j) == i && prec[j] + 25 * __builtin_popcount(i ^ j) <= prec[i])
                    caap = min(caap, prec[j] + 25 * __builtin_popcount(i ^ j));
            }
            if (caap == 0) prec[i] = 0;
            else {
                ++real_done;
                prec[i] = d.max_flow2();
            }
        }
        for (int j = 0; j < sz; ++j) {
            mem[i][j] = fg.edges[j].f;
        }
        memf[i] = fg.flow;

        if ((clock() - start_time) * 1.0 / CLOCKS_PER_SEC > 4.6) break;
    }

    show(prec);

    vector<bool> useless(1 << k, false);
    for (int i = 0; i < (1 << k); ++i) {
        for (int j = 0; j < (1 << k); ++j) {
            if (i == j) continue;
            if ((i & j) == j && prec[j] <= prec[i])
                useless[i] = true;
            if ((i & j) == i && prec[j] + 25 * __builtin_popcount(i ^ j) <= prec[i])
                useless[i] = true;
        }
    }

    vector<pair<int, int>> good;
    for (int i = 0; i < (1 << k); ++i) {
        if (!useless[i]) {
            good.eb(i, prec[i]);
        }
    }

    show(good.size());

    sort(good.begin(), good.end(), [&](const auto &a, const auto &b) {
        return a.second < b.second;
    });

    mclock;

    array<unsigned char, 1 << 5> c1, c2;
    
    array<int, 10> w;
    w.fill(0);
    
    while (q--) {
        for (int i = 0; i < k; ++i) {
            cin >> w[i];
        }
        int ans = inf;
    
        c1.fill(0);
        c2.fill(0);
        for (int i = 0; i < (1 << 5); ++i) {
            for (int j = 0; j < 5; ++j) {
                if ((i >> j) & 1) {
                    c1[i] += w[j];
                    c2[i] += w[j + 5];
                }
            }
        }
    
        for (auto [i, cur] : good) {
            if (cur >= ans) break;
            ans = min(ans, cur + c1[i & 31] + c2[i >> 5]);
        }
        cout << initial + ans << '\n';
    }

    mclock;

    return 0;
}