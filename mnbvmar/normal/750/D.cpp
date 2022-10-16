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


const int MaxSize = 512;
const int Bias = 256;

const int DirsR[8] = {0, 1, 1, 1, 0, -1, -1, -1},
          DirsC[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int N;
bool used[MaxSize][MaxSize];

set<tuple<int, int, int>> locs;


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(12);
  cerr << fixed << setprecision(6);

  cin >> N;
  //used[Bias][Bias] = true;
  locs.insert(make_tuple(0, 0, 2));

  for (int i = 0; i < N; i++) {
    set<tuple<int,int,int>> nextLocs;

    int cnt;
    cin >> cnt;
    debug(cnt);

    for (auto P : locs) {
      int row, col, dir;
      tie(row,col,dir) = P;

      debug(i, row, col, dir);

      for (int j = 0; j < cnt; j++) {
        row += DirsR[dir];
        col += DirsC[dir];
        used[Bias + row][Bias + col] = true;
      }

      nextLocs.insert(make_tuple(row, col, (dir + 1) % 8));
      nextLocs.insert(make_tuple(row, col, (dir + 7) % 8));
    }

    locs = nextLocs;
  }

  int result = 0;
  for (int i = 0; i < MaxSize; i++) {
    for (int j = 0; j < MaxSize; j++) {
      result += used[i][j];
    }
  }

  cout << result << "\n";
}