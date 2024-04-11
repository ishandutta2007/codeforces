#include <bits/stdc++.h>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define RE(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define R(i,n) REP(i,n)
#define VI vector<int>
#define PII pair<int,int>
#define LD long double
#define FI first
#define SE second
#define st FI
#define nd SE
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())

template<class C> void mini(C& _a4, C _b4) { _a4 = min(_a4, _b4); }
template<class C> void maxi(C& _a4, C _b4) { _a4 = max(_a4, _b4); }

template<class TH> void _dbg(const char *sdbg, TH h){ cerr << sdbg << '=' << h << endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#define debugv(CC) {cerr<<#CC<<"=";for(auto&cc:CC)cerr<<cc<<",";cerr<<endl;}
#else
#define debug(...) (__VA_ARGS__)
#define debugv(CC) {}
#define cerr if(0)cout
#endif

struct Dinic {
  struct Edge {
    int v, c, inv;
  };
  
public:
  Dinic() {
    n = -1;
  }  
  
  void AddEdge(int a, int b, int cap, int bi_dir) {
    if (n < max(a, b)) {
      n = max(n, max(a, b));
      ResizeVectors();
    }
    e_orig[a].PB(Edge{b, cap, SZ(e_orig[b])});
    e_orig[b].PB(Edge{a, bi_dir * cap, SZ(e_orig[a]) - 1});
  }
  
  int MaxFlow(int s, int t) {
    e = e_orig;
    int result = 0;
    while (Bfs(s, t)) {
      for (int i = 0; i <= n; i++) {
        beg[i] = 0;
      }
      result += Dfs(s, t, kInf);
    }
    return result;
  }

  vector<bool> MinCut(int s, int t) {
    assert(!Bfs(s, t));
    vector<bool> res(n + 1);
    for (int i = 0; i <= n; i++) { if (dis[i] <= n) { res[i] = true; } }
    return res;
  }
  
private:
  int n;
  vector<vector<Edge>> e_orig, e;
  VI dis, beg;
  vector<PII> cut;
  
  bool Bfs(int s, int t) {
    for (int i = 0; i <= n; i++) {
      dis[i] = n + 1;
    }
    dis[s] = 0;
    VI que;
    que.push_back(s);
    for (int i = 0; i < SZ(que); i++) {
      int v = que[i];
      for (auto edge : e[v]) {
        int nei = edge.v;
        if (edge.c && dis[nei] > dis[v] + 1) {
          dis[nei] = dis[v] + 1;
          que.push_back(nei);
          if (nei == t) {
            cut.clear();
            return true;
          }
        } else if (!edge.c) {
          cut.PB(MP(v, nei));
        }
      }
    }
    return false;
  }
  
  int Dfs(int v, int t, int min_cap) {
    int result = 0;
    if (v == t || min_cap == 0) {
      return min_cap;
    }
    for (int& i = beg[v]; i < SZ(e[v]); i++) {
      int nei = e[v][i].v;
      int c = e[v][i].c;
      if (dis[nei] == dis[v] + 1 && c > 0) {
        int flow_here = Dfs(nei, t, min(min_cap, c));
        result += flow_here;
        min_cap -= flow_here;
        e[v][i].c -= flow_here;
        e[nei][e[v][i].inv].c += flow_here;
      }
      if (min_cap == 0) {
        break;
      }
    }
    return result;
  }
  
  void ResizeVectors() {
    e_orig.resize(n + 2);
    beg.resize(n + 2);
    dis.resize(n + 2);
  }
  
#ifdef int
  static const int kInf = 1e18;
#else
  static const int kInf = 1e9;
#endif
  
};

struct GomoryHu {
  vector<vector<pair<int, int>>> graph, tree;
  vector<vector<int>> nodes;
  vector<bool> visited;
  vector<int> groupId, contrId;
  int wnode, n;

  GomoryHu(int N) : graph(N), tree(N), visited(N), groupId(N), contrId(N), n(N) {}

  void addEdge(int u, int v, int cap) {
    graph[u].emplace_back(v, cap);
    graph[v].emplace_back(u, cap);
  }

  void dfs(int v, int type) {
    visited[v] = true; contrId[v] = type;
    for (auto P : tree[v]) {
      if (!visited[P.first]) { dfs(P.first, type); }
    }
  }

  vector<vector<pair<int, int>>> run() {
    vector<int> allNodes(n);
    iota(ALL(allNodes), 0);
    nodes = vector<vector<int>>{allNodes};
    fill(ALL(groupId), 0);

    for (int step = 1; step < n; step++) {
      Dinic dinic;

      for (int i = 0; i < SZ(nodes); i++) {
        if (SZ(nodes[i]) > 1) { wnode = i; break; }
      }
      fill(ALL(visited), false);

      visited[wnode] = true;
      for (auto P : tree[wnode]) { dfs(P.first, nodes[P.first][0]); }
      for (int v = 0; v < n; v++) {
        int a = groupId[v] == wnode ? v : contrId[groupId[v]];
        for (auto& P : graph[v]) {
          int b = groupId[P.first] == wnode ? P.first : contrId[groupId[P.first]];
          if (a != b) { dinic.AddEdge(a, b, P.second, 0); }
        }
      }
      dinic.AddEdge(n-1, n-1, 0, 0);

      int a = nodes[wnode][0], b = nodes[wnode][1], f = dinic.MaxFlow(a, b);
      auto cut = dinic.MinCut(a, b);

      for (int v = 0; v < step; v++) {
        if (v == wnode) { continue; }
        for (auto& P : tree[v]) {
          if (P.first == wnode && !cut[contrId[v]]) { P.first = step; }
        }
      }
      
      vector<pair<int,int>> PA, PB;
      for (auto& P : tree[wnode]) { (cut[contrId[P.first]] ? PA : PB).emplace_back(P.first, P.second); }
      tree[wnode] = PA; tree[step] = PB;
      tree[wnode].emplace_back(step, f);
      tree[step].emplace_back(wnode, f);
      vector<int> A, B;
      for (int v : nodes[wnode]) {
        (cut[v] ? A : B).push_back(v);
        if (!cut[v]) { groupId[v] = step; }
      }
      nodes[wnode] = A;
      nodes.push_back(B);
    }

    vector<vector<pair<int,int>>> res(n);
    for (int i = 0; i < n; i++) {
      for (auto P : tree[i]) { res[nodes[i][0]].emplace_back(nodes[P.first][0], P.second); }
    }
    return res;
  }
};


#undef int
int main() {
#define int LL
  int N, M;

  cin >> N >> M;
  GomoryHu gomory(N);

  for (int i = 0; i < M; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    gomory.addEdge(u - 1, v - 1, c);
  }
 
  auto V = gomory.run();
  
  vector<int> connRoot(N);
  vector<list<int>> vertList(N);
  iota(ALL(connRoot), 0);
  for (int i = 0; i < N; i++) { vertList[i].push_back(i); }
  
  vector<tuple<int, int, int>> edges;
  for (int i = 0; i < N; i++) {
    for (auto& P : V[i]) {
      if (i < P.first) { edges.emplace_back(-P.second, i, P.first); }
    }
  }
  
  sort(ALL(edges));
  
  int sum = 0;
  for (auto E : edges) {
    int from = get<1>(E), to = get<2>(E);
    sum -= get<0>(E);
    from = connRoot[from]; to = connRoot[to];
    if (from > to) { swap(from, to); }
    debug(from, to);
    vertList[from].splice(vertList[from].end(), vertList[to]);
    for (int i = 0; i < N; i++) {
      if (connRoot[i] == to) { connRoot[i] = from; }
    }
  }
  
  cout << sum << "\n";
  for (int v : vertList[0]) { cout << v + 1 << " "; }
  cout << "\n";
  
}