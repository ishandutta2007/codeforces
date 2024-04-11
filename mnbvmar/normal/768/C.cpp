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


const int MaxVal = 1024;

int N, K, X;
int cnts[MaxVal];
int nxtCnts[MaxVal];


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> N >> K >> X;
  for (int i = 0; i < N; i++) {
    int v; cin >> v;
    cnts[v]++;
  }

  for (int step = 0; step < K; step++) {
    memset(nxtCnts, 0, sizeof(int) * MaxVal);
    int curParity = 1;

    for (int val = 0; val < MaxVal; val++) {
      int numUpgrade = (cnts[val] + curParity) >> 1;
      curParity = (cnts[val] + curParity) & 1;

      nxtCnts[val ^ X] += numUpgrade;
      nxtCnts[val] += cnts[val] - numUpgrade;
    }

    memcpy(cnts, nxtCnts, sizeof(int) * MaxVal);
  }

  int maxRes = -1e9, minRes = 1e9;

  for (int i = 0; i < MaxVal; i++) {
    if (cnts[i]) {
      maxi(maxRes, i);
      mini(minRes, i);
    }
  }

  cout << maxRes << " " << minRes << "\n";
}