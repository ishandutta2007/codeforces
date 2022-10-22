#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 205;

template <typename T>
class graph {
  public:
  struct edge {
    int from;
    int to;
    T cost;
  };
 
  vector <edge> edges;
  vector < vector <int> > g;
  int n;
 
  graph(int n) : n(n) {
    g.resize(n);
  }
 
  virtual void add(int from, int to, T cost) = 0;
};
 
template <typename T>
class undigraph : public graph<T> {
  public:
  using graph<T>::edges;
  using graph<T>::g;
  using graph<T>::n;
 
  undigraph(int n) : graph<T>(n) {
  }
 
  void add(int from, int to, T cost = 1) {
    assert(0 <= from && from < n && 0 <= to && to < n);
    g[from].push_back(edges.size());
    g[to].push_back(edges.size());
    edges.push_back({from, to, cost});
  }
};
 
template <typename T>
class forest : public graph<T> {
  public:
  using graph<T>::edges;
  using graph<T>::g;
  using graph<T>::n;
 
  forest(int n) : graph<T>(n) {
  }
 
  void add(int from, int to, T cost = 1) {
    assert(0 <= from && from < n && 0 <= to && to < n);
    g[from].push_back(edges.size());
    g[to].push_back(edges.size());
    edges.push_back({from, to, cost});
  }
};

template <typename T>
class flow_graph {
  public:
  static constexpr T eps = (T) 1e-9;
 
  struct edge {
    int to;
    T c;
    T f;
    int rev;
  };
 
  vector< vector<edge> > g;
  vector<int> ptr;
  vector<int> d;
  vector<int> q;
  vector<int> cnt_on_layer;
  vector<int> prev_edge;
  vector<T> to_push;
  vector<T> pushed;
  vector<int> smallest;
  bool can_reach_sink;
 
  int n;
  int st, fin;
  T flow;

flow_graph(int n, int st, int fin) : n(n), st(st), fin(fin) {
    assert(0 <= st && st < n && 0 <= fin && fin < n && st != fin);
    g.resize(n);
    ptr.resize(n);
    d.resize(n);
    q.resize(n);
    cnt_on_layer.resize(n + 1);
    prev_edge.resize(n);
    to_push.resize(n);
    pushed.resize(n);
    smallest.resize(n);
    flow = 0;
  }
 
  void clear_flow() {
    for (int i = 0; i < n; i++) {
      for (edge &e : g[i]) {
        e.f = 0;
      }
    }
    flow = 0;
  }
   
  void add(int from, int to, T forward_cap, T backward_cap) {
    assert(0 <= from && from < n && 0 <= to && to < n);
    int from_size = g[from].size();
    int to_size = g[to].size();
    g[from].push_back({to, forward_cap, 0, to_size});
    g[to].push_back({from, backward_cap, 0, from_size});
  }
 
  bool expath() {
    fill(d.begin(), d.end(), n);
    q[0] = fin;
    d[fin] = 0;
    fill(cnt_on_layer.begin(), cnt_on_layer.end(), 0);
    cnt_on_layer[n] = n - 1;
    cnt_on_layer[0] = 1;
    int beg = 0, end = 1;
    while (beg < end) {
      int i = q[beg++];
      for (const edge &e : g[i]) {
        const edge &back = g[e.to][e.rev];
        if (back.c - back.f > eps && d[e.to] == n) {
          cnt_on_layer[d[e.to]]--;
          d[e.to] = d[i] + 1;
          cnt_on_layer[d[e.to]]++;
          q[end++] = e.to;
        }
      }
    }
    return (d[st] != n);
  }
 
  void rollback(int &v) {
    edge &e = g[v][prev_edge[v]];
    if (pushed[v]) {
      edge &back = g[e.to][e.rev];
      back.f += pushed[v];
      e.f -= pushed[v];
      pushed[e.to] += pushed[v];
      to_push[e.to] -= pushed[v];
      pushed[v] = 0;
    }
    v = e.to;
  }
 
  void augment(int &v) {
    pushed[v] += to_push[v];
    to_push[v] = 0;
    int new_v = smallest[v];
    while (v != new_v) {
      rollback(v);
    }
  }
 
