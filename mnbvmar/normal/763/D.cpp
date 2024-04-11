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

using Hash = unsigned long long;

Hash hashesDown[MaxN], hashesUp[MaxN];
int N;
vector<int> adj[MaxN];

const Hash startHash = 0x129847DABCEF194LL,
           mulHash1  = 0x876124782498124LL,
           mulHash2  = 2189279012481290125LL,
           addHash1  = 5918274819274129LL,
           addHash2  = 1239741298471241111LL;


void dfs(int v, int p) {
  hashesDown[v] = startHash;
  Hash mul = mulHash1, add = addHash1;
  
  for (int s : adj[v]) {
    if (s == p) { continue; }
    dfs(s, v);
    
    mul *= hashesDown[s];
    add += hashesDown[s];
  }
  
  mul += mulHash2;
  add *= addHash2;
  hashesDown[v] ^= mul ^ add;
  
  debug(v, hashesDown[v]);
}


void dfsUp(int v, int p) {
  if (v == p) {
    hashesUp[v] = 0;
  }
  
  vector<int> children;
  
  for (int s : adj[v]) {
    if (s == p) { continue; }
    children.push_back(s);
  }
  
  vector<Hash> mulsPref, addsPref, mulsSuf, addsSuf;
  mulsPref.push_back(1);
  addsPref.push_back(0);
  for (int s : children) {
    mulsPref.push_back(hashesDown[s]);
    addsPref.push_back(hashesDown[s]);
    mulsSuf.push_back(hashesDown[s]);
    addsSuf.push_back(hashesDown[s]);
  }
  mulsSuf.push_back(1);
  addsSuf.push_back(0);
  
  int K = SZ(children);
  for (int i = 1; i <= K; i++) {
    mulsPref[i] *= mulsPref[i - 1];
    addsPref[i] += addsPref[i - 1];
  }
  for (int i = K - 1; i >= 0; i--) {
    mulsSuf[i] *= mulsSuf[i + 1];
    addsSuf[i] += addsSuf[i + 1];
  }
  
  debug(v, K, mulsPref, mulsSuf);
  
  for (int i = 0; i < K; i++) {
    Hash mul = mulHash1 * mulsPref[i] * mulsSuf[i + 1];
    Hash add = addHash1 + addsPref[i] + addsSuf[i + 1];
    if (v != p) {
      mul *= hashesUp[v];
      add += hashesUp[v];
    }
    
    mul += mulHash2;
    add *= addHash2;
    hashesUp[children[i]] = startHash ^ mul ^ add;
    
    debug(children[i], hashesUp[children[i]]);
  }
  
  for (int s : children) {
    dfsUp(s, v);
  }
}

map<Hash, int> curHashes;
int cntHashes;

void addHash(Hash h) {
  //debug("add", h);
  if (curHashes[h] == 0) { cntHashes++; }
  curHashes[h]++;
}

void delHash(Hash h) {
  //debug("del", h);
  curHashes[h]--;
  if (curHashes[h] == 0) { cntHashes--; }
}


void dbg() {
  #ifdef LOCAL
  for (auto P : curHashes) {
    if (P.second) { debug(P); }
  }
  #endif
}

int bestRes = -1, whoBest = -1;

void dfsCount(int v, int p) {
  delHash(hashesDown[v]);
  
  cerr << "\n";
  debug(v, p, cntHashes);
  dbg();
  
  if (cntHashes > bestRes) {
    bestRes = cntHashes;
    whoBest = v;
  }
  
  for (int s : adj[v]) {
    if (s != p) {
      debug(v, s);
      addHash(hashesUp[s]);
      dfsCount(s, v);
      delHash(hashesUp[s]);
    }
  }
  
  addHash(hashesDown[v]);
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> N;
  for (int i = 0; i < N - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].PB(v);
    adj[v].PB(u);
  }
  
  dfs(1, 1);
  dfsUp(1, 1);
  
  for (int i = 1; i <= N; i++) {
    addHash(hashesDown[i]);
  }
  
  dfsCount(1, 1);
  
  cout << whoBest << "\n";
}