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

template<class C> void mini(C&a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C&a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<endl;}
template<class TH, class...TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while (*sdbg!=',')cerr<<*sdbg++;cerr<<'='<<h<<",";_dbg(sdbg+1, a...);
}

template<class T> ostream& operator<<(ostream &os, vector<T> V) {
  os<<"[";for(auto vv:V)os<<vv<<","; os<<"]";
  return os;
}
template<class L, class R> ostream& operator<<(ostream &os, pair<L, R> P) {
  os<<"("<<P.first<<","<<P.second<<")";
  return os;
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int MaxMask = (1 << 22);
const int MaxN = (1 << 19);

vector<int> children[MaxN];
string dnVals;
int masks[MaxN];
int treeSize[MaxN], depth[MaxN];
int heavyChild[MaxN];
int N;
int result[MaxN];


void dfs(int v) {
  if (v > 1) {
    masks[v] ^= (1 << (dnVals[v] - 'a'));
  }
  treeSize[v] = 1;
  heavyChild[v] = -1;
  int maxSize = -1;
  
  for (int s : children[v]) {
    masks[s] = masks[v];
    depth[s] = depth[v] + 1;
    dfs(s);
    treeSize[v] += treeSize[s];
    if (treeSize[s] > maxSize) {
      maxSize = treeSize[s];
      heavyChild[v] = s;
    }
  }
}




int maxDepth[MaxMask];


void addToRes(int v, int root) {
  debug("addDepth", v, root, masks[v]);
  for (int i = 0; i < 22; i++) {
    debug(i, maxDepth[masks[v] ^ (1 << i)]);
    maxi(result[root], maxDepth[masks[v] ^ (1 << i)] + depth[v] - 2 * depth[root]);
  }
  maxi(result[root], maxDepth[masks[v]] + depth[v] - 2 * depth[root]);
  //maxi(maxDepth[masks[v]], depth[v]);
}

void dfsAddToRes(int v, int root) {
  addToRes(v, root);

  for (int s : children[v]) {
    dfsAddToRes(s, root);
  }
}

void dfsAddToDepth(int v) {
  maxi(maxDepth[masks[v]], depth[v]);
  for (int s : children[v]) { dfsAddToDepth(s); }
}

void dfsHeavy(int v) {
  debug("heavy", v);
  if (heavyChild[v] != -1) {
    dfsHeavy(heavyChild[v]);
  }
  addToRes(v, v);
  maxi(maxDepth[masks[v]], depth[v]);
  for (int s : children[v]) {
    if (heavyChild[v] != s) {
      dfsAddToRes(s, v);
      dfsAddToDepth(s);
    }
  }
}


void dfsCleanup(int v) {
  debug("cleanup", v);
  maxDepth[masks[v]] = -1e9;
  for (int s : children[v]) {
    dfsCleanup(s);
  }
}


void dfsPath(int v) {
  debug("path", v);
  dfsHeavy(v);
  dfsCleanup(v);

  int heavy = v;
  do {
    for (int s : children[heavy]) {
      if (s != heavyChild[heavy]) { dfsPath(s); }
    }
    heavy = heavyChild[heavy];
  } while (heavy > 0);
}


void dfsRecoverRes(int v) {
  for (int s : children[v]) {
    dfsRecoverRes(s);
    maxi(result[v], result[s]);
  }
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(12);
  cerr << fixed << setprecision(6);
  cin >> N;

  dnVals = "??";
  for (int i = 2; i <= N; i++) {
    int up;
    char ch;
    cin >> up >> ch;
    children[up].PB(i);
    dnVals.PB(ch);
  }

  dfs(1);
  fill(maxDepth, maxDepth + MaxMask, (int)-1e9);
  for (int i = 1; i <= N; i++) {
    debug(i, depth[i], treeSize[i], heavyChild[i]);
  }
  dfsPath(1);
  dfsRecoverRes(1);

  for (int i = 1; i <= N; i++) {
    cout << result[i] << " ";
  }
  cout << "\n";
}