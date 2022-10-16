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
#define VI vector<int>
#define PII pair<int,int>
#define LD long double
#define FI first
#define SE second
#define st FI
#define nd SE
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())

template<class C> void mini(C& a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C& a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h) {cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while (*sdbg!=',')cerr<<*sdbg++;cerr<<"="<<h<<","; _dbg(sdbg+1, a...);
}

template<class T> ostream& operator<<(ostream &os, vector<T> V) {
  os << "["; for (auto v : V) os << v << ","; os << ']'; return os;
}

template<class L, class R> ostream &operator<<(ostream &os, pair<L, R> P ){
  return os << "(" << P.st << ", " << P.nd << ")";
}


#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int MaxN = 105;

int N;
int points[MaxN], change[MaxN], order[MaxN], curOrder[MaxN];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> points[i] >> change[i];
  }
  
  iota(order, order + N, 0);
  iota(curOrder, curOrder + N, 0);
  
  auto rankOrder = [&](int lhs, int rhs) {
    return MP(-points[lhs], lhs) < MP(-points[rhs], rhs);
  };
  
  sort(order, order + N, [&](int lhs, int rhs) {
    if ((change[lhs] > 0) != (change[rhs] > 0)) {
      return (change[rhs] > 0);
    }
    
    if (change[lhs] > 0) {
      return rankOrder(rhs, lhs);
      //return points[lhs] < points[rhs];
    } else {
      return rankOrder(lhs, rhs);
      //return points[lhs] > points[rhs];
    }
  });
  

  
  sort(curOrder, curOrder + N, rankOrder);
  
  int res = 0;
  for (int t = 0; t < N; t++) {
    int who = order[t];
    debug(who);
    points[who] += change[who];
    int posFrom = 0, posTo = 0;
    
    while (curOrder[posFrom] != who) { posFrom++; }
    sort(curOrder, curOrder + N, rankOrder);
    while (curOrder[posTo] != who) { posTo++; }
    
    res += abs(posFrom - posTo);
  }
  
  cout << res << "\n";
}