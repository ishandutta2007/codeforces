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


const int MaxN = 1024;

vector<int> adj[MaxN];
int weights[MaxN];
int beauty[MaxN];
int totalW[MaxN], totalB[MaxN];
int N, M;

bool vis[MaxN];
vector<vector<int>> compos;


void dfs(int v, int root, vector<int> &who) {
  totalW[root] += weights[v];
  totalB[root] += beauty[v];
  vis[v] = true;
  who.PB(v);

  for (int s : adj[v]) {
    if (!vis[s]) { dfs(s, root, who); }
  }
}


const int MaxW = 1024;

int maxBeauty[MaxW];
int oldBeauty[MaxW];
int W;


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(12);
  cerr << fixed << setprecision(6);

  cin >> N >> M >> W;
  for (int i = 1; i <= N; i++) { cin >> weights[i]; }
  for (int i = 1; i <= N; i++) { cin >> beauty[i]; }
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >>v;
    adj[u].PB(v); adj[v].PB(u);
  }

  for (int i = 1; i <= N; i++) {
    if (!vis[i]) {
      compos.emplace_back();
      dfs(i, i, compos.back());
    }
  }

  for (int i = 0; i <= W; i++) { maxBeauty[i] = 0; }
  
  for (auto V : compos) {
    debug(V);
    for (int i = 0; i <= W; i++) { oldBeauty[i] = maxBeauty[i]; }

    vector<PII> opts;
    for (int s : V) { opts.PB({weights[s], beauty[s]}); }
    opts.PB({totalW[V[0]], totalB[V[0]]});

    for (auto data : opts) {
      int w = data.first, b = data.second;
      debug(w, b);
      for (int nw = W; nw >= w; nw--) {
        maxi(maxBeauty[nw], oldBeauty[nw - w] + b);
      }
    }
  }

  cout << *max_element(maxBeauty, maxBeauty + W + 1) << "\n";
}