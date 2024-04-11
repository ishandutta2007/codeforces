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

template<class C> void mini(C &a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C &a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<'='<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
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
  vector<vector<MCEdge*>> adjList;
  int N, Source, Sink;
  VI dist;
  vector<MCEdge*> prev, Edges;
  
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
  MinCostFlow(){}
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
    MCEdge *E1 = new MCEdge{v, cost, flow}, *E2 = new MCEdge{u, -cost, 0};
    Edges.PB(E1); Edges.PB(E2);
    E1->next = E2; E2->next = E1;
    adjList[u].PB(E1); adjList[v].PB(E2);
  }
  
  PII get_min_cost_flow(int s, int t){
    fit(max(s, t) + 1);
    Source = s; Sink = t;
    int cost = 0, flow = 0;
    spfa();
    if(dist[Sink] > Infty / 2) { return {0,0}; }
    int sinkCost = reduce_cost();
    
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
      flow += maxSend;
      cost += maxSend * sinkCost;
    }
    return {flow, cost};
  }
};

const int MAX = 51;
int mi[MAX],ma[MAX];
int n,q;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> q;
  R(i,n){
    mi[i] = 0;
    ma[i] = n-1;
  }
  R(i,q){
    int typ,l,r,v;
    cin >> typ >> l >> r >> v;v--;
    l--;
    for(int j = l; j < r; j++){
      if(typ == 1){
        maxi(mi[j], v);
      }else{
        mini(ma[j], v);
      }
    }
  }
  MinCostFlow flow(2 * n+2);
  R(i,n){
    flow.add_edge(2 * n + 1, n + i, 1, 0);
    for(int j = mi[i]; j <= ma[i]; j++){
      flow.add_edge(n + i, j, 1, 0);
    }
    R(j,n){
      flow.add_edge(i, n*2, 1, 2*j + 1);
    }
  }
  PII pom = flow.get_min_cost_flow(2*n+1, n*2);
  if(pom.FI == n){
    cout << pom.SE << "\n";
  }else{
    cout << "-1\n";
  }
  
}