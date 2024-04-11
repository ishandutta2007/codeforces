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

const int MaxN = 1e5 + 100;

int N, M, S;
vector<int> Adj[MaxN];

bool Reachable[MaxN][2];
int PrevVert[MaxN][2];

void dfs(int v, int x) {
  Reachable[v][x] = true;
  for (int s : Adj[v])
    if (!Reachable[s][x ^ 1]) {
      PrevVert[s][x ^ 1] = v;
      dfs(s, x ^ 1);
    }
}

int Vis[MaxN];

bool dfsCycle(int v) {
  Vis[v] = 1;
  for (int s : Adj[v]) {
    if (Vis[s] == 1) { return true; }
    if (Vis[s] == 0 && dfsCycle(s))
      return true;
  }

  Vis[v] = 2;
  return false;
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> N >> M;
  for (int i = 1; i <= N; ++i) {
    int c; cin >> c;
    for (int j = 0; j < c; ++j) {
      int v;
      cin >> v;
      Adj[i].PB(v);
    }
  }

  cin >> S;
  dfs(S, 0);

  for (int i = 1; i <= N; ++i) {
    if (SZ(Adj[i]) == 0 && Reachable[i][1]) {
      cout << "Win\n";
      vector<int> Res;
      int v = i, x = 1;
      Res.push_back(v);
      while (v != S || x != 0) {
        v = PrevVert[v][x];
        x ^= 1;
        Res.push_back(v);
      }

      reverse(ALL(Res));
      for (int s : Res) { cout << s << " "; }
      cout << "\n";
      return 0;
    }
  }

  if (dfsCycle(S))
    cout << "Draw\n";
  else
    cout << "Lose\n";
}