  void retreat(int &v) {
    int new_dist = n - 1;
    for (const edge &e : g[v]) {
      if (e.c - e.f > eps && d[e.to] < new_dist) {
        new_dist = d[e.to];
      }
    }
    cnt_on_layer[d[v]]--;
    if (cnt_on_layer[d[v]] == 0) {
      if (new_dist + 1 > d[v]) {
        can_reach_sink = false;
      }
    }
    d[v] = new_dist + 1;
    cnt_on_layer[d[v]]++;
    if (v != st) {
      rollback(v);
    }
  }
   
  T max_flow() {
    can_reach_sink = true;
    for (int i = 0; i < n; i++) {
      ptr[i] = (int) g[i].size() - 1;
    }
    if (expath()) {
      int v = st;
      to_push[v] = numeric_limits<T>::max();
      smallest[v] = v;
      while (d[st] < n) {
        while (ptr[v] >= 0) {
          const edge &e = g[v][ptr[v]];
          if (e.c - e.f > eps && d[e.to] == d[v] - 1) {
            prev_edge[e.to] = e.rev;
            to_push[e.to] = to_push[v];
            smallest[e.to] = smallest[v];
            if (e.c - e.f < to_push[e.to]) {
              to_push[e.to] = e.c - e.f;
              smallest[e.to] = v;
            }
            v = e.to;
            if (v == fin) {
              augment(v);
            }
            break;
          }
          ptr[v]--;
        }
        if (ptr[v] < 0) {
          ptr[v] = (int) g[v].size() - 1;
          retreat(v);
          if (!can_reach_sink) {
            break;
          }
        }
      }
      while (v != st) {
        rollback(v);
      }
      flow += pushed[st];
      pushed[st] = 0;
    }
    return flow;
  }
 
  vector<bool> min_cut() {
    max_flow();
    assert(!expath());
    vector<bool> ret(n);
    for (int i = 0; i < n; i++) {
      ret[i] = (d[i] != n);
    }
    return ret;
  }
};

template <typename T>
forest<T> gomory_hu(const undigraph<T> &g) {
  int n = g.n;
  flow_graph<T> fg(n, 0, 1);
  for (auto &e : g.edges) {
    fg.add(e.from, e.to, e.cost, e.cost);
  }
  forest<T> ret(n);
  vector<int> pr(n, 0);
  for (int i = 1; i < n; i++) {
    fg.clear_flow();
    fg.st = i;
    fg.fin = pr[i];
    T flow = fg.max_flow();
    vector<bool> cut = fg.min_cut();
    for (int j = i + 1; j < n; j++) {
      if (cut[j] == cut[i] && pr[j] == pr[i]) {
        pr[j] = i;
      }
    }
    ret.add(i, pr[i], flow);
  }
  return ret;
}

int n, m;
int res;
bool forb[Maxn];
vector <int> ans;

ii getSmallest(forest <int> &T, int v, int p)
{
    ii res = ii(-1, -1);
    for (int i = 0; i < T.g[v].size(); i++) {
        int e = T.g[v][i];
        if (forb[e]) continue;
        int u = T.edges[e].from == v? T.edges[e].to: T.edges[e].from;
        if (u == p) continue;
        ii cand = ii(e, u);
        if (res.first == -1 || T.edges[cand.first].cost < T.edges[res.first].cost)
            res = cand;
        cand = getSmallest(T, u, v);
        if (res.first == -1 || T.edges[cand.first].cost < T.edges[res.first].cost)
            res = cand;
    }
    return res;
}

void Solve(forest <int> &T, int v)
{
    ii got = getSmallest(T, v, 0);
    if (got.first == -1) return;
    forb[got.first] = true;
    Solve(T, v);
    ans.push_back(got.second);
    Solve(T, got.second);
}

int main()
{
    scanf("%d %d", &n, &m);
    undigraph <int> G(n);
    for (int i = 0; i < m; i++) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        a--; b--;
        G.add(a, b, c);
    }
    auto T = gomory_hu(G);
    for (auto e: T.edges)
        res += e.cost;
    printf("%d\n", res);
    ans.push_back(0);
    Solve(T, 0);
    for (int i = 0; i < ans.size(); i++)
        printf("%d%c", ans[i] + 1, i + 1 < ans.size()? ' ': '\n');
    return 0;
}