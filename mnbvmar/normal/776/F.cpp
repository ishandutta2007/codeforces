#include <bits/stdc++.h>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define RE(i,n) FOR(i,1,n)
#define R(i,n) REP(i,n)
#define FI first
#define SE second
#define st FI
#define nd SE
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define VI vector<int>
#define PII pair<int,int>
#define LD long double

template<class C> void mini(C& a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C& a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<"="<<h<<","; _dbg(sdbg+1, a...);
}

template<class T> ostream &operator<<(ostream &os, vector<T> V){
  os<<"[";for(auto vv:V)os<<vv<<",";return os<<"]";
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


const int MaxN = 1e5 + 6;
int N, M;

vector<PII> diags;
map<PII, PII> order;
vector<int> outgoing[MaxN];

set<PII> diagOrd, visited;
map<PII, int> diagMap;
vector<VI> regions;
vector<int> adj[MaxN];



bool forbidden[MaxN];
int V;
int vis[MaxN];
int treeSize[MaxN];
int result[MaxN];

int curDfs;

void dfsSizes(int v) {
  vis[v] = curDfs;
  treeSize[v] = 1;
  for (int s : adj[v]) {
    if (vis[s] == curDfs || forbidden[s]) { continue; }
    dfsSizes(s);
    treeSize[v] += treeSize[s];
  }
}

int findCentro(int v, int tSz) {
  int cur = v;
  bool failed = false;

  while (!failed) {
    failed = true;
    for (int s : adj[cur]) {
      if (forbidden[s]) { continue; }
      if (treeSize[s] < treeSize[cur] && treeSize[s] * 2 >= tSz) {
        failed = false;
        cur = s;
        break;
      }
    }
  }

  return cur;
}

void centroids(int v, int depth) {
  curDfs++;
  dfsSizes(v);

  int c = findCentro(v, treeSize[v]);
  debug(v, depth, c);
  result[c] = depth;
  forbidden[c] = true;
  for (int s : adj[c]) {
    if (!forbidden[s]) {
      centroids(s, depth + 1);
    }
  }
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    diags.emplace_back(u, v);
    outgoing[u].PB(v);
    outgoing[v].PB(u);
    diagOrd.insert(make_pair(u, v));
    diagOrd.insert(make_pair(v, u));
  }

  for (int i = 0; i < N; i++) {
    outgoing[i].push_back((i + 1) % N);
    outgoing[i].push_back((i + N - 1) % N);
    diagOrd.insert(make_pair(i, (i + 1) % N));
  }

  for (int i = 0; i < N; i++) {
    vector<int> rels;
    for (int v : outgoing[i]) {
      rels.push_back((v - i + N) % N);
    }
    sort(ALL(rels));

    debug(i, rels);

    int S = SZ(rels);
    for (int j = 1; j < S; j++) {
      debug(rels[j], i, rels[j - 1]);
      order[make_pair((i + rels[j]) % N, i)] = make_pair(i, (i + rels[j - 1]) % N);
    }
  }

  for (auto P : diagOrd) {
    if (!visited.count(P)) {
      auto ptr = P;
      vector<int> region;
      vector<PII> edges;

      do {
        edges.push_back(ptr);
        visited.insert(ptr);
        region.push_back(ptr.first);
        ptr = order[ptr];
      } while (ptr != P);

      int id = SZ(regions);
      regions.push_back(region);

      for (auto PP : edges) {
        auto QQ = make_pair(PP.second, PP.first);
        if (diagMap.count(QQ)) {
          int other = diagMap[QQ];
          adj[id].push_back(other);
          adj[other].push_back(id);
        }
      }

      for (auto PP : edges) {
        diagMap[PP] = id;
      }
    }
  }

  debug(regions);
  for (int i = 0; i < SZ(regions); i++) {
    debug(i, adj[i]);
  }

  for (auto &reg : regions) {
    sort(ALL(reg), greater<int>());
  }

  vector<int> compOrder(SZ(regions));
  iota(ALL(compOrder), 0);
  sort(ALL(compOrder), [&](int lhs, int rhs) {
        return regions[lhs] < regions[rhs];
      });

  debug(compOrder);

  V = SZ(regions);
  centroids(0, 1);


  for (int c : compOrder) {
    cout << result[c] << " ";
  }
  cout << "\n";

}