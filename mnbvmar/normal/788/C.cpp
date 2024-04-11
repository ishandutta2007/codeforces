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


const int DivCon = 1000;
const int MaxDiv = 1024;

int N, K;
bool present[MaxDiv];

bitset<2 * MaxDiv> available, navailable;


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> N >> K;
  int minV = 1e9, maxV = -1e9;

  for (int i = 0; i < K; i++) {
    int v; cin >> v;
    mini(minV, v); maxi(maxV, v);
    present[v] = true;
  }

  if (maxV < N || minV > N) {
    cout << "-1\n";
    return 0;
  }

  available[MaxDiv] = 1;
  int iters = 0;
  while (true) {
    navailable.reset();

    for (int i = 0; i <= DivCon; i++) {
      if (present[i]) {
        if (i <= N) {
          navailable |= available >> (N - i);
        } else {
          navailable |= available << (i - N);
        }
      }
    }

    //debug(navailable);

    available = navailable;
    iters++;
    if (available[MaxDiv]) { cout << iters << "\n"; return 0; }
  }
}