#include <bits/stdc++.h>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
//#define int LL
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


map<pair<int, LL>, int> memo;

int compute(int size, LL mask) {
  auto P = make_pair(size, mask);
  if (memo.count(P)) { return memo[P]; }

  bool vars[64];
  for (int i = 0; i < 64; i++) { vars[i] = false; }

  for (int i = 1; i <= size; i++) {
    if (mask & (1LL << i)) {
      vars[compute(size - i, mask ^ (1LL << i))] = true;
    }
  }

  for (int i = 0; i < 64; i++) {
    if (!vars[i]) { return memo[P] = i; }
  }
  assert(false);
}

int values[64];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  for (int i = 1; i <= 60; i++) {
    values[i] = compute(i, LLONG_MAX);
  }

  int N;
  cin >> N;
  int res = 0;
  for (int i = 0; i < N; i++) {
    int v;
    cin >> v;
    res ^= values[v];
  }
  //cout << res << endl;

  cout << (res == 0 ? "YES\n" : "NO\n");
  cout << flush;
}