#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPDN(i,n) for(int i=(n)-1;i>=0;--i)
#define FOR(i,a,n) for(int i=(a);i<(n);++i)
#define FORE(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
typedef long long ll;

const int N=100100, LOGN=18, M=10000000, MOD=1000000007;
int n,val[N],x[N],q,logn;
vector<int> adj[N];
int T,tin[N],tout[N],parent[N],up[LOGN][N];
vector<int> queries[N];
int QUERY[N];
vector<int> TOTAL,TOTAL_inv;
int sz;

int dz[M+1];
int gcnt[M+1],gpos[M+1],ginv[M+1];

void sieve(int m) {
  for (int d=2; d<=m; ++d) if (!dz[d]) {
    dz[d] = d;
    for (int j=2*d; j<=m; j+=d) if (!dz[j]) dz[j] = d;
  }
}

void dfs(int v, int par) {
  tin[v] = T++;
  parent[v] = par;
  FORE(i,adj[v]) if (*i != par) {
    dfs(*i, v);
  }
  tout[v] = T;
}

void init_lca() {
  logn=1; while ((1<<logn-1) < n) { ++logn; }
  REP(i,n+1) up[0][i] = parent[i];
  REP(k,logn-1) REP(i,n+1) {
    up[k+1][i] = up[k][up[k][i]];
  }
}

bool insubtree(int vr, int v) {
  return tin[vr] <= tin[v] && tin[v] < tout[vr];
}

int lca(int va, int vb) {
  REPDN(k,logn) {
    if (!insubtree(up[k][va], vb)) { va = up[k][va]; }
  }
  if (!insubtree(va, vb)) { va = up[0][va]; }
  return va;
}

inline void mult(int& a, int b) { a = ll(a) * b % MOD; }

int modpow(int a, int n) {
  int w = 1;
  while (n) {
    if (n&1) mult(w, a);
    mult(a, a);
    n /= 2;
  }
  return w;
}

int inv(int a) { return modpow(a, MOD-2); }

void dfs2(int v, int par) {
  // Enter vertex
  int w = val[v];
  while (dz[w]) {
    int d = dz[w], pos = gpos[d], dinv = ginv[d];
    while (dz[w] == d) {
      mult(TOTAL[pos], d);
      mult(TOTAL_inv[pos], dinv);
      ++pos;
      w /= d;
    }
  }
  // Process queries for vertex
  FORE(i,queries[v]) {
    int w = x[*i/2];
    while (dz[w]) {
      int d = dz[w], pos = gpos[d], posend = pos + gcnt[d];
      while (dz[w] == d) {
        if (pos < posend) {
          if (*i&1) { mult(QUERY[*i/2], TOTAL_inv[pos++]); }
          else { mult(QUERY[*i/2], TOTAL[pos++]); }
        }
        w /= d;
      }
    }
  }
  // Process children
  FORE(i,adj[v]) if (*i != par) {
    dfs2(*i, v);
  }
  // Leave vertex
  w = val[v];
  while (dz[w]) {
    int d = dz[w], pos = gpos[d], dinv = ginv[d];
    while (dz[w] == d) {
      mult(TOTAL[pos], dinv);
      mult(TOTAL_inv[pos], d);
      ++pos;
      w /= d;
    }
  }
}

int main() {
  sieve(M);
  scanf("%d",&n);
  REP(i,n-1) {
    int a,b; scanf("%d%d",&a,&b); --a; --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(0, -1);
  parent[0] = n;
  val[n] = 1;
  adj[n].push_back(0);
  tin[n] = -1; tout[n] = n;
  init_lca();

  REP(i,n) {
    scanf("%d",&val[i]);
    int w = val[i];
    while (dz[w]) {
      int d = dz[w], cnt = 1;
      while (dz[w] == d) {
        ++cnt;
        w /= d;
      }
      gcnt[d] = max(gcnt[d], cnt);
    }
  }
  sz = 0;
  REP(i,M+1) if (gcnt[i]) {
    gpos[i] = sz;
    sz += gcnt[i];
    ginv[i] = inv(i);
  }
  TOTAL = TOTAL_inv = vector<int>(sz, 1);

  scanf("%d",&q);
  REP(i,q) {
    int a,b; scanf("%d%d%d",&a,&b,&x[i]); --a; --b;
    int c = lca(a,b);
    queries[a].push_back(i*2);
    queries[b].push_back(i*2);
    queries[c].push_back(i*2+1);
    queries[parent[c]].push_back(i*2+1);
    QUERY[i] = 1;
  }

  dfs2(n, -1);

  REP(i,q) printf("%d\n", QUERY[i]);
}