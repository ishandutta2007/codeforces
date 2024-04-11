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

const int M = 1 << 30;
const int Mod = 1e9 + 7;

struct Testcase {
  int x1, y1, x2, y2, k;
  LL result;

  LL getSum(int x) {
    return (LL)x * (x + 1) / 2;
  }

  void consider(int xl, int xr, int yl, int yr) {
    debug(xl, xr, yl, yr);
    int txor = xl ^ yl;
    int minLen = xr - xl,
        maxLen = yr - yl;
    if (minLen > maxLen) { swap(minLen, maxLen); }

    int intvTo   = txor | (maxLen - 1),
        intvFrom = intvTo ^ (maxLen - 1),
        coef     = minLen;

    intvTo++;

    debug(intvFrom, intvTo, coef);

    mini(intvTo, k);
    debug(intvFrom, intvTo, coef);
    if (intvFrom >= intvTo) { return; }

    LL sumNums = (getSum(intvTo) - getSum(intvFrom)) % Mod;
    debug(sumNums * coef);
    result += (sumNums * coef) % Mod;
  }

  void consider1D(int LBase, int RBase, int yl, int yr) {
    if (RBase <= x1 || LBase >= x2) { return; }
    if (x1 <= LBase && RBase <= x2) {
      consider(LBase, RBase, yl, yr);
      return;
    }

    int mid = (LBase + RBase) / 2;
    consider1D(LBase, mid, yl, yr);
    consider1D(mid, RBase, yl, yr);
  }

  void consider2D(int LBase, int RBase) {
    if (RBase <= y1 || LBase >= y2) { return; }
    if (y1 <= LBase && RBase <= y2) {
      consider1D(0, M, LBase, RBase);
      return;
    }

    int mid = (LBase + RBase) / 2;
    consider2D(LBase, mid);
    consider2D(mid, RBase);
  }

  void run() {
    cin >> x1 >> y1 >> x2 >> y2 >> k;
    x1--; y1--;
    result = 0;

    consider2D(0, M);

    cout << result % Mod << "\n";
  }
};


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  int Q;
  cin >> Q;
  for (int i = 0; i < Q; i++) {
    Testcase tc;
    tc.run();
  }
}