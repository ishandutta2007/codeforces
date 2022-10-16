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


const int MaxN = 1e5 + 6;

int N;
int data[MaxN];
int diffs[MaxN];


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> data[i];
  }

  LL result = -1e18;
  for (int i = 0; i < N - 1; i++) {
    diffs[i] = abs(data[i] - data[i + 1]);
  }

  for (int b : {0, 1}) {
    vector<int> ndiffs(diffs, diffs + N - 1);
    for (int i = b; i < N - 1; i += 2) {
      ndiffs[i] = -ndiffs[i];
    }

    debug(ndiffs);

    LL minPref = b == 1 ? 0 : 1e18;
    LL pref = 0;
    for (int i = 0; i < N - 1; i++) {
      pref += ndiffs[i];
      maxi(result, pref - minPref);
      if (i % 2 == b) { mini(minPref, pref); }
    }
  }


  cout << result << "\n";
}