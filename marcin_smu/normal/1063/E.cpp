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

const int MAX = 1001;
int n;
int gd[MAX];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n;
  bool wynn = 1;
  R(i,n){
    int pom;
    cin >> pom;
    pom--;
    gd[pom] = i;
    if(pom != i)wynn = 0;
  }
  if(wynn){
    cout << n << "\n";
    string res(n,'.');
    R(i,n){
      cout << res << "\n";
    }
    return 0;
  }
  cout << n-1 << "\n";
  int wol = 0;
  R(_,n){
    string res(n,'.');
    if(gd[wol] != wol){
      int ak = -1;
      R(j,n){
        if(gd[j] == wol){
          ak = j;
          break;
        }
      }
      if(ak < wol){
        res[ak] = '\\';
        res[wol] = '\\';
        if(gd[wol] == ak){
          for(int i = 0; i < ak; i++){
            if(gd[i] != i){
              res[i] = '\\';
              swap(gd[i], gd[ak]);
              ak = i;
              break;
            }
          }
        }
      }else{
        res[ak] = '/';
        res[wol] = '/';
        for(int i = n-1; i > ak; i--){
          if(gd[i] != i){
            res[i] = '/';
            swap(gd[i], gd[ak]);
            ak = i;
            break;
          }
        }
      }
      swap(gd[ak],gd[wol]);
      wol = ak;
    }else{
      R(j,n){
        if(gd[j] < j && wol < gd[j]){
          int a = wol;
          int b = gd[j];
          int c = j;
          
          res[a] = '/';
          res[b] = '/';
          res[c] = '/';
          
          gd[a] = gd[b];
          gd[b] = b;
          gd[c] = a;
          wol = c;
          break;
        }
        if(gd[j] > j && wol > gd[j]){
          int a = wol;
          int b = gd[j];
          int c = j;
          
          res[a] = '\\';
          res[b] = '\\';
          res[c] = '\\';
          
          gd[a] = gd[b];
          gd[b] = b;
          gd[c] = a;
          wol = c;
          break;
        }
      }
    }
    cout << res << "\n";
  }
  
}