#include <algorithm>
#include <iostream>
#include <vector>
#include <array>
#include <cstring>
#include <ext/pb_ds/priority_queue.hpp>
#include <cstdio>
#include <numeric>

struct UnsafeInput {
  static constexpr int bufsz = 1 << 15;

  UnsafeInput() {
    read();
  }

  void read() {
    fread(buf + 1, 1, sizeof buf - 1, stdin);
    bufptr = buf;
  }

  template <typename T>
  void operator()(T* b, size_t n) {
    for (size_t i = 0; i < n; ++i) {
      b[i] = {};
    }
    (*this)(b, b + n);
  }

  template <typename ...Ts>
  auto operator()(Ts&... xs) -> std::enable_if_t<(!std::is_pointer_v<std::decay_t<Ts>> && ...)> {
    ((*this)(&(xs = {}), &xs + 1), ...);
  }

  char buf[bufsz], *bufptr = buf;
private:

  template <typename T>
  void operator()(T* b, T* e) {
    bool sign = 0;
    while (b != e) {
      if (++bufptr == buf + bufsz) {
        read();
      } else if (*bufptr == '-') {
        sign = 1;
      } else if (*bufptr < '0') {
        *b++ *= sign? -1: 1, sign = 0;
      } else {
        *b = *b * 10 + *bufptr - '0';
      }
    }
  }
} reader;

using namespace std;

bool online_judge =
                    #ifdef ONLINE_JUDGE
                    1;
                    #else
                    0;
                    #endif
struct { using X = int; template <typename T = X> T operator()() { T t; cin >> t; return t; } operator X() { return operator()(); } template <typename T> operator T() { return operator()<T>(); } } $;
void print(const auto&... ts) { string sep = ""; ((cout << sep << ts, sep = " "), ...); cout << '\n'; }
auto print(const auto& c) -> decltype(c.begin(), void()) { cout << c.end() - c.begin() << ' ' << c << '\n'; }
auto operator>>(istream& in, auto&& c) -> enable_if_t<!is_same_v<decay_t<decltype(c)>, string>, decltype(c.begin(), in)> { for (auto& i: c) in >> i; return in; }
auto operator<<(ostream& out, const auto& c) -> enable_if_t<!is_same_v<decay_t<decltype(c)>, string>, decltype(c.begin(), out)> { string sep = ""; for (auto i: c) out << sep << i, sep = " "; return out; }
template <typename It> struct range { It first, last; range(It first, It last) : first{first}, last{last} {} range(It first, auto n) : range{first, first + n} {} range(auto&& c) : range{c.begin(), c.end()} {} It begin() const { return first; } It end() const { return last; } }; range(auto&& c) -> range<decltype(c.begin())>;
bool minb(auto& a, const auto& b) { return b < a? a = b, 1: 0; } auto& mini(auto&& a, const auto& b) { return minb(a, b), a; } auto mind(auto& a, const auto& b) { auto t = a; return t - mini(a, b); }
bool maxb(auto& a, const auto& b) { return a < b? a = b, 1: 0; } auto& maxi(auto& a, const auto& b) { return maxb(a, b), a; } auto maxd(auto& a, const auto& b) { auto t = a; return maxi(a, b) - t; }
auto unz(auto a) { return max(a, {}); } auto change(auto& a, const auto& b) { auto t = a; return (a = b) - t; }

constexpr int N = 20, K = 200, M = N * K * 4;

int n, k;
int a[1 << N], idx[1 << N];
vector<array<int, 2>> edges;
vector<int> vertices;

struct MCMF {
  using Flow = int;
  using Cost = int;
  static constexpr int N = ::M + 2;
  static constexpr Cost INF = make_unsigned_t<Cost>(-1) / 255 * 127;

  struct Edge {
    int to, r;
    Cost cost;
    Flow cap;

    Edge(int to, int r, Cost cost, Flow cap = {}) : to{to}, r{r}, cost{cost}, cap{cap} {};
  };

  void ae(int u, int v, Flow cap, Cost cost = {}) {
    nei[u].emplace_back(v, nei[v].size(), cost, cap);
    nei[v].emplace_back(u, nei[u].size() - 1, -cost);
  }

  auto& rev(const Edge* e) {
    return nei[e->to][e->r];
  }

  bool relax(Edge& e, int d) {
    return e.cap > 0 && minb(dist[e.to], e.cost + d) && (in[e.to] = &e, 1);
  }

  bool dijkstra(int s, int t) {
    using DV = pair<Cost, int>;
    static auto cmp = [](DV a, DV b){return a.first > b.first;};
    static priority_queue<DV, vector<DV>, decltype(cmp)> pq{cmp};
    memset(dist, INF, sizeof dist);
    pq.emplace(dist[s] = 0, s);
    while (!pq.empty()) if (auto [d, v] = pq.top(); pq.pop(), d == dist[v]) {
      for (auto& e: nei[v]) if (/*(e.cost >= 0 || dist[e.to] == INF) & */relax(e, d)) {
        pq.emplace(dist[e.to], e.to);
      }
    }
    return dist[t] != INF;
  }

