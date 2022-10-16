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


const int MaxN = 2e5 + 6;

int N, M, K;
vector<int> adj[MaxN];
vector<int> order;
bool visited[MaxN];

void dfs(int v) {
  order.push_back(v);
  visited[v] = true;

  for (int s : adj[v]) {
    if (visited[s]) { continue; }
    dfs(s);
    order.push_back(v);
  }
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> N >> M >> K;
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].PB(v);
    adj[v].PB(u);
  }

  dfs(1);
  debug(SZ(order));
  debug(order);

  assert(SZ(order) == 2 * N - 1);

  int ptr = 0;

  for (int i = 0; i < K; i++) {
    int from = SZ(order) * i / K,
        to   = SZ(order) * (i + 1) / K;
    cout << to - from;
    for (int j = from; j < to; j++) {
      cout << " " << order[j];
    }
    cout << "\n";
  }

}