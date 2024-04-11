#include <bits/stdc++.h>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
//#define int LL
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

const int MaxN = 22;

int Dist[1 << MaxN];
int Who[1 << MaxN];
int Prev[1 << MaxN];
int Adj[MaxN];


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  int N, M;
  cin >> N >> M;
  if (M == N * (N - 1) / 2) {
    cout << "0\n";
    return 0;
  }

  fill_n(Dist, 1 << N, (int)1e9);
  for (int i = 0; i < N; ++i)
    Dist[1 << i] = 0;

  for (int i = 0; i < M; ++i) {
    int u, v;
    cin >> u >> v;
    --u; --v;
    Adj[u] |= 1 << v;
    Adj[v] |= 1 << u;
  }

  for (int Msk = 0; Msk < (1 << N); ++Msk) {
    for (int i = 0; i < N; ++i)
      if (Msk & (1 << i)) {
        int R = Dist[Msk] + 1,
            NM = Msk | Adj[i];
        if (Dist[NM] > R) {
          Dist[NM] = R;
          Prev[NM] = Msk;
          Who[NM] = i;
        }
      }
  }

  cout << Dist[(1 << N) - 1] << "\n";

  int MM = (1 << N) - 1;
  while (__builtin_popcount(MM) > 1) {
    cout << Who[MM] + 1 << " ";
    MM = Prev[MM];
  }
  cout << "\n";
}