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

const int alfa = 'z' - 'a' + 1;
struct Sol{
  int n;
  string z;
  vector<int> ile;
  void run(){
    ile.resize(alfa);
    cin >> z;
    n = SZ(z);
    R(i,n){
      ile[z[i] - 'a'] ++;
    }
    R(i,alfa){
      if(ile[i] == 1){
        string res;
        res += 'a' + i;
        R(j,alfa)if(i != j){
          R(_,ile[j]){
            res += 'a' + j;
          }
        }
        cout << res << "\n";
        return;
      }
    }
    vector<int> kt;
    R(i,alfa){
      if(ile[i])kt.PB(i);
    }
    R(i,alfa){
      if(ile[i] > 0){
        {
          string res;
          res += 'a' + i;
          res += 'a' + i;
          int pom = ile[i] - 2;
          R(j,alfa)if(i != j){
            R(_,ile[j]){
              res += 'a' + j;
              if(pom){
                res += 'a' + i;
                pom--;
              }
            }
          }
          if(pom == 0){
            cout << res << "\n";
            return;
          }
        }
        
        if(SZ(kt) >= 3){
          string res;
          res += 'a' + i;
          res += 'a' + kt[1];
          R(_,ile[i]-1){
            res += 'a' + i;
          }
          res += 'a' + kt[2];
          ile[kt[1]]--;
          ile[kt[2]]--;
          R(j,alfa)if(i != j){
            R(_,ile[j]){
              res += 'a' + j;
            }
          }
          cout << res << "\n";
          return;
        }
        string res;
        res += 'a' + i;
        R(j,alfa)if(i != j){
          R(_,ile[j]){
            res += 'a' + j;
          }
        }
        R(_,ile[i]-1){
          res += 'a' + i;
        }
        cout << res << "\n";
        return;
      }
    }
  }
};

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  int t;
  cin >> t;
  while(t--){
    Sol sol;
    sol.run();
  }
}