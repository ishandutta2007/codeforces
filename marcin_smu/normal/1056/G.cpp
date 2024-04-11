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

int n,m;
void add(int& a,int b){
  a += b;
  if(a >= n)
    a -= n;
}
void sub(int& a,int b){
  a -= b;
  if(a < 0)
    a += n;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> m;
//   vector<vector<int>> dp(n+1,vector<int>(n));
//   R(i,n)dp[0][i] = i;
//   debug(dp[0]);
//   R(i,n+1)if(i){
//     R(j,n){
//       if(j < m){
//       //  debug(i,j, dp[i-1][add(j,i)], add(j,i)); 
//         dp[i][j] = dp[i-1][add(j,i)];
//       }else{
//         dp[i][j] = dp[i-1][sub(j,i)];
//       }
//       cerr << dp[i][j] << " ";
//     }
//     cerr << "\n";
//   }
//   
//   R(i,n)
  
  int s,t;
  cin >> s >> t;
  int skok = t % n;
  vector<int> k(n,-1);
  s--;
  while(t){
    if(skok == 0){
      if(k[s] > 0){
        t %= (k[s] - t);
        k = vector<int>(n,-2);
      }else{
        if(k[s] == -1)
          k[s] = t;
      }
      if(t == 0)break;
      skok = n - 1;
    }else{
       if(s < m){
//         if(m - s > skok){
//           int sk = (m - s) / skok;
//           mini(sk,skok);
//           int pom = (2 * skok - sk + 1) * sk;
//           pom >>= 1;
//           skok -= sk;
//           t -= sk;
//           s += pom;
//         }
        add(s,skok);
      }else{
//         if(s - m > skok){
//           int sk = (s - m) / skok;
//           mini(sk,skok);
//           int pom = (2 * skok - sk + 1) * sk;
//           pom >>= 1;
//           skok -= sk;
//           t -= sk;
//           s -= pom;
//         }
        sub(s,skok);
      }
      skok --;
    }
    t--;
//    debug(s,t,skok);
  }
  s++;
  cout << s << "\n";
//   cout << dp[t][s-1] + 1 << "\n";
}