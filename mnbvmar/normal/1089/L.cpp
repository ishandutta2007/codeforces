#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define RE(i,n) FOR(i,1,n)
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

template<class C> void mini(C&a4, C b4){a4=min(a4,b4);}
template<class C> void maxi(C&a4, C b4){a4=max(a4,b4);}

template<class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA...a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<"="<<h<<","; _dbg(sdbg+1,a...);
}

template<class T> ostream&operator<<(ostream&os, vector<T> V) {
  os<<"[";
  for (auto v : V)os<<v<<",";
  return os << "]";
}
template<class L, class R> ostream&operator<<(ostream&os, pair<L,R> P) {
  return os<<"("<<P.st<<","<<P.nd<<")";
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int MaxN = 1e5 + 100;

int num_assigned[MaxN];
int needed_time[MaxN];
int assignment[MaxN];
int N, K;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  
  cin >> N >> K;
  int num_diff = 0;
  for (int i = 0; i < N; ++i) {
    cin >> assignment[i];
    if (num_assigned[assignment[i]]++ == 0) {
      ++num_diff;
    }
  }
  for (int i = 0; i < N; ++i)
    cin >> needed_time[i];
  
  if (num_diff >= K) {
    cout << "0\n";
    return 0;
  }
  
  vector<int> order(N);
  iota(ALL(order), 0);
  sort(ALL(order), [&](int lhs, int rhs) { return needed_time[lhs] < needed_time[rhs]; });
  
  LL ans = 0;
  for (int v : order) {
    if (num_assigned[assignment[v]] == 1) { continue; }
    debug(v);
    --num_assigned[assignment[v]];
    ans += needed_time[v];
    ++num_diff;
    if (num_diff >= K) { break; }
  }
  
  cout << ans << "\n";
}