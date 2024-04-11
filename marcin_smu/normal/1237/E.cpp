#pragma GCC optimize("O3")
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// gp_hash_table<int, int> mapka;

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
  while(*sdbg!=',')cerr<<*sdbg++;
  cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
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

int n;
// const int MAX = 1001001;
// int res[MAX][2];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n;
  int ok = 1;
  int i = 0;
  while(ok < n){
    if(i & 1){
      ok*=2;
      if(i & 2){
        ok--;
      }
    }else{
      ok++;
    }
    i++;
    debug(ok);
  }
  if(ok == n){
    cout << "1\n";
  }else{
    cout << "0\n";
  }
  return 0;
//   res[1][1] = 1;
//   res[2][0] = 1;
//   int h = 0;
//   for(int i = 3; i < n;i++){
//     if(((i + 1) & i) == 0){
//       h++;
//     }
//   //  debug(i,h);
//     for(int root = 1; root <= i; root++){
//       int left = root - 1;
//       int right = i - left - 1;
//       if(left < ((1 << h) - 1) || left >= (1 << (h+1)))continue;
//       if(right < ((1 << h) - 1) || right >= (1 << (h+1)))continue;
//       //debug(i,root,left,right,((1 << h) - 1));
//       if(root & 1){
//         res[i][1] += res[left][0] * res[right][0];
//       }else{
//         res[i][0] += res[left][1] * res[right][0];
//       }
//     }
//     if(res[i][0] + res[i][1])
//       debug(i,res[i][0],res[i][1]);
//   }
}