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

const int MaxN = 400005;

int N;
LL balloons[MaxN], weight[MaxN];
vector<int> order;


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(12);
  cerr << fixed << setprecision(6);

  set<pair<LL, int>> betterTeams;

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> balloons[i] >> weight[i];
  }

  LL curBalloons = balloons[0];

  order.resize(N);
  iota(ALL(order), 1);
  sort(ALL(order), [&](int lhs, int rhs) {
        return balloons[lhs] > balloons[rhs];
      });
  
  int optr = 0;
  while (balloons[order[optr]] > curBalloons) {
    int who = order[optr];
    betterTeams.insert({weight[who] - balloons[who] + 1, who});
    optr++;
  }

  int result = SZ(betterTeams);
  while (curBalloons > 0 && SZ(betterTeams) > 0) {
    auto P = *betterTeams.begin();
    betterTeams.erase(betterTeams.begin());
    
    curBalloons -= P.first;
    if (curBalloons < 0) { break; }
    while (balloons[order[optr]] > curBalloons) {
      int who = order[optr];
      betterTeams.insert({weight[who] - balloons[who] + 1, who});
      optr++;
    }

    mini(result, SZ(betterTeams));
  }

  cout << result + 1 << "\n";
}