  int spfa(int s, int t) {
    static deque<int> q;
    static bool enq[N];
    memset(dist, INF, sizeof dist);
    memset(enq, 0, sizeof enq);
    dist[s] = 0, q.push_back(s);
    int ops{};
    while (q.size()) {
      int v = q.front(); q.pop_front(); enq[v] = 0;
      ops += nei[v].size() + 1;
      for (auto& e: nei[v]) if (relax(e, dist[v]) && !enq[e.to]) {
//        if (e.cost < 0) {
//          q.push_front(e.to);
//        } else {
          q.push_back(e.to);
//        }
        enq[e.to] = 1;
      }
    }
    return dist[t] != INF? ops: 0;
  }

  int spfa2(int s, int t) {
    static vector<int> q, nq;
    static bool enq[N];
    memset(dist, INF, sizeof dist);
    memset(enq, 0, sizeof enq);
    dist[s] = 0, q.push_back(s);
    int ops{};
    while (q.size()) {
      for (auto v: q) if (enq[v] = 0, ops += nei[v].size() + 1)
      for (auto& e: nei[v]) if (relax(e, dist[v]) && !enq[e.to]) {
//        if (e.cost < 0) {
//          q.push_front(e.to);
//        } else {
          nq.push_back(e.to);
//        }
        enq[e.to] = 1;
      }
      swap(q, nq);
      nq.clear();
//      sort(q.begin(), q.end(), [dist=as_const(dist)](int a, int b){return dist[a] < dist[b];});
    }
    return dist[t] != INF? ops: 0;
  }

  int epl(int s, int t) {
    static deque<int> q;
    static int8_t enq[N];
    memset(dist, INF, sizeof dist);
    memset(enq, 2, sizeof enq);
    dist[s] = 0, q.push_back(s);
    int ops{};
    while (q.size()) {
      int v = q.front(); q.pop_front(); enq[v] = 0;
      ops += nei[v].size() + 1;
      for (auto& e: nei[v]) if (relax(e, dist[v])) {
        if (!enq[e.to]) {
          q.push_front(e.to);
        } else if (enq[e.to] == 2) {
          q.push_back(e.to);
        }
        enq[e.to] = 1;
      }
    }
    return dist[t] != INF? ops: 0;
  }

  void reduce_cost() {
    for (int i = 0; i < N; ++i) if (dist[i] != INF) {
      for (auto& e: nei[i]) if (dist[e.to] != INF) {
        e.cost -= dist[e.to] - dist[i];
      }
    }
  }

  bool route(int s, int t) {
    static const int m = accumulate(nei, nei + N, 0, [](int a, auto&& b){return a + b.size();}), dops = 2 * (m + N) * (32 - __builtin_clz(m + 1));
    static int wops{};
    auto ops = wops > dops? dijkstra(s, t): spfa2(s, t);
    maxi(wops, ops);
    return ops;
  }

  auto solve(int s, int t, Flow target) {
    if (target == -1) {
      target = numeric_limits<Flow>::max();
    }
    Cost cost{}, reduced_dist{};
    Flow flow{};
    while (flow < target && route(s, t)) {
      reduce_cost();
      reduced_dist += dist[t];
      Flow cap = target - flow;
      for (auto pass: {0, 1})
      for (int i = t; i != s; i = rev(in[i]).to) {
        pass? in[i]->cap -= cap, rev(in[i]).cap += cap:
              mini(cap, in[i]->cap);
      }
      flow += cap;
      cost += reduced_dist * cap;
    }
    return pair{cost, flow};
  }

  vector<Edge> nei[N];
  Cost dist[N];
  Edge* in[N];
} mcmf;

int main() {
  reader(n, k);
  reader(a, 1 << n);
  auto shrink = [](){
    auto last = min(edges.begin() + 2 * n * k, edges.end());
    nth_element(edges.begin(), last, edges.end(), [](const auto& x, const auto& y) {return a[x[0]] + a[x[1]] > a[y[0]] + a[y[1]];});
    edges.erase(last, edges.end());
  };
  for (int i = 0; i < 1 << n; ++i) if (__builtin_parity(i))
  for (int d = 0; d < n; ++d) {
    int j = i ^ (1 << d);
    edges.push_back({i, j});
    if (edges.size() >= 6 * n * k) {
      shrink();
    }
  }
  shrink();
  for (auto& [u, v]: edges) {
    vertices.push_back(u);
    vertices.push_back(v);
  }
  sort(vertices.begin(), vertices.end());
  vertices.erase(unique(vertices.begin(), vertices.end()), vertices.end());
  int s = vertices.size(), t = s + 1;
  for (auto& v: vertices) {
    idx[v] = &v - &vertices[0];
    if (__builtin_parity(v)) {
      mcmf.ae(s, idx[v], 1);
    } else {
      mcmf.ae(idx[v], t, 1);
    }
  }
  for (auto [u, v]: edges) {
    mcmf.ae(idx[u], idx[v], 999, -a[v] - a[u]);
  }
  cout << -mcmf.solve(s, t, k).first << '\n';
}