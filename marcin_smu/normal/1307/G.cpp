#pragma GCC optimize("O3")
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// gp_hash_table<int, int> mapka;

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

template<class C> void mini(C &a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C &a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<'='<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;
  cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}

template<class T> ostream &operator<<(ostream& os, vector<T> V) {
  os << "["; for (auto vv : V) os << vv << ","; return os << "]";
}
template<class L, class R> ostream &operator<<(ostream &os, pair<L,R> P) {
  return os << "(" << P.st << "," << P.nd << ")";
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

class MinCostFlow {  
  struct MCEdge { int to, cost, flow; MCEdge* next; };
  const int Infty = 1e9 + 100;
  int N, Source, Sink;
  VI dist;
  vector<MCEdge*> prev, Edges;
  vector<vector<MCEdge*>> adjList;
  
  void spfa() {
    queue<int> Q; vector<bool> onQueue(N); fill(ALL(dist), Infty);
    Q.push(Source); onQueue[Source] = true; dist[Source] = 0;
    while (!Q.empty()) {
      int v = Q.front(); Q.pop(); onQueue[v] = false;
      for (MCEdge *E : adjList[v]) {
        int s = E->to;
        if (E->flow == 0) { continue; }

        int newDist = dist[v] + E->cost;
        if (newDist < dist[s]) {
          dist[s] = newDist;
          prev[s] = E->next;
          if (!onQueue[s]) {
            Q.push(s); onQueue[s] = true;
          }
        }
      }
    }
  }
  
  int reduce_cost() {
    REP (v, N) { for (MCEdge* E: adjList[v]){ E->cost += dist[v] - dist[E->to]; } }
    return dist[Sink];
  }
  void dijkstra_shortest_path(){
    fill(ALL(dist), Infty); dist[Source] = 0;
    priority_queue<PII> Q; Q.push(make_pair(0, Source));
    
    while (!Q.empty()){
      int dst = -Q.top().st, v = Q.top().nd; Q.pop();
      if (dst != dist[v]) { continue; }
      for (MCEdge* E: adjList[v]){
        int s = E->to;
        if (!E->flow) { continue; }
        int newDist = dist[v] + E->cost;
        if(newDist < dist[s]){
          dist[s] = newDist;
          prev[s] = E->next;
          Q.push({-newDist, s});
        }
      }
    }
  }
public:
  MinCostFlow(){N=0;}
  MinCostFlow(int _N) : N(_N), dist(_N), prev(_N), adjList(_N) {}
  ~MinCostFlow(){ for (MCEdge* E: Edges) { delete E; } }
  
  void fit(int size) {
    if (size > N) {
      N = size;
      dist.resize(size); prev.resize(size); adjList.resize(size);
    }
  }
  
  void add_edge(int u, int v, int flow, int cost){
    fit(max(u, v) + 1);
    MCEdge *E1 = new MCEdge{v, cost, flow, 0}, *E2 = new MCEdge{u, -cost, 0 ,0};
    Edges.PB(E1); Edges.PB(E2);
    E1->next = E2; E2->next = E1;
    adjList[u].PB(E1); adjList[v].PB(E2);
  }
  
  vector<int> get_min_cost_flow(int s, int t){
    fit(max(s, t) + 1);
    Source = s; Sink = t;
//     int cost = 0, flow = 0;
    spfa();
    if(dist[Sink] > Infty / 2) { return {0,0}; }
    int sinkCost = reduce_cost();
    
    vector<int> res;
    res.PB(0);
    while (true) {
      dijkstra_shortest_path();
      if(dist[Sink] > Infty / 2) { break; }
      sinkCost += reduce_cost();
      
      int maxSend = Infty;
      for(int v = Sink; v != Source; v = prev[v]->to){
        maxSend = min(maxSend, prev[v]->next->flow);
      }
      for(int v = Sink; v != Source; v = prev[v]->to){
        MCEdge *E1 = prev[v], *E2 = E1->next;
        E1->flow += maxSend; E2->flow -= maxSend;
      }
      R(i,maxSend){
        res.PB(res.back() + sinkCost);
      }
//       flow += maxSend;
//       cost += maxSend * sinkCost;
    }
    return res;
  }
};

int n,m;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> m;
  MinCostFlow flow;
  R(i,m){
    int a,b,c;
    cin >> a >> b >> c;
    a--;b--;
    flow.add_edge(a,b,1,c);
  }
  vector<int> pom = flow.get_min_cost_flow(0,n-1);

  int q;
  cin >> q;
  R(i,q){
    int x;
    cin >> x;
    LD res = 1e18;
    R(j,SZ(pom))if(j){
      mini(res, ((LD)(pom[j] + x) )/ j);
    }
    cout << res << "\n";
  }

}