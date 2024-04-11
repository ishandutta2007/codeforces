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



const int MaxN = 512;

struct BitMatrix {
  bitset<MaxN> data[MaxN];
  int sz;

  BitMatrix() {
    for (int i = 0; i < MaxN; i++) { data[i].reset(); }
  }

  /*BitMatrix &operator=(const BitMatrix &other) {
    for (int i = 0; i < sz; i++) {
      data[i] = other.data[i];
    }
    sz = other.sz;
    return *this;
  }*/


  BitMatrix mul(const BitMatrix &other) const {
    BitMatrix result;
    result.sz = sz;
    for (int i = 0; i < sz; i++) {
      for (int j = 0; j < sz; j++) {
        if (data[i][j]) {
          result.data[i] |= other.data[j];
        }
      }
    }
    return result;
  }
};


const int MaxBits = 61;

BitMatrix reach[MaxBits][2];
int N, M;


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int v, u, t;
    cin >> v >> u >> t;
    debug(v, u, t);
    u--; v--;
    reach[0][t].data[v][u] = true;
  }

  if (M == 0) {
    cout << "0\n";
    return 0;
  }

  reach[0][0].sz = reach[0][1].sz = N;

  for (int i = 1; i < MaxBits; i++) {
    reach[i][0] = reach[i - 1][0].mul(reach[i - 1][1]);
    reach[i][1] = reach[i - 1][1].mul(reach[i - 1][0]);
  }

  int pos = -1;

  for (int i = 0; i < MaxBits; i++) {
    for (int t : {0}) {
      for (int b = 0; b < N; b++) {
        if (reach[i][t].data[0][b]) { debug(i); pos = i; }
      }
    }
  }


  debug(pos);

  if (pos == -1) {
    cout << "0\n";
    return 0;
  }
  if (pos == MaxBits - 1) {
    cout << "-1\n";
    return 0;
  }

  long long maxLen = (1LL << pos);

  vector<BitMatrix> curReach{reach[pos][0], reach[pos][1]};
  int which = 1;
  for (int bit = pos - 1; bit >= 0; bit--) {
    BitMatrix nxtReach[2] = {curReach[1].mul(reach[bit][0]),
                             curReach[0].mul(reach[bit][1])};
    bool found = false;
    for (int t : {which}) {
      for (int b = 0; b < N; b++) {
        if (nxtReach[t].data[0][b]) { found = true; break; }
      }
    }

    if (found) {
      curReach[0] = nxtReach[0];
      curReach[1] = nxtReach[1];
      maxLen += (1LL << bit);
      which ^= 1;
    }
  }

  if (maxLen > (int)1e18) {
    cout << "-1\n";
    return 0;
  }

  cout << maxLen << "\n";

}