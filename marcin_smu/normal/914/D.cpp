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

template<class C> void mini(C &a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C &a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<'='<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}

template<class T> ostream &operator<<(ostream& os, vector<T> V) {
  os << "["; for (auto vv : V) os << vv << ","; return os << "]";
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

const int MAX = 1 << 21;
int n;
int nn;
int dp[MAX];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n;
  nn = 1;while(nn <= n)nn*=2;
  R(i,n){
    cin >> dp[i + nn];
  }
  for(int i = nn - 1; i > 0; i--){
    dp[i] = __gcd(dp[i*2],dp[i*2+1]);
  }
  int q;
  cin >> q;
  R(i,q){
    int typ;
    cin >> typ;
    if(typ == 1){
      int l,r,x;
      cin >> l >> r >> x;
      l--;
      int gl = 0;
      function<void(int,int,int)> rec = [&](int nr,int po,int ko){
        if(po >= r || l >= ko)return;
        if(l <= po && ko <= r && dp[nr] % x == 0)return;
        if(po + 1 == ko){
          gl++;
          return;
        }
        rec(nr * 2, po, (po+ko)/2);
        if(gl >= 2)return;
        rec(nr * 2 + 1, (po+ko)/2, ko);
      };
      rec(1,0,nn);
      if(gl <= 1){
        cout << "YES\n";
      }else{
        cout << "NO\n";
      }
    }else{
      int id,y;
      cin >> id >> y;
      id--;
      id += nn;
      dp[id] = y;
      while(id != 1){
        id /= 2;
        dp[id] = __gcd(dp[id * 2], dp[id * 2 +1]);
      }
    }
      
  }